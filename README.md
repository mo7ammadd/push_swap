*This project has been created as part of the 42 curriculum by malnaam, ahobeida.*

# push_swap

## Description

**push_swap** is a sorting project written in C. The program receives a list of
unique integers and must print, on the standard output, the shortest possible
list of instructions that sorts them in ascending order, using only two stacks
(**A** and **B**) and a fixed set of operations.

At the beginning, all the numbers are in stack **A** (the first argument is the
top of the stack) and stack **B** is empty. At the end, stack **A** must contain
all the numbers sorted, with the smallest on top, and stack **B** must be empty.

### Allowed operations

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` | Swap the first two elements of stack A / B. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Take the top element of B and put it on top of A. |
| `pb` | Take the top element of A and put it on top of B. |
| `ra` / `rb` | Rotate the stack up: the first element becomes the last. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` / `rrb` | Reverse rotate the stack: the last element becomes the first. |
| `rrr` | `rra` and `rrb` at the same time. |

All operations do nothing (and print nothing) when they cannot be applied, for
example when a stack has fewer than two elements for a swap or a rotation.

### Design overview

- The stacks are implemented as **singly linked lists** (`t_node`), each node
  storing its `value`, its `index` and a pointer to the next node.
- Before sorting, every value is replaced by its **index** (its rank in the
  sorted list, from `0` to `n - 1`). The algorithms work on indexes, so negative
  numbers and large gaps between values do not matter.
- The program supports **four sorting strategies** and chooses one depending on
  the size of the input and on how disordered it is (see [Algorithms](#algorithms)).
- Only `write`, `malloc` and `free` are used. No external library (including
  libft) is linked: the helper functions (`ft_split`, `ft_atoi`, `ft_strcmp`, ...)
  are implemented inside the project.

## Instructions

### Compilation

```bash
make        # build the push_swap executable
make clean  # remove the object files
make fclean # remove the object files and the executable
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`, and `make` does not
relink when nothing has changed.

### Usage

```bash
./push_swap [flags] <numbers>
```

The numbers can be given as separate arguments, as a single quoted string, or
both:

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap "5 -2" 8 +3 0
```

### Flags

Flags must be placed **before** the numbers. At most one strategy flag can be
used, and a flag cannot be repeated.

| Flag | Description |
|------|-------------|
| `--simple` | Force the simple strategy, `O(n²)`. |
| `--medium` | Force the medium strategy, `O(n√n)`. |
| `--complex` | Force the complex strategy, `O(n log n)`. |
| `--adaptive` | Choose the strategy automatically from the disorder (default). |
| `--bench` | Print a benchmark report on the **standard error** after sorting. |

`--bench` can be combined with one strategy flag, in any order:

```bash
./push_swap --bench --complex 4 -1 3 0 2 5
./push_swap --medium --bench 4 -1 3 0 2 5
```

> If the stack contains 5 numbers or fewer, the simple strategy is always used,
> whatever the flag.

### Behaviour and error handling

| Situation | Result |
|-----------|--------|
| No arguments | Nothing is displayed. |
| Stack already sorted | Nothing is displayed. |
| Non-numeric argument, number outside the `int` range, duplicate number, invalid or repeated flag, flag placed after a number | `Error` followed by a newline, written on the **standard error**, exit status `1`. |

### Examples

```bash
$ ./push_swap 3 1 2
ra
pb
pb
pb
pa
pa
pa

$ ./push_swap 2 1 3 a
Error
```

Count the operations:

```bash
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

If you have the 42 checker, you can verify the result:

```bash
./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

### Disorder metric

Before choosing a strategy, the program measures how disordered the input is:

```
disorder = inversions / (n * (n - 1) / 2)
```

An **inversion** is a pair of elements where the bigger one appears before the
smaller one. The result goes from `0` (already sorted) to `1` (completely
reversed).

### Strategy selection (`--adaptive`)

| Stack size / disorder | Strategy |
|-----------------------|----------|
| 5 numbers or fewer | Simple |
| `disorder < 0.2` | Simple |
| `0.2 <= disorder < 0.5` | Medium |
| `disorder >= 0.5` | Complex |

A forced flag (`--simple`, `--medium`, `--complex`) overrides this choice for
inputs of more than 5 numbers.

### Simple: selection sort, `O(n²)`

While stack A is not empty, find the smallest value, bring it to the top of A
with the shortest rotation (`ra` or `rra`, depending on which side it is closer
to), then push it to B. When A is empty, push everything back to A with `pa`.
Because the smallest values are pushed first, B ends up sorted in descending
order from the bottom, and the pushes back produce an ascending stack A.

*Why we use it:* it is trivial, correct, and efficient enough when the input is
small or almost sorted.

### Medium: chunk / sliding window, `O(n√n)`

1. A window of indexes is defined: `range = ceil(√n) * 1.4`.
2. Stack A is scanned from the top. If the index of the top element is inside
   the window, it is pushed to B, and the window grows by one. Elements that are
   small compared to the window are rotated to the bottom of B (`rb`), so B
   stays roughly split between small values (bottom) and large ones (top).
   Elements outside the window are rotated in A (`ra`).
3. When A is empty, the biggest index of B is brought to the top using `rb` or
   `rrb` (whichever is shorter) and pushed back with `pa`, until B is empty.
   Since we always pull the maximum, A is built in ascending order.

*Why we use it:* it needs far fewer operations than the simple strategy on
medium or large inputs, without the fixed cost of the radix sort.

### Complex: radix sort (LSD), `O(n log n)`

The sort works on the **binary representation of the indexes**, one bit at a
time, from the least significant bit to the most significant one. The number of
passes is the number of bits needed to write `n - 1`.

For each bit, the `n` elements of A are processed once:

- bit equal to `1` → `ra` (the element stays in A);
- bit equal to `0` → `pb` (the element goes to B);

then all the elements of B are pushed back to A with `pa`. The two inversions
(`pb` then `pa`) keep the relative order of the elements, which makes every pass
**stable**, and after the last bit the stack is sorted.

*Why we use it:* its number of operations does not depend on the initial order,
so it is predictable, and it scales well for large inputs.

### Benchmark mode (`--bench`)

With `--bench`, a report is printed on the **standard error** (so the list of
operations on the standard output is not polluted):

```
[bench] disorder: 60.71%
[bench] strategy: Medium / O(n√n)
[bench] total_ops: 31
[bench] sa: 0 sb: 0 ss: 0 pa: 8 pb: 8
[bench] ra: 2 rb: 9 rr: 0 rra: 0 rrb: 4 rrr: 0
```

The counters are stored in a static structure (`t_stats`) updated by every
operation through `record_op`.

### Measured performance

Average number of operations over 15 random permutations per case (every result
was checked to be correctly sorted):

| Numbers | `--simple` | `--medium` | `--complex` | `--adaptive` |
|---------|-----------:|-----------:|------------:|-------------:|
| 100 | ~1480 | ~581 | 1084 | ~913 |
| 500 | ~32500 | ~5076 | 6784 | ~6208 |

On random inputs the disorder is close to 50%, so `--adaptive` alternates
between the medium and the complex strategy.

## Project structure

```
.
├── Makefile
├── push_swap.h              # structures, enums and prototypes
├── main.c                   # entry point and program flow
├── ft_Execution.c           # dispatches to the chosen algorithm
├── Stack_building.c         # node creation, stack A building, index computation
├── free.c                   # memory release
├── Validity/                # parsing, validation and strategy selection
│   ├── split_input.c        # splits all the arguments into words
│   ├── split_words.c        # custom ft_split
│   ├── checkers.c           # flags and numbers validation
│   ├── duplicates.c         # duplicate detection
│   ├── utils.c              # ft_strcmp, ft_atoi, is_valid_int
│   └── determine_the_way.c  # disorder metric and strategy choice
├── Move/                    # the 11 operations
├── algorithm/               # simple.c, medium.c, complex.c and helpers
└── bench/                   # statistics recording and report printing
```

## Resources

### References

- Selection sort: <https://en.wikipedia.org/wiki/Selection_sort>
- Radix sort: <https://en.wikipedia.org/wiki/Radix_sort>
- Inversions (used for the disorder metric): <https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)>
- Time complexity and Big-O notation: <https://en.wikipedia.org/wiki/Time_complexity>
- Linked lists: <https://en.wikipedia.org/wiki/Linked_list>
- Manual pages: `man 2 write`, `man 3 malloc`, `man 3 free`
- The push_swap subject of the 42 curriculum

### Use of AI

AI (Claude) was used as a learning and review tool: to explain parts of the
code step by step, to help understand the algorithms and their complexity, to
review the flag-parsing logic and the Makefile, and to help draft this README.
The code itself was written, tested and is understood by the authors.

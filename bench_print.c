#include "push_swap.h"

static void	put_str(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(2, s, len);
}

static void	put_nbr(int n)
{
	char	c;

	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + (n % 10);
	write(2, &c, 1);
}

static void	put_line(char *name, int n)
{
	put_str("[bench] ");
	put_str(name);
	put_str(": ");
	put_nbr(n);
	put_str("\n");
}

void	print_bench(double dis, int choice, int adaptive)
{
	t_stats	*s;
	int		p;

	s = get_stats();
	p = (int)(dis * 10000 + 0.5);
	put_str("[bench] disorder: ");
	put_nbr(p / 100);
	put_str(".");
	if (p % 100 < 10)
		put_str("0");
	put_nbr(p % 100);
	put_str("%\n[bench] strategy: ");
	if (adaptive)
		put_str("Adaptive / ");
	if (choice == 1)
		put_str("Simple / O(n^2)\n");
	else if (choice == 2)
		put_str("Medium / O(n√n)\n");
	else
		put_str("Complex / O(n log n)\n");
	put_line("total_ops", s->total);
}
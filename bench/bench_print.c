/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:55:19 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 08:55:21 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	put_disorder(double dis)
{
	int	p;

	p = (int)(dis * 10000 + 0.5);
	put_str("[bench] disorder: ");
	put_nbr(p / 100);
	put_str(".");
	if (p % 100 < 10)
		put_str("0");
	put_nbr(p % 100);
	put_str("%\n");
}

static void	put_strategy(int choice, int adaptive)
{
	put_str("[bench] strategy: ");
	if (adaptive)
		put_str("Adaptive / ");
	else if (choice == 1)
		put_str("Simple / ");
	else if (choice == 2)
		put_str("Medium / ");
	else
		put_str("Complex / ");
	if (choice == 1)
		put_str("O(n^2)\n");
	else if (choice == 2)
		put_str("O(n√n)\n");
	else
		put_str("O(n log n)\n");
}

static void	put_kv(char *name, int n)
{
	put_str(" ");
	put_str(name);
	put_str(": ");
	put_nbr(n);
}

static void	put_ops(t_stats *s)
{
	put_str("[bench]");
	put_kv("sa", s->count[OP_SA]);
	put_kv("sb", s->count[OP_SB]);
	put_kv("ss", s->count[OP_SS]);
	put_kv("pa", s->count[OP_PA]);
	put_kv("pb", s->count[OP_PB]);
	put_str("\n[bench]");
	put_kv("ra", s->count[OP_RA]);
	put_kv("rb", s->count[OP_RB]);
	put_kv("rr", s->count[OP_RR]);
	put_kv("rra", s->count[OP_RRA]);
	put_kv("rrb", s->count[OP_RRB]);
	put_kv("rrr", s->count[OP_RRR]);
	put_str("\n");
}

void	print_bench(double dis, int choice, int adaptive)
{
	t_stats	*s;

	s = get_stats();
	put_disorder(dis);
	put_strategy(choice, adaptive);
	put_str("[bench] total_ops: ");
	put_nbr(s->total);
	put_str("\n");
	put_ops(s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:55:45 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 08:55:46 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stats	*get_stats(void)
{
	static t_stats	stats;

	return (&stats);
}

void	record_op(int op)
{
	t_stats	*s;

	s = get_stats();
	s->count[op]++;
	s->total++;
}

int	is_bench(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}

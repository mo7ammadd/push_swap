/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:00:00 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/28 07:49:25 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *s)
{
	t_node	*tmp;

	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
}

void	free_split(char **split, int new_argc)
{
	int		i;

	i = 1;
	while (i < new_argc)
		free(split[i++]);
	free(split);
}

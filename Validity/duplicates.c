/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:59:57 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/26 08:59:58 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	dublicat_numbers(char **argv, int index, int start)
{
	int	j;

	j = start;
	while (j < index)
	{
		if (ft_atoi(argv[j]) == ft_atoi(argv[index]))
			return (0);
		j++;
	}
	return (1);
}

int	dublicat_flags(char **argv, char *target, int index)
{
	int	j;

	j = 1;
	while (j < index)
	{
		if (ft_strcmp(argv[j], target) == 0)
			return (0);
		j++;
	}
	return (1);
}

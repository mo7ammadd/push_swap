/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malnaam <malnaam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:55:36 by malnaam           #+#    #+#             */
/*   Updated: 2026/10/26 08:55:38 by malnaam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(2, s, len);
}

void	put_nbr(int n)
{
	char c;

	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + (n % 10);
	write(2, &c, 1);
}

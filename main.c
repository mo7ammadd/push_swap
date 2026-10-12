/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:11:55 by ahobeida          #+#    #+#             */
/*   Updated: 2026/10/12 10:12:58 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	print_stack(t_node *s)
{
	int	i;

	i = 0;
	while (s)
	{
		printf("[%d] value = %d | index = %d\n", i, s->value, s->index);
		s = s->next;
		i++;
	}
	if (i == 0)
		printf("(stack empty)\n");
}

static void	free_stack(t_node *s)
{
	t_node	*tmp;

	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
}

static void	free_split(char **split, int new_argc)
{
	int	i;

	i = 1; /* split[0] is argv[0], don't free it */
	while (i < new_argc)
		free(split[i++]);
	free(split);
}

int	main(int argc, char **argv)
{
	char	**split;
	int		new_argc;
	int		start;
	t_node	*a;
	t_node	*b;

	if (!argc_checker(argc))
		return (0);
	split = split_input(argc, argv, &new_argc);
	if (!split || !number_checker(split, new_argc))
	{
		write(2, "Error\n", 6);
		if (split)
			free_split(split, new_argc);
		return (1);
	}
	// when i call the function determine_way
	// i should create a t_node and i should
	// give to it the value which returned from function build_stack
	b = NULL;
	start = flags_checker(split, new_argc);
	printf("flags count = %d, numbers start at index %d\n", start - 1, start);
	a = build_stack_a(split, new_argc, start);
	print_stack(a);
	free_stack(a);
	free_split(split, new_argc);
	return (0);
}

#include "push_swap.h"

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

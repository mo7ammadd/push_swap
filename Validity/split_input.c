#include <stdlib.h>
#include "push_swap.h"

static int	count_total(int argc, char **argv)
{
	char	**temp;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i]);
		if (!temp)
			return (-1);
		j = 0;
		while (temp[j])
		{
			total++;
			free(temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
	return (total);
}

static int	fill_result(char **result, int argc, char **argv)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i]);
		if (!temp)
			return (0);
		j = 0;
		while (temp[j])
		{
			result[k] = temp[j];
			k++;
			j++;
		}
		free(temp);
		i++;
	}
	result[k] = NULL;
	return (1);
}

char	**split_input(int argc, char **argv, int *new_argc)
{
	char	**result;
	int		total;

	total = count_total(argc, argv);
	if (total < 0)
		return (NULL);
	result = malloc(sizeof(char *) * (total + 2));
	if (!result)
		return (NULL);
	result[0] = argv[0];
	if (!fill_result(result, argc, argv))
		return (NULL);
	*new_argc = total + 1;
	return (result);
}

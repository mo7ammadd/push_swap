#include "push_swap.h"

int	is_flag(char *s)
{
	return (ft_strcmp(s, "--bench") == 0 || ft_strcmp(s, "--adaptive") == 0
		|| ft_strcmp(s, "--simple") == 0 || ft_strcmp(s, "--complex") == 0
		|| ft_strcmp(s, "--medium") == 0);
}

static int	count_flags(char **argv, int argc, int *bench)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (i < argc && is_flag(argv[i]))
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = 1;
		if (dublicat_flags(argv, argv[i], i) == 0)
			return (-1);
		counter++;
		i++;
	}
	return (counter);
}

int	flags_checker(char **argv, int argc)
{
	int	counter;
	int	bench;

	bench = 0;
	counter = count_flags(argv, argc, &bench);
	if (counter < 0)
		return (-1);
	if (counter == 2)
	{
		if (!bench)
			return (-1);
		return (3);
	}
	if (counter > 2)
		return (-1);
	return (counter + 1);
}

int	number_checker(char **argv, int argc)
{
	int	i;
	int	start;

	start = flags_checker(argv, argc);
	if (start < 0)
		return (0);
	i = start;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			return (0);
		if (!is_valid_int(argv[i]) || !dublicat_numbers(argv, i, start))
			return (0);
		i++;
	}
	return (1);
}

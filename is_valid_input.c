#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * Checks if a string is a valid integer.
 * Returns 1 if valid, 0 if invalid (contains characters, empty sign, or overflows).
 */
int is_valid_int(const char *str)
{
	int i = 0;
	long long res = 0;
	int sign = 1;
	int len = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0');
		len++;
		if (len > 11 || (sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int ft_atoi(const char *nptr)
{
	long long res = 0;
	int i = 0;
	int sign = 1;

	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}

int duplicate_numbers(char **argv, int index, int start)
{
	int j;

	j = start;
	//if (ft_atoi(argv[index]))
	while (j < index)
	{
		if (ft_atoi(argv[j]) == ft_atoi(argv[index]))
			return (0);
		j++;
	}
	return (1);
}

int duplicate_flags(char **argv, char *target, int index)
{
	int j = 0;
	while (j < index)
	{
		if (ft_strcmp(argv[j], target) == 0)
			return (0);
		j++;
	}
	return (1);
}

// هسا انا مشيت لوب طالما انه بلاقي فلاغات و بعدهم طبعا
//هسا بعمل فنكشن للاقرقام و ببلش من عند اندكس يساوي عدد الفلاقات
// واذا لقيت فلاق بطريقي برجع صفر 
// flags_checkerطبعا انا ب فنكشن الارقام قبل ما ابلش باللوب بحط شرط انه اذا فنكشن 
// رجع واحد بفوت على فنكشن الارقام اما اذا رجع صفر ف فش داعي افوت عليه من الاساس مشان اقلل وقت كومبايليشن
// طبعا لما انا اعمل كل فنكزم اراعي ترتيبهن جوا جمله ال اف ستيتمينت اللي بالبدايشنات الايررور لا
// يعني هنه لازم كلهن يرجعن واحد ف الترتيب مهم و لازم احط الفنكشنات اللي وقت الكومبايليشن تاعهم قليل بالبداية
// مشان اذا فنكشن ما تحقق و فش داعي يروح عالباقي و يعمل عمليات ما الها داعي و بتزيد و بتبطئ الكود
//flags_checker  هسا فش داعي اخط جوا ال اف تاعيت التحقق من كلشي فنكشن 
//  number_checker لانه انا بستدعيه جوا فنكشن 
int flags_checker(char **argv, int argc)
{
	int i = 0; /* تم التعديل لتبدأ من 0 عشان المصفوفة الموحدة */
	int counter = 0;
	int bench = 0;

	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0 || ft_strcmp(argv[i], "--adaptive") == 0 || 
			ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--complex") == 0 || 
			ft_strcmp(argv[i], "--medium") == 0)
		{
			if (ft_strcmp(argv[i], "--bench") == 0)
				bench = 1;
			if (duplicate_flags(argv, argv[i], i) == 0)
				return (-1);
			counter++;
		}
		else
			break;
		i++;
	}
	if (counter == 2)
	{
		if (!bench)
			return (-1);
		else
			return (2);
	}
	if (counter > 2)
		return (-1);

	return (counter);
}

int number_checker(char **argv, int argc)
{
	int i;
	int start;
	
	start = flags_checker(argv, argc);
	if (start < 0)
		return (0);
	if (start == 0)
		start = 1;
		
	i = start;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0 || ft_strcmp(argv[i], "--adaptive") == 0 || 
			ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--complex") == 0 || 
			ft_strcmp(argv[i], "--medium") == 0)
			return (0);
			 
		if (!is_valid_int(argv[i]) || !duplicate_numbers(argv, i, start))
			return (0);
			 
		i++;
	}
	return (1);
}


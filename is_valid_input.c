#include <stdio.h>
#include <limits.h>
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * Checks if a string is a valid integer.
 * Returns 1 if valid, 0 if invalid (contains characters, empty sign).
 */
int	is_valid_int(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
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
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}


int	ft_atoi(const char *nptr)
{
	long long	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
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

int argc_checker(int argc)
{
    if (argc <= 1)
    return (0);
    return (1);
}

int dublicat_numbers(char **argv, int index)
{
    int    j;

    j = 1;
    if (ft_atoi(argv[index]))
    while (j < index)
    {
        if (ft_atoi(argv[j] == ft_atoi(argv[index])))
        return (0);
        j++;
    }
    return (1);
}

int dublicat_flags(char **argv, char *target, int index)
{
    int j;

    j = 0;
    while (j < index)
    {
        if (ft_strcmp(argv[j], "--bench") == 0)
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
    int i;
    int counter;
    int    ans;
    int bench;

    i = 0;
    counter = 0;
    bench = 0;
    while (i < argc)
    {
        if (argv[i] == "--bench" || argv[i] == "--adaptive" || argv[i] == "--simple" || argv[i] == "--complex" || argv[i] == "--medium")
        {
            if (argv[i] == "--bench")
            bench = 1;
            ans = dublicat_flags(argv, argv[i], i);
            if (ans == 0)
            {
                return (0);
            }
            counter++;
        }
        else
        break ;
        i++;
    }
    if (counter == 2)
    {
        if (!bench)
        return (0);
    }
    if (counter > 2)
    {
        return (0);
    }
    return (counter);
}

int number_checker(char **argv, int argc)
{
    int i;
    int counter;
    if (flags_checker(argv, argc))
    i = flags_checker(argv, argc);
    else
    return (0);
    counter = 0;
    while (i < argc)
    {
         if (argv[i] == "--bench" || argv[i] == "--adaptive" || argv[i] == "--simple" || argv[i] == "--complex" || argv[i] == "--medium")
         return (0);
         if ( !is_valid_int(argv[i]) || !dublicat_numbers(argv, i))
         return (0);
         counter++;
         i++;
    }
    return (counter);
}

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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
 * Returns 1 if valid, 0 if invalid (contains characters, empty sign, or overflows).
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

int dublicat_numbers(char **argv, int index, int start)
{
    int    j;

    j = start;
    //if (ft_atoi(argv[index]))
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
        if (ft_strcmp(argv[j], target) == 0)
        return (0);
        j++;
    }
    return (1);
}

int word_count(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t'
            || str[i] == '\n' || str[i] == '\v'
            || str[i] == '\f' || str[i] == '\r')
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && str[i] != ' ' && str[i] != '\t'
                && str[i] != '\n' && str[i] != '\v'
                && str[i] != '\f' && str[i] != '\r')
                i++;
        }
    }
    return (count);
}

/* NEW: duplicate one word */
char *word_dup(char *str, int *i)
{
    int     start;
    int     len;
    char    *word;
    int     j;

    while (str[*i] == ' ' || str[*i] == '\t'
        || str[*i] == '\n' || str[*i] == '\v'
        || str[*i] == '\f' || str[*i] == '\r')
        (*i)++;
    start = *i;
    while (str[*i] && str[*i] != ' ' && str[*i] != '\t'
        && str[*i] != '\n' && str[*i] != '\v'
        && str[*i] != '\f' && str[*i] != '\r')
        (*i)++;
    len = *i - start;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    j = 0;
    while (j < len)
    {
        word[j] = str[start + j];
        j++;
    }
    word[j] = '\0';
    return (word);
}

/* NEW: split one argument */
char **ft_split(char *str)
{
    char    **result;
    int     words;
    int     i;
    int     j;

    words = word_count(str);
    result = malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (j < words)
    {
        result[j] = word_dup(str, &i);
        if (!result[j])
            return (NULL);
        j++;
    }
    result[j] = NULL;
    return (result);
}

char **split_input(int argc, char **argv, int *new_argc)
{
    char    **temp;
    char    **result;
    int     total;
    int     i;
    int     j;
    int     k;

    total = 0;
    i = 1;
    while (i < argc)
    {
        temp = ft_split(argv[i]);
        if (!temp)
            return (NULL);
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
    result = malloc(sizeof(char *) * (total + 1));
    if (!result)
        return (NULL);
    i = 1;
    k = 0;
    while (i < argc)
    {
        temp = ft_split(argv[i]);
        if (!temp)
            return (NULL);
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
    *new_argc = total;
    return (result);
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

    i = 1;
    counter = 0;
    bench = 0;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--bench") == 0 || ft_strcmp(argv[i], "--adaptive") == 0 || ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--complex") == 0 || ft_strcmp(argv[i], "--medium") == 0)
        {
            if ( ft_strcmp(argv[i], "--bench") == 0)
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
		else
			return(2);
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
    //int counter;
    int start;
    //if (flags_checker(argv, argc))
    start = flags_checker(argv, argc);
    if (start < 0)
        return (0);
        i = start;
    //counter = 0;
    while (i < argc)
    {
         if (ft_strcmp(argv[i], "--bench") == 0 || ft_strcmp(argv[i], "--adaptive") == 0 || ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--complex") == 0 || ft_strcmp(argv[i], "--medium") == 0)
         return (0);
         if ( !is_valid_int(argv[i]) || !dublicat_numbers(argv, i, start))
         return (0);
         //counter++;
         i++;
    }
    return (1);
}

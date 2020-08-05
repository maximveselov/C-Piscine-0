#include "bsq.h"

int		my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return(1);
	else
		return(0);
}

int		ft_atoi(char *str)
{
	int sign;
	int meaning;

	sign = 1;
	meaning = 0;
	while(my_isspace(*str))
		str++;
	while(*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while(*str >= '0' && *str<= '9')
	{
		meaning *= 10;
		meaning += *str - '0';
		str++;
	}
	return (meaning);
}

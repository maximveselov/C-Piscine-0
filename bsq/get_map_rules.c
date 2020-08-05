#include "bsq.h"

char	get_empty_c(char **c)
{
	int i;
    i = ft_strlen(c[0]);
    return c[0][i-3];
}

char	get_obstacle_c(char **c)
{
	int i;
    i = ft_strlen(c[0]);
    return c[0][i-2];
}

char	get_full_c(char **c)
{
    int i;
    i = ft_strlen(c[0]);
	return c[0][i-1];
}

int		get_line_n(char *optional, char empty, char obstacle, char full)
{
	return (read_option_str(optional, &empty, &obstacle, &full));
}

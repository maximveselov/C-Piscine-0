#include "bsq.h"

int		err_catcher(char **file)
{
	char	obs;
	char	emp;
	char	full;

	obs = get_obstacle_c(file);
	emp = get_empty_c(file);
	full = get_full_c(file);
	if (err_option_str(file[0]) < 0)
	   return (0);
	if (get_line_n(file[0], emp, obs, full) != string_count_from_buffer(file))
		return (0);
	return (1);
}

int		str_compare(char **file)
{
	int		i;

	i = 1;
	while (i < string_count_from_buffer(file))
	{
		if (ft_strlen(file[i]) != ft_strlen(file[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

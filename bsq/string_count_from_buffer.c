#include "bsq.h"

int		string_count_from_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (*buffer)
	{
		i++;
		buffer++;
	}
	return (i - 1);
}

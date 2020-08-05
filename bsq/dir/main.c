#include "bsq.h"

int		main(int argc, char **argv)
{
	char	**input;

	if (argc == 1)
	{
		input = parse_input();
		construct_from_input(input);
		return (0);
	}
	else
	{
		int 	i = 1;
		while (i < argc)
		{
			construct_matrix(argv[i]);
			i++;
		}
	}
	return (0);
}

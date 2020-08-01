#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int		check_int(char *num)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!check_int(argv[1]))
		{
			ft_putstr("Error\n"); // checking for a valid positive int
		// only convert argv[1]
			return (0);
		}
		else
			// print num
	}
	else if (argc == 3)
	{
		if !(check_int(argv[2]))  // add a dictionary check later
		{
			ft_putstr("Error\n");
			return (0);
		}
		else
		// argv[1] = dictionary, argv[2] = value to convert
		// check for dictionary
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
}

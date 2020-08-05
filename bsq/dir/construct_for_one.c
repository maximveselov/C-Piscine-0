void	construct_for_line(char **tab)
{
	int		i;
	char	obs;
	char	emp;
	char	full;

	obs = fetch_obstcl_char(tab);
	emp = fetch_empt_char(tab);
	full = fetch_full_char(tab);
	i = 0;
	while (tab[1][i] != '\0')
	{
		if (tab[1][i] == emp)
			tab[1][i] = full;
		i++;
	}
}

# include "../../includes/cube3d.h"

int	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	print_char_tab(char **tab)
{
	int	i;

	i = 0;
	printf("__________________________________\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("__________________________________\n\n");
	return (0);
}

int	ft_strlen_cb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
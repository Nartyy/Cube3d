#include "../../includes/cube3d.h"

size_t	ft_wcount_cb(char const *s, char c)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	if (!s)
		return (-1);
	if (s[i] == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			r++;
			i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c && s[i] == 0 && i > 0)
		r++;
	return (r);
}

char	*ft_writetab_cb(char *p, char c, char **p2)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (p[i] != c && p[i])
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (0);
	line[0] = 0;
	while (j < i)
	{
		line[j] = p[j];
		j++;
	}
	line[i] = 0;
	if (p[i] == c && p[i + 1])
		i++;
	*p2 = &p[i];
	return (line);
}

void	ft_freetab_cb(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char	**ft_split_cb(char const *s, char c)
{
	int		i;
	char	*p;
	char	**tab;
	int		ct;

	p = NULL;
	ct = ft_wcount_cb(s, c);
	tab = malloc(sizeof(char *) * (ct + 1));
	if (!tab || (ct + 1) == 0)
		return (NULL);
	i = -1;
	p = (char *)s;
	while (++i < ct)
	{
		tab[i] = ft_writetab_cb(p, c, &p);
		if (tab[i] == NULL)
		{
			ft_freetab_cb(tab, i);
			break ;
		}
	}
	tab[i] = NULL;
	return (tab);
}

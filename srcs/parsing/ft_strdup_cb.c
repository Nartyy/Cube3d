#include "../../includes/cube3d.h"

char	*ft_strdup_cb(const char *s)
{
	size_t	i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

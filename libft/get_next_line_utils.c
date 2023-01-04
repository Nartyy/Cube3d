/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:29:13 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/23 19:40:20 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

//Fonction use pour reduire le stay
char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	st;

	st = start;
	if (!s)
		return (NULL);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = 0;
	return (p);
}

//Fonction pour reduire le stay apres l'ecriture
char	*ft_fix_stay_gnl(char **stay, char *line)
{
	size_t	i;
	char	*new_stay;

	i = 0;
	if ((!line))
	{
		free(stay[0]);
		return (NULL);
	}
	if (!*stay)
		return (NULL);
	while (stay[0][i] && stay[0][i] != '\n')
		i++;
	if (stay[0][i] == '\n')
	{
		i++;
		new_stay = ft_substr_gnl(*stay, i, (ft_strlen(*stay) - i));
		free(*stay);
		return (new_stay);
	}
	return (NULL);
}

int	ft_checkforbreak_gnl(char *buf, int lenrd)
{
	int	i;

	i = 0;
	while (i < lenrd)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_buflen_gnl(char *buf, int lenrd, char *stay)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((int)i < lenrd)
	{
		if (!buf[i])
			break ;
		i++;
	}
	j = ft_strlen_gnl(stay);
	if ((i + j) > 0)
		i++;
	return (i + j);
}

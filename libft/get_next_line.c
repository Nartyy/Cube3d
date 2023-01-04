/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:29:10 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/23 19:40:31 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_central_gnl(fd);
	return (line);
}

char	*ft_central_gnl(int fd)
{
	char static	*stay;
	char		buf[BUFFER_SIZE];
	int			lenrd;
	char		*line;

	lenrd = read(fd, buf, BUFFER_SIZE);
	if (!buf[0] && !stay)
		return (NULL);
	while (lenrd > 0)
	{
		stay = ft_read_gnl((size_t)lenrd, &stay, buf);
		if (ft_checkforbreak_gnl(buf, lenrd) == 1)
			break ;
		lenrd = read(fd, buf, BUFFER_SIZE);
	}
	if (lenrd == -1)
		return (failret_gnl(stay));
	if (!stay && lenrd < 0)
		return (NULL);
	line = ft_write_gnl(&stay);
	stay = ft_fix_stay_gnl(&stay, line);
	return (line);
}

char	*ft_read_gnl(int lenrd, char **stay, char *buf)
{
	size_t	len;
	char	*new_stay;
	int		i;
	int		j;

	if (!stay && lenrd == 0)
		return (NULL);
	len = ft_buflen_gnl(buf, lenrd, *stay);
	new_stay = malloc(sizeof(char) * (len));
	if (!new_stay)
		return (NULL);
	i = -1;
	j = -1;
	if (*stay)
	{
		while (stay[0][++i] && *stay != NULL)
			new_stay[i] = stay[0][i];
	}
	else
		i++;
	while (++j < lenrd)
		new_stay[i + j] = buf[j];
	new_stay[i + j] = 0;
	free(*stay);
	return (new_stay);
}

char	*ft_write_gnl(char **stay)
{
	int	i;

	i = -1;
	if (!stay[0])
		return (NULL);
	if (!stay[0][0])
		return (NULL);
	while (stay[0][++i])
	{
		if (stay[0][i] == '\n')
		{
			i++;
			return (ft_substr_gnl(stay[0], 0, i));
		}
	}
	return (stay[0]);
}

char	*failret_gnl(char *stay)
{
	if (stay)
		stay[0] = 0;
	return (NULL);
}

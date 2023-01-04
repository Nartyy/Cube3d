/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:28:07 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/10 08:59:45 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = (char *) s;
	i = 0;
	while (c >= 256)
		c -= 256;
	while (p[i])
	{
		if (p[i] == c)
		{
			p = &p[i];
			return (p);
		}
		i++;
	}
	if (c == 0)
	{
		p = &p[i];
		return (p);
	}
	return (NULL);
}

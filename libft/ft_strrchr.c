/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:31:10 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/10 09:00:07 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	while (c >= 256)
		c -= 256;
	while (s[i])
	{
		if (s[i] == c)
			p = (char *) &s[i];
		i++;
	}
	if (c == 0)
		p = (char *) &s[i];
	return (p);
}

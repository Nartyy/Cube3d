/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:53:54 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/08 20:32:43 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	r;
	char	*d;
	char	*s;

	i = -1;
	d = (char *) dst;
	s = (char *) src;
	r = ft_strlen(s);
	if (!src)
		return (0);
	if (!dst || size < 1)
		return (r);
	while (++i < (size - 1) && src[i])
		d[i] = s[i];
	d[i] = 0;
	return (r);
}

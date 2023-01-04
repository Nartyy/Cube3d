/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:26:50 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/08 17:06:10 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = -1;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d < s)
	{
		while (++i < n)
			*(d++) = *(s++);
	}
	else if (d > s)
	{
		d = &d[n - 1];
		s = &s[n - 1];
		while (++i < n)
			*(d--) = *(s--);
	}
	return (dest);
}

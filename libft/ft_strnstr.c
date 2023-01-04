/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:58:08 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/08 18:18:29 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*r;

	i = -1;
	if (*little == 0)
		return ((char *) big);
	while (++i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] == big[i + j] && (i + j) < len)
			{
				if (little[j + 1] == 0)
				{
					r = (char *) &big[i];
					return (r);
				}
				j++;
			}
		}
	}
	return (NULL);
}

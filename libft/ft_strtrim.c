/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:13:04 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/10 13:30:28 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	strlen2(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (s1[++i])
	{
		if (ft_memchr(set, s1[i], ft_strlen(set)))
			j++;
		else
		{
			while (s1[i])
				i++;
			while (--i > 0)
			{
				if (ft_memchr(set, s1[i], ft_strlen(set)))
					j++;
				else
					return (ft_strlen(s1) - j);
			}
		}
	}
	return (ft_strlen(s1) - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	dup = malloc(strlen2(s1, set) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (ft_memchr(set, s1[i], ft_strlen(set)))
		i++;
	ft_memcpy(dup, &s1[i], strlen2(s1, set));
	dup[strlen2(s1, set)] = '\0';
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:41:22 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/09 15:30:05 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_itoa_sizen(int *n, size_t *neg, size_t nb)
{
	size_t	i;

	i = 0;
	if (*n < 0)
	{
		*neg = 1;
		*n *= -1;
	}
	if (*n == 0)
		return (1);
	nb = *n;
	while (nb >= 1)
	{
		i++;
		nb /= 10;
	}
	if (*neg == 1)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	neg;
	char	*p;

	i = 0;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_itoa_sizen(&n, &neg, 0);
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	p[i] = 0;
	while (i >= 1)
	{
		p[i - 1] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	if (neg)
		p[0] = '-';
	return (p);
}

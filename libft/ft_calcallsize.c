/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcallsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:20 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/12 14:37:04 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calcstr_ptf(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (6);
	while (s[len])
		len++;
	return (len);
}

int	calcnbr_ptf(long int nb)
{
	long int	ref;
	int			len;

	ref = 10;
	len = 1;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (ref <= nb)
	{
		ref *= 10;
		len++;
	}
	return (len);
}

int	calcp_ptf(unsigned long long n)
{
	int				len;
	size_t			i;
	unsigned long	fnb;

	len = 0;
	i = 0;
	if (n == 0)
		return (3);
	if (n < 0)
		fnb = 4294967296 + n;
	else
		fnb = n;
	while (fnb > 1)
	{
		len++;
		fnb /= 16;
	}
	if (fnb == 1)
		len++;
	return (len + 2);
}

int	calcu_ptf(unsigned int nb)
{
	size_t	ref;
	int		len;

	ref = 10;
	len = 1;
	while (ref <= nb)
	{
		ref *= 10;
		len++;
	}
	return (len);
}

int	calcx_ptf(long n)
{
	int				len;
	size_t			i;
	unsigned long	fnb;

	len = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (n == 16)
		return (2);
	if (n < 0)
		fnb = 4294967296 + n;
	else
		fnb = n;
	while (fnb > 1)
	{
		len++;
		fnb /= 16;
	}
	if (fnb == 1)
		len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:46 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/11 18:26:02 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbru_size(unsigned int n)
{
	size_t	i;
	size_t	nb;

	nb = 10;
	i = 1;
	while (nb <= (size_t)n)
	{
		nb *= 10;
		i++;
	}
	return (i);
}

void	ft_ptnbru_write(unsigned int n)
{
	size_t	nb;
	char	c;
	size_t	size;
	size_t	i;

	nb = 0;
	size = ft_putnbru_size(n);
	i = 0;
	while (++i <= size)
	{
		nb *= 10;
		nb += n % 10;
		n /= 10;
	}
	i = 0;
	while (++i <= size)
	{
		c = (nb % 10) + 48;
		write(1, &c, 1);
		nb /= 10;
	}
}

void	ft_putnbru_ptf(unsigned int n)
{
	char	c;

	if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		c = '-';
		write(1, &c, 1);
	}
	ft_ptnbru_write(n);
}

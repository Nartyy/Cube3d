/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:50:47 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/12 15:08:14 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_base2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			if (base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base2_ptf(unsigned long long nbr, char *base)
{
	int		tbase;

	tbase = ft_calc_base2(base);
	if (tbase < 2)
		return ;
	if (nbr == 16)
	{
		write(1, "10", 2);
		return ;
	}
	if (nbr > (unsigned long long)tbase)
		ft_putnbr_base2_ptf(nbr / tbase, base);
	else if (tbase == 2 && nbr > 1)
		write(1, &base[1], 1);
	nbr = nbr % tbase;
	write(1, &base[nbr], 1);
}

void	ft_pnb2_ptf(unsigned long long nbr, char *base)
{
	ft_putstr("0x");
	ft_putnbr_base2_ptf(nbr, base);
}

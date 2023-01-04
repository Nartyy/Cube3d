/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:44:42 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/28 11:25:26 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_base(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int				tbase;
	unsigned int	fnb;

	tbase = ft_calc_base(base);
	if (tbase < 2)
		return ;
	if (nbr == 16 && tbase == 16)
	{
		write(1, "10", 2);
		return ;
	}
	if (nbr < 0)
		fnb = 4294967296 + nbr;
	else
		fnb = nbr;
	if (fnb > (unsigned int)tbase)
		ft_putnbr_base(fnb / tbase, base);
	else if (tbase == 2 && fnb > 1)
		write(1, &base[1], 1);
	fnb = fnb % tbase;
	write(1, &base[fnb], 1);
}

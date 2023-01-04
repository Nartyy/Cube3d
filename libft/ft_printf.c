/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:41:14 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/28 11:25:29 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_cs(int c, va_list lst)
{
	int	c2;

	if (c == 'c')
	{
		c2 = (int) va_arg(lst, int);
		return (1);
	}
	else if (c == 's')
		return (calcstr_ptf((char *) va_arg(lst, char *)));
	else if (c == 'p')
		return (calcp_ptf((long) va_arg(lst, long)));
	else if (c == 'd')
		return (calcnbr_ptf((long int) va_arg(lst, int)));
	else if (c == 'i')
		return (calcnbr_ptf((long int) va_arg(lst, int)));
	else if (c == 'u')
		return (calcu_ptf((unsigned int) va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (calcx_ptf((int) va_arg(lst, int)));
	else if (c == 'X')
		return (calcx_ptf((int) va_arg(lst, int)));
	else if (c == '%')
		return (1);
	(void)c;
	return (2);
}

int	ft_printf_size(va_list lst, char *in)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (in[i])
	{
		if (in[i] == '%')
		{
			i++;
			len += ft_printf_cs(in[i], lst);
		}
		else
			len++;
		i++;
	}
	va_end(lst);
	return (len);
}

void	ft_printf_checkchar(int c, va_list plist)
{
	if (c == 'c')
		ft_putchar((char) va_arg(plist, int));
	else if (c == 's')
		ft_putstr((char *) va_arg(plist, char *));
	else if (c == 'p')
		ft_pnb2_ptf((ULL) va_arg(plist, ULL), "0123456789abcdef");
	else if (c == 'd')
		ft_putnbr((int) va_arg(plist, int));
	else if (c == 'i')
		ft_putnbr((int) va_arg(plist, int));
	else if (c == 'u')
		ft_putnbru_ptf((unsigned int) va_arg(plist, unsigned int));
	else if (c == 'x')
		ft_putnbr_base((long) va_arg(plist, long), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base((long) va_arg(plist, long), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
	else
	{
		ft_putchar('%');
		ft_putchar(c);
	}
}

int	ft_printf(const char *in, ...)
{
	va_list		plist;
	va_list		r_size;
	size_t		i;

	i = 0;
	if (!in)
		return (0);
	va_start(plist, in);
	va_start(r_size, in);
	while (in[i])
	{
		if (in[i] == '%')
		{
			i++;
			ft_printf_checkchar(in[i], plist);
		}
		else
			ft_putchar(in[i]);
		i++;
	}
	va_end(plist);
	return (ft_printf_size(r_size, (char *)in));
}

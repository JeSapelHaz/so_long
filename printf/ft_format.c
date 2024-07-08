/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:54:57 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/08 16:14:34 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* cspdiuxX%
	c : char
	s : string
	p : pointeur
	d / i : decimal signe
	u : decimal non signe
	x : hexadecimal <abcdef>
	X : hexadecimal <ABCDEF>
	% : '%'
	*/
size_t	ft_format(va_list args, char c)
{
	size_t	result;

	result = 0;
	if (c == 'c')
		result = result + ft_putchar(va_arg(args, int));
	else if (c == 's')
		result = result + ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		result = result + ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		result = result + ft_putstr("0x") + ft_putnbr_base(va_arg(args,
					unsigned long), "0123456789abcdef");
	else if (c == 'u')
		result = result + ft_putnbr_base(va_arg(args, unsigned), "0123456789");
	else if (c == 'x')
		result = result + ft_putnbr_base(va_arg(args, unsigned),
				"0123456789abcdef");
	else if (c == 'X')
		result = result + ft_putnbr_base(va_arg(args, unsigned),
				"0123456789ABCDEF");
	else
		result = result + ft_putchar(c);
	return (result);
}

size_t	ft_putnbr(long int nbr)
{
	size_t	result;

	result = 0;
	if (nbr < 0)
	{
		result = result + ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		result = result + ft_putnbr(nbr / 10);
		result = result + ft_putnbr(nbr % 10);
	}
	else
		result = result + ft_putchar(nbr + 48);
	return (result);
}

size_t	ft_putnbr_base(unsigned long int nbr, const char *base)
{
	size_t	len_base;
	size_t	result;

	len_base = ft_strlen_3(base);
	result = 0;
	if (nbr < len_base)
		result = ft_putchar(base[nbr]);
	if (nbr >= len_base)
	{
		result = result + ft_putnbr_base(nbr / len_base, base);
		result = result + ft_putnbr_base(nbr % len_base, base);
	}
	return (result);
}

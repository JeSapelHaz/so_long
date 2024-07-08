/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:31:03 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/08 16:14:23 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* ft_printf.c */
int		ft_printf(const char *format, ...);

/* ft_format.c */
size_t	ft_format(va_list args, char c);
size_t	ft_putnbr(long int nbr);
size_t	ft_putnbr_base(unsigned long int nbr, const char *base);

/* utils.c */
size_t	ft_putchar(char c);
size_t	ft_strlen_3(const char *str);
size_t	ft_putstr(const char *str);
#endif
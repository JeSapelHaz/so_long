/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:31:13 by hbutt             #+#    #+#             */
/*   Updated: 2024/05/24 17:28:50 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	result;
	va_list	args;
	size_t	i;

	result = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 32 && format[i + 2] == format[i])
				result = result + ft_format(args, format[i]);
			else
				result = result + ft_format(args, format[i + 1]);
			i++;
		}
		else
			result = result + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (result);
}

// #include <libc.h>
// int main(void)
// {
// 	// char *ptr = NULL;
// 	// ft_printf("%p", ptr);
// 	// printf("\n");
// 	// printf("%p", ptr);

// 	// ft_printf("%d", 10);
// 	// printf("\n");
// 	// printf("%d", 10);

// 	// ft_printf("%u", -10);
// 	// printf("\n");
// 	// printf("%u", -10);

// 	// ft_printf("%w test", 10);
// 	// printf("\n");
// 	int a;
// 	char *s = "kik";
// 	a = 1;
// 	printf(" nb : %d", printf("vrai <%c> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%c> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%s> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%s> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%p> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%p> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%d> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%d> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%i> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%i> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%u> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%u> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%x> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%x> ", NULL));
// 	printf("\n");
// 	printf("\n");
// 	printf(" nb : %d", printf("vrai <%X> ", NULL));
// 	printf("\n");
// 	printf(" nb : %d", ft_printf("mien <%X> ", NULL));
// 	printf("\n");
// 	printf("\n");
// }

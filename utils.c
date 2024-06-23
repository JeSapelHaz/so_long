/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:11 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/23 20:58:28 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *msg)
{
	int len;

	len = ft_strlen(msg);
	write(1, msg, len);
	write(1, "\n", 1);
	exit(1);
}

void ft_you_win()
{
	write(1, "YOU WIN\n", 8);
	exit(0);
}
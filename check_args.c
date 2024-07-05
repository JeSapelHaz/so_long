/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:09:46 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/04 17:15:45 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	if (ac < 2)
		ft_error("Error : Pas de map, tu veux pas jouer chef ?");
	else if (ac > 2)
		ft_error("Error : Le seul argument valable est la map");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		ft_error("Error : Map invalide chef");
}

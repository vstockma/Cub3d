/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:00:43 by valentin          #+#    #+#             */
/*   Updated: 2023/07/10 19:11:17 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkfile(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '.')
		{
			if (str[i++] != 'c')
				return (1);
			if (str[i++] != 'u')
				return (1);
			if (str[i++] != 'b')
				return (1);
			if (str[i] != '\0')
				return (1);
			count++;
		}
	}
	if (count == 0)
		return (1);
	return (0);
}

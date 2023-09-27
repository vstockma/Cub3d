/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:58:33 by valentin          #+#    #+#             */
/*   Updated: 2023/09/27 11:12:56 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_arr(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	printf("\n%s", game->img.no_texture);
	printf("\nPlayer_x_position = %f\n", game->player.x);
	printf("\nPlayer_y_position = %f\n", game->player.y);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Not enough arguments!\n");
		return (1);
	}
	if (ft_checkfile(av[1]) == 1)
	{
		ft_printf("Error\nWrong file format!\n");
		return (1);
	}
	ft_init(&game);
	ft_events_init(&game);
	game.file_name = ft_strdup(av[1]);
	ft_handle_input(&game);
	print_arr(&game);
	return (0);
}
	// ft_find_player_position(&game);
	// ft_player_angle(&game);

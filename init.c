/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/27 11:12:48 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init(t_game *game)
{
	game->screen_width = 0;
	game->screen_height = 0;
	game->height = 0;
	game->width = 0;
	game->square_x = 0;
	game->square_y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->mlx = mlx_init();
	game->stop = 0;

	game->lines = 0;
	game->img.no_texture = NULL;
	game->img.so_texture = NULL;
	game->img.we_texture = NULL;
	game->img.ea_texture = NULL;
	game->img.floor_color = NULL;
	game->img.ceiling_color = NULL;
	game->index = 0;
	game->all_done = 0;
	game->rows = 0;
}

void	ft_events_init(t_game *game)
{
	game->moves.move_back = 0;
	game->moves.move_forward = 0;
	game->moves.move_left = 0;
	game->moves.move_right = 0;
	game->moves.rotate_left = 0;
	game->moves.rotate_right = 0;
}

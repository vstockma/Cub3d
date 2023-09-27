/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:02 by ddyankov          #+#    #+#             */
/*   Updated: 2023/09/27 11:24:05 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>

// Math
# define PI 3.1415926535

// Colors
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define RED 0xFF0000
# define YELLOW 0xFFEF00
# define GREY 0xA0A0A0

// 2Dmap player square attributes
# define PLAYER_SIZE 1

// 2Dmap wall or empty attributes
# define SQUARE_SIZE 32

// Angle Speed
# define ANGLE_SPEED 0.04

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	char		*no_texture;
	char		*ea_texture;
	char		*so_texture;
	char		*we_texture;
	char		*floor_color;
	char		*ceiling_color;
}				t_img;

typedef struct s_player
{
	float		x;
	float		y;
	float		delta_x;
	float		delta_y;
	float		angle;
}				t_player;

typedef struct s_moves
{
	int			move_forward;
	int			move_back;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
}				t_moves;

typedef struct s_game
{
	int			screen_width;
	int			screen_height;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	int			square_x;
	int			square_y;
	int			square_size;
	t_player	player;
	t_img		img;
	t_moves		moves;
	int			stop;

	char		*file_name;
	char		**content;
	int			lines;
	char		*tmp_string;
	int			index;
	int			all_done;
	int			rows;
}				t_game;

void			ft_draw_circle(t_game *game);
// init
void			ft_init(t_game *game);
void			ft_events_init(t_game *game);

// map
// void	ft_get_map(t_game *game, char *map_name);

// render
void			ft_draw_background(t_game *game);
void			ft_draw_2d_map(t_game *game);
void			ft_draw_square(t_game *game, int color);
void			ft_draw_player(t_game *game);
int				img_pix_put(t_game *game, int x, int y, int color);
void			ft_draw_line(t_game *game, int x1, int y1, int x2, int y2);
void			ft_find_player_position(t_game *game);
void			ft_player_angle(t_game *game);

// key events
int				ft_key_press(int key, t_game *game);
int				ft_key_release(int key, t_game *game);

// moves
void			ft_move_forward(t_game *game);
void			ft_move_back(t_game *game);
void			ft_move_left(t_game *game);
void			ft_move_right(t_game *game);
void			ft_rotate_right(t_game *game);
void			ft_rotate_left(t_game *game);

int				render(t_game *game);

bool			ft_player_in_bounds(t_game *game);

//main_utils.c
int				ft_handle_input(t_game *game);
int				ft_linecount(int fd);

//map_check_walls.c
int				ft_check_walls(t_game *game);

//map_check.c
int				ft_get_player_position(t_game *game);
int				ft_check_map(t_game *game);
int				ft_checkfile(char *str);
int				ft_get_map(t_game *game, int i);


//map_manipulation.c
int				ft_change_map(t_game *game);

//input_check_colors.c
int				ft_strncmp_colors(t_game *game, char *s1, const char *s2,
					size_t n);
int				ft_check_colors(t_game *game);

//input_check_textures.c
int				ft_strncmp_textures(t_game *game, char *s1, const char *s2,
					size_t n);
int				ft_check_textures(t_game *game);

//input_receiving.c
int				ft_get_file_content(t_game *game);

//free.c
void			ft_free_content(t_game *game);
void			ft_free_colors_textures_error(t_game *game, char *tmp,
					int i);
void			ft_free_map_error(t_game *game, int i);
void			ft_free_game(t_game *game);
#endif
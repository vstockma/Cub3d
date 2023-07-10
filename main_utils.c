/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:17:18 by valentin          #+#    #+#             */
/*   Updated: 2023/07/10 20:00:53 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init_struct(t_var *vars)
{
    vars->lines = 0;
    vars->i = 0;
}

void	ft_linecount(int fd, t_var *vars)
{
	int		n;
	char	*line;

	n = 1;
	line = malloc(2);
	while (n > 0)
	{
		n = read(fd, line, BUFFER_SIZE);
		if (n == -1)
            return ;
		line[n] = '\0';
		if (ft_strchr(line, '\n'))
			vars->lines++;
	}
	free(line);
	line = NULL;
	close(fd);
}

int ft_get_file_content(int fd, t_var *vars)
{
    int	i;

	i = 0;
	ft_linecount(fd, vars);
	fd = open(vars->file, O_RDONLY);
	vars->input = malloc(sizeof(char *) * (vars->lines + 1));
	while (i < vars->lines)
	{
		vars->input[i] = get_next_line(fd);
		i++;
	}
	vars->input[vars->lines] = NULL;
	close(fd);
    return (0);
}

int ft_extract_input(t_var *vars)
{
    while (vars->i < vars->lines)
    {
        ft_get_textures(vars);
        ft_get_colours(vars);
        ft_get_map(vars);
        vars->i++;
    }
    return (0);
}
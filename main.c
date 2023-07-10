/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:58:33 by valentin          #+#    #+#             */
/*   Updated: 2023/07/10 19:40:41 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_arr(t_var *vars)
{
    int i = 0;
    while (vars->input[i] != NULL)
    {
        printf("%s", vars->input[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int fd;
    t_var vars;

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
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error opening file!\n");
        return (1);
    }
    ft_init_struct(&vars);
    vars.file = av[1];
    ft_get_file_content(fd, &vars);
    ft_extract_input(&vars);
    print_arr(&vars);
    return (0);
}
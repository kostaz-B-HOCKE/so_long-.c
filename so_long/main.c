/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:16:52 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:34:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init_count(t_map1 *vars)
{
	vars->wall = 0;
	vars->exit = 0;
	vars->player = 0;
	vars->item = 0;
	vars->count_key = 0;
}

void	img_map(t_map1 *vars)
{
	int	x;
	int	y;

	x = 5;
	y = 5;
	vars->img_item = mlx_xpm_file_to_image(vars->mlx, "./77.xpm", &x, &y);
	vars->img_player = mlx_xpm_file_to_image(vars->mlx, "./13.xpm", &x, &y);
	vars->img_playerr = mlx_xpm_file_to_image(vars->mlx, "./14.xpm", &x, &y);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx, "./5.xpm", &x, &y);
	vars->img_enemy = mlx_xpm_file_to_image(vars->mlx, "./9.xpm", &x, &y);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, "./11.xpm", &x, &y);
	vars->img_test = mlx_xpm_file_to_image(vars->mlx, "./Zwall.xpm", &x, &y);
}

int	main(int argc, char **argv)
{
	t_map1	vars;

	if ((argc == 1) || (argc > 2))
	{
		printf("\033[%dm%s\033[m", 31, "ERROR/  что ты печатаешь ????");
		exit (1);
	}
	map_completion(argv, &vars);
	map_h_w(&vars);
	map_test_all(&vars);
	vars.mlx = mlx_init();
	vars.wind = mlx_new_window(vars.mlx, 1920, 1080, "Pom");
	img_map(&vars);
	printf_wall_map(&vars, 50, 50);
	mlx_hook(vars.wind, 2, 1L << 0, key_test, &vars);
	mlx_loop (vars.mlx);
	mlx_destroy_window (vars.mlx, vars.wind);
}

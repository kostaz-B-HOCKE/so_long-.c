/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:15:52 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:15:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printf_pixel_s(t_map1 *vars, int x, int y)
{
	vars->poi_y = vars->poi_y + 50;
	square_void(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_player,
		vars->poi_x, vars->poi_y);
}

void	printf_pixel_w(t_map1 *vars, int x, int y)
{
	vars->poi_y = vars->poi_y - 50;
	square_void(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_player,
		vars->poi_x, vars->poi_y);
}

void	printf_pixel_d(t_map1 *vars, int x, int y)
{
	vars->poi_x = vars->poi_x + 50;
	square_void(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_player,
		vars->poi_x, vars->poi_y);
}

void	printf_pixel_a(t_map1 *vars, int x, int y)
{
	vars->poi_x = vars->poi_x - 50;
	square_void(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_playerr,
		vars->poi_x, vars->poi_y);
}

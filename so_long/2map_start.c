/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2map_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:19:04 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:30:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_h_w(t_map1 *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map_full[y])
	{
		x = 0;
		while (vars->map_full[y][x])
		{
			if (vars->map_full[y][x] == 'C')
				vars->item++;
			if (vars->map_full[y][x] == 'E')
				vars->exit++;
			if (vars->map_full[y][x] == 'P')
				vars->player++;
			x++;
		}
		y++;
	}
}

void	square_wall(t_map1 *vars, int x1, int y1, int color)
{
	int	x;
	int	y;

	x = x1 - 1;
	y = y1 + 1;
	while (x++ < 50 + x1 - 1)
		mlx_pixel_put(vars->mlx, vars->wind, x, y, color);
	while (y++ < 50 + y1 - 1)
		mlx_pixel_put(vars->mlx, vars->wind, x, y, color);
	while (x-- > x1 + 1)
		mlx_pixel_put(vars->mlx, vars->wind, x, y, color);
	x++;
	while (y-- > y1 + 1)
		mlx_pixel_put(vars->mlx, vars->wind, x, y, color);
}

void	square_void(t_map1 *vars, int x1, int y1)
{
	int	x;
	int	y;

	y = y1;
	while (y++ < 50 + y1)
	{
		x = x1;
		while (x++ < 50 + x1)
			mlx_pixel_put(vars->mlx, vars->wind, x, y, 0x000000);
	}
}

void	printf_wall_map(t_map1 *vars, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map_full[j])
	{
		i = 0;
		while (vars->map_full[j][i])
		{
			if (vars->map_full[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->wind,
					vars->img_test, x, y);
			x = x + 50;
			if (chek_symbol(vars->map_full[j][i]) == 1)
				ch_ecp(vars, j, i, vars->map_full[j][i]);
			i++;
		}
		j++;
		x = 50;
		y = y + 50;
	}
}

void	step_count(t_map1 *vars)
{
	char	*n;

	vars->count_key++;
	n = ft_itoa(vars->count_key);
	square_void(vars, 0, 0);
	mlx_string_put(vars->mlx, vars->wind, 10, 11, 0x00FF00, n);
	free(n);
}

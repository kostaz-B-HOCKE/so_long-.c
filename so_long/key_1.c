/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:16:23 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:16:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_test(int key_code, t_map1 *vars)
{
	if (key_code == 53)
		exit(0);
	if (key_code == 13)
		if (map_clone(vars, vars->poi_x, vars->poi_y + 50, 'w') == 0)
			printf_pixel_w(vars, vars->poi_x, vars->poi_y);
	if (key_code == 0)
		if (map_clone(vars, vars->poi_x - 50, vars->poi_y, 'a') == 0)
			printf_pixel_a(vars, vars->poi_x, vars->poi_y);
	if (key_code == 1)
		if (map_clone(vars, vars->poi_x, vars->poi_y - 50, 's') == 0)
			printf_pixel_s(vars, vars->poi_x, vars->poi_y);
	if (key_code == 2)
		if (map_clone(vars, vars->poi_x + 50, vars->poi_y, 'd') == 0)
			printf_pixel_d(vars, vars->poi_x, vars->poi_y);
	step_count(vars);
	return (0);
}

int	map_clone(t_map1 *vars, int x, int y, char c)
{
	x = (vars->poi_x / 50) - 1;
	y = (vars->poi_y / 50) - 1;
	if (vars->map_full[y][x] == 'C')
	{
		vars->map_full[y][x] = '0';
		vars->item--;
	}
	if (c == 'w' && vars->map_full[y - 1][x] != 'E')
		if (vars->map_full[y - 1][x] != '1')
			return (0);
	if (c == 'a' && vars->map_full[y][x - 1] != 'E')
		if (vars->map_full[y][x - 1] != '1')
			return (0);
	if (c == 's' && vars->map_full[y + 1][x] != 'E')
		if (vars->map_full[y + 1][x] != '1')
			return (0);
	if (c == 'd' && vars->map_full[y][x + 1] != 'E')
		if (vars->map_full[y][x + 1] != '1')
			return (0);
	chek_exit(vars, x, y, c);
	return (1);
}

void	chek(t_map1 *vars, int x, int y, char c)
{
	if (c == 'w')
		if (vars->map_full[y - 1][x] == 'F')
			exit(0);
	if (c == 'd')
		if (vars->map_full[y][x + 1] == 'F')
			exit(0);
	if (c == 's')
		if (vars->map_full[y + 1][x] == 'F')
			exit(0);
	if (c == 'a')
		if (vars->map_full[y][x - 1] == 'F')
			exit(0);
}

void	chek_exit_v2(t_map1 *vars, int x, int y, char c)
{
	if (c == 'd')
	{
		if (vars->map_full[y][x + 1] == 'E' && vars->item == 0)
		{
			printf_pixel_d(vars, vars->poi_x, vars->poi_y);
			exit(0);
		}
	}
	if (c == 's')
	{
		if (vars->map_full[y + 1][x] == 'E' && vars->item == 0)
		{
			printf_pixel_s(vars, vars->poi_x, vars->poi_y);
			exit(0);
		}
	}
}

void	chek_exit(t_map1 *vars, int x, int y, char c)
{
	if (c == 'w')
	{
		if (vars->map_full[y - 1][x] == 'E' && vars->item == 0)
		{
			printf_pixel_w(vars, vars->poi_x, vars->poi_y);
			exit(0);
		}
	}
	if (c == 'a')
	{
		if (vars->map_full[y][x - 1] == 'E' && vars->item == 0)
		{
			printf_pixel_a(vars, vars->poi_x, vars->poi_y);
			exit(0);
		}
	}
	if (c == 'd')
		chek_exit_v2(vars, x, y, c);
	if (c == 's')
		chek_exit_v2(vars, x, y, c);
}

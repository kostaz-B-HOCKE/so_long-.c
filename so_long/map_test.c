/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:49:56 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:59:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_symbol(char c)
{
	if (c != '0' && c != 'P' && c != 'E' && c != 'C' && c != 'F')
		return (0);
	return (1);
}

int	map_test2(t_map1 *vars, int x1, int y1)
{
	int	y;

	y = 0;
	while (++y < y1)
	{
		if (vars->map_full[y][0] != '1' || vars->map_full[y][x1 - 1] != '1')
			return (1);
	}
	return (0);
}

int	map_testwall(t_map1 *vars, int x1, int y1)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map_full[y])
		y++;
	while (vars->map_full[0][x] && vars->map_full[0][x] != '\n')
		x++;
	if ((y < 3 || x < 4) && (y < 4 || x < 3))
		return (1);
	while (vars->map_full[y1])
	{
		x1 = 0;
		while (vars->map_full[y1][x1] && vars->map_full[y1][x1] != '\n')
			x1++;
		if (x != x1)
			return (1);
		y1++;
	}
	return (0);
}

int	map_test1(t_map1 *vars)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	if (1 == map_testwall(vars, 0, 0))
		return (1);
	while (vars->map_full[y])
		y++;
	while (vars->map_full[y - 1][++x])
		if (vars->map_full[y - 1][x] != '1')
			return (1);
	x = -1;
	while (vars->map_full[0][++x] != '\n')
		if (vars->map_full[0][x] != '1')
			return (1);
	if (1 == map_test2(vars, x, y))
		return (1);
	return (0);
}

void	map_test_all(t_map1 *vars)
{
	int	f;

	f = map_test1(vars);
	if (f == 1)
	{
		printf("\033[%dm%s\033[m", 31,
			"ERROR / карта - хрень");
		exit(0);
	}
	printf("\033[%dm%s\033[m", 34, "WOW");
}

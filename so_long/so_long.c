/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:17:30 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:48:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_symbol_s(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (chek_symbol(s[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ch_ecp(t_map1 *vars, int j, int i, char c)
{
	if (c == 'P')
	{
		vars->x_player = i;
		vars->y_player = j;
		vars->poi_x = (i + 1) * 50;
		vars->poi_y = (j + 1) * 50;
		mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_player,
			(vars->x_player + 1) * 51, (vars->y_player + 1) * 50);
	}
	if (c == 'C')
	{
		vars->x_player = i;
		vars->y_player = j;
		mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_item,
			(vars->x_player + 1) * 50, (vars->y_player + 1) * 51);
	}
	if (c == 'E')
	{
		vars->x_player = i;
		vars->y_player = j;
		mlx_put_image_to_window(vars->mlx, vars->wind, vars->img_exit,
			(vars->x_player + 1) * 50, (vars->y_player + 1) * 50);
	}
}

void	map_completion(char **argv, t_map1 *vars)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map_init_count(vars);
	fd = open(argv[1], O_RDONLY);
	vars->map_full = (char **)malloc(sizeof(char *) * 100);
	line = get_next_line(fd);
	while (line != 0)
	{
		if (vars->map_full == NULL)
		{
			printf("\033[%dm%s\033[m", 31, "ERROR  gnl kill");
			free(line);
			exit(0);
		}
		vars->map_full[i++] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

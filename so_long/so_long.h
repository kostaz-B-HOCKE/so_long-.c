/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:19:30 by                   #+#    #+#             */
/*   Updated: 2021/11/21 13:59:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"minilibx_opengl_20191021/mlx.h"

typedef struct tt_map
{
	char	**map_full;
	int		wall;
	int		player;
	int		x_player;
	int		y_player;
	int		item;
	int		exit;
	int		width;
	int		height;
	int		poi_x;
	int		poi_y;
	int		x_exit;
	int		y_exit;
	int		count_key;
	void	*mlx;
	void	*wind;
	void	*img_player;
	void	*img_playerr;
	void	*img_exit;
	void	*img_item;
	void	*img_enemy;
	void	*img_wall;
	void	*img_test;
}			t_map1;

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

void	map_init_count(t_map1 *vars);
int		chek_symbol(char c);
int		chek_symbol_s(char *s);
void	map_completion(char **argv, t_map1 *vars);
void	map_h_w(t_map1 *vars);
int		key_test(int key_code, t_map1 *vars);
char	*ft_itoa(int n);

void	printf_wall_map(t_map1 *vars, int x, int y);
void	square_w(t_map1 *vars, int x1, int y1, unsigned int color);
void	square_void(t_map1 *vars, int x1, int y1);
void	square_wall(t_map1 *vars, int x1, int y1, int color);
void	step_count(t_map1 *vars);
void	printf_pixel_s(t_map1 *vars, int x, int y);
void	printf_pixel_w(t_map1 *vars, int x, int y);
void	printf_pixel_a(t_map1 *vars, int x, int y);
void	printf_pixel_d(t_map1 *vars, int x, int y);
void	ch_ecp(t_map1 *vars, int j, int i, char c);
int		map_clone(t_map1 *vars, int x1, int y1, char c);
void	chek_exit(t_map1 *vars, int x, int y, char c);
void	chek_exit_v2(t_map1 *vars, int x, int y, char c);
void	map_test_all(t_map1 *vars);
int		map_test1(t_map1 *vars);
int		map_testwall(t_map1 *vars, int x1, int y1);
int		map_test2(t_map1 *vars, int x1, int y1);

void	img_map(t_map1 *vars);
void	chek(t_map1 *vars, int x, int y, char c);
#endif

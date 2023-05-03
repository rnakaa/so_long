/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:17 by rnaka             #+#    #+#             */
/*   Updated: 2023/05/03 18:51:03 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<fcntl.h>
# include<stdlib.h>
# include"../minilibx_opengl_20191021/mlx.h"

typedef struct s_data
{
	char	**map;
	int		width;
	int		height;
	int		i;
	int		j;
	int		count;
	int		total;
	int		donum;
	void	*mlx;
	void	*mlx_win;
	void	*grass;
	void	*ball;
	void	*cock;
	void	*wall;
	void	*exit;
}t_data;

void	file_name(int argc, const char **argv);
void	error(int num);
char	**const_map(int fd);
void	check_char(char **map);
void	check_map(char **map);
void	error_free(char **map, int i);
void	free_dp_char(char **chardp);
void	check_wall(char **map);
int		mapsize(char **map);
int		maplen(char *map);
void	check_cep(char **map);
void	find_cep(char **map, int size);
void	draw(t_data *map);
void	make_field(t_data *map);
int		make_map(t_data *map);
int		player_move(int key, t_data *map);
int		end_game(t_data *map);
#endif

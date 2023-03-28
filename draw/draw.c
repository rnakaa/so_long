/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:16:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/28 23:54:10 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	make_field(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->grass,j*32 ,i *32);
			j++;
		}
		i++;
	}
}

int	make_map(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	make_field(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, j * 32, i * 32);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->cock, j * 32, i * 32);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->ball, j * 32, i * 32);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit, j * 32, i * 32);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_init(t_data *map)
{
	int	i;
	int	j;

	map->grass = mlx_xpm_file_to_image(map->mlx, "./images/grass.xpm", &i,&j);
	map->ball = mlx_xpm_file_to_image(map->mlx, "./images/ball.xpm", &i,&j);
	map->cock = mlx_xpm_file_to_image(map->mlx, "./images/cock.xpm", &i,&j);
	map->wall = mlx_xpm_file_to_image(map->mlx, "./images/wall.xpm", &i,&j);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./images/exit.xpm", &i,&j);
}

void	end_game(t_data *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_image(map->mlx, map->grass);
	mlx_destroy_image(map->mlx, map->ball);
	mlx_destroy_image(map->mlx, map->cock);
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->exit);
	if (map->count == map->total)
		ft_printf("Congratulations!\n");
	free_dp_char(map->map);
	exit(0);
}

void	move_up(t_data *map)
{
	int	i;
	int	j;

	i = map->i;
	j = map->j;
	if (map->map[i - 1][j] == '0' || map->map[i - 1][j] == 'C')
	{
		if (map->map[i - 1][j] == 'C')
			map->count++;
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'P';
		map->i--;
		printf("%dtimes\n", ++(map->donum));
	}
	else if(map->map[i - 1][j] == 'E' && map->count == map->total)
		end_game(map);
}

void	move_down(t_data *map)
{
	int	i;
	int	j;

	i = map->i;
	j = map->j;
	if (map->map[i + 1][j] == '0' || map->map[i + 1][j] == 'C')
	{
		if (map->map[i + 1][j] == 'C')
			map->count++;
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'P';
		map->i++;
		printf("%dtimes\n", ++(map->donum));
	}
	else if(map->map[i + 1][j] == 'E' && map->count == map->total)
		end_game(map);
}

void	move_right(t_data *map)
{
	int	i;
	int	j;

	i = map->i;
	j = map->j;
	if (map->map[i][j + 1] == '0' || map->map[i][j + 1] == 'C')
	{
		if (map->map[i][j + 1] == 'C')
			map->count++;
		map->map[i][j] = '0';
		map->map[i][j + 1] = 'P';
		map->j++;
		printf("%dtimes\n", ++(map->donum));
	}
	else if(map->map[i][j + 1] == 'E' && map->count == map->total)
		end_game(map);
}

void	move_left(t_data *map)
{
	int	i;
	int	j;

	i = map->i;
	j = map->j;
	if (map->map[i][j - 1] == '0' || map->map[i][j - 1] == 'C')
	{
		if (map->map[i][j - 1] == 'C')
			map->count++;
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'P';
		map->j--;
		printf("%dtimes\n", ++(map->donum));
	}
	else if(map->map[i][j - 1] == 'E' && map->count == map->total)
		end_game(map);
}

int	player_move(int key, t_data *map)
{
	if (key == 13 || key == 126)
		move_up(map);
	else if (key == 2|| key == 124)
		move_right(map);
	else if (key == 1 || key == 125)
		move_down(map);
	else if (key == 0|| key == 123)
		move_left(map);
	key = map->width;
	return (0);
}

void	count_c(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	map->total = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->total++;
			j++;
		}
		i++;
	}
}

void	current_loc(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->i = i;
				map->j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw(t_data *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx,32 * map->width, 32 * map->height, "./so_long");
	current_loc(map);
	count_c(map);
	map->count = 0;
	map->donum = 0;
	map_init(map);
	mlx_loop_hook(map->mlx, make_map, map);
	mlx_hook(map->mlx_win, 2,1L << 0, player_move, map);
	mlx_loop(map->mlx);
}

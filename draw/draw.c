/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:16:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/29 01:42:20 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	map_init(t_data *map)
{
	int	i;
	int	j;

	map->grass = mlx_xpm_file_to_image(map->mlx, "./images/grass.xpm", &i,&j);
	map->ball = mlx_xpm_file_to_image(map->mlx, "./images/ball.xpm", &i,&j);
	map->cock = mlx_xpm_file_to_image(map->mlx, "./images/cock.xpm", &i,&j);
	map->wall = mlx_xpm_file_to_image(map->mlx, "./images/wall.xpm", &i,&j);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./images/exit.xpm", &i,&j);
}

int	end_game(t_data *map)
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
	return (0);
}

static void	count_c(t_data *map)
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

static void	current_loc(t_data *map)
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
	mlx_hook(map->mlx_win, 17, 1L << 2, end_game, map);
	mlx_loop(map->mlx);
}


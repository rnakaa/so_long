/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:16:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/28 20:38:37 by rnaka            ###   ########.fr       */
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

int	player_move(int key, t_data *map)
{
	printf("%d\n", key);
	key = map->width;
	return (0);
}

void	draw(t_data *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx,32 * map->width, 32 * map->height, "./so_long");
	map_init(map);
	mlx_loop_hook(map->mlx, make_map, map);
	printf("okokokokokpok\n");
	mlx_hook(map->mlx_win, 2,1L << 0, player_move, map);
	mlx_loop(map->mlx);
}

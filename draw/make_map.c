/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:38:10 by rnaka             #+#    #+#             */
/*   Updated: 2023/05/03 19:21:15 by rnaka            ###   ########.fr       */
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
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->grass, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

static void	draw_map(t_data *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx,
			map->mlx_win, map->wall, j * 32, i * 32);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx,
			map->mlx_win, map->cock, j * 32, i * 32);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx,
			map->mlx_win, map->ball, j * 32, i * 32);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx,
			map->mlx_win, map->exit, j * 32, i * 32);
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
			draw_map(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

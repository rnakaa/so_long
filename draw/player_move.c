/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:32:30 by rnaka             #+#    #+#             */
/*   Updated: 2023/05/03 20:41:30 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	move_up(t_data *map)
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
	else if (map->map[i - 1][j] == 'E' && map->count == map->total)
		end_game(map);
}

static void	move_down(t_data *map)
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
	else if (map->map[i + 1][j] == 'E' && map->count == map->total)
		end_game(map);
}

static void	move_right(t_data *map)
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
	else if (map->map[i][j + 1] == 'E' && map->count == map->total)
		end_game(map);
}

static void	move_left(t_data *map)
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
	else if (map->map[i][j - 1] == 'E' && map->count == map->total)
		end_game(map);
}

int	player_move(int key, t_data *map)
{
	if (key == 12 || key == 53)
		end_game(map);
	else if (key == 13 || key == 126)
		move_up(map);
	else if (key == 2 || key == 124)
		move_right(map);
	else if (key == 1 || key == 125)
		move_down(map);
	else if (key == 0 || key == 123)
		move_left(map);
	key = map->width;
	return (0);
}

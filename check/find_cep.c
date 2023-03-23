/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:35:45 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/23 18:04:51 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static int	find_c(int i, int j, char **map, int *list)
{
	if (list[i*maplen(map[0])+j])
		return (0);
	list[i*maplen(map[0])+j] = 1;
	if(map[i][j] == 'C')
		return (1);
	else if (map[i][j] == '1' || map[i][j] == 'E')
		return (0);
	else if (find_c(i + 1, j, map, list))
		return (1);
	else if (find_c(i, j + 1, map, list))
		return (1);
	else if (find_c(i - 1, j, map, list))
		return (1);
	else if (find_c(i, j - 1, map, list))
		return (1);
	return (0);
}

static int	find_e(int i, int j, char **map, int *list)
{
	if (list[i*maplen(map[0])+j])
		return (0);
	list[i*maplen(map[0])+j] = 1;
	if(map[i][j] == 'E')
		return (1);
	else if (map[i][j] == '1')
		return (0);
	else if (find_e(i + 1, j, map, list))
		return (1);
	else if (find_e(i, j + 1, map, list))
		return (1);
	else if (find_e(i - 1, j, map, list))
		return (1);
	else if (find_e(i, j - 1, map, list))
		return (1);
	return (0);
}

static void	find_p(int *i, int *j, char **map)
{
	int	h;
	int	b;

	h = 0;
	b = 0;
	while (map[h])
	{
		b = 0;
		while (map[h][b])
		{
			if (map[h][b] == 'P')
			{
				*i = h;
				*j = b;
			}
			b++;
		}
		h++;
	}
}

static void	reset_list(char **map, int *list)
{
	int	i;

	i = 0;
	while (i < maplen(map[0]) * mapsize(map))
	{
		list[i] = 0;
		i++;
	}
}

void	find_cep(char **map)
{
	int	i;
	int	j;
	int	list[maplen(map[0]) * mapsize(map)];

	i = 0;
	j = 0;
	reset_list(map, list);
	find_p(&i, &j, map);
	if (!find_e(i, j, map, list))
		error_free(map, 8);
	reset_list(map, list);
	if (!find_c(i, j, map, list))
		error_free(map, 8);
}

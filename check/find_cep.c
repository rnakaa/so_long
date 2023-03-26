/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:35:45 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/26 20:29:58 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static int	find_c(int i, int j, char **map, int *list)
{
	if (list[i * maplen(map[0]) + j])
		return (0);
	list[i * maplen(map[0]) + j] = 1;
	if (map[i][j] == 'P')
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
	if (list[i * maplen(map[0]) + j])
		return (0);
	list[i * maplen(map[0]) + j] = 1;
	if (map[i][j] == 'P')
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

int	enumera_c(char **map, int *list)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' && !find_c(i, j, map, list))
				return (0);
			else if (map[i][j] == 'E' && !find_e(i, j, map, list))
				return (0);
			j++;
			reset_list(map, list);
		}
		i++;
	}
	return (1);
}

void	find_cep(char **map, int size)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	reset_list(map, list);
	if (!enumera_c(map, list))
		error_free(map, 8);
}

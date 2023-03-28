/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:09:39 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/29 01:54:18 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static int	mapisrectangle(char **map)
{
	int	len;
	int	i;

	i = 0;
	if (mapsize(map) <= 2)
		return (1);
	len = maplen(map[0]);
	if (len <= 2)
		return (1);
	while (map[i])
	{
		if (len != maplen(map[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	u_and_d_one(char **map)
{
	int	i;
	int	s;

	i = 0;
	s = mapsize(map) - 1;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1' || map[s][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	l_and_r_one(char **map)
{
	int	i;
	int	l;

	i = 0;
	l = maplen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][l] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_wall(char **map)
{
	if (mapisrectangle(map))
		error_free(map, 5);
	if (u_and_d_one(map) || l_and_r_one(map))
		error_free(map, 6);
}

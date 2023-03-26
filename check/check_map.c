/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:05:33 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/26 20:23:39 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

int	mapsize(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

int	maplen(char *map)
{
	int	len;

	len = 0;
	if (!map)
		return (0);
	while (map[len] != '\n' && map[len])
		len++;
	if (len <= 2)
		return (0);
	return (len);
}

void	check_map(char **map)
{
	int	size;

	check_char(map);
	check_wall(map);
	check_cep(map);
	size = maplen(map[0]) * mapsize(map);
	find_cep(map, size);
}


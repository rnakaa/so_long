/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:36:42 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/20 15:28:11 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static void	chardp_mig(char **map, char **save)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		save[i] = map[i];
		i++;
	}
}

static void	free_dp_char(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		i++;
	free(map[i]);
	free(map);
}
char	**const_map(int fd)
{
	int		size;
	char	**map;
	char	**save;
	char	*stock;

	map = NULL;
	stock = get_next_line(fd);
	if (!stock)
		error(3);
	size = 0;
	while (stock)
	{
		size++;
		save = (char **)malloc(sizeof(char *) * (size + 1));
		chardp_mig(map, save);
		save[size - 1] = stock;
		save[size] = NULL;
		free_dp_char(map);
		map = save;
		stock = get_next_line(fd);
	}
	return (map);
}

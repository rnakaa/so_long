/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:35:10 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/29 01:52:00 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static int	find_e(char **map)
{
	int	e;
	int	i;
	int	j;

	i = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e != 1)
		return (1);
	return (0);
}
static int	find_p(char **map)
{
	int	i;
	int	p;
	int	j;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (1);
	return (0);
}
static int	find_c(char **map)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
		return (1);
	return (0);
}

void	check_cep(char **map)
{
	if (find_c(map) || find_e(map) || find_p(map))
		error_free(map, 7);
}


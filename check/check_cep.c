/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:35:10 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/22 15:50:57 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static int	find_e(char **map)
{
	int	E;
	int	i;
	int	j;

	i = 0;
	E = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				E++;
			j++;
		}
		i++;
	}
	if (E != 1)
		return (1);
	return (0);
}
static int	find_p(char **map)
{
	int	i;
	int	P;
	int	j;

	i = 0;
	P = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				P++;
			j++;
		}
		i++;
	}
	if (P != 1)
		return (1);
	return (0);
}
static int	find_c(char **map)
{
	int	i;
	int	C;
	int	j;

	i = 0;
	C = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				C++;
			j++;
		}
		i++;
	}
	if (C < 1)
		return (1);
	return (0);
}

void	check_cep(char **map)
{
	if (find_c(map) || find_e(map) || find_p(map))
		error_free(map, 7);
}

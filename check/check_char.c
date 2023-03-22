/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:00:01 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/22 09:11:02 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

static int	is_mapascii(char i)
{
	if (i == '1' || i == '0' || i == 'C' || i == 'E' || i == 'P')
		return (0);
	return (1);
}

void	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (is_mapascii(map[i][j]))
				error_free(map, 4);
			j++;
		}
		i++;
	}
}

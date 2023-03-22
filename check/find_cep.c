/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:35:45 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/23 04:09:26 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

int	find_cep(int i, int j, char **map, int *list)
{
	ft_printf("%c i=%d j=%d \n", map[i][j], i, j);
	int k = 0;
	while (k < maplen(map[0])*mapsize(map))
	{
		ft_printf("%d",list[k]);
		if (k%maplen(map[0]) == 0)
			ft_printf("\n");
		k++;
	}
	ft_printf("\n");
	if (list[i*maplen(map[0])+j])
		return (0);
	list[i*maplen(map[0])+j] = 1;
	if(map[i][j] == 'E')
		return (1);
	else if (map[i][j] == '1')
		return (0);
	else if (find_cep(i + 1, j, map, list))
		return (1);
	else if (find_cep(i, j + 1, map, list))
		return (1);
	else if (find_cep(i - 1, j, map, list))
		return (1);
	else if (find_cep(i, j - 1, map, list))
		return (1);
	return (0);
}

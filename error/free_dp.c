/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:17:49 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/22 08:46:09 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"so_long.h"

void	free_dp_char(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

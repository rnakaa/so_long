/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:20:24 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/22 19:01:27 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"libft.h"

int	main(int argc, const char *argv[])
{
	int		fd;
	char	**map;

	map = NULL;
	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(2);
	map = const_map(fd);
	check_map(map);


	int i = 0;
	int j = 0;
	int ii = 0;
	int jj = 0;

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
			{
				ii = i;
				jj = j;
			}
			j++;
		}
		i++;
	}
	ft_printf("%d  %d\n", ii, jj);
	int list[maplen(map[0])*mapsize(map)];
	list[maplen(map[0])*mapsize(map) - 1] = 2;
	int nn = 0;
	list[0] = 0;
	while (nn < maplen(map[0])*mapsize(map)) 
	{
		list[nn] = 0;
		nn++;
	}
	if (!find_cep(ii, jj, map, list))
		error(8);
	free_dp_char(map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:20:24 by rnaka             #+#    #+#             */
/*   Updated: 2023/05/03 20:55:10 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"libft.h"

int	main(int argc, const char *argv[])
{
	int		fd;
	char	**map;
	t_data	mapdata;

	map = NULL;
	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(2);
	map = const_map(fd);
	check_map(map);
	mapdata.map = map;
	mapdata.width = maplen(map[0]);
	mapdata.height = mapsize(map);
	draw(&mapdata);
	free_dp_char(map);
	return (0);
}


#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q so_long");
}

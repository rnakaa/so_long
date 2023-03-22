/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:20:24 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/22 16:48:03 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"libft.h"

int	main(int argc, const char *argv[])
{
	int		fd;
	char	**map;
	int		i;

	i = 0;
	map = NULL;
	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(2);
	map = const_map(fd);
	check_map(map);
	while (map[i])
	{
		ft_printf("%s",map[i]);
		free(map[i++]);
	}
	free(map[i]);
	free(map);
	return (0);
}

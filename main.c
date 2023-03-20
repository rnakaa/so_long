/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:20:24 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/20 11:03:19 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"libft.h"

int	main(int argc, const char *argv[])
{
	int		fd;
	char	*a;

	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(2);
	ft_printf("nnnnn\n");
	while (1)
	{
		a = get_next_line(fd);
		ft_printf("%s", a);
		if (!a)
			break ;
		free(a);
	}
	free(a);
	return (0);
}

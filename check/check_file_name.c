/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:36:26 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/29 01:53:20 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include"libft.h"

int	check_extencion(const char *argv)
{
	char	*ber;
	int		i;
	int		j;

	i = 0;
	ber = ".ber\0";
	while (argv[i])
	{
		j = 0;
		while (argv[i] == ber[j] && ber[j])
		{
			j++;
			i++;
		}
		if (ber[j] == '\0' && argv[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	file_name(int argc, const char *argv[])
{
	if (argc <= 1)
		error(0);
	else if (check_extencion(argv[1]))
		error(1);
	return ;
}

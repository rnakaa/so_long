/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:25:28 by rnaka             #+#    #+#             */
/*   Updated: 2023/05/03 18:46:33 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	error(int num)
{
	if (num == 0)
		ft_printf("error (no file.) \n");
	else if (num == 1)
		ft_printf("error  (invalid argument.) \n");
	else if (num == 2)
		ft_printf("error (no file.)\n");
	else if (num == 3)
		ft_printf("error (no arguments in file.)\n");
	else if (num == 4)
		ft_printf("error (found invalid characters in map file.)\n");
	else if (num == 5)
		ft_printf("error (form is invalid.)\n");
	else if (num == 6)
		ft_printf("error (wall is broken.)\n");
	else if (num == 7)
		ft_printf("error (number of CEP is invalid.)\n");
	else if (num == 8)
		ft_printf("error (no road.)\n");
	exit (1);
}

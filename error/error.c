/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:25:28 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/20 15:10:10 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	error(int num)
{
	if (num == 0)
		ft_printf("error (no file) \n");
	else if (num == 1)
		ft_printf("error  (invalid argument) \n");
	else if (num == 3)
		ft_printf("error (no arguments in file)\n");
	exit (1);
}
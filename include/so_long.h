/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:17 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/22 07:19:52 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>

void	file_name(int argc, const char **argv);
void	error(int num);
char	**const_map(int fd);
void	check_char(char **map);
void	free_dp_char(char **chardp);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:17 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/23 09:00:27 by rnaka            ###   ########.fr       */
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
void	check_map(char **map);
void	error_free(char **map, int i);
void	free_dp_char(char **chardp);
void	check_wall(char **map);
int		mapsize(char **map);
int		maplen(char *map);
void	check_cep(char **map);
void	find_cep(char **map);
#endif

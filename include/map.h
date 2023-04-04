/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:01:21 by evallee-          #+#    #+#             */
/*   Updated: 2023/04/04 02:54:51 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include<stdint.h>
# include<stdbool.h>
# include"vector.h"
# include"libft.h"
# include"parsing.h"
# define TILE_SIZE 32

typedef struct s_map
{
	uint32_t	num_coll;
	char		**data;
	uint32_t	dim_x;
	uint32_t	dim_y;
	t_uvec		start;
	t_uvec		end;
}	t_map;

typedef void	(*t_tileiterator)(uint32_t, uint32_t, char, va_list);

bool	map_load(char *path);
t_map	map_get(void);
void	map_clear(void);
bool	map_is_valid(t_map map, t_list *list);
void	map_iter_tiles(t_map map, t_tileiterator it, ...);
size_t	row_len(char	*line);

#endif
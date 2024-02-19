/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:01:21 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/19 15:41:46 by evallee-         ###   ########.fr       */
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
	t_uvec		dim;
	t_uvec		start;
	t_uvec		end;
}	t_map;

typedef struct s_floodfill
{
	bool		found_exit;
	uint32_t	found_coll;
}	t_floodfill;

typedef void	(*t_tileiterator)(uint32_t, uint32_t, char, va_list);

bool	map_load(char *path);
t_map	map_get(void);
void	map_clear(void);
bool	map_is_valid(t_map map, t_list *list);
void	map_iter_tiles(t_map map, t_tileiterator it, ...);
size_t	row_len(char	*line);
bool	flood_check(t_map map);

#endif
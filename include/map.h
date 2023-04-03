#ifndef	MAP_H
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

bool		map_load(char *path);
t_map		map_get(void);
void		map_clear(void);
bool		map_is_valid(t_map map);
bool		map_check_borders(t_map map);
void		map_iter_tiles(t_map map, void (*f)(char));
size_t		row_len(char	*line);

#endif
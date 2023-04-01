#ifndef	MAP_H
# define MAP_H

# include<stdint.h>
# include<stdbool.h>
# include"vector.h"
# include"libft.h"
# include"parsing.h"

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
bool		map_is_valid(t_map map);
bool		map_check_borders(t_map map);

#endif
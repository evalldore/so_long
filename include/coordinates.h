#ifndef COORDINATES_H
# define COORDINATES_H
# include "vector.h"
# include "stdint.h"
# include "map.h"

t_uvec		pos_to_coords(double x, double y);
void		line_coords(t_uvec start, t_uvec end, void (*f)(uint32_t, uint32_t));

#endif
#ifndef ENTITIES_H
# define ENTITIES_H
# include <stdbool.h>
# include <stdint.h>
# include <MLX42/MLX42.h>
# include "ecs.h"

typedef enum comp_e
{
	COMP_NONE,
	COMP_POS,
	COMP_CTRL,
	COMP_VEL,
	COMP_GRAV,
	COMP_SPRITE
}	compnum_t;

typedef struct
{
	float x;
	float y;
}	vector_t;

typedef struct
{
	vector_t	curr;
	vector_t	last;
}	comp_pos_t;

typedef struct
{
	vector_t	curr;
	vector_t	last;
}	comp_vel_t;

typedef struct
{
	float	scale;
}	comp_grav_t;

typedef struct
{
	int32_t			asset;
	int32_t			inst;
	vector_t		offset;
}	comp_sprite_t;

typedef struct
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	comp_ctrl_t;

void		entities_init(void);
ent_id_t	entities_player(mlx_t *mlx, double x, double y);
ent_id_t	entities_collectible(double x, double y);

void		comp_ctrl_reg(void);
void		comp_pos_reg(void);
void		comp_vel_reg(void);
void		comp_grav_reg(void);
void		comp_sprite_reg(void);

#endif
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
	COMP_SPRITE,
	COMP_COLLISION,
	COMP_ANIM,
	COMP_STATE,
	COMP_DIRECTION
}	compnum_t;

enum e_state
{
	STATE_IDLE,
	STATE_WALK,
	STATE_JUMP
};

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
	int32_t		asset;
	int32_t		last_asset;
	vector_t	offset;
	int32_t		*insts;
}	comp_sprite_t;

typedef struct
{
	bool	left;
	bool	right;
	bool	jump;
	bool	shoot;
}	comp_ctrl_t;

typedef struct
{
	vector_t		offset;
	unsigned int	width;
	unsigned int	height;
}	comp_coll_t;

typedef struct
{
	int32_t		index;
	int32_t		frame;
	double		time;

}	comp_anim_t;

typedef struct
{
	bool	last;
	bool	curr;

}	comp_dir_t;

typedef struct
{
	int32_t	curr;
	int32_t last;
}	comp_state_t;

void		entities_init(void);
ent_id_t	entities_player(double x, double y);
ent_id_t	entities_collectible(double x, double y);

void		animation_set(ent_id_t ent, int32_t index, int32_t frame);
void		state_set(ent_id_t ent, int32_t next);

void		sys_controls(mlx_key_data_t keydata, void *params);
void		sys_controls_tick(double dt);
void		sys_movement(double dt);
void		sys_sprites(mlx_t *mlx);
void		sys_animation(double dt);
void		sys_state(void);

void		comp_ctrl_reg(void);
void		comp_pos_reg(void);
void		comp_vel_reg(void);
void		comp_grav_reg(void);
void		comp_sprite_reg(void);
void		comp_coll_reg(void);
void		comp_anim_reg(void);
void		comp_state_reg(void);
void		comp_dir_reg(void);

#endif
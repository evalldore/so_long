/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:14:25 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 02:34:02 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H
# include <stdbool.h>
# include <stdint.h>
# include <MLX42/MLX42.h>
# include "ecs.h"
# include "vector.h"

enum	e_collflags
{
	COLL_FLAG_WORLD = 1 << 0,
	COLL_FLAG_PLAYER = 1 << 1,
	COLL_FLAG_ENEMIES = 1 << 2,
	COLL_FLAG_COLLECTIBLE = 1 << 3,
	COLL_FLAG_PROJECTILE = 1 << 4
};

enum e_comp
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
};

enum e_state
{
	STATE_IDLE,
	STATE_WALK,
	STATE_JUMP
};

typedef struct s_comp_position
{
	t_dvec	curr;
	t_dvec	last;
}	t_c_pos;

typedef struct s_com_velocity
{
	t_dvec	curr;
	t_dvec	last;
}	t_c_vel;

typedef struct s_comp_gravity
{
	double	scale;
}	t_c_grav;

typedef struct s_comp_sprite
{
	int32_t		asset;
	int32_t		last_asset;
	t_dvec		offset;
	int32_t		*insts;
}	t_c_sprt;

typedef struct s_comp_control
{
	bool	left;
	bool	right;
	bool	jump;
	bool	shoot;
}	t_c_ctrl;

typedef struct s_comp_collision
{
	t_dvec		offset;
	t_uvec		size;
	uint32_t	flags;
}	t_c_coll;

typedef struct s_comp_animation
{
	int32_t		index;
	int32_t		frame;
	double		time;

}	t_c_anim;

typedef struct s_comp_direction
{
	bool	last;
	bool	curr;

}	t_c_dir;

typedef struct s_comp_state
{
	int32_t	curr;
	int32_t last;
}	t_c_state;

void		entities_init(void);
uint32_t	entities_player(double x, double y);
uint32_t	entities_collectible(double x, double y);

void		animation_set(uint32_t ent, int32_t index, int32_t frame);
void		state_set(uint32_t ent, int32_t next);

void		sys_controls(mlx_key_data_t keydata, void *params);
void		sys_controls_tick(uint32_t ent, va_list args);
void		sys_movement(uint32_t ent, va_list args);
void		sys_sprites(uint32_t ent, va_list args);
void		sys_animation(uint32_t ent, va_list args);
void		sys_state(uint32_t ent, va_list args);
void		sys_collision(uint32_t ent, va_list args);
void		sys_gravity(uint32_t ent, va_list args);

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
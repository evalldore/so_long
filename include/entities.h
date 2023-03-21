#ifndef ENTITIES_H
# define ENTITIES_H
# include <stdbool.h>
# include "ecs.h"

typedef enum comp_e
{
	COMP_NONE,
	COMP_POS,
	COMP_CTRL
}	compnum_t;

typedef struct
{
	unsigned int x;
	unsigned int y;
}	vector_t;

typedef struct
{
	vector_t	curr;
	vector_t	last;
} comp_pos_t;

typedef struct
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	comp_ctrl_t;

void		entities_init(void);
ent_id_t	entities_player(unsigned int x, unsigned int y);
ent_id_t	entities_collectible(unsigned int x, unsigned int y);
void		comp_ctrl_reg(void);
void		comp_pos_reg(void);

#endif
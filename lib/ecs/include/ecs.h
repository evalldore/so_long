/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:33:14 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/20 20:47:51 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECS_H
# define ECS_H
# define MAX_ENTS 256
# define MAX_COMP 32
# include <stdlib.h>

typedef unsigned int ent_id_t;
typedef void *(*constructor_t)(ent_id_t);
typedef void (*destructor_t)(ent_id_t);

typedef struct
{
	constructor_t	new;
	destructor_t	dest;
	void			*ptrs[MAX_ENTS];
}	component_t;

ent_id_t	ecs_create(void);
ent_id_t	ecs_num(void);
void		*ecs_comp_add(ent_id_t ent_id, int comp);
void		ecs_comp_remove(ent_id_t ent_id, int comp);
void		ecs_comp_register(int comp, constructor_t c, destructor_t d);
void		*ecs_comp_get(ent_id_t ent_id, int comp);
void		ecs_iterate(void (*f)(ent_id_t));

#endif
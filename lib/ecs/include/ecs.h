/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:33:14 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 02:14:48 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECS_H
# define ECS_H
# define MAX_ENTS 256
# define MAX_COMP 32
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

typedef void *(*constructor_t)(va_list);
typedef void (*destructor_t)(void	*);

typedef struct
{
	constructor_t	new;
	destructor_t	dest;
	void			*ptrs[MAX_ENTS];
}	component_t;

uint32_t	ecs_create(void);
uint32_t	ecs_num(void);
void		*ecs_comp_add(uint32_t ent_id, int comp, int argc, ...);
void		ecs_comp_remove(uint32_t ent_id, int comp);
void		ecs_comp_register(int comp, constructor_t c, destructor_t d);
void		*ecs_comp_get(uint32_t ent_id, int comp);
void		ecs_iterate(void (*f)(uint32_t, va_list), ...);

#endif
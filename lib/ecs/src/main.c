/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:47:33 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 18:39:43 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

static uint32_t	g_entities;

uint32_t	ecs_num(void)
{
	return (g_entities);
}

uint32_t	ecs_create(void)
{
	if (g_entities >= MAX_ENTS)
		return (-1);
	return (g_entities++);
}

void	ecs_iterate(t_system f, ...)
{
	uint32_t	ent_id;
	va_list		o_args;
	va_list		e_args;

	if (!f)
		return ;
	ent_id = 0;
	va_start(o_args, f);
	while (ent_id < g_entities)
	{
		va_copy(e_args, o_args);
		f(ent_id++, e_args);
	}
	va_end(o_args);
	va_end(e_args);
}

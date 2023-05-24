/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:58 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/24 00:31:08 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "libft.h"

void	coll_new(void	*ptr, va_list args)
{
	t_c_coll	*coll;

	coll = ptr;
	coll->size.x = va_arg(args, uint32_t);
	coll->size.y = va_arg(args, uint32_t);
	coll->offset.x = va_arg(args, double);
	coll->offset.y = va_arg(args, double);
	coll->flags = va_arg(args, uint32_t);
}

void	comp_coll_reg(void)
{
	size_t	size;

	size = sizeof(t_c_coll);
	ecs_comp_register(COMP_COLLISION, size, &coll_new, NULL);
}

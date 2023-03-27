/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:52:10 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/27 17:14:06 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "vector.h"

bool	box_check(t_dvec pos, t_uvec size, t_dvec tpos, t_uvec tsize)
{
	if (tpos.x <= (pos.x + size.x) && (tpos.x + tsize.x) >= pos.x)
	{
		if (tpos.y <= (pos.y + size.y) && (tpos.y + tsize.y) >= pos.y)
			return (true);
	}
	return (false);
}

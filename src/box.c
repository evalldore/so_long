/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:52:10 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/29 22:23:39 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

bool	box_check(t_dvec pos, t_uvec size, t_dvec tpos, t_uvec tsize)
{
	if (tpos.x <= (pos.x + size.x) && (tpos.x + tsize.x) >= pos.x)
	{
		if (tpos.y <= (pos.y + size.y) && (tpos.y + tsize.y) >= pos.y)
			return (true);
	}
	return (false);
}

double	box_intersect(t_dvec step, t_box s, t_box t)
{
	t_dvec	ti;
	double	ati;

	ti.x = 1.0;
	ti.y = 1.0;
	if (step.x > 0.0)
		ti.x = (t.x - (s.x + s.w)) / step.x;
	else if (step.x < 0.0)
		ti.x = ((t.x + t.w) - s.x) / step.x;
	if (step.y > 0.0)
		ti.y = (t.y - (s.y + s.h)) / step.y;
	else if (step.y < 0.0)
		ti.y = ((t.y + t.h) - s.y) / step.y;
	ati = fmax(ti.x, ti.y);
	if ((ati < 1.0) && (ti.x >= 0.0 && ti.y >= 0.0) && ti.x < 1.0 && ti.y < 1.0)
	{
		if (ti.x < 0.0 && ((s.x + s.w) <= t.x || s.x >= (s.x + t.w)))
			return (1.0);
		else if (ti.y < 0.0 && ((s.y + s.h) <= t.y || s.y >= (t.y + t.h)))
			return (1.0);
		return (ati);
	}
	return (1.0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:52:10 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/30 02:02:48 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

double	box_intersect_v(double step, t_box s, t_box t)
{
	double	ti;

	ti = 1.0;
	if (step > 0.0)
		ti = ((s.y + s.h) - t.y) / step;
	else if (step < 0.0)
		ti = (s.y - (t.y + t.h)) / step;
	if (ti >= 0.0 && ti < 1.0)
	{
		if (ti < 0.0 && ((s.y + s.h) <= t.y || s.y >= (t.y + t.h)))
			return (1.0);
		return (ti);
	}
	return (1.0);
}

double	box_intersect_h(double step, t_box s, t_box t)
{
	double	ti;

	ti = 1.0;
	if (step > 0.0)
		ti = ((s.x + s.w) - t.x) / step;
	else if (step < 0.0)
		ti = (s.x - (t.x + t.w)) / step;
	if (ti >= 0.0 && ti < 1.0)
	{
		if (ti < 0.0 && ((s.x + s.w) <= t.x || s.x >= (t.x + t.w)))
			return (1.0);
		return (ti);
	}
	return (1.0);
}

double	box_intersect(t_dvec step, t_box s, t_box t)
{
	t_dvec	ti;
	double	ati;

	ti.x = 1.0;
	ti.y = 1.0;
	if (step.x > 0.0)
		ti.x = ((s.x + s.w) - t.x) / step.x;
	else if (step.x < 0.0)
		ti.x = (s.x - (t.x + t.w)) / step.x;
	if (step.y > 0.0)
		ti.y = ((s.y + s.h) - t.y) / step.y;
	else if (step.y < 0.0)
		ti.y = (s.y - (t.y + t.h)) / step.y;
	ati = fmin(ti.x, ti.y);
	if ((ti.x >= 0.0 || ti.y >= 0.0) && (ti.x < 1.0 || ti.y < 1.0))
	{
		if (ti.x < 0.0 && ((s.x + s.w) <= t.x || s.x >= (t.x + t.w)))
			return (1.0);
		else if (ti.y < 0.0 && ((s.y + s.h) <= t.y || s.y >= (t.y + t.h)))
			return (1.0);
		return (ati);
	}
	return (1.0);
}

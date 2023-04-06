/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/06 08:31:20 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	clamp(double value, double min, double max)
{
	return (fmax(min, fmin(max, value)));
}

t_dvec	normalize(double x, double y)
{
	double	l;
	t_dvec	norm;

	norm.x = 0.0;
	norm.y = 0.0;
	l = sqrt((x * x) + (y * y));
	if (l != 0.0)
	{
		norm.x = x / l;
		norm.y = y / l;
	}
	return (norm);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:22:22 by evallee-          #+#    #+#             */
/*   Updated: 2023/04/03 18:21:26 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H
# include <stdint.h>
# include <math.h>
# include <stdbool.h>
# include "vector.h"

typedef struct s_box
{
	double		x;
	double		y;
	uint32_t	w;
	uint32_t	h;
}	t_box;

bool		box_check(t_dvec pos, t_uvec size, t_dvec tpos, t_uvec tsize);
double		box_intersect(t_dvec step, t_box s, t_box t);
double		box_intersect_v(double step, t_box s, t_box t);
double		box_intersect_h(double step, t_box s, t_box t);

#endif
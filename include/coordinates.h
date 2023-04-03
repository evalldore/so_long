/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:21:33 by evallee-          #+#    #+#             */
/*   Updated: 2023/04/03 18:21:41 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
# define COORDINATES_H
# include "vector.h"
# include "stdint.h"
# include "map.h"

t_uvec	pos_to_coords(double x, double y);
bool	line_coords(t_uvec start, t_uvec end, bool (*f)(uint32_t, uint32_t));

#endif
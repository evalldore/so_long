/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:05:12 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/01 18:13:24 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <math.h>
# include <stdint.h>
# include "vector.h"

double	clamp(double value, double min, double max);
t_dvec	normalize(double x, double y);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/01 23:22:44 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <libft.h>
# include <stddef.h>
# include <ecs.h>
# include <math.h>
# include "vector.h"
# include "entities.h"
# include "coordinates.h"
# include "assets.h"
# include "map.h"
# include "game.h"

# define WIDTH 512
# define HEIGHT 512

bool		sl_init(mlx_t *mlx);
void		sl_keys(mlx_key_data_t keydata, void *params);
void		sl_tick(void *params);
void		sl_exit(void);

#endif
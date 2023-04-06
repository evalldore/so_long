/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/06 08:41:55 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <MLX42/MLX42.h>
# include "vector.h"
# include "entities.h"
# include "coordinates.h"
# include "assets.h"
# include "map.h"
# include "game.h"
# include "moves.h"

bool		sl_init(void *params);
void		sl_keys(mlx_key_data_t keydata, void *params);
void		sl_tick(void *params);
void		sl_exit(void);
void		sl_addmoves(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:46:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 04:01:25 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdint.h>
# include <libft.h>
# include "map.h"
# include "entities.h"
# include "coordinates.h"
# include "so_long.h"

typedef struct s_gamestate
{
	uint32_t	player;
	uint32_t	collected;
	uint32_t	moves;
}	t_gamestate;

t_gamestate		game_get(void);
void			game_add_collectible(void);
void			game_add_player(t_uvec start);
void			game_tick(void	*params);
void			game_set_tile(uint32_t x, uint32_t y, char c, va_list args);

#endif
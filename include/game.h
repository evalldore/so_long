/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:46:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/02 00:37:36 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdint.h>
# include <libft.h>
# include "map.h"
# include "entities.h"

typedef struct s_gamestate
{
	uint32_t	player;
	uint32_t	collected;
	uint32_t	moves;
}	t_gamestate;

t_gamestate		game_get(void);
void			game_add_collectible();
void			game_add_player(t_uvec start);

#endif
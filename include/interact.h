/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:15:00 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 04:02:25 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACT_H
# define INTERACT_H
# include <stdint.h>
# include "entities.h"
# include "assets.h"
# include "game.h"
# include "so_long.h"

void		interact(void *params, uint32_t ent1, uint32_t ent2);
void		shoot(uint32_t	player);

#endif
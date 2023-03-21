/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:11:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/20 05:30:40 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*map_load(map_t *map_data, const char	*path)
{
	int		fd;
	bool	map_loaded;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_loaded = false;
	while (!map_loaded)
	{
		line = ft_get_next_line(fd);
		map_loaded = (line == NULL);
		if (map_loaded)
			break;
	}
	close(fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:11:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 21:12:13 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_content(t_mapcheck *mapcheck, char *content, size_t *len)
{
	*len = 0;
	while (content[*len] && content[*len] != '\n')
	{
		if (content[*len] == 'P')
		{
			if (!mapcheck->has_start)
				mapcheck->has_start = true;
			else
				return (false);
		}
		if (content[*len] == 'E' && !mapcheck->has_exit)
		{
			if (!mapcheck->has_exit)
				mapcheck->has_exit = true;
			else
				return (false);
		}
		if (content[*len] == 'C')
			mapcheck->collectibles++;
		*len += 1;
	}
	return (false);
}

static bool	init_map(map_t *map_data, t_list *list)
{
	t_mapcheck		mapcheck;
	t_list			*temp;
	char			*content;
	size_t			len;
	(void)map_data;
	while (list)
	{
		temp = list;
		content = list->content;
		check_content(&mapcheck, content, &len);
		if (mapcheck.x == 0)
			mapcheck.x = len;
		// if (mapcheck.x != len)
		// 	ft_lstclear(&list, &free);
		// else
			list = list->next;
		ft_lstdelone(temp, &free);
		mapcheck.y++;
	}
	return (true);
}

bool	map_load(map_t *map_data, const char	*path)
{
	int		fd;
	t_list	*list;
	t_list	*new;
	char	*line;

	fd = open(path, O_RDONLY);
	(void)map_data;
	if (fd < 0)
		return (NULL);
	list = NULL;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		if (!new)
			break ;
		ft_lstadd_back(&list, new);
	}
	close(fd);
	return (init_map(map_data, list));
}

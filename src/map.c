/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:11:34 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 01:51:00 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	g_map;

static bool	check_line(t_mapcheck *check, char	*line)
{
	check->len = 0;
	while(line[check->len] && line[check->len] != '\n')
	{
		if (line[check->len] == 'P')
		{
			if (!check->has_start)
				check->has_start = true;
			else
				return (false);
		}
		if (line[check->len] == 'E')
		{
			if (!check->has_exit)
				check->has_exit = true;
			else
				return (false);
		}
		if (line[check->len] == 'C')
			check->collectibles++;
		check->len++;
	}
	return (true);
}

static bool	map_init(t_list *list)
{
	size_t	index;

	index = 0;
	g_map.dim_x = ft_strlen(list->content);
	g_map.dim_y = ft_lstsize(list);
	g_map.data = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	while (list)
	{
		g_map.data[index] = list->content;
		if (ft_strchr(list->content, 'P'))
		{
			g_map.start.x = ft_strchr(list->content, 'P') - (char *)(list->content);
			g_map.start.y = index;
		}
		if (ft_strchr(list->content, 'E'))
		{
			g_map.end.x = ft_strchr(list->content, 'E') - (char *)(list->content);
			g_map.end.y = index;
		}
		index++;
		list = list->next;
	}
	g_map.data[index] = NULL;
	ft_printf("dim x: %d\ndim y: %d\nstart x: %d\nstart y: %d\nend x :%d\nend y:%d\n", g_map.dim_x, g_map.dim_y, g_map.start.x, g_map.start.y);
	return (true);
}

t_map	map_get()
{
	return (g_map);
}

bool	map_load(char *path)
{
	static t_mapcheck	check;
	t_list				*list;
	t_list				*curr;

	list = parse_file(path);
	if (!list)
		return (false);
	curr = list;
	while (curr)
	{
		if (check_line(&check, curr->content))
		{
			curr = curr->next;
			continue ;
		}
		ft_lstclear(&list, &free);
		break;
	}
	if (list)
		return (map_init(list));
	return (false);
}

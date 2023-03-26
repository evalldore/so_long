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

static bool	check_line(t_linecheck *check, char	*line)
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

static bool	map_init(map_t *map_data, t_list *list)
{
	size_t	index;

	index = 0;
	map_data->dim_x = ft_strlen(list->content);
	map_data->dim_y = ft_lstsize(list);
	map_data->data = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	while (list)
	{
		map_data->data[index++] = list->content;
		list = list->next;
	}
	map_data->data[index] = NULL;
	ft_printf("dim x: %d\ndim y: %d\n", map_data->dim_x, map_data->dim_y);
	return (true);
}

bool	map_load(map_t *map_data, const char	*path)
{
	static t_linecheck	check;
	int					fd;
	char				*line;
	t_list				*list;
	t_list				*new;

	fd = open(path, O_RDONLY);
	list = NULL;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (check_line(&check, line))
		{
			new = ft_lstnew(line);
			if (new)
			{
				ft_lstadd_back(&list, new);
				continue ;
			}
		}
		free(line);
		ft_lstclear(&list, &free);
		break;
	}
	close(fd);
	if (list)
		return (map_init(map_data, list));
	return (false);
}

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

bool	map_load(map_t *map_data, const char	*path)
{
	static t_linecheck	check;
	int					fd;
	char				*line;
	t_list				*list;
	t_list				*new;

	fd = open(path, O_RDONLY);
	(void)map_data;
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
		ft_lstclear(&list, &free);
		break;
	}
	close(fd);
	if (list)
		ft_printf("woah\n");
	return (false);
}

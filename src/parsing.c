/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:56:16 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 18:15:32 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*parse_line(int fd, char **line)
{
	*line = ft_get_next_line(fd);
	return (*line);
}

t_list	*parse_file(char	*path)
{
	int			fd;
	t_list		*list;
	t_list		*new;
	char		*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	list = NULL;
	while (parse_line(fd, &line))
	{
		new = ft_lstnew(line);
		if (new)
		{
			ft_lstadd_back(&list, new);
			continue ;
		}
		free(line);
		ft_lstclear(&list, &free);
		break ;
	}
	close(fd);
	return (list);
}

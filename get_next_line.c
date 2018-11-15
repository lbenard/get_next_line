/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:13:57 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/15 08:00:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int	fd_cmp(const void *fd, const void *list)
{
	return (ft_memcmp(fd, list, sizeof(int)));
}

int	get_line(t_fd *fd, char **line)
{
	t_list	*buffer_list;
	t_list	*last_list;
	char	last_buffer[BUFF_SIZE + 1];
	ssize_t	read_size;
	size_t	chr_len;

	buffer_list = ft_lstnew(fd->buffer, ft_strlen(fd->buffer));
	last_list = buffer_list;
	fd->buffer[0] = 0;
	while (!ft_strchr((char*)last_list->content, '\n'))
	{
		if ((read_size = read(fd->fd, last_buffer, BUFF_SIZE)) == 0)
			break ;
		last_buffer[read_size] = 0;
		last_list = ft_lstpushback(&last_list,
			ft_lstnew(last_buffer, read_size + 1));
	}
	fd->buffer[0] = 0;
	*line = ft_lststrjoin(buffer_list, "");
	chr_len = ft_strchr(*line, '\n') - *line;
	(*line)[chr_len] = 0;
	printf("%s\n", *line);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*fd_list = NULL;
	t_list			*find;
	t_fd			new_fd;

	if (!line)
		return (-1);
	new_fd.fd = fd;
	new_fd.buffer[0] = 0;
	if (!fd_list)
	{
		fd_list = ft_lstnew(&new_fd, sizeof(t_fd));
		find = fd_list;
	}
	else if (!(find = ft_lstfind(fd_list, &fd, fd_cmp)))
		ft_lstadd(&fd_list, (find = ft_lstnew(&new_fd, sizeof(t_fd))));
	return (get_line(find->content, line));
}

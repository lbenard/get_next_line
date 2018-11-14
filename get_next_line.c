/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:13:57 by lbenard           #+#    #+#             */
/*   Updated: 2018/11/14 09:51:40 by lbenard          ###   ########.fr       */
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
	char	*buffer;
	char	*tmp;
	char	*chr;
	ssize_t	size;
	size_t	str_size;

	buffer = NULL;
	while (!(chr = ft_strchr(fd->buffer, '\n')))
	{
		tmp = buffer;
		if (tmp)
		{
			buffer = ft_strjoin(buffer, fd->buffer);
			printf("strjoin (%s, %s) = %s\n", tmp, fd->buffer, buffer);
			free(tmp);
		}
		else
			buffer = ft_strdup(fd->buffer);
		size = read(fd->fd, fd->buffer, BUFF_SIZE);
		if (size < 0)
		{
			free(buffer);
			return (ERROR);
		}
		fd->buffer[size] = 0;
		if (size == 0)
			break ;
	}
	if (!chr && ft_strlen(buffer) == 0)
		return (READ_FINISH);
	str_size = chr - fd->buffer;
	if (!(buffer = ft_strnew(ft_strlen(buffer) + str_size + 1)))
		return (ERROR);
	
	ft_strcpy(fd->buffer, chr + 1);
	*line = buffer;
	return (LINE_READ);
}

int	get_line(t_fd *fd, char **line)
{
	t_list	*buffers;

	while (
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

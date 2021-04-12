/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:19:24 by pherranz          #+#    #+#             */
/*   Updated: 2021/03/26 12:19:40 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_control(ssize_t nbytes, char **text, char **line)
{
	if (nbytes < 0 || (!nbytes && !*text))
	{
		if (nbytes < 0)
		{
			if (*text)
			{
				free(*text);
				*text = NULL;
			}
			return (-1);
		}
		*line = ft_strdup("");
	}
	else if (ft_strchr(*text, '\0'))
	{
		*line = ft_strdup(*text);
		free(*text);
		*text = NULL;
		return (0);
	}
	return (0);
}

static char	*ft_text(char *buffer, char *text)
{
	char	*aux;

	if (!text)
	{
		text = ft_strdup(buffer);
		return (text);
	}
	aux = ft_strjoin(text, buffer);
	free(text);
	text = 0;
	text = aux;
	return (text);
}

int	ft_output(char nbytes, char **text, char **line)
{
	char	*aux;
	char	*aux2;

	aux = ft_strchr(*text, '\n');
	if (aux)
	{
		*aux = '\0';
		*line = ft_strdup(*text);
		aux2 = ft_strdup(aux + 1);
		free(*text);
		*text = aux2;
		return (1);
	}
	if (ft_strchr(*text, '\0'))
		return (ft_control(nbytes, &*text, &*line));
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*text[4096];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		nbytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buffer[nbytes] = '\0';
		text[fd] = ft_text(buffer, text[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	if ((!nbytes && !text[fd]) || nbytes < 0)
		return (ft_control(nbytes, &text[fd], &*line));
	return (ft_output(nbytes, &text[fd], &*line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:01:15 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 12:01:16 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

static char	*return_val_norm(int fd)
{
	close(fd);
	return (NULL);
}

char		*get_stage(char *filename)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		ret;
	char	*res;
	char	*tmp;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror(filename);
		return (NULL);
	}
	if ((res = ft_strnew(1)) == NULL)
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[ret] = '\0';
		tmp = res;
		if ((res = ft_strjoin(res, buff)) == NULL)
			return (return_val_norm(fd));
		free(tmp);
	}
	close(fd);
	return (res);
}

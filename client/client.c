/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:52:42 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:58:09 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/client.h"

static void	ft_print_error(char *str, int kill)
{
	int		fucking_norminette_she_sucks;

	(void)fucking_norminette_she_sucks;
	ft_printf("%rerror: %s\n", str);
	if (kill)
		_exit(kill);
}

static int	init_socket(int sockfd, int port)
{
	struct sockaddr_in	this;

	bzero(&this, sizeof(this));
	this.sin_family = AF_INET;
	this.sin_port = htons(port);
	this.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&this, sizeof(this)) < 0)
	{
		printf("Server could not init the connection\n");
		return (-1);
	}
	if (listen(sockfd, 1) < 0)
	{
		printf("Server could not listen\n");
		return (-1);
	}
	return (0);
}

static void	v_child(int newsockfd, int sockfd)
{
	close(sockfd);
	compute(newsockfd);
	close(newsockfd);
	exit(0);
}

static void	loop_listen(socklen_t lg, int sockfd)
{
	int					newsockfd;
	struct sockaddr_in	that;
	pid_t				pid;
	int					ret;

	while (1)
	{
		ret = -1;
		newsockfd = accept(sockfd, (struct sockaddr *)(&that), &lg);
		if (newsockfd < 0)
			ft_print_error("Fail to accept new connection\n", 0);
		else
		{
			if ((pid = fork()) < 0)
				ft_print_error("fork error\n", 1);
			if (pid == 0)
				v_child(newsockfd, sockfd);
			else
				new_file_for_norme(newsockfd, &ret);
			ft_printf("Compute end with status: %d\n", ret);
		}
	}
	close(sockfd);
}

int			ft_listen(int port)
{
	int					sockfd;
	socklen_t			lg;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		ft_printf("%rServer could not init socket\n");
		return (-1);
	}
	if (init_socket(sockfd, port) < 0)
		return (-1);
	lg = (socklen_t)sizeof(struct sockaddr_in);
	loop_listen(lg, sockfd);
	return (0);
}

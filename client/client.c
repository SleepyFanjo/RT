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
	printf("error: %s\n", str);
	if (kill)
		_exit(kill);
}

int		compute(int socketfd)
{
	char		buf[NET_BUFF_SIZE + 10];
	int			ret;
	char		*host;
	t_inf_exec	*inf;

	inf = malloc(sizeof(t_inf_exec));
	if ((ret = read(socketfd, buf, NET_BUFF_SIZE)) < 0)
	{
		perror("read");
		exit(1);
	}
	buf[ret] = '\0';
	host = strdup(buf);
	printf("Host connect: %s\n", host);
	host = getenv("HOST");
	if (host == NULL)
		host = ft_strdup("unknow\n");
	write(socketfd, host, strlen(host));
//	ft_printf("get stage\n");
	get_stage(socketfd);
//	ft_printf("get core\n");
	get_core(inf, socketfd);
//	ft_printf("calc\n");
	calc_multi_stage(socketfd, inf);
//	printf("inf: nb_th: %d, nb_tot_th: %d, nb_st_th: %d\n", inf->nb_th, inf->nb_tot_th, inf->nb_st_th);
	return (0);
}

static int		init_socket(int sockfd, int port)
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

static void		loop_listen(socklen_t lg, int sockfd)
{
	int					newsockfd;
	struct sockaddr_in	that;
	pid_t				pid;

	while (1)
	{
		newsockfd = accept(sockfd, (struct sockaddr *)(&that), &lg);
		if (newsockfd < 0)
			ft_print_error("Fail to accept new connection\n", 0);
		else
		{
			if ((pid = fork()) < 0)
				ft_print_error("fork error\n", 1);
			if (pid == 0)
			{
				close(sockfd);
				compute(newsockfd);
				close(newsockfd);
				close(sockfd);
				exit(0);
			}
			else
				wait(NULL);
			printf("close sockfd\n");
			close(newsockfd);
			close(sockfd);
			exit(0);
		}
	}
}

int				ft_listen(int port)
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

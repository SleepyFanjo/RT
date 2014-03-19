#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
# define BUFF_SIZE 4096

static void	ft_print_error(char *str, int kill)
{
	printf("error: %s\n", str);
	if (kill)
		_exit(kill);
}

int		compute(int socketfd)
{
	char		buf[BUFF_SIZE + 10];
	int			ret;
	char		*host;
    
	if ((ret = read(socketfd, buf, BUFF_SIZE)) < 0)
	{
		perror("read");
		exit(1);
	}
	buf[ret] = '\0';
	host = strdup(buf);
	printf("Host: %s\n", host);
	host = getenv("HOST");
	write(socketfd, host, strlen(host));
	return (0);
}

int		ft_listen(int port)
{
	struct sockaddr_in	this;
	int					sockfd;
	int					newsockfd;
	socklen_t			lg;
	struct sockaddr_in	that;
	pid_t				pid;
    
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		printf("Server could not init socket\n");
		return (-1);
	}
	bzero(&this, sizeof(this));
	this.sin_family = AF_INET;
	this.sin_port = htons(port);
	this.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&this, sizeof(this)) < 0)
	{
		printf("Server could not init the connection\n");
		return (-1);
	}
	if (listen(sockfd, 5) < 0)
	{
		printf("Server could not listen\n");
		return (-1);
	}
	lg = (socklen_t)sizeof(that);
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
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	ft_listen(atoi(argv[1]));
	return (0);
}

#include "client.h"

static void	write_img(char *stage, int size, int sockfd)
{
	int		fd;
	int		ret;

	if ((fd = open(NAME_STAGE, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		ret = STAGE_FAIL;
		send_message(sockfd, sizeof(int), (void *)(&ret));
		close(sockfd);
		exit(1);
	}
	write(fd, stage, size);
	close(fd);
}

static void	get_content(int fd, int size)
{
	char	*stage;
	int		ret;

	stage = malloc(sizeof(char) * (size + 10));
	if ((ret = read(fd, stage, size)) != size)
	{
		ret = STAGE_FAIL;
		send_message(fd, sizeof(int), (void *)(&ret));
		exit(1);
	}
	write_img(stage, size, fd);
	ret = STAGE_SUCCES;
	send_message(fd, sizeof(int), (void *)(&ret));
}

void		get_stage(int fd)
{
	int		size;
	int		ret;

	if ((ret = read(fd, &size, sizeof(int))) != sizeof(int))
	{
		ret = SIZE_FAIL;
		send_message(fd, sizeof(int), (void *)(&ret));
		exit(1);
	}
	ret = SIZE_SUCCES;
	send_message(fd, sizeof(int), (void *)(&ret));
	get_content(fd, size);
}

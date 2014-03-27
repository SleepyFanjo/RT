#include "client.h"

static int	get_fd_img(int sockfd)
{
	int		fd;
	int		ret;

	if ((fd = open(NAME_STAGE, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		ret = STAGE_FAIL;
		ft_printf("%19\n");
		send_message(sockfd, sizeof(int), (void *)(&ret));
		close(sockfd);
		exit(1);
	}
	return (fd);
}

static void	v_fail(int sockfd)
{
	int		ret;

	ret = STAGE_FAIL;
	ft_printf("%r18\n");
	send_message(sockfd, sizeof(int), (void *)(&ret));
	close(sockfd);
	exit(1);
}

static void	get_stage_read(int sockfd, int size)
{
	char		*buff;
	int			pos;
	int			ret;
	int			ask_size;
	int			fd;

	buff = malloc(sizeof(char) * (BUFF_SIZE + 10));
	pos = 0;
	fd = get_fd_img(sockfd);
	while (pos < size)
	{
		ask_size = size - pos;
		if (ask_size > BUFF_SIZE)
			ask_size = BUFF_SIZE;
		ret = read(sockfd, buff, ask_size);
		if (ret < 0)
			v_fail(sockfd);
		write(fd, buff, ret);
		pos += ret;
	}
	close(fd);
}

static void	get_content(int fd, int size)
{
	int		ret;

	get_stage_read(fd, size);
	ret = STAGE_SUCCES;
	send_message(fd, sizeof(int), (void *)(&ret));
}

void		get_stage(int fd)
{
	int		size;
	int		ret;

	if ((ret = read(fd, &size, sizeof(int))) != sizeof(int))
	{
		ft_printf("%rFail #2\n");
		ret = SIZE_FAIL;
		send_message(fd, sizeof(int), (void *)(&ret));
		exit(1);
	}
	ret = SIZE_SUCCES;
	send_message(fd, sizeof(int), (void *)(&ret));
	get_content(fd, size);
}

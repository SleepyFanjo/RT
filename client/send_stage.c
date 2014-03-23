#include "../includes/client.h"

void		send_stage(int sockfd, t_param *p, int start, int end)
{
	int		pos;
	int		size;
	t_img	*img;
	int		ret;
	int		test;
	char	*addr;

	pos = 0;
	test = 0;
	img = &(p->v_img);
	ft_printf("img->bpp: %d\n", img->line);
	size = end - start;
	ft_printf("send stage(size: %d)\n", size);
	ft_printf("Height: %d, W: %d\n", HEIGHT, WIDTH);
	addr = img->addr + start;
	while (pos < size)
	{
		ft_printf("start loop\n");
		ret = write(sockfd, addr + pos, size - pos);
		ft_printf("loop, ret: %d\n");
		if (ret < 0)
		{
			perror("#9");
			exit(9);
		}
		if (ret == 0)
			test++;
		if (test == LIM_NB_WRITE)
		{
			ft_printf("%r#10\n");
			exit(10);
		}
		pos += ret;
	}
}

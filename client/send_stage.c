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
	size = end - start;
	addr = img->addr + start;
	while (pos < size)
	{
		ret = write(sockfd, addr + pos, size - pos);
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

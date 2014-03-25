#include "../includes/client.h"

static int	get_serv_text(int sockfd, void *dest, int size)
{
	int			pos;
	int			ret;
	int			ask_size;

	pos = 0;
	while (pos < size)
	{
		ask_size = size - pos;
		if (ask_size > BUFF_SIZE)
			ask_size = BUFF_SIZE;
		ret = read(sockfd, dest + pos, ask_size);
		if (ret < 0)
			return (-1);
		pos += ret;
	}
	return (0);
}

static int	get_serv_tex(int sockfd, t_textures **tex)
{
	int			i;
	t_textures	*my_tex;
	int			size;

	i = 0;
	*tex = (t_textures *)j_malloc(sizeof(t_textures) * NB_T);
	my_tex = *tex;
	while (i < NB_T)
	{
		if (get_serv_text(sockfd, my_tex + i, sizeof(t_textures)) < 0)
			return (-1);
		size = my_tex[i].sizeline * my_tex[i].size_y;
		printf("size: %d\n", size);
		my_tex[i].data = j_malloc(size);
		if (get_serv_text(sockfd, my_tex[i].data, size) < 0)
			return (-1);
		i++;
	}
	return (0);
}

void		get_env(int sockfd, t_img *img, t_textures **tex)
{
	int		send;
	int		*decrgb;

	decrgb = j_malloc(sizeof(int) * 6);
	img->endian = -1;
	if (get_value(sockfd, img, sizeof(t_img)) < 0)
	{
		ft_printf("%rError: #14\n");
		exit(14);
	}
	if (get_value(sockfd, decrgb, sizeof(int) * 6) < 0)
	{
		ft_printf("%rError: #14\n");
		exit(14);
	}
	img->decrgb = decrgb;
	if (get_serv_tex(sockfd, tex) < 0)
	{
		ft_printf("%rError: #24\n");
		exit(24);
	}
	send = SIZE_SUCCES;
	send_message(sockfd, sizeof(int), &send);
}

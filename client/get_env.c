#include "../includes/client.h"

void		get_env(int sockfd, t_img *img)
{
	int		send;

	img->endian = -1;
	if (get_value(sockfd, img, sizeof(t_img)) < 0)
	{
		ft_printf("%rError: %14\n");
		exit(14);
	}
	send = SIZE_SUCCES;
	send_message(sockfd, sizeof(int), &send);
	ft_printf("env: bpp: %d line: %d endian: %d\n", img->bpp, img->line, img->endian);
}

#include "../includes/client.h"

void		get_env(int sockfd, t_img *img)
{
	int		send;
	int		*decrgb;

	decrgb = j_malloc(sizeof(int) * 6);
	img->endian = -1;
	if (get_value(sockfd, img, sizeof(t_img)) < 0)
	{
		ft_printf("%rError: %14\n");
		exit(14);
	}
	if (get_value(sockfd, decrgb, sizeof(int) * 6) < 0)
	{
		ft_printf("%rError: %14\n");
		exit(14);
	}
	img->decrgb = decrgb;
	send = SIZE_SUCCES;
	send_message(sockfd, sizeof(int), &send);
}

#include "../includes/network.h"
#include "../includes/define.h"

static void	send_stage_cl(t_client *cl, t_info_serv *inf)
{
	int		fd;
	int		buf;

	buf = -1;
	fd = cl->sockfd;
	if (send_message(fd, sizeof(int), (void *)(&(inf->size_stage))) < 0)
		return ;
	read(fd, &buf, sizeof(int));
	if (buf != SIZE_SUCCES)
	{
		ft_printf("Fail\n");
		return ;
	}
	if (send_long_message(fd, inf->stage, inf->size_stage) < 0)
		return ;
	read(fd, &buf, sizeof(int));
	if (buf != STAGE_SUCCES)
	{
		ft_printf("Fail again and again\n");
		return ;
	}
}

int			send_stage(t_info_serv *inf, t_list *lst)
{
	inf->size_stage = ft_strlen(inf->stage);
	while (lst != NULL)
	{
		send_stage_cl((t_client *)lst->content, inf);
		lst = lst->next;
	}
	return (0);
}

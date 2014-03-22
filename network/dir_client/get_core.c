#include "client.h"

int		get_core(t_inf_exec *inf, int sockfd)
{
	int		ret;

	if ((ret = read(sockfd, inf, sizeof(t_inf_exec))) != sizeof(t_inf_exec))
	{
		ft_printf("%rNot receive full exec information\n");
		close(sockfd);
		exit(1);
	}
	return (0);
}

#include "../network.h"

int		send_message(int fd, size_t size, void *mess)
{
	if (write(fd, mess, size) < 0)
	{
		ft_printf("%rFail to communicate with the server\n");
		close(fd);
		return (1);
	}
	return (0);
}

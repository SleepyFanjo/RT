#include "../includes/client.h"

int		compute(int socketfd)
{
	char		buf[NET_BUFF_SIZE + 10];
	int			ret;
	char		*host;
	t_inf_exec	*inf;
	t_img		img;
	t_textures	*tex;

	inf = j_malloc(sizeof(t_inf_exec));
	if ((ret = read(socketfd, buf, NET_BUFF_SIZE)) < 0)
	{
		perror("read");
		exit(1);
	}
	buf[ret] = '\0';
	host = strdup(buf);
	printf("Host connect: %s\n", host);
	host = getenv("HOST");
	if (host == NULL)
		host = ft_strdup("Unknow\n");
	write(socketfd, host, strlen(host));
	get_env(socketfd, &img, &tex);
	get_stage(socketfd);
	get_core(inf, socketfd);
	calc_multi_stage(socketfd, inf, &img, tex);
	return (0);
}

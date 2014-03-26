#include "client.h"

int		compute(int socketfd)
{
	char		buf[NET_BUFF_SIZE + 10];
	int			ret;
	char		*host;
	t_inf_env	*inf_env;

	inf_env = (t_inf_env *)j_malloc(sizeof(t_inf_env));
	inf_env->inf = j_malloc(sizeof(t_inf_exec));
	inf_env->img = (t_img *)j_malloc(sizeof(t_img));
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
	get_env(socketfd, inf_env);
	get_stage(socketfd);
	get_core(inf_env->inf, socketfd);
	calc_multi_stage(socketfd, inf_env);
	return (0);
}

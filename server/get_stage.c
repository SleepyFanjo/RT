#include "../includes/network.h"

char	*get_stage(char *filename)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		ret;
	char	*res;
	char	*tmp;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror(filename);
		return (NULL);
	}
	if ((res = ft_strnew(1)) == NULL)
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[ret] = '\0';
		tmp = res;
		if ((res = ft_strjoin(res, buff)) == NULL)
			return (NULL);
		free(tmp);
	}
	return (res);
}

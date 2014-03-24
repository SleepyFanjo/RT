#include "../includes/network.h"

static size_t	v_get_size_tab(char **tab)
{
	size_t		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

static void		my_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char			**get_tab(char *line)
{
	char		*str;
	char		**tab;

	if ((str = ft_strtrim(line)) == NULL)
		return (NULL);
	if ((tab = ft_strsplit(str, ':')) == NULL)
	{
		ft_printf("%rFail to split\n");
		free(str);
		return (NULL);
	}
	if (v_get_size_tab(tab) != 2)
	{
		ft_printf("Line %s: Bad syntax, host was not import\n", line);
		my_free_tab(tab);
		free(str);
		return (NULL);
	}
	free(str);
	return (tab);
}

static t_id_client	*get_pars_cl(char *line)
{
	char		**tab;
	t_id_client	*id_cl;
	int			port;

	if ((tab = get_tab(line)) == NULL)
		return (NULL);
	if ((port = ft_atoi(tab[1])) <= 1024 || port >= 65535)
	{
		ft_printf("%rLine %s: Need a port number > \
				1024 and < 65535, host was not import\n");
		my_free_tab(tab);
		return (NULL);
	}
	if ((id_cl = (t_id_client *)malloc(sizeof(t_id_client))) == NULL)
		exit(1);
	id_cl->ip = tab[0];
	id_cl->port = port;
	free(tab[1]);
	free(tab);
	return (id_cl);
}

void				get_lst_cl(char *filename, t_list **lst_id_cl)
{
	int			fd;
	int			ret;
	char		*line;
	t_id_client	*cl_id;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror(filename);
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '#')
		{
			free(line);
			continue ;
		}
		cl_id = get_pars_cl(line);
		if (cl_id != NULL)
			ft_lstadd(lst_id_cl, ft_lstnew((void *)cl_id, sizeof(t_id_client)));
		free(line);
	}
}

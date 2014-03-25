#include "../includes/network.h"

void		free_cl(t_list *lst_cl)
{
	t_list		*tmp;
	t_client	*cl;

	tmp = lst_cl;
	while (tmp != NULL)
	{
		cl = (t_client *)tmp->content;
		if (cl->name_host_server != NULL)
			free(cl->name_host_server);
		if (cl->name_host_cl != NULL)
			free(cl->name_host_cl);
		free(cl);
		tmp = tmp->next;
	}
	ft_lstdel(&lst_cl, lst_cl);
}

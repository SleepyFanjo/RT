/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cl_th.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:57:25 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 11:57:26 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.h"

static int		get_sockfd(char *addr_ip, int port)
{
	struct sockaddr_in	that;
	int					sockfd;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		ft_printf("%r\e[0;31mUnable to create socket\e[0;m\n");
		return (-1);
	}
	ft_bzero(&that, sizeof(that));
	that.sin_family = AF_INET;
	that.sin_port = htons(port);
	that.sin_addr.s_addr = inet_addr(addr_ip);
	if (connect(sockfd, (struct sockaddr *)(&that), sizeof(that)) < 0)
	{
		close(sockfd);
		ft_printf("%r\e[0;31mFail to open the socket\e[0;m\n");
		return (-1);
	}
	return (sockfd);
}

static int		cl_connect(t_client *cl, t_id_client *id_cl)
{
	int			ret;

	if ((cl->sockfd = get_sockfd(id_cl->ip, id_cl->port)) < 0)
		return (-1);
	ret = write(cl->sockfd, cl->name_host_server,
			ft_strlen(cl->name_host_server));
	if (ret < 0)
		return (-1);
	cl->name_host_cl = (char *)j_malloc(sizeof(char ) * (MAX_HOST_NAME + 1));
	if (cl->name_host_cl == NULL)
		return (-1);
	if ((ret = recv(cl->sockfd, cl->name_host_cl, MAX_HOST_NAME, 0)) < 0)
		return (-1);
	(cl->name_host_cl)[ret] = '\0';
	return (0);
}

static void		init_cl(t_client *cl, int id, t_info_serv *inf)
{
	cl->id = id;
	cl->name_host_server = inf->name_serv;
	cl->stage = inf->stage;
	cl->name_host_cl = NULL;
}

static t_client	*get_client(t_id_client *id_cl, t_info_serv *inf, int nb_cl)
{
	t_client		*cl;

	if ((cl = (t_client *)j_malloc(sizeof(t_client))) == NULL)
	{
		ft_printf("%rAllocation fail\n");
		exit(1);
	}
	init_cl(cl, nb_cl, inf);
	if (cl_connect(cl, id_cl) < 0)
		return (NULL);
	return (cl);
}

int		get_cl_th(t_list **lst_th, t_list *lst_cl, t_info_serv *inf)
{
	int			nb_cl;
	t_client	*elem;
	t_id_client	*cl_id;
	int			nb_cl_connected;

	nb_cl = 0;
	nb_cl_connected = 0;
	while (lst_cl != NULL)
	{
		cl_id = (t_id_client *)lst_cl->content;
		ft_printf("Try connection, ip: %s:%d\n", cl_id->ip, cl_id->port);
		elem = get_client(cl_id, inf, nb_cl);
		if (elem != NULL)
		{
			ft_lstadd(lst_th, ft_lstnew((void *)elem, sizeof(t_client)));
			nb_cl_connected++;
			ft_printf("\e[0;32mDone\e[0;m\n");
		}
		lst_cl = lst_cl->next;
		nb_cl++;
	}
	ft_printf("%d/%d clients connected\n", nb_cl_connected, nb_cl);
	return (nb_cl_connected);
}

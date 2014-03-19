#ifndef NETWORK_H
# define NETWORK_H

# include "raytracer.h"
# include <pthread.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>

# define WIDTH			1024
# define HEIGHT			1024
# define MAX_HOST_NAME	4095

typedef struct		s_nb_th
{
	int				nb_tot;
	int				nb_start;
	int				nb_to_calc;
}					t_nb_th;

typedef struct		s_client
{
	int				id;
	pthread_t		th;
	t_nb_th			nb_th;
	int				*size_img;
	char			*name_host_server;
	char			*name_host_cl;
	char			*stage;
	int				sockfd;
	int				*th_com;
	pthread_mutex_t	*lock_th_com;
}					t_client;

typedef struct		s_info_serv
{
	int				size_img[2];
	int				nb_th;
	int				th_com[2];
	char			*stage;
	char			*name_serv;
}					t_info_serv;

typedef struct		s_id_client
{
	char			*ip;
	int				port;
}					t_id_client;

char	*get_stage(char *filename);
void	get_lst_cl(char *filename, t_list **lst_id_cl);
void	get_cl_th(t_list **lst_th, t_list *lst_cl, t_info_serv *inf);

#endif

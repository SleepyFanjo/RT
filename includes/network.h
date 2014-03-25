#ifndef NETWORK_H
# define NETWORK_H

# include "raytracer.h"
# include <pthread.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <X11/Xlib.h>
# include "define.h"

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
	t_nb_th			nb_th;
	char			*name_host_server;
	char			*name_host_cl;
	char			*stage;
	int				sockfd;
	int				lim;
	int				size;
	int				start;
	int				end;
}					t_client;

typedef struct		s_info_serv
{
	int				nb_th;
	int				th_com[2];
	char			*stage;
	int				size_stage;
	char			*name_serv;
	t_list			*fail_cl;
}					t_info_serv;

typedef struct		s_id_client
{
	char			*ip;
	int				port;
}					t_id_client;

typedef struct		s_v_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line;
	int				endian;
	t_textures		text[NB_T];
	t_param			*p;
	t_info_serv		*inf;
	t_list			*lst_id_cl;
}					t_v_env;

typedef struct	s_my_mlx
{
    Display		*display;
    Window		root;
    int			screen;
    int			depth;
    Visual		*visual;
    Colormap	cmap;
    int			private_cmap;
    void		*win_list;
    int			(*loop_hook)();
    void		*loop_param;
    int			use_xshm;
    int			pshm_format;
    int			do_flush;
    int			decrgb[6];
}				t_my_mlx;

char	*get_stage(char *filename);
void	get_lst_cl(char *filename, t_list **lst_id_cl);
int		get_cl_th(t_list **lst_th, t_list *lst_cl, t_info_serv *inf);
int		send_message(int fd, size_t size, void *mess);
int		send_stage(t_info_serv *inf, t_list *lst);
int		send_inf_calc(t_list *list, t_info_serv *inf, int nb_cl);
void	init_env(t_v_env *env);
int		get_value(int fd, void *buf, size_t size);
void	send_env(t_list *lst, t_v_env *e);
void	get_cl_stage(t_list *lst_th, t_v_env *env);
int		key_hook(int keycode, t_v_env *e);
int		expose_hook(void *env);
int		mouse_hook(int button, int x, int y, t_v_env *e);
void	free_cl(t_list *lst_cl);
void	*j_malloc(size_t size);
void	get_textures(t_v_env *param, void *e);
int		send_long_message(int sockfd, void *mess, int size);
void	calc_img(t_list *lst_host, t_info_serv *inf, t_v_env *e);

#endif

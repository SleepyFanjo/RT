#ifndef CLIENT_H
# define CLIENT_H

# include "define.h"
# include "raytracer.h"

void		send_message(int fd, size_t size, void *mess);
void		send_stage(int sockfd, t_param *p, int start, int end);
int			get_value(int fd, void *buf, size_t size);

void		get_stage(int fd);
int			get_core(t_inf_exec *inf, int sockfd);
void		calc_multi_stage(int socketfd, t_inf_exec *inf, t_img *img);

#endif

#ifndef CLIENT_H
# define CLIENT_H

# include "define.h"
# include "raytracer.h"

void		send_message(int fd, size_t size, void *mess);
void		get_stage(int fd);
int			get_core(t_inf_exec *inf, int sockfd);

#endif

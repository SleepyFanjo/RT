/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:59:41 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 10:59:43 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "define.h"
# include "raytracer.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <X11/Xlib.h>

void		send_message(int fd, size_t size, void *mess);
void		send_stage(int sockfd, t_param *p, int start, int end);
int			get_value(int fd, void *buf, size_t size);

void		get_stage(int fd);
int			get_core(t_inf_exec *inf, int sockfd);
void		calc_multi_stage(int sockfd, t_inf_env *inf_env);
int			my_mlx_get_color_value(int color, int *decrgb, int depth);

int			compute(int socketfd);
void		new_file_for_norme(int newsockfd, int *status);

#endif

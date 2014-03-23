#ifndef DEFINE_H
# define DEFINE_H

# define SIZE_FAIL		0
# define SIZE_SUCCES	1
# define STAGE_FAIL		2
# define STAGE_SUCCES	3
# define MOD_CLIENT		0

# define NAME_STAGE		"stage.tmp"
# define NET_BUFF_SIZE	1000000
# define LIM_NB_WRITE	10
# define LIM_NB_READ	10

typedef struct	s_inf_exec
{
	int			nb_th;
	int			nb_tot_th;
	int			nb_st_th;
}				t_inf_exec;

#endif

#include "raytracer.h"

static void		getobjln(t_obj *o, char *ln, int (*f)(t_obj *, char *), int nb)
{
	if (f(o, ln) < 0)
	{
		ft_printf("%rUnable to get line ");
		ft_printf("%r%d: ", nb);
		ft_printf("%r%s\n", ln);
	}
}

static void		get_obj_cd(int cur_obj, t_obj *obj, char *line, int n_l)
{
	if (cur_obj == CD_SPHERE)
		getobjln(obj, line, get_sphere, n_l);
	else if (cur_obj == CD_PLAN)
		getobjln(obj, line, get_plan, n_l);
	else if (cur_obj == CD_SPOT)
		getobjln(obj, line, get_spot, n_l);
	else if (cur_obj == CD_CAM)
		getobjln(obj, line, get_cam, n_l);
	else if (cur_obj == CD_CYLINDER)
		getobjln(obj, line, get_cylinder, n_l);
	else if (cur_obj == CD_CONE)
		getobjln(obj, line, get_cone, n_l);
}

static void		loop_get_struct(t_var_parser *var)
{
	if ((var->ret = get_type_obj(var->line)) == CD_ERROR)
	{
		ft_printf("%rSyntax error at line %d\n", var->num_line);
		exit(1);
	}
	if (var->ret == CD_COM)
		return ;
	if (var->ret == CD_NOT_CMD && var->cur_obj > 0)
		get_obj_cd(var->cur_obj, var->obj, var->line, var->num_line);
	else
		var->cur_obj = var->ret;
}

static t_obj	*get_struct_obj(int fd)
{
	t_var_parser	var;

	var.num_line = 0;
	var.cur_obj = -1;
	var.obj = get_obj();
	while ((var.ret = get_next_line(fd, &(var.line))) > 0)
	{
		if (ft_strlen(var.line) == 0)
		{
			free(var.line);
			continue ;
		}
		(var.num_line) += 1;
		loop_get_struct(&var);
		free(var.line);
	}
	if (var.ret < 0)
		return (NULL);
	free(var.line);
	return (var.obj);
}

void	parser(char *filename, t_param *param)
{
	int		fd;
	t_obj	*obj;

	if ((fd = open(filename, O_RDONLY)) < 0)
		print_error(filename, "Unable to open the file\n");
	obj = get_struct_obj(fd);
	param->cylinder = obj->cylinder;
	param->plane = obj->plan;
	param->spot = obj->spot;
	param->sphere = obj->sphere;
	param->cone = obj->cone;
	if (obj->cam == NULL)
		print_error(filename, "Not find cam\n");
	param->cam = obj->cam->point;
	param->rot_cam = obj->cam->rot;
	calc_matrix((void *)param, CAM);
	bzero(&param->env, sizeof(t_env));
	param->text = NULL;
	close(fd);
}

#include <raytracer.h>


//thtfhfth
#include <stdio.h>
static void			init_struct(t_parse_mesh *e)
{
	t_mesh			*mesh;

	if ((mesh = (t_mesh *)malloc(sizeof(mesh))) == NULL)
		exit(0);
	e->i = 0;
	e->str = NULL;
	e->header = 1;
	e->nbr_ver = 0;
	e->nbr_face = 0;
	e->mesh = mesh;
}

int					l_error(char *str, int ret)
{
	ft_putendl_fd(str, 2);
	return (ret);
}

int					l_check_end(t_parse_mesh *e)
{
	int				nbr;
	int				i;

	e->header = 0;
	if (e->nbr_ver == 0 || e->nbr_face == 0)
		return (-1);
	nbr = e->nbr_ver / 3;
	e->nbr_ver = nbr;
	e->mesh->tri = (t_triangle **)j_malloc(sizeof(t_triangle *) * (nbr + 1));
	i = 0;
printf("nbr:%d", nbr);
	while(i < nbr)
	{
		(e->mesh->tri)[i] = NULL;
		i++;
	}
	e->nbr_face = 0;
	return (1);
}

void				v_clear_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int					get_info(t_parse_mesh *e, char *str)
{
	char			**tab;

	if (!(ft_strncmp(str, "format", 5)) || !(ft_strncmp(str, "comment", 7))
			|| !(ft_strncmp(str, "property", 8)))
		return (1);
printf("##%s\n", str);
	if (!(ft_strncmp(str, "end_header", 10)))
		return (l_check_end(e));
	tab = ft_strsplit(str, ' ');
	if (e->nbr_ver == 0)
		e->nbr_ver = ft_atoi(tab[2]);
	else if (e->nbr_face == 0)
		e->nbr_face = ft_atoi(tab[2]);
	v_clear_tab(tab);
	return (1);
}


void				l_putin_ver(double ver[3], char **tab)
{
	ver[0] = atof(tab[0]);
	ver[1] = atof(tab[1]);
	ver[2] = atof(tab[2]);
}

void				l_putin_norm(double ver[3], char **tab)
{
	ver[0] = atof(tab[3]);
	ver[1] = atof(tab[4]);
	ver[2] = atof(tab[5]);
}

void				get_vertex(t_parse_mesh *e, char **tab)
{
	int				mod;
	int				div;

	mod = e->nbr_face % 3;
	div = e->nbr_face / 3;
	if (TRI[div] == NULL)
		TRI[div] = (t_triangle *)j_malloc(sizeof(t_triangle));
	if (mod == 0)
	{
		l_putin_ver(TRI[div]->vert0, tab);
		l_putin_norm(TRI[div]->vecn, tab);
	}
	if (mod == 1)
		l_putin_ver(TRI[div]->vert1, tab);
	if (mod == 2)
		l_putin_ver(TRI[div]->vert2, tab);
}

int					do_the_ver_dance(t_parse_mesh *e, char *str)
{
	char			**tab;
	int				size;
	if ((tab = ft_strsplit(str, ' ')) == NULL)
		return (l_error("Couldn't split", 0));
	size = get_size_tab(tab);
int fd=open("YO", O_WRONLY | O_APPEND | O_CREAT, 0644);
ft_putnbr_fd(e->nbr_face, fd);
ft_putendl_fd("", fd);
close (fd);
	if (size == 6)
	{
		get_vertex(e, tab);
		e->nbr_face++;
	}
	else if (size == 4)
		e->i = 42;
	else
		return (l_error("Your file is wrong, GET THE HELL OUT OF HERE!!", 0));
	v_clear_tab(tab);
	return (1);
}

void		test_print(t_parse_mesh *e)
{
	int		i =0;

	while(TRI[i] != NULL)
		{
			printf("ligne %d\n", i);
			printf("%f %f %f %f %f %f\n %f %f %f\n%f %f %f\n", TRI[i]->vert0[0], TRI[i]->vert0[1]
		, TRI[i]->vert0[2], TRI[i]->vecn[0], TRI[i]->vecn[1], TRI[i]->vecn[2], TRI[i]->vert1[0]
		, TRI[i]->vert1[1], TRI[i]->vert1[2], TRI[i]->vert2[0], TRI[i]->vert2[1], TRI[i]->vert2[2]);
		i++;
		}
	}

int					get_mesh(t_obj *obj, char *line)
{
	int				ret;
	int				fd;
	t_parse_mesh	e;

	init_struct(&e);
	if ((fd = open(line, O_RDONLY)) == - 1)
		return (l_error("File not found", -1));
	while (e.i != 42 && (ret = get_next_line(fd, &e.str)) > 0)
	{
		if (e.i == 0)
		{
			e.i++;
			if (ft_strcmp(e.str, "ply") != 0)
				return (l_error("File is not a .ply", -1));
		}
		else
		{
			if (e.header)
			{
				if (!get_info(&e, e.str))
					return (l_error("Do not like your head...er", -1));
			}
			else if(e.nbr_face < (e.nbr_ver * 3))
			{
				if (!do_the_ver_dance(&e, e.str))
					return (l_error("You ain't got no rhythm", -1));
			}
		}
		free(e.str);
	}
	test_print(&e);
	ft_lstadd(&(obj->mesh), ft_lstnew(e.mesh, sizeof(t_mesh)));
	return (0);
}

int		main(void)
{
	t_obj *obj=NULL;
	char line[] = "3dmesh/susanne.ply";

	printf("retour de la fonction%d\n", get_mesh(obj, line));
	return (0);
}

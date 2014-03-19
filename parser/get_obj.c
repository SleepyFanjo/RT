#include "../raytracer.h"

static int		cmp_line(char *new_line)
{
	if (ft_strcmp(new_line, "sphere") == 0)
		return (CD_SPHERE);
	if (ft_strcmp(new_line, "plane") == 0)
		return (CD_PLAN);
	if (ft_strcmp(new_line, "spot") == 0)
		return (CD_SPOT);
	if (ft_strcmp(new_line, "cam") == 0)
		return (CD_CAM);
	if (ft_strcmp(new_line, "cylinder") == 0)
		return (CD_CYLINDER);
	if (ft_strcmp(new_line, "cone") == 0)
		return (CD_CONE);
	return (CD_ERROR);
}

int				get_type_obj(char *line)
{
	int		size;
	char	*new_line;

	new_line = ft_strtrim(line);
	if (new_line == NULL)
	{
		ft_printf("%rAllocation fail\n");
		exit(1);
	}
	size = ft_strlen(new_line);
	if (size == 0)
		return (CD_ERROR);
	if (line[0] == '#')
		return (CD_COM);
	if (ft_strncmp(new_line, "//", 2) != 0)
		return (CD_NOT_CMD);
	new_line += 2;
	return (cmp_line(new_line));
}

t_obj			*get_obj(void)
{
	t_obj		*res;

	if ((res = (t_obj *)malloc(sizeof(t_obj))) == NULL)
	{
		ft_printf("%rAllocation Fail\n");
		exit(1);
	}
	res->plan = NULL;
	res->cylinder = NULL;
	res->spot = NULL;
	res->sphere = NULL;
	res->cam = NULL;
	res->cone = NULL;
	return (res);
}

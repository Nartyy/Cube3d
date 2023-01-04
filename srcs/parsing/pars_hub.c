#include "../../includes/cube3d.h"

int	pars_hub2(t_system *sys, int s);
int	pars_hub3(t_system *sys);
int	verif_mapfile(t_system *sys);
int	verif_char(t_system *sys, int fd);

int	pars_hub(t_system *sys)
{
	if (sys->argc != 2)
	{
		printf("Usage : ./cube3D [name of map file]\n");
		return (-1);
	}
	else if (pars_hub2(sys, 1) == -1)
		return (-1);
	else if (verif_mapfile(sys) == -1)
		return(-1);
	else if (pars_hub2(sys, 2) == -1)
		return (-1);
	else if (pars_hub3(sys) == -1)
		return (-1);
	return (0);
}

int	verif_mapfile(t_system *sys)
{
	int	fd;

	fd = open(sys->mapfile, O_RDONLY);
	if (fd == -1)
	{
		printf("File can't be read !\n");
		return(-1);
	}
	if (verif_char(sys, fd) == -1)
		return (-1);
	return (0);
}

int	verif_line(t_system *sys)
{
	int	i;

	i = 0;
	while (sys->map[i])
		i++;
	if (i < 11)
	{
		free_char_tab(sys->map);
		printf("Error with format !\n");
		return (-1);
	}
	return (0);
}

int	verif_char(t_system *sys, int fd)
{
	int		i;
	int		j;
	int		k;
	char	buf[BUFFER_SIZE];

	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = 0;
	i = 8;
	sys->map = ft_split_cb(buf, '\n');
	if (verif_line(sys) == -1)
		return (-1);
	while (sys->map[i])
	{
		j = 0;
		while (sys->map[i][j])
		{
			k = 0;
			while (k <= NB_CHAR)
			{
				if (k == NB_CHAR)
				{
					free_char_tab(sys->map);
					printf("Not usable char in map !\n");
					return (-1);
				}
				if (sys->map[i][j] == sys->sprite[k])
					k = 100;
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
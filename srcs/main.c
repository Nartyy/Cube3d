#include "../includes/cube3d.h"

void	make_tab_char(char *tab)
{
	tab[0] = '0';
	tab[1] = '1';
	tab[2] = 'N';
	tab[3] = 'S';
	tab[4] = 'E';
	tab[5] = 'W';
	tab[6] = ' ';
}

void	free_all_cb(t_system *sys)
{
	free_char_tab(sys->play_map);
}

int	main(int argc, char **argv)
{
	t_system	sys;

	sys.argc = argc;
	sys.argv = argv;
	sys.mapfile = argv[1];
	make_tab_char(sys.sprite);
	if (pars_hub(&sys) == -1)
	{
		system("leaks cube3D");
		return (-1);
	}
	//free_all_cb(&sys);
	print_char_tab(sys.play_map);
	system("leaks cube3D");
	return (0);
}
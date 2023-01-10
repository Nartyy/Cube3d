/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:42 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/10 16:26:32 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	make_tab_char(char *tab);
int		exe_hub(t_system	*sys);

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
	exe_hub(&sys);
	system("leaks cube3D");
	return (0);
}
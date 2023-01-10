/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/10 16:23:30 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	enter_init_player_pos(t_player *player, int x, int z, char c)
{
	player->case_pos.x = x;
	player->case_pos.z = z;
	if (c == 'N')
		player->rotation = 0;
	else if (c == 'E')
		player->rotation = 90;
	else if (c == 'S')
		player->rotation = 180;
	else if (c == 'W')
		player->rotation = 270;
	player->pos.x = player->case_pos.x * Multiplier + (Multiplier / 2);
	player->pos.z = player->case_pos.z * Multiplier + (Multiplier / 2);
	player->pos.y = (Multiplier / 2);
}

void	init_player(t_player *player, char **map)
{
	int	x;
	int	z;

	player->case_pos.y = 0;
	x = 0;
	while (map[x])
	{
		z = 0;
		while (map[x][z])
		{
			if (map[x][z] == 'N' || map[x][z] == 'E'
				|| map[x][z] == 'S' || map[x][z] == 'W')
				enter_init_player_pos(player, x, z, 'N');
			z++;
		}
		x++;
	}
}

void	print_player_pos(t_player *player)
{
	printf("x = %d\n", player->pos.x);
	printf("y = %d\n", player->pos.y);
	printf("z = %d\n", player->pos.z);
}

int	exe_hub(t_system	*sys)
{
	t_player	player;

	init_player(&player, sys->play_map);
	print_player_pos(&player);
	return (1);
}

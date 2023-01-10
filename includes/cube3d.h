/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:25:29 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/10 17:42:28 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>

# define NB_CHAR 7
# define NB_CHAR_B 10
# define Multiplier 100

typedef struct s_system
{
	int		argc;
	char	**argv;
	char	*mapfile;
	char	sprite[10];
	char	**map;
	char	**play_map;
}t_system;

typedef struct s_game
{
	void	*mlx;
	void	*win;
}t_game;

typedef struct s_pos
{
	int	x;
	int	y;
	int	z;
}t_pos;

typedef struct s_player
{
	t_pos	case_pos;
	t_pos	pos;
	int		fov;
	int		rad_rotation;
	int		rotation;
	int		speed;
}t_player;

//				PARSING				//
void	*ft_memchr_cb(const void *s, int c, size_t n);
void	*ft_memcpy_cb(void *dest, const void *src, size_t n);
char	*ft_strtrim_cb(char *s1, char *set);
int		pars_hub(t_system *sys);
int		free_char_tab(char **tab);
char	**ft_split_cb(char const *s, char c);
int		print_char_tab(char **tab);
int		ft_strlen_cb(char *str);
int		verif_format_NO(t_system *sys);
int		verif_format_SO(t_system *sys);
int		verif_format_WE(t_system *sys);
int		verif_format_EA(t_system *sys);
char	*ft_strdup_cb(const char *s);
char	**make_map(t_system *sys);

#endif
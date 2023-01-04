/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:05:20 by lfantine          #+#    #+#             */
/*   Updated: 2022/11/09 09:23:50 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define ULL unsigned long long

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
long	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *news);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *news);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
char	*ft_fix_stay_gnl(char **stay, char *line);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_central_gnl(int fd);
char	*ft_read_gnl(int lenrd, char **stay, char *buf);
char	*ft_write_gnl(char **stay);
int		ft_checkforbreak_gnl(char *buf, int lenrd);
size_t	ft_buflen_gnl(char *buf, int lenrd, char *stay);
char	*failret_gnl(char *stay);

int		ft_printf(const char *in, ...);
int		ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		calcstr_ptf(char *s);
int		calcnbr_ptf(long int nb);
void	ft_putnbru_ptf(unsigned int n);
int		calcu_ptf(unsigned int nb);
void	ft_putnbr_base(int nbr, char *base);
int		calcx_ptf(long n);
int		calcp_ptf(unsigned long long n);
void	ft_putnbr_base2_ptf(unsigned long long nbr, char *base);
void	ft_pnb2_ptf(unsigned long long nbr, char *base);

char	*ft_itoa_base(int nbr, char *base);

#endif

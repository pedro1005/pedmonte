/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:49:34 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/29 15:04:33 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef N_FILES
#  define N_FILES 50
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *b, int c, size_t n);
int					ft_memcmp(const void *b1, const void *b2, size_t n);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big,
						const char *little, size_t	len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));
int					ft_atoi_base(const char *str, int str_base);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t				ft_strlen(const char *s);
char				*str_join(char *static_data, char *buff);
int					find_char(char *s, int c);
char				*update_data(int fd, char *static_data);
char				*line_cpy(char *line, char *static_data);
char				*update_line(char **static_data);
char				*cut_static_data(char **static_data, size_t str_len);
char				*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		print_s(char *temp, va_list ptr);
int		print_d(char *temp, va_list ptr);
int		print_c(char *temp, va_list ptr);
int		print_u(char *temp, va_list ptr);
int		print_x(char *temp, va_list ptr);
int		print_upx(char *temp, va_list ptr);
int		print_p(char *temp, va_list ptr);

int		get_x_len(unsigned int temp_value);
void	print_address(unsigned long long address, int num_chars);
int		print_formats(const char *str, int i, int n_chars, va_list ptr);

#endif

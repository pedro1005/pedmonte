/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:32:10 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/31 16:18:41 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*update_data(int fd, char *static_data);
int		find_char(char *s, int c);
char	*str_join(char *static_data, char *buff);
size_t	ft_strlen(char *s);
char	*cut_static_data(char **static_data, size_t str_len);
char	*update_line(char *static_data);
char	*str_cpy(char *src, char *src2, char *dst);
char	*line_cpy(char *static_data, char *line);
char	*check_static_data(char *static_data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:59:24 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/23 22:21:18 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *memory, char *tmp);
char	*ft_strchr(char *s, int c);
char	*ft_new_string(char *memory);
char	*ft_put_line(char *memory);
char	*ft_read_string(int fd, char *memory);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
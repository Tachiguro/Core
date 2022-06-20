/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:37:38 by marvin            #+#    #+#             */
/*   Updated: 2022/06/20 14:14:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif

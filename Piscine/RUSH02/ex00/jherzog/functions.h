/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:44:12 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/12 17:46:54 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int				check_argv2(char **argv, char *path, char **number);
int				check_argv3(char **argv, char **path, char **number);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_translate(char *number, char *path);
int				check_number(char *number);
int				dict_found(char *path);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
long			ft_atol(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:42:38 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 15:38:11 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_strlen                                                       */
/*  --------------------                                                      */
/*  The memset() function returns the length of the C string str.             */
/*                                                                            */
/*  The length of a C string is determined by the terminating null-character: */
/*  A C string is as long as the number of characters between the beginning   */
/*  of the string and the terminating null character (without including the   */
/*  terminating null character itself).                                       */
/*                                                                            */
/*  c: String.                                                                */
/*  return: The length of string (without including the terminating null      */
/*    character itself).                                                      */
/* ************************************************************************** */
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

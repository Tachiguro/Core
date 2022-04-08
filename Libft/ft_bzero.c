/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:33:09 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/06 10:30:25 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_bzero                                                        */
/*  --------------------                                                      */
/*  The ft_bzero() function erases the data in the n bytes of the memory      */
/*  starting at the location pointed to by s, by writing zeros (bytes         */
/*  containing '\0') to that area.                                            */
/*                                                                            */
/*  s: Pointer to the object to fill.                                         */
/*  n: Number of bytes to fill.                                               */
/* ************************************************************************** */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

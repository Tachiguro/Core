/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:40:54 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/09 18:43:37 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  Function: ft_isascii                                                      */
/*  --------------------                                                      */
/*  The ft_isascii() function checks whether a character is an ascii          */
/*  character or not.                                                         */
/*                                                                            */
/*  c: Character to be checked.                                               */
/*  return: Non-zero value if the c is an ascii character, zero otherwise.    */
/* ************************************************************************** */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

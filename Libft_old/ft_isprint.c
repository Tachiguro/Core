/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:42:04 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 15:06:53 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  Function: ft_isprint                                                      */
/*  --------------------                                                      */
/*  The ft_isprint() function Checks whether c is a printable character.      */
/*                                                                            */
/*  c: Character to be checked.                                               */
/*  return: Non-zero value if the c is an ascii character, zero otherwise.    */
/* ************************************************************************** */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

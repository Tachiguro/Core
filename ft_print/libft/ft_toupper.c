/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:26:14 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 15:42:54 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  Function: ft_toupper                                                      */
/*  --------------------                                                      */
/*  The ft_toupper() function Converts the given character to uppercase.      */
/*                                                                            */
/*  c: Character to be converted.                                             */
/*  return: Converted character or ch if no uppercase version.                */
/* ************************************************************************** */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}

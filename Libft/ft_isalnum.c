/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:38:44 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 15:04:51 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  Function: ft_isalnum                                                      */
/*  --------------------                                                      */
/*  The isalnum() function Checks if the given character is an alphanumeric   */
/*  character                                                                 */
/*                                                                            */
/*  c: character to be checked                                                */
/*  return: Non-zero value if the c is a alphanumeric, zero otherwi           */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

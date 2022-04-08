/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 22:09:00 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:13:39 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_strnstr                                                      */
/*  --------------------                                                      */
/*  The ft_strnstr() locates the first occurrence of the null-termi-nated     */
/*  string needle in the string haystack, where not more than len characters  */
/*  are searched. Characters that appear after a `\0' character are not       */
/*  searched.                                                                 */
/*                                                                            */
/*  haystack: This is the main C string to be scanned.                        */
/*  needle: Character to search for.                                          */
/*  len: The maximum number of characters to be scanned.                      */
/*  return: Pointer to the first occurrence in haystack of any of the entire  */
/*    sequence of characters specified in needle, or a null pointer if the    */
/*    sequence is not present in haystack.                                    */
/* ************************************************************************** */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (counter < len && haystack[counter] != '\0')
	{
		i = 0;
		while ((haystack[counter + i] == needle[i]) && ((counter + i) < len))
		{
			if (haystack[counter + i] == needle[i] && needle[i + 1] == '\0')
			{
				return ((char *)haystack + counter);
			}
			i++;
		}
		counter++;
	}
	return (NULL);
}

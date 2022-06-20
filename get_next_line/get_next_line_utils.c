/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:33:48 by marvin            #+#    #+#             */
/*   Updated: 2022/06/20 14:19:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len;
    size_t i;
    size_t j;
    char *new_str;

    if (s1 == NULL || s2 == NULL)
        return (0);
    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    new_str = (char *)malloc(len * sizeof(char));
    j = 0;
    i = 0;
    if (new_str == 0)
        return (NULL);
    while (s1[i])
    {
        new_str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        new_str[i + j] = s2[j];
        j++;
    }
    new_str[i + j] = '\0';
    return (new_str);
}

char *ft_strchr(const char *s, int c)
{
    while (*s || *s == (char)c)
    {
        if (*s == (char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strdup(const char *s)
{
    char *new_string;
    size_t i;

    i = 0;
    new_string = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!new_string)
        return (NULL);
    while (s[i])
    {
        new_string[i] = s[i];
        i++;
    }
    new_string[i] = '\0';
    return (new_string);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *string;
    unsigned int i;
    unsigned int string_len;
    unsigned int s_len;

    i = 0;
    s_len = ft_strlen(s);
    if (start >= s_len)
        string_len = 1;
    else if (len >= s_len)
        string_len = s_len - start + 1;
    else
        string_len = len + 1;
    string = (char *)malloc(string_len);
    if (!string)
        return (NULL);
    while ((start < s_len) && (i < len))
    {
        string[i] = s[start];
        i++;
        start++;
    }
    string[i] = 0;
    return (string);
}

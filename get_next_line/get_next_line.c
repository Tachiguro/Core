/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:20:24 by marvin            #+#    #+#             */
/*   Updated: 2022/06/20 14:13:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *cat;
    size_t len;
    int i;
    int j;

    i = 0;
    j = 0;
    len = ft_strlen(s1) + ft_strlen(s2);
    cat = (char *)malloc(sizeof(char) * (len + 1));
    if (!cat)
        return (NULL);
    cat[len] = 0;
    while (s1[i])
    {
        cat[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        cat[i] = s2[j];
        j++;
        i++;
    }
    cat[i] = 0;
    return (cat);
}

char *ft_strchr(const char *s, int c)
{
    size_t slen;
    size_t i;

    slen = ft_strlen(s);
    i = 0;
    while (i <= slen)
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(const char *s)
{
    char *dups;
    size_t i;

    dups = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!dups)
        return (NULL);
    i = 0;
    while (s[i])
    {
        dups[i] = s[i];
        i++;
    }
    dups[i] = '\0';
    return (dups);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    unsigned int i;
    unsigned int truelen;
    unsigned int slen;

    i = 0;
    slen = ft_strlen(s);
    if (start >= slen)
        truelen = 1;
    else if (len >= slen)
        truelen = slen - start + 1;
    else
        truelen = len + 1;
    sub = (char *)malloc(truelen);
    if (!sub)
        return (NULL);
    while ((start < slen) && (i < len))
    {
        sub[i] = s[start];
        i++;
        start++;
    }
    sub[i] = 0;
    return (sub);
}

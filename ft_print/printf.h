#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

char *func_itoh(int number);
int ft_printf(const char *format, ...);
char to_upper(char c);
int count_args(const char *format);
int func_strlen(char *str);
int func_numlen(int num);
char *func_strdup(char *s1);
char *func_strdup_itoa(int n);
char *func_itoa(int n);
void *func_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char *func_ulltoh(unsigned long long number);
#endif

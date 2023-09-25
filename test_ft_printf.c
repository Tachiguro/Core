#include <stdio.h>
#include "./ft_printf/src/ft_printf.h"

int	main(void)
{
	int or = 0;
	int my = 0;
	char *s;


	printf("0--------------------\n");
	my = ft_printf("%p\n", (void *)0);
	or = printf   ("%p\n", (void *)0);
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("1--------------------\n");
	my = ft_printf("%p\n", NULL);
	or = printf   ("%p\n", NULL);
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("2--------------------\n");
	my = ft_printf("%s\n", NULL);
	or = printf   ("%s\n", NULL);
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("3--------------------\n");
	my = ft_printf("%p\n", "");
	or = printf   ("%p\n", "");
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("4--------------------\n");
	my = ft_printf("%p\n", (void *)-14523);
	or = printf   ("%p\n", (void *)-14523);
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("5--------------------\n");
	my = ft_printf("0x%p-\n", (void *)ULONG_MAX);
	or = printf   ("0x%p-\n", (void *)ULONG_MAX);
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("6--------------------\n");
	my = ft_printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	or = printf   ("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("Or:%d\n", or);
	printf("My:%d\n", my);
	printf("7--------------------\n");

	return (0);
}

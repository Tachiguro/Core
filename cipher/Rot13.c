#include <stdio.h>
#include <string.h>

#define CRYPT 13

void	default_message(void);
void	encrypt(char *str);
void	decrypt(char *str);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isdigit(int c);

int	main(int argc, char **argv)
{
	if (argc != 3)
		default_message();
	if (strcmp(argv[1],"1") != 0 && strcmp(argv[1],"2") != 0)
	{
		printf("Wrong! 1 = encrypt and 2 = decrypt!");
		return (1);
	}
	else if (strcmp(argv[1], "1") == 0)
		encrypt(argv[2]);
	else if (strcmp(argv[1], "2") == 0)
		decrypt(argv[2]);
	return (0);
}

void	encrypt(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			str[i] = ((str[i] - '0' + CRYPT) % 10) + '0';
		}
		if (ft_isupper(str[i]))
		{
			if (str[i] + CRYPT > 'Z')
				str[i] = str[i] + CRYPT - 26;
			else
				str[i] += CRYPT;
		}
		else if (ft_islower(str[i]))
		{
			if (str[i] + CRYPT > 'z')
				str[i] = str[i] + CRYPT - 26;
			else
				str[i] += CRYPT;
		}
		i++;
	}
	printf("encrypted:\n%s\n", str);
}

void	decrypt(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			str[i] = ((str[i] - '0' + 10 - 3) % 10) + '0';
		}
		if (ft_isupper(str[i]))
		{
			if (str[i] - CRYPT < 'A')
				str[i] = str[i] + 26 - CRYPT;
			else
				str[i] -= CRYPT;
		}
		else if (ft_islower(str[i]))
		{
			if (str[i] - CRYPT < 'a')
				str[i] = str[i] + 26 - CRYPT;
			else
				str[i] -= CRYPT;
		}
		i++;
	}
	printf("decrypted:\n%s\n", str);
}

void	default_message(void)
{
	printf("How to:\n");
	printf("\tType <program name> 1 or 2 \"Text to en- or decrypt\"\n");
	printf("\t1 = encrypt\n");
	printf("\t2 = decrypt\n");
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

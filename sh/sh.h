#ifndef SH_H
# define SH_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

// Grammar tests
bool	is_correct_syntax(const char *l);

// Error handling
void	print_error(const char *text);

// Tokenization
typedef enum	e_type
{
	T_WORD,		// char, string ...
	T_PIPE,		// |
	T_IN,		// <
	T_OUT,		// >
	T_APPEND	// >>
}				t_type;

typedef struct	s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}				t_token;

t_token	*create_tokens(char *line);

// buildins
void	ft_exit(char *line);

// utils
void	print_tokens(t_token *head);
void	free_tokens(t_token *head);

#endif

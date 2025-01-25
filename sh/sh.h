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
	T_SINGLE_QUOTE =	'\'',
	T_DOUBLE_QUOTE =	'\"',
	T_LESS_THAN =		'<',
	T_GREATER_THAN =	'>',
	T_PIPE =			'|',
	T_DOLLAR =			'$',
	T_QUESTION_MARK =	'?',
	T_TILDE =			'~',
	T_DWORD =			' '
}				t_symbol;

typedef struct	s_token
{
	t_symbol		type;
	char			*value;
	struct s_token	*next
} t_token;

t_token	*get_token(char *line);
// Lexer

#endif

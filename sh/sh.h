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
#endif

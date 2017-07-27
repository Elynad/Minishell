/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:12:12 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 23:24:31 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"

typedef struct			s_info
{
	char				*home;
}						t_infos;

typedef struct			s_env
{
	char				*name;
	char				*value;
	int					hidden;
	struct s_env		*next;
}						t_env;

/*
**		GET ENV
*/

t_env					*get_env(char **env);
void					get_elem(t_env *env, char *str);
char					*get_until_eq(char *str);
char					*get_after_eq(char *str);

/*
**		GET COMMANDS
*/

char					**get_command(char *str);
int						get_spaces(char *str);
char					*get_until_next_sp(char *str, int *index);

/*
**		CHECK COMMANDS
*/

int						check_builtins(char **str);

/*
**		BUILTINS
*/

void					builtins(char **command, t_env *env);

/*
**		ENV FUNC
*/

void					set_env(t_env *env, char **command);
void					set_env_2(t_env *env, char **command);
void					unset_env(t_env *env, char **command);
void					unset_env_2(t_env *env, char **command);
void					modify_env_var(t_env *env, char *name, char *value);
char					*get_env_value(t_env *env, char *name);

/*
**		CHANGE DIRECTORY
*/

void					change_directory(t_env *env, char **command);
void					change_directory_2(t_env *env, char *path);
char					*get_until_next_sl(char *str, int *i);

/*
**		FREE
*/

void					free_env(t_env *env);
void					free_command(char **command);

/*
**		PRINT
*/

void					print_env(t_env *env);
void					print_array(char **array);

/*
**		CORE
*/

void					core(t_env *env);

#endif

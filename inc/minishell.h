/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:10:57 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 17:54:19 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# define DEFAULT_PATH_1 "/Users/mameyer/.brew/bin:/usr/bin:/bin:/usr/sbin:"
# define DEFAULT_PATH_2 "/sbin:/usr/local/bin:/usr/local/munki"
# define DEFAULT_HOME "/Users/mameyer"
# define DEFAULT_TERM "xterm-256color"
# define DEFAULT_SHLVL "1"

# include "../libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>

/*
**		CORE
*/

void		put_prompt(char **env);
void		core(char **env);
int			check(char *str);
int			check_spaces(char *str);
void		secure_putstr(char *str);

/*
**		PARSING
*/

char		**dup_env(char **env);
char		**set_default_env(void);
char		**str_split(char *str, char sep, int mfree);

/*
**		ERRORS
*/

void		cd_errors(char **command, char **env, char *path);
void		execute_error(char **commands, char **env, int error);

/*
**		PRINT
*/

void		print_tab(char **tab);

/*
**		CHECK COMMANDS
*/

void		check_command(char **command, char **env);
int			check_unsetenv_syntax(char **command);
int			check_setenv_syntax(char **command);

/*
**		MY COMMANDS
*/

void		echo_command(char **command, char **env);
void		env_command(char **command, char **env);
void		unsetenv_command(char **command, char **env);
void		setenv_command(char **command, char **env);
void		cd_command(char **command, char **env);
void		exit_command(char **command, char **env);

char		**unset_env_var(char **env, int line);
int			get_env_var_line(char **command, char **env);

char		**add_env_var(char **command, char **env);
char		**replace_env_var(char **command, char **env, int line);
void		setenv_command_2(char **command, char **env);

char		**get_setenv_commands(char *buf, char *var);

char		*get_env_var(char **env, char *name);
char		*get_env_var_2(char **env, int a, int eq, int i);

void		cd_command_2(char **command, char **env, char *path, int isprev);
void		cd_home(char **command, char **env);
void		cd_previous(char **command, char **env);
void		cd_success(char **env, char **command);

/*
**		OTHER COMMANDS
*/

void		fork_func(char **commands, char **env, int type);
void		execute(char **commands, char **env);
char		**get_paths(char **env);
int			test_access(char *path);
char		*get_binary_path(char *path, char *command);
void		execute_current(char **comands, char **env);

/*
**		OTHER
*/

void		free_tab(char **tab);
char		**increase_shlvl(char **env);
char		**decrease_shlvl(char **env);
char		*dup_and_cat(char *s1, char *s2);
char		**str_split(char *str, char sep, int free);
int			get_rep(char **env);

void		free_tab_exit(char **env);

#endif

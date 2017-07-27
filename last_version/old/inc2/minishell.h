/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:20 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/27 18:05:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"

typedef struct		s_infos
{
	int				env_changed;
	char			*env_home;
	char			*env_pwd;
	char			*env_oldpwd;
	char			**env_path;
}					t_infos;

/*
**		PARSING
*/

char				**duplicate_env(char **env, t_infos *infos);
void				get_infos(char **env, t_infos *infos);
void				get_infos_2(char *str, t_infos *infos);
char				**get_path(char *str);
char				*get_until_next_colon(char *str, int *index);
char				*get_after_equal(char *str);
char				**get_options(char *str);
char				*copy_until_nxt_sp(char *str, int *index);
int					get_spaces(char *str);

/*
**		CORE
*/

void				core(char **env, t_infos *infos);

/*
**		CHECK COMMANDS
*/

int					check_command(char **options);
int					check_my_commands(char **options);
int					check_env_commands(char **options, int type);

/*
**		ENV FUNCS
*/

char				**env_funcs(char **env, char **command, t_infos *infos);
char				**set_env(char **env, char **command);
char				**unset_env(char **env, char **command, t_infos *infos);
int					check_env(char **env, char **command);
char				**create_new_var(char **env, char **command);
char				*copy_env_line(char **env, int index);
char				*set_new_env_var(char **command);
char				**replace_env_var(char **env, char **command, int index);
char				*sub_replace(char **command);
char				**delete_env_var(char **env, char **command);

/*
**		FORK FUNCS
*/

void				fork_func(char **options, char **env, t_infos *infos);
void				execute(char **command, char **env);

/*
**		MY COMMANDS
*/

void				my_commands(char **options, char **env, t_infos *infos);
void				clear_command(void);
void				change_directory(char **option, char **env, t_infos *infos);
char				**replace_env_line(char **env, char *env_var, char *value);

/*
**		PRINT
*/

void				print_test(char **double_string);

/*
**		ERROR
*/

void				error(int type, char *str);

/*
**		FREE
*/

void				free_opt(char **options);

/*
**		OTHER
*/

void				env_usage(int type);
int					check_current_dir(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:21:52 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/24 21:51:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <errno.h>

typedef struct			s_infos
{
	int					env_changed;
	char				*env_pwd;
	char				*env_oldpwd;
	char				*env_home;
}						t_infos;

int		check_commands(char *str);		// test
void	execute(char **command, char **env);

char	**get_options(char *str);
int		get_spaces(char *str);
char	*copy_until_nxt_sp(char *str, int *index);

void	print_test(char **options);

void	free_opt(char **options);

//	______________________________________________________________

int			check_env_commands(char **str);
char		**env_funcs(char **env, char **command);
char		*copy_env_line(char **env, int index);
char		*set_new_env_var(char **command);
int			check_env(char **env, char **command);
char		**replace_env_var(char **env, char **command, int index);
char		*sub_replace(char **command);
char		**create_new_var(char **env, char **command);

char		**delete_env_var(char **env, char **command);

void		core(char **env, t_infos *infos);
void		sub_core(char **env);
void		fork_func(char **options, char **env, t_infos *infos);
int			my_commands(char **options, char **env, t_infos *infos);
void		clear_command(void);

void		print_env(char **env);
char		**set_env(char **env, char **command);
char		**unset_env(char **env, char **command);

void		cd_command(char **options, char **env, t_infos *infos);

void		free_env(char **env);

void		get_env_infos(char **env, t_infos *infos);
void		get_env_infos_2(char *str, t_infos *infos);
char		*get_after_equal(char *str);

char		**change_pwd(char *str, char **env);

#endif

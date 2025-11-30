/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:55:34 by amandine          #+#    #+#             */
/*   Updated: 2025/11/30 20:31:24 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_cmd(t_pipex *data, char *cmd)
{
	char	*new_cmd;
	char	*tmp;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (data->tab_path == NULL)
		return (NULL);
	new_cmd = ft_strjoin("/", cmd);
	if (!new_cmd)
		return (free(cmd), NULL);
	while (data->tab_path[i])
	{
		tmp = ft_strjoin(data->tab_path[i], new_cmd);
		if (!tmp)
			return (free(cmd), free(new_cmd), NULL);
		if (access(tmp, X_OK) == 0)
			return (free(cmd), free(new_cmd), tmp);
		free(tmp);
		i++;
	}
	return (free(cmd), free(new_cmd), NULL);
}

void	access_cmd(t_pipex *data, int num)
{
	char	*cmd;

	if (num == 1)
	{
        data->cmd1 = NULL;
		cmd = ft_strdup(data->tab_cmd1[0]);
		if (!cmd)
			return;
		data->cmd1 = create_cmd(data, cmd);
		if (data->cmd1 == NULL)
			return;
	}
	if (num == 2)
	{
        data->cmd2 = NULL;
		cmd = ft_strdup(data->tab_cmd2[0]);
		if (!cmd)
			return;
		data->cmd2 = create_cmd(data, cmd);
		if (data->cmd2 == NULL)
			return;
	}
}

void	create_path(t_pipex *data, char **envp)
{
	char	*path_envp;
	int		i;

	i = 0;
	path_envp = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			path_envp = ft_strdup(envp[i] + 5);
			break ;
		}
		i++;
	}
	if (path_envp == NULL)
		return ;
	data->tab_path = ft_split(path_envp, ':');
	free(path_envp);
}

int	fill_struct_pipex(t_pipex *data, char **argv, char **envp)
{
	data->file1 = ft_strdup(argv[1]);
	if (!data->file1)
		return (malloc_failure);
	data->file2 = ft_strdup(argv[4]);
	if (!data->file2)
		return (free(data->file1), malloc_failure);
	data->tab_cmd1 = ft_split(argv[2], ' ');
	if (!data->tab_cmd1)
		return (free(data->file1), free(data->file2), malloc_failure);
	data->tab_cmd2 = ft_split(argv[3], ' ');
	if (!data->tab_cmd2)
		return (free(data->file1), free(data->file2), free(data->tab_cmd1),
			malloc_failure);
	data->tab_path = NULL;
	create_path(data, envp);
    if (data->tab_cmd1[0] == NULL)
        data->cmd1 = NULL;
    else
	    access_cmd(data, 1);
	if (data->tab_cmd2[0] == NULL)
        data->cmd2 = NULL;
    else
	    access_cmd(data, 2);
	return (Success);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/11/28 15:43:03 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_files(t_pipex *data)
{
    int file1;
    int file2;
    
    file1 = open(data->file1, F_OK | R_OK);
    file2 = open(data->file2, F_OK | W_OK);
    if (file1 < 0 || file2 < 0)
        return (-1);
    return (0);
}

char *create_cmd(t_pipex *data, char *cmd)
{
    char *new_cmd;
    char *tmp;
    int i;
    
    i = 0;
    if (access(cmd, X_OK) == 0)
        return (cmd);
    new_cmd = ft_strjoin("/", cmd);
    if (!new_cmd)
        return (free(cmd), NULL);
    while(data->tab_path[i])
    {
        tmp = ft_strjoin(data->tab_path[i], new_cmd);
        if (!tmp)
            return (free(cmd), free(new_cmd), NULL);
        if (access(tmp, X_OK) == 0)
            return (free(cmd), free(new_cmd), tmp);
        free (tmp);
        i++;
    }
    return (free(cmd), free(new_cmd), NULL);
}

int access_cmd(t_pipex *data, int num)
{
    char *cmd;

    if (num == 1)
    {
        cmd = ft_strdup(data->tab_cmd1[0]);
        if (!cmd)
            return (malloc_failure);
        data->cmd1 = create_cmd(data, cmd);
        if (data->cmd1 == NULL)
            return (command_not_found);
    }
    if (num == 2)
    {
        cmd = ft_strdup(data->tab_cmd2[0]);
        if (!cmd)
            return (malloc_failure);
        data->cmd2 = create_cmd(data, cmd);
        if (data->cmd2 == NULL)
            return (command_not_found);
    }
    return (Success);
}

void print_error(int status)
{
    if (status == malloc_failure)
        ft_putendl_fd("ERROR : memory allocation", 2);
    if (status == path_error)
        ft_putendl_fd("ERROR : make path", 2);
}

void create_path(t_pipex *data, char **envp)
{
    char *path_envp;
    int i;

    i = 0;
    path_envp = NULL;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", 6) != NULL)
        {
            path_envp = ft_strdup(envp[i] + 5);
            break;
        }
        i++;
    }
    if (path_envp == NULL)
        return;
    data->tab_path = ft_split(path_envp, ':');
    free(path_envp);
}

int fill_struct_pipex(t_pipex *data, char **argv, char **envp)
{
    data->file1 = ft_strdup(argv[1]);
    if (!data->file1)
        return (malloc_failure);
    data->file2 = ft_strdup(argv[4]);
    if (!data->file2)
        return (free(data->file1), malloc_failure);
    data->cmd1 = NULL;
    data->cmd2 = NULL;
    data->tab_cmd1 = ft_split(argv[2], ' ');
    if (!data->tab_cmd1)
        return (free(data->file1), free(data->file2), malloc_failure);
    data->tab_cmd2 = ft_split(argv[3], ' ');
    if (!data->tab_cmd2)
        return (free(data->file1), free(data->file2), free(data->tab_cmd1), malloc_failure);
    data->tab_path = NULL;
    create_path(data, envp);
    access_cmd(data, 1);
    access_cmd(data, 2);
    return (Success);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex data;
    int status;

    if (argc != 5)
        return (1);
    status = fill_struct_pipex(&data, argv, envp);
    if (status != Success)
        return (print_error(status), status);
    pipex(&data, envp);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/11/24 19:58:10 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int check_access(t_pipex *pipex)
// {
//     int status;

//     status = access(pipex->file1, F_OK | R_OK);
//     if (status != 0)
//         return;
//     status = access(pipex->file2, F_OK);
//     if (status != 0)
//     {
//         // create file2
//     }
//     status =access(pipex->file2, W_OK);
//     if (status != 0)
//         return;
//     // pas faire fonction a part mauvaise idee
// }
char *create_cmd(t_pipex *pipex, char *cmd)
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
    while(pipex->tab_path[i])
    {
        tmp = ft_strjoin(pipex->tab_path[i], new_cmd);
        if (!tmp)
            return (free(cmd), free(new_cmd), NULL);
        if (access(tmp, X_OK) == 0)
            return (free(cmd), free(new_cmd), tmp);
        free (tmp);
        i++;
    }
    return (free(cmd), free(new_cmd), NULL);
}

int access_cmd(t_pipex *pipex, int num)
{
    char *cmd;

    if (num == 1)
    {
        cmd = ft_strdup(pipex->tab_cmd1[0]);
        if (!cmd)
            return (malloc_failure);
        pipex->cmd1 = create_cmd(pipex, cmd);
        if (pipex->cmd1 == NULL)
            return (command_not_found);
    }
    if (num == 2)
    {
        cmd = ft_strdup(pipex->tab_cmd2[0]);
        if (!cmd)
            return (malloc_failure);
        pipex->cmd2 = create_cmd(pipex, cmd);
        if (pipex->cmd2 == NULL)
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

void create_path(t_pipex *pipex, char **envp)
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
    pipex->tab_path = ft_split(path_envp, ':');
    free(path_envp);
}

int fill_struct_pipex(t_pipex *pipex, char **argv, char **envp)
{
    pipex->file1 = ft_strdup(argv[1]);
    if (!pipex->file1)
        return (malloc_failure);
    pipex->file2 = ft_strdup(argv[4]);
    if (!pipex->file2)
        return (free(pipex->file1), malloc_failure);
    pipex->cmd1 = NULL;
    pipex->cmd2 = NULL;
    pipex->tab_cmd1 = ft_split(argv[2], ' ');
    if (!pipex->tab_cmd1)
        return (free(pipex->file1), free(pipex->file2), malloc_failure);
    pipex->tab_cmd2 = ft_split(argv[3], ' ');
    if (!pipex->tab_cmd2)
        return (free(pipex->file1), free(pipex->file2), free(pipex->tab_cmd1), malloc_failure);
    pipex->tab_path = NULL;
    create_path(pipex, envp);
    access_cmd(pipex, 1);
    access_cmd(pipex, 2);
    return (Success);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
    int status;

    if (argc != 5)
        return (1);
    status = fill_struct_pipex(&pipex, argv, envp);
    if (status != Success)
        return (print_error(status), status);
    return (0);
}

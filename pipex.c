/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/11/24 02:35:08 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_access(t_pipex *pipex1)
{
    int status;

    status = access(pipex1->file1, F_OK | R_OK);
    if (status != 0)
        return;
    status = access(pipex1->file2, F_OK);
    if (status != 0)
    {
        // create file2
    }
    status =access(pipex1->file2, W_OK);
    if (status != 0)
        return;
    // pas faire fonction a part mauvaise idee
}

void print_error(int status)
{
    if (status == malloc_failure)
        ft_putendl_fd("ERROR : memory allocation", 2);
    if (status == path_error)
        ft_putendl_fd("ERROR : make path", 2);
}

void create_path(t_pipex *pipex1, char **envp)
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
    pipex1->tab_path = ft_split(path_envp, ':');
    free(path_envp);
}

int fill_struct_pipex(t_pipex *pipex1, char **argv, char **envp)
{
    pipex1->file1 = ft_strdup(argv[1]);
    if (!pipex1->file1)
        return (malloc_failure);
    pipex1->cmd1 = ft_strdup(argv[2]);
    if (!pipex1->cmd1)
        return (free(pipex1->file1), malloc_failure);
    pipex1->file2 = ft_strdup(argv[3]);
    if (!pipex1->file2)
        return (free(pipex1->file1), free(pipex1->cmd1), malloc_failure);
    pipex1->cmd2 = ft_strdup(argv[4]);
    if (!pipex1->cmd2)
        return (free(pipex1->file1), free(pipex1->cmd1), free(pipex1->file2), malloc_failure);
    pipex1->tab_cmd1 = split(pipex1->cmd1, ' ');
    if (!pipex1->tab_cmd1)
        return (free(pipex1->file1), free(pipex1->cmd1), free(pipex1->file2), free(pipex1->cmd2), malloc_failure);
    pipex1->tab_cmd2 = split(pipex1->cmd2, ' ');
    if (!pipex1->tab_cmd2)
        return (free(pipex1->file1), free(pipex1->cmd1), free(pipex1->file2), free(pipex1->cmd2), free(pipex1->tab_cmd1), malloc_failure);
    pipex1->tab_path = NULL;
    create_path(pipex1, envp);
    return (Success);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex1;
    int status;

    if (argc != 5)
        return (1);
    status = fill_struct_pipex(&pipex1, argv, envp);
    if (status != Success)
        return (print_error(status), status);
    return (0);
}

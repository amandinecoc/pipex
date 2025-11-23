/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/11/23 22:15:02 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fil1 existe = access(fil1, F_OK | R_OK);
// fil2 existe ou creer = access(fil2, F_OK);
// is OK = access(fl2, W_OK);
// is not ok = create fil2 et access(fil2, F_OK | W_OK);
// create variable PATH = PATH = (ft_strcmp("PATH =", **envp))
// suppr "PATH =" in PATH et split PATH :

// tab cmd1 = split(cmd1, ' ')
// tab cmd2 = split(cmd2, ' ')
// chercher cmd1[0] dans PATH 
// access(PATH[i] + cmd1[j], X_OK);

// dup file1 pour executer la cmd1 sur le dup
// execve(cmd, mycmdargs, envp); // Si execve réussit, le processus se termine
// // perror("Erreur"); <- ajouter perror pour le débogage
// free(cmd) // si execve échoue, on libère la mémoire et on essaie un autre chemin
// } return (EXIT_FAILURE);

/* ************************************************************************** */

// int check_access(t_pipex *pipex1)
// {
//     int status;

//     status = access(pipex1->file1, F_OK | R_OK);
//     if (status != 0)
//         return;
//     status = access(pipex1->file2, F_OK);
//     if (status != 0)
//     {
//         // create file2
//     }
//     status =access(pipex1->file2, W_OK);
//     if (status != 0)
//         return;
//     // pas faire fonction a part mauvaise idee
// }

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
    pipex1->tab_path = NULL;
    create_path(pipex1, envp);
    pipex1->tab_cmd1 = NULL;
    pipex1->tab_cmd2 = NULL;
    return (Success);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex1;
    int status;
    
    (void)envp;
    if (argc != 5)
        return (1);
    status = fill_struct_pipex(&pipex1, argv, envp);
    if (status != Success)
        return (status);
    return (0);
}

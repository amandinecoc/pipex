/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/11/01 12:44:57 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fil1 existe = access(fil1, F_OK | R_OK);
// fil2 existe ou creer = acccess(fil2, F_OK);
// is OK = access(fl2, W_OK);
// is not ok = create fil2 et access(fil2, F_OK | W_OK);
// creste variable PATH = PATH = (ft_strcmp("PATH =", *envps))
// suppr "PATH =" in PATH et split PATH :

// tab cmd1 = split(cmd1, ' ')
// tab cmd2 = split(cmd2, ' ')
// chercher cmd1[0] dans PATH 
// access(PATH[i] + cmd1[j], X_OK);  

int fill_struct_pipex(t_pipex *pipex1, char **argv)
{
    (*pipex1).file1 = ft_strdup(argv[1]);
    if (!(*pipex1).file1)
        return (malloc_failure);
    (*pipex1).cmd1 = ft_strdup(argv[2]);
    if (!(*pipex1).cmd1)
        return (free((*pipex1).file1), malloc_failure);
    (*pipex1).file2 = ft_strdup(argv[3]);
    if (!(*pipex1).file2)
        return (free((*pipex1).file1), free((*pipex1).cmd1), malloc_failure);
    (*pipex1).cmd2 = ft_strdup(argv[4]);
    if (!(*pipex1).cmd2)
        return (free((*pipex1).file1), free((*pipex1).cmd1), free((*pipex1).file2), malloc_failure);
    return (Success);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex1;
    int status;
    
    (void)envp;
    if (argc != 5)
        return (1);
    status = fill_struct_pipex(&pipex1, argv);
    if (status != Success)
        return (malloc_failure);
        
}

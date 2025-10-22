/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:03:28 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/22 05:59:57 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int fill_struct_pipex(t_pipex *pipex1, char **argv)
{
    (*pipex1).file1 = ft_strdup(argv[1]);
    if (!(*pipex1).file1)
        return (malloc_failure);
    (*pipex1).cmd1 = ft_strdup(argv[2]);
    if (!(*pipex1).cmd1)
        return (free((void *)(*pipex1).file1), malloc_failure);
    (*pipex1).file2 = ft_strdup(argv[3]);
    if (!(*pipex1).file2)
        return (free((void *)(*pipex1).file1), free((void *)(*pipex1).cmd1), malloc_failure);
    (*pipex1).cmd2 = ft_strdup(argv[4]);
    if (!(*pipex1).cmd2)
        return (free((void *)(*pipex1).file1), free((void *)(*pipex1).cmd1), free((void *)(*pipex1).file2), malloc_failure);
    return (Success);
}

int main(int argc, char **argv)
{
    t_pipex pipex1;
    int status;
    
    if (argc != 5)
        return;
    status = fill_struct_pipex(&pipex1, argv);
    if (status != Success)
        return (malloc_failure);
        
}
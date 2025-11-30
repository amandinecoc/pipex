/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:50:41 by amandine          #+#    #+#             */
/*   Updated: 2025/11/30 19:44:27 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_pipex(t_pipex *data)
{
    int i;

    i = 0;
    if (data->cmd1 != NULL)
        free(data->cmd1);
    if (data->cmd2 != NULL)
        free(data->cmd2);
    free(data->file1);
    free(data->file2);
    while (data->tab_cmd1[i])
        free(data->tab_cmd1[i++]);
    free(data->tab_cmd1);
    i = 0;
    while (data->tab_cmd2[i])
        free(data->tab_cmd2[i++]);
    free(data->tab_cmd2);
    i = 0;
    
    if (data->tab_path != NULL)
    {
        while (data->tab_path[i])
            free(data->tab_path[i++]);
        free(data->tab_path);
    }
}
    
void print_error(int status)
{
    if (status == malloc_failure)
        ft_putendl_fd("ERROR : memory allocation", 2);
    if (status == command_not_found)
        ft_putendl_fd("ERROR : command_not_found", 2);
}

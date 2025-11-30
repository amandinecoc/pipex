/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:50:41 by amandine          #+#    #+#             */
/*   Updated: 2025/11/30 18:57:48 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_error(int status)
{
    if (status == malloc_failure)
        ft_putendl_fd("ERROR : memory allocation", 2);
    if (status == command_not_found)
        ft_putendl_fd("ERROR : command_not_found", 2);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:50:51 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/27 23:52:27 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ************************************************************************** */
/*INCLUDES*/
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
#include <sys/wait.h>


/* ************************************************************************** */
/*TYPEDEF*/
typedef enum e_status
{
	Success,
	malloc_failure,
}			t_status;

typedef struct s_pipex
{
	char	*file1;
	char	*cmd1;
	char	*file2;
	char	*cmd2;
}			t_pipex;

/* ************************************************************************** */
/*PARSING*/
int fill_struct_pipex(t_pipex *pipex1, char **argv);

/* ************************************************************************** */
/*PIPEX*/

#endif
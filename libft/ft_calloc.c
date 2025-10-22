/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:47:28 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:31:59 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	int		len;
	int		i;

	len = nmemb * size;
	i = 0;
	tmp = malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

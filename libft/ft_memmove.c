/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:24:50 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:32:34 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;
	int		i;

	if (!dest && !src)
		return (NULL);
	tmp_d = (char *)dest;
	tmp_s = (char *)src;
	if (tmp_d > tmp_s && (tmp_s + n) > tmp_d)
	{
		while (n-- > 0)
			tmp_d[n] = tmp_s[n];
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	}
	return (dest);
}

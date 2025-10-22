/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:47:50 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:33:03 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	strc;

	i = 0;
	strc = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == strc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == strc)
		return ((char *)&s[i]);
	return (NULL);
}

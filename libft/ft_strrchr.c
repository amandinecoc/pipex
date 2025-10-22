/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:38:18 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:33:41 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	strc;

	len = ft_strlen(s);
	strc = (char)c;
	while (len > 0)
	{
		if (s[len] == strc)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == strc)
		return ((char *)&s[len]);
	return (NULL);
}

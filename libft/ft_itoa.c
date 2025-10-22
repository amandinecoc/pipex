/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:04:57 by amandine          #+#    #+#             */
/*   Updated: 2025/06/17 21:32:21 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_int(int n)
{
	int	len;
	int	nbr;

	len = 0;
	nbr = n;
	if (n > 0 || n < 0)
	{
		while (nbr != 0)
		{
			nbr = nbr / 10;
			len++;
		}
	}
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*nbr;
	long long	nb;

	nb = n;
	len = len_int(n);
	nbr = malloc(sizeof(char) * len + 1);
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	len--;
	if (n < 0)
	{
		nbr[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		nbr[len] = (nb % 10 + '0');
		nb = nb / 10;
		len--;
	}
	if (n == 0)
		nbr[0] = '0';
	return (nbr);
}

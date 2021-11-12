/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:06:50 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/12 11:19:00 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*arr;
	size_t			i;
	unsigned int	total;

	total = nmemb * size;
	arr = malloc(total);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (total--)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}

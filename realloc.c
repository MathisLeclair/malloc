/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:09 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/08 17:13:42 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		verif_ptr(void *ptr)
{
	t_link *node;

	node = truc->tiny;
	while (node->next)
	{
		if (ptr == node->next + 1)
			return (1);
		node = node->next;
	}
	node = truc->small;
	while (node->next)
	{
		if (ptr == node->next + 1)
			return (1);
		node = node->next;
	}
	node = truc->large;
	while (node->next)
	{
		if (ptr == node->next + 1)
			return (1);
		node = node->next;
	}
	return (0);
}

void	*realloc(void *ptr, size_t size)
{
	void	*ptr2;

	if (!size || !ptr)
		return (NULL);
	if (verif_ptr(ptr) == 0)
		return (NULL);
	ptr2 = malloc(size);
	ft_memcpy(ptr2, ptr, size);
	free(ptr);
	return (ptr2);
}

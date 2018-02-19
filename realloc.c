/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:09 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/19 11:26:23 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	refit(t_link *start, t_link *node, long size, long max)
{
	if (((char*)node->next + size <= (char*)node->next->end)
		|| (node->next->next != NULL && (char*)node->next + size
		<= (char*)node->next->next) || (node->next->next == NULL
		&& ((char*)node->next + size) - (char*)start <= max))
	{
		node->next->end = (t_link*)((char*)node->next + size);
		return (1);
	}
	return (0);
}

static void	*realloc_small(t_link *start, t_link *ptr, long size, long max)
{
	t_link *node;

	node = start;
	while (node->next != NULL)
	{
		if (ptr == node->next + 1)
		{
			if (refit(start, node, size, max) == 1)
				return (ptr);
			ptr = malloc(size);
			if (ptr == NULL)
				return (NULL);
			if (size > (char*)node->next->end - (char*)node->next)
				size = (char*)node->next->end - (char*)node->next;
			ft_memcpy(ptr, node->next + 1, size);
			free(node->next);
			return (ptr);
		}
		node = node->next;
	}
	return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	t_link *node;

	size += sizeof(t_link);
	node = realloc_small(g_truc->tiny, ptr, size, g_truc->tiny_max);
	if (!ptr)
		return (malloc(size));
	if (node != NULL)
		return (node);
	node = realloc_small(g_truc->small, ptr, size, g_truc->small_max);
	if (node != NULL)
		return (node);
	node = g_truc->large;
	while (node->next != NULL)
	{
		if (ptr != node->next + 1 && (node = node->next) != NULL)
			continue ;
		if ((ptr = malloc(size)) == NULL)
			return (NULL);
		if (size > (size_t)((char*)node->next->end - (char*)node->next))
			size = (char*)node->next->end - (char*)node->next;
		ft_memcpy(ptr, node->next + 1, size);
		free(node->next);
		return (ptr);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:03 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/19 14:13:59 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*small_malloc(t_link *start, long size, long max)
{
	t_link *node;
	t_link *tmp;

	node = start;
	while (node->next != NULL)
	{
		if ((char*)node->next - (char*)node->end >= size)
			break ;
		node = node->next;
	}
	if ((char*)node->end + size > (char*)start + max)
		return (NULL);
	tmp = node->next;
	node->next = node->end;
	node->next->end = (t_link*)((char*)node->next + size);
	node->next->next = tmp;
	return (node->next + 1);
}

void		*malloc2(size_t size)
{
	t_link *node;

	init();
	size += sizeof(t_link);
	if (size <= (size_t)g_truc->tiny_max)
		return (small_malloc(g_truc->tiny, size, g_truc->tiny_max));
	if (size <= (size_t)g_truc->small_max)
		return (small_malloc(g_truc->small, size, g_truc->small_max));
	node = g_truc->large;
	while (node->next != NULL)
		node = node->next;
	node->next = mmap(NULL, size, PRT, MAP, -1, 0);
	if (node->next == NULL)
		return (NULL);
	node->next->end = (t_link*)((char*)node->next + size);
	node->next->next = NULL;
	return (node->next + 1);
}

void		*malloc(size_t size)
{
	pthread_mutex_t	lock;
	void			*ptr;

	pthread_mutex_lock(&lock);
	ptr = malloc2(size);
	pthread_mutex_unlock(&lock);
	return (ptr);
}

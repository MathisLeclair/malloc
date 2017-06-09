/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:03 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/09 14:00:00 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*small_alloc(t_link *test, long size)
{
	t_link *node;
	t_link *old;

	node = test;
	while (test->next)
	{
		if ((char *)test->next - (char *)test->end >= size)
			break ;
		test = test->next;
	}
	old = test->next;
	test->next = test->end;
	test->next->end = (t_link *)((char *)test->next + size);
	test->next->next = old;
	return (test->next + 1);
}

void	*malloc2(size_t size)
{
	if ((long)(truc->tinycurr + size) > truc->tiny_max)
		return (NULL);
	truc->tinycurr += size;
	return (small_alloc(truc->tiny, size));
}

void	*malloc(size_t size)
{
	t_link *node;

	if (!size)
		return (NULL);
	size += sizeof(t_link);
	init();
	if ((long)size <= tny)
		return (malloc2(size));
	else if ((long)size <= sml)
	{
		if (truc->smallcurr += (long)size > truc->small_max)
			return (NULL);
		truc->smallcurr += size;
		return (small_alloc(truc->small, size));
	}
	node = truc->large;
	while (node->next)
		node = node->next;
	node->next = mmap(NULL, size, PRT, MAP, -1, 0);
	if (node->next == NULL)
		return (NULL);
	node->next->end = (t_link *)((char *)node->next + size);
	node->next->next = NULL;
	return (node->next + 1);
}

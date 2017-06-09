/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:08:30 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/09 13:59:22 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_struc *truc = NULL;

void	init()
{
	if (truc == NULL)
	{
		truc = mmap(NULL, sizeof(t_struc) + tny * 100 + sml
		* 100, PRT, MAP, -1, 0);
		truc->tiny_max = tny * 100;
		truc->small_max = sml * 100;
		truc->tiny = (t_link *)(truc + 1);
		truc->tiny->next = NULL;
		truc->tiny->end = (t_link *)(truc + 2);
		truc->small = (t_link *)((char *)truc->tiny + tny * 100);
		truc->small->next = NULL;
		truc->small->end = truc->small + 1;
		truc->tinycurr = 0;
		truc->smallcurr = 0;
		truc->large = (t_link *)(truc->tiny + 1);
		truc->large->next = NULL;
	}
}

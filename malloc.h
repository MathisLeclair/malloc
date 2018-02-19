/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:45:04 by mleclair          #+#    #+#             */
/*   Updated: 2018/02/19 13:22:46 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>
# include "./libft/libft.h"

# define TNY 8 * getpagesize()
# define SML 32 * getpagesize()
# define PRT PROT_READ | PROT_WRITE
# define MAP MAP_ANON | MAP_PRIVATE

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				init();
void				show_alloc_mem();

typedef struct		s_link
{
	struct s_link	*end;
	struct s_link	*next;
}					t_link;

typedef struct		s_struc
{
	t_link			*tiny;
	long			tiny_max;
	size_t			tinycurr;
	t_link			*small;
	long			small_max;
	long			smallcurr;
	t_link			*large;
}					t_struc;

extern t_struc		*g_truc;

#endif

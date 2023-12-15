/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:48:09 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/14 16:34:08 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src) 
{
    t_stack_node *push_node;
    if (!*src)
        return;
    push_node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    push_node->prev = NULL;
    if (!*dst) {
        *dst = push_node;
        push_node->next = NULL;
    } else {
        push_node->next = *dst;
        push_node->next->prev = push_node;
        *dst = push_node;
    }
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}

void	pp(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	push(b, a);
	write(1, "pp\n", 3);
}

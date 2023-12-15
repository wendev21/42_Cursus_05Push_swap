/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:52:35 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/14 16:58:51 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void reverse_rotate(t_stack_node **stack) 
{
    t_stack_node *last;
    if (!*stack || !(*stack)->next)
        return;
    last = find_last(stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void	rra(t_stack_node **stack, bool print)
{
	reverse_rotate(stack);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **stack, bool print)
{
	reverse_rotate(stack);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

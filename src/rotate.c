/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:53:21 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/15 16:51:34 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void rotate(t_stack_node **stack) 
{
    t_stack_node *last_node;
    if (!*stack || !(*stack)->next)
        return;
    last_node = find_last(stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void	ra(t_stack_node **stack_a, bool print)
{
	if (!(*stack_a))
		return ;
	rotate(stack_a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b, bool print)
{
	if (!(*stack_b))
		return ;
	rotate(stack_b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || !(*b))
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

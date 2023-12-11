/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:53:21 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 17:00:16 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = find_last(stack);
	if (!(*stack) || !((*stack)->next))
		return ;
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
}

void	ra(t_stack_node **stack_a, bool print)
{
	if (!(*stack_a))
		return ;
	rotate(stack_a);
	if (!print)
		write(1, "ra\n", 1);
}

void	rb(t_stack_node **stack_b, bool print)
{
	if (!(*stack_b))
		return ;
	rotate(stack_b);
	if (!print)
		write(1, "rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || (*b))
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:52:31 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 17:04:50 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = (*stack);
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **stack_a, bool print)
{
	if (!(*stack_a))
		return ;
	swap(stack_a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **stack_b, bool print)
{
	if (!(*stack_b))
		return ;
	swap(stack_b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!(*stack_a) || (*stack_b))
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

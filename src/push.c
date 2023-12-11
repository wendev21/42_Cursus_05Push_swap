/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:48:09 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 16:59:36 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if (!(*stack_b))
		(*stack_b)->prev = NULL;
	if (!(*stack_a))
	{
		(*stack_a) = tmp;
		tmp->next = NULL;
	}
	else
	{
		(*stack_a)->prev = tmp;
		(*stack_a)->prev->next = (*stack_a);
		(*stack_a) = tmp;
		tmp->prev = NULL;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:14:20 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/15 16:26:34 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*get_cheapest(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = (*stack);
	while (!(tmp->cheapest))
		tmp = tmp->next;
	return (tmp);
}

void	pre_mov(t_stack_node **stack, t_stack_node *cheapest, char c)
{
	while ((*stack) != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (c == 'b')
		{
			if (cheapest->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	target_node_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	long			best_match;
	t_stack_node	*target;
	t_stack_node	*b;
	t_stack_node	*a;

	b = (*stack_b);
	while (b)
	{
		best_match = LONG_MAX;
		a = (*stack_a);
		while (a)
		{
			if (a->nbr > b->nbr && a->nbr < best_match)
			{
				target = a;
				best_match = a->nbr;
			}
			a = a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = stack_min(stack_a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_b_a(t_stack_node **a, t_stack_node **b)
{
	c_index(a);
	c_index(b);
	target_node_b(a, b);
}

void	move_b_a(t_stack_node **a, t_stack_node **b)
{
	pre_mov(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

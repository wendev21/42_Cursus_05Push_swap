/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:14:20 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/13 16:50:44 by wecorzo-         ###   ########.fr       */
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
	while (!(*stack) == cheapest)
	{
		if (c == 'a')
		{
			if ((*stack)->above_median)
				ra(stack, false);
			else	
				rra(stack, false);
		}else if (c == 'b')
		{	
			if ((*stack)->above_median)
				rb(stack, false);
			else	
				rrb(stack, false);
		}
	}
}

void	init_b_a(t_stack_node **b, t_stack_node **a)
{
	c_index(b);
	c_index(a);
	target_nodei_b(a, b); 
}

void	move_b_a(t_stack_node **b, t_stack_node **a)
{
	(void)b;
	(void)a;
}

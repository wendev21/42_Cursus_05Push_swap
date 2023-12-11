/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_initiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:18:14 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 16:59:10 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_a_b(t_stack_node **a, t_stack_node **b)
{
	index(*a);
	index(*b);
	push_cost(*a, *b);
	cheapest(*a);
	target_node(*a, *b);
}

void	index(t_stack_node *stack)
{
	int				median;
	int				i;

	i = 0;
	median = stack_len(&stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	target_node(t_stack_node *a, t_stack_node *b)
{
	long			best_match;		
	t_stack_node	target;
	t_stack_node	*tmp;

	while (a)
	{
		best_match = LONG_MIN;
		tmp = *b;
		while (tmp)
		{
			if ((tmp->nbr < a->nbr) && (tmp->nbr > best_match))
			{
				target = tmp;
				best_match = tmp->nbr;
			}
			tmp = tmp->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	push_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(&a);
	len_b = stack_len(&b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = (len_a - a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += (len_b - a->target_node->index);
		a = a->next;
	}
}

void	cheapest(t_stack_node *stack)
{
	long			cheap;
	t_stack_node	*aux;

	cheap = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheap)
		{
			cheap = stack->push_cost;
			aux = stack;
		}
		stack = stack->next;
	}
	aux->cheapest = true;
}

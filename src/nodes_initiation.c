/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_initiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:18:14 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/13 16:51:18 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_a_b(t_stack_node **a, t_stack_node **b)
{
	c_index(a);
	c_index(b);
	target_node(a, b);
	push_cost(a, b);
	cheapest(a);
}

void	c_index(t_stack_node **stack)
{
	int				median;
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = (*stack);
	median = stack_len(stack) / 2;
	while (tmp)
	{
		tmp->index = i;
		if (i <= median)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
		i++;
	}
}

void	target_node(t_stack_node **a, t_stack_node **b)
{
	long			best_match;		
	t_stack_node	*target;
	t_stack_node	*tmp;
	t_stack_node	*aux;;

	aux = (*a);
	while (aux)
	{
		best_match = LONG_MIN;
		tmp = (*b);
		while (tmp)
		{
			if ((tmp->nbr < aux->nbr) && (tmp->nbr > best_match))
			{
				target = tmp;
				best_match = tmp->nbr;
			}
			tmp = tmp->next;
		}
		if (best_match == LONG_MIN)
			aux->target_node = stack_max(b);
		else
			aux->target_node = target;
		aux = aux->next;
	}
}

void	push_cost(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*aux;


	len_a = stack_len(a);
	len_b = stack_len(b);
	aux = (*a);
	while (aux)
	{
		aux->push_cost = aux->index;
		if (!(aux->above_median))
			aux->push_cost = (len_a - aux->index);
		if (aux->target_node->above_median)
			aux->push_cost += aux->target_node->index;
		else
			aux->push_cost += (len_b - aux->target_node->index);
		aux = aux->next;
	}
}

void	cheapest(t_stack_node **stack)
{
	long			cheap;
	t_stack_node	*aux;
	t_stack_node	*tmp;

	cheap = LONG_MAX;
	tmp = (*stack);
	while (tmp)
	{
		if (tmp->push_cost < cheap)
		{
			cheap = tmp->push_cost;
			aux = tmp;
		}
		tmp = tmp->next;
	}
	aux->cheapest = true;
}

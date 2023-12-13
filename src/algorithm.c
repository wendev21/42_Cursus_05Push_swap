/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:07:03 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/13 16:46:56 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	rot_both(t_stack_node **a, t_stack_node **b, 
		t_stack_node *cheapest)
{
	while ((*b) != cheapest->target_node && (*a) != cheapest)
		rr(a, b);
	c_index(a);
	c_index(b);
}

void	rev_rot_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while ((*b) != cheapest->target_node && (*a) != cheapest)
		rrr(a, b);
	c_index(a);
	c_index(b);
}
	
void	move_a_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(a);
	if (cheapest->above_median 
			&& cheapest->target_node->above_median)
		rot_both(a, b, cheapest);
	else if (!(cheapest->above_median)
			&& !(cheapest->target_node->above_median))
		rev_rot_both(a, b, cheapest);
	pre_mov(a, cheapest, 'a');
	pre_mov(b, cheapest, 'b');
	pb (b, a, false);

}

static void	its_top_min(t_stack_node **a)
{
	t_stack_node	*min;
	t_stack_node	*tmp;


	min = stack_min(a);
	tmp = (*a);
	while (min->nbr != (tmp)->nbr)
	{
		if (tmp->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*tmp;

	len_a = stack_len(a);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a, false);
	while (len_a-- > 3 && !(stack_sorted(a)))
	{
		init_a_b(a, b);
		move_a_b(a, b);
	}
	sort_three(a);
	tmp = *b;
	while (tmp)
	{
		init_b_a(b, a);
		move_b_a(b, a);
		tmp = tmp->next;
	}
//	c_index(a);
//	its_top_min(a);
}

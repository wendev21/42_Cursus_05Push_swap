/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:07:03 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/15 16:57:50 by wecorzo-         ###   ########.fr       */
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
	printf("jamon york\n");
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
	pre_mov(b, cheapest->target_node, 'b');
	pb (b, a, false);

}

static void	its_top_min(t_stack_node **a)
{
	t_stack_node	*min;

	min = stack_min(a);
	while (min->nbr != (*a)->nbr)
	{
		if (min->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int				len_a;

	len_a = stack_len(a);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a, false);
	int	i = 0;
	while (len_a-- > 3 && !(stack_sorted(a)))
	{
		init_a_b(a, b);

		move_a_b(a, b);
		i++;
	}

	if (!stack_sorted(b))
		sort_three(a);
	 i = 0;
	while (stack_len(b) > 0)
	{
		if (!(*a) || !(*b))
		{
			return ;
		}
		init_b_a(a,b);
		move_b_a(a, b);
		i++;

	}
	c_index(a);
	its_top_min(a);
}

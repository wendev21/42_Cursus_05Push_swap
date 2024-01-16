/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:23:15 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/16 16:42:25 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*void	leaks(void)
{
	system("leaks -q push_swap");
	atexit(leaks);
}*/
static void	stack_sort(t_stack_node **a, t_stack_node **b)
{
	if (stack_sorted(a) == false)
	{
		if (stack_len(a) == 2)
			sa(a, false);
		else if (stack_len(a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
	free_stack(b);
	free_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack_node	**a;
	t_stack_node	**b;
	int				i;
	int				j;
	char			**result;

	if (argc < 2 || (argc == 2 && !(argv[1][0])))
		return (1);
	a = malloc(sizeof(t_stack_node *));
	b = malloc(sizeof(t_stack_node *));
	if (!a || !b)
		exit(0);
	j = 0;
	while (argc > ++j)
	{
		result = split_mut(argv[j], ' ');
		i = -1;
		while (result[++i] != NULL)
			(init_stack_a(a, result[i]), free(result[i]));
		free(result);
	}
	stack_sort(a, b);
	return (0);
}

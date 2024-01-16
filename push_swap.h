/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:49 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/16 15:31:28 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}t_stack_node;

//**Handles errors
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node **a, int n);
void			free_stack(t_stack_node **stack);
void			free_error(t_stack_node **stack);

//**Stack initiation
void			init_stack_a(t_stack_node **a, char *str_n);
//**Nodes Initiation
void			init_a_b(t_stack_node **a, t_stack_node **b);
void			c_index(t_stack_node **stack);
void			target_node(t_stack_node **a, t_stack_node **b);
void			push_cost(t_stack_node **a, t_stack_node **b);
void			cheapest(t_stack_node **stack);
void			init_b_a(t_stack_node **b, t_stack_node **a);
void			move_b_a(t_stack_node **b, t_stack_node **a);
t_stack_node	*get_cheapest(t_stack_node **stack);
void			pre_mov(t_stack_node **stack, t_stack_node *chepest, char c);
void			target_node_b(t_stack_node **stack_b, t_stack_node **stack_a);
//**Stack Utils
t_stack_node	*find_last(t_stack_node **stack);
unsigned int	ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**split_mut(const char *str_n, char c);
bool			stack_sorted(t_stack_node **a);
int				stack_len(t_stack_node **a);
t_stack_node	*stack_min(t_stack_node **stack);
t_stack_node	*stack_max(t_stack_node **stack);
//**Commands
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node	**stack_b);

void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rr(t_stack_node **a, t_stack_node **b);

void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b);

void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			pp(t_stack_node **a, t_stack_node **b);

//**Algorithm
void			sort_three(t_stack_node **stack);
void			sort_stack(t_stack_node **a, t_stack_node **b);
#endif

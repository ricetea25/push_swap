/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:39:32 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/22 21:39:32 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nb_conv(int nb)
{
	if (nb < 0)
		return (-(nb));
	return (nb);
}

//finding the number of moves it would take to move each node to where it should be based on the index and the nodes current position
void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

//finding the node with the least cost and move it to where it should be
void	do_optimal_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		optimal;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	optimal = INT_MAX;
	while (tmp)
	{
		if (nb_conv(tmp->cost_a) + nb_conv(tmp->cost_b) < optimal)
		{
			optimal = nb_conv(tmp->cost_a) + nb_conv(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

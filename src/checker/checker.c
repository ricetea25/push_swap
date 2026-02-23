/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:38:53 by rteoh             #+#    #+#             */
/*   Updated: 2024/04/18 19:38:53 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a) && get_stack_size(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}

static int	exe_com(const char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strncmp(line, "sa", 2)))
		do_sa(stack_a);
	else if (!(ft_strncmp(line, "sb", 2)))
		do_sb(stack_b);
	else if (!(ft_strncmp(line, "ss", 2)))
		do_ss(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pa", 2)))
		do_pa(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pb", 2)))
		do_pb(stack_a, stack_b);
	else if (!(ft_strncmp(line, "ra", 2)))
		do_ra(stack_a);
	else if (!(ft_strncmp(line, "rb", 2)))
		do_rb(stack_b);
	else if (!(ft_strncmp(line, "rr\n", 3)))
		do_rr(stack_a, stack_b);
	else if (!(ft_strncmp(line, "rra", 3)))
		do_rra(stack_a);
	else if (!(ft_strncmp(line, "rrb", 3)))
		do_rrb(stack_b);
	else if (!(ft_strncmp(line, "rrr", 3)))
		do_rrr(stack_a, stack_b);
	return (0);
}

//basically just takes the instructions i received from my push_swap and does the moving operator, and if the stack is sorted it would print OK if not it would print KO, and if there is an error in the instruction it would print error.
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	if ((av[1] == NULL) || av[1][0] == '\0')
		exit_error(NULL, NULL);
	if (ac == 2)
		av = make_input(av);
	if (is_correct_input(av) == -1)
		exit_error(NULL, NULL);
	stack_a = fill_stack_values(ac, av);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line_error(line) == -1)
			exit_error(&stack_a, &stack_b);
		exe_com(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	check_stack(&stack_a, &stack_b);
	return (0);
}

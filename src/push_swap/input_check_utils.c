/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:52:37 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/02 14:52:37 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_cmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	if (s2[j] == '+')
		j++;
	while ((s1[i] != '\0' && s2[j] != '\0') && s1[i] == s2[j])
	{
		j++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

//take one long string from input and split it into multiple strings, then return the array of strings 
char	**make_input(char **av)
{
	char	*str;
	char	*s1;
	char	*s2;
	int		i;
	char	**arg;

	i = 0;
	str = ft_strdup("");
	while (av[i])
	{
		s1 = ft_strjoin(str, av[i]);
		free(str);
		s2 = ft_strjoin(s1, " ");
		str = ft_strdup(s2);
		free(s1);
		free(s2);
		i++;
	}
	arg = ft_split(str, ' ');
	free(str);
	return (arg);
}

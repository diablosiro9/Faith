/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:51:26 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/16 18:08:11 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_three_all(t_list *tmp)
{
	do_three(tmp);
	do_three2(tmp);
}

void	do_three(t_list *tmp)
{
	if (check_order(tmp) == 123)
		case_123(&tmp);
	if (check_order(tmp) == 132)
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		case_132(&tmp);
	}
	else if (check_order(tmp) == 213)
	{
		write(1, "sa\n", 3);
		case_213(tmp);
	}
}

void	do_three2(t_list *tmp)
{
	if (check_order(tmp) == 231)
	{
		write(1, "rra\n", 4);
		case_231(tmp);
	}
	else if (check_order(tmp) == 312)
	{
		write(1, "ra\n", 3);
		case_312(&tmp);
	}
	else if (check_order(tmp) == 321)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
		case_321(tmp);
	}
}

void	ft_case_two(t_list **l)
{
	t_list	*tmp;
	int		i;

	tmp = (*l);
	i = tmp->data;
	if (tmp->data > tmp->next->data)
	{
		i = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = i;
	}
}

void	ft_case_two_reverse(t_list **l)
{
	t_list	*tmp;
	int		i;

	tmp = (*l);
	i = tmp->data;
	if (tmp->data < tmp->next->data)
	{
		i = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = i;
	}
	(*l) = tmp;
}

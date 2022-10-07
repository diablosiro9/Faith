/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_three3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:48:48 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/16 18:09:01 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_312_reverse(t_list **l)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = *l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 312))
	{
		i = return_data(tmp, 1);
		j = return_data(tmp, 2);
		change_data(l, 1, j);
		change_data(l, 2, i);
	}
}

void	case_321(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 321))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 2);
		change_data(&l, 0, j);
		change_data(&l, 2, i);
	}
}

void	case_321_reverse(t_list *l)
{
	t_list	*tmp;
	int		tp;

	tp = 0;
	tmp = l;
	while (tmp)
	{
		if ((tmp->data > tmp->next->data)
			&& (tmp->next->data > tmp->next->next->data)
			&& (tmp->data > tmp->next->next->data))
			return ;
		tmp = tmp->next;
	}
}

void	ft_case_three(t_list **l)
{
	t_list	*tmp;

	tmp = *l;
	do_three_all(tmp);
}

void	ft_case_three_reverse(t_list **l)
{
	t_list	*tmp;

	tmp = *l;
	if (check_order(tmp) == 123)
		case_123_reverse(&tmp);
	if (check_order(tmp) == 132)
		case_132_reverse(&tmp);
	else if (check_order(tmp) == 213)
		case_213_reverse(tmp);
	else if (check_order(tmp) == 231)
		case_231_reverse(tmp);
	else if (check_order(tmp) == 312)
		case_312_reverse(&tmp);
	else if (check_order(tmp) == 321)
		case_321_reverse(tmp);
}

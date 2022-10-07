/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_three2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:00:56 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/16 18:08:44 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_213(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 213))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 1);
		change_data(&l, 0, j);
		change_data(&l, 1, i);
	}
}

void	case_213_reverse(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 213))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 2);
		change_data(&l, 0, j);
		change_data(&l, 2, i);
		i = return_data(tmp, 1);
		j = return_data(tmp, 2);
		change_data(&l, 1, j);
		change_data(&l, 2, i);
	}
}

void	case_231(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 231))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 2);
		change_data(&l, 0, j);
		change_data(&l, 2, i);
		i = return_data(tmp, 1);
		j = return_data(tmp, 2);
		change_data(&l, 1, j);
		change_data(&l, 2, i);
	}
}

void	case_231_reverse(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 231))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 1);
		change_data(&l, 0, j);
		change_data(&l, 1, i);
	}
}

void	case_312(t_list **l)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = *l;
	i = 0;
	j = 0;
	if (ft_lstsize(tmp) == 3 && (check_order(tmp) == 312))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 1);
		change_data(l, 0, j);
		change_data(l, 1, i);
		i = return_data(tmp, 1);
		j = return_data(tmp, 2);
		change_data(l, 1, j);
		change_data(l, 2, i);
	}
}

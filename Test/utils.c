/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:47:07 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char const *s)
{
	int	i;
	int	res;
	int	sign;
	int	new_res;

	i = 0;
	sign = 1;
	res = 0;
	new_res = 0;
	while (s[i] == '\f' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == ' ')
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= (-1);
		i++;
	}
	res = do_atoi(s, i, res, new_res);
	error_atoi(sign, res);
	return (res * -sign);
}

void	affichelist(t_list *l)
{
	t_list	*tmp;

	tmp = (l);
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		////printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int	check_order(t_list *l)
{
	t_list	*tmp;
	int		i;

	tmp = l;
	i = 0;
	while (tmp)
	{
		if ((tmp->data < tmp->next->data)
			&& (tmp->next->data < tmp->next->next->data)
			&& (tmp->data < tmp->next->next->data))
			return (123);
		else
		{
			i = condi_check_order(tmp);
			return (i);
		}
	}
	return (0);
}

int	condi_check_order(t_list *tmp)
{
	if (ft_lstsize(tmp) != 3)
		return (-1);
	if ((tmp->data > tmp->next->data)
		&& (tmp->next->data < tmp->next->next->data)
		&& (tmp->data < tmp->next->next->data))
		return (213);
	if ((tmp->data < tmp->next->data)
		&& (tmp->next->data > tmp->next->next->data)
		&& (tmp->data > tmp->next->next->data))
		return (231);
	if ((tmp->data > tmp->next->data)
		&& (tmp->next->data < tmp->next->next->data)
		&& (tmp->data > tmp->next->next->data))
		return (312);
	if ((tmp->data > tmp->next->data)
		&& (tmp->next->data > tmp->next->next->data)
		&& (tmp->data > tmp->next->next->data))
		return (321);
	if ((tmp->data < tmp->next->data)
		&& (tmp->next->data > tmp->next->next->data)
		&& (tmp->data < tmp->next->next->data))
		return (132);
	else
		return (0);
}

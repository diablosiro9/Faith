/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:31:25 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_atoi(char const *s, int i, int res, int new_res)
{	
	while (s[i] >= '0' && s[i] <= '9')
	{
		new_res = res * 10 - (s[i] - '0');
		if (new_res > res)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		res = new_res;
		i++;
	}
	return (res);
}

void	error_atoi(int sign, int res)
{
	if (sign == 1 && res == -2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	top_la_inf_lb(t_list **la, t_list **lb)
{
	if ((*la)->data < min_int(*lb))
	{
		// //////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		rb(lb);
		return (-1);
	}
	else
		return (0);
}

int	top_la_sec_lb(t_list **la, t_list **lb)
{
	if ((*la)->data < (*lb)->data && (*la)->data > (*lb)->next->data)
	{
		pb(lb, la);
		sb(lb);
		return (-1);
	}
	else
		return (0);
}

t_list	*copie_b(t_list **lb)
{
	t_list	*tmp;
	t_list	*save;

	save = NULL;
	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (!((*lb) == NULL))
	{
		tmp->data = (*lb)->data;
		if ((*lb)->next == NULL)
		{
			tmp->data = (*lb)->data;
			tmp->next = NULL;
			return (tmp);
		}	
		save = tmp;
		while ((*lb)->next)
		{
			*lb = (*lb)->next;
			tmp->next = malloc(sizeof(t_list));
			if (tmp->next == NULL)
				return (NULL);
			tmp = tmp->next;
			tmp->data = (*lb)->data;
			tmp->last = (*lb)->last;
		}
		tmp->next = NULL;
	}
	//////printf("finish him\n");
	//////printf("ftlstsizeuu = %d\n", ft_lstsize(save));
	return (save);
}

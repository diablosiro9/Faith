/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:38:22 by dojannin          #+#    #+#             */
/*   Updated: 2022/09/06 15:15:41 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_rrb_cent(t_list **la, t_list *tmp2, int i)
{
	if ((*la)->data < tmp2->data)
	{
		rrb_copy(&tmp2);
		i++;
	}
	if ((*la)->data > tmp2->data)
	{
		i = main_rrb_copy_cent(la, &tmp2, i);
		i++;
		if (tmp2->data < (*la)->data)
			i = do_rrb_copy_cent(la, &tmp2, i);
		else
		{
			delete_list(&tmp2);
			return (i - 1);
		}
	}
	delete_list(&tmp2);
	return (i);
}

int	main_rrb_copy_cent(t_list **la, t_list **tmp2, int i)
{
	while ((*tmp2) != NULL && ((*la)->data > (*tmp2)->data
			&& (*tmp2)->data != max_int(*tmp2)))
	{
		rrb_copy(tmp2);
		i++;
	}
	rrb_copy(tmp2);
	return (i);
}

int	do_rrb_copy_cent(t_list **la, t_list **tmp2, int i)
{
	while ((*tmp2) != NULL && (*la)->data > (*tmp2)->data
		&& (*tmp2)->data != max_int(*tmp2))
	{
		rrb_copy(tmp2);
		i++;
	}
	return (i);
}

int	check_before_rb_cent(t_list **la, t_list **lb)
{
	t_list	*tmp2;
	int		i;
	t_list	*tmp;

	tmp = (*lb);
	i = 0;
	tmp2 = copie_b(&tmp);
	while ((tmp2) != NULL && (tmp2)->data > (*la)->data
		&& (tmp2)->data != min_int(tmp2))
	{
		rb_copy(&tmp2);
		i++;
	}
	delete_list(&tmp2);
	return (i);
}

int	check_before_rrb_cent(t_list **la, t_list **lb)
{
	t_list	*tmp2;
	int		i;
	t_list	*tmp;

	tmp = (*lb);
	i = 0;
	tmp2 = copie_b(&tmp);
	i = all_rrb_cent(la, tmp2, i);
	return (i);
}

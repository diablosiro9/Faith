/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_rb_rrb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:58:27 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_before_rrb(t_list **lb, t_index_b *idxs)
{
	t_list	*tmp2;
	int		i;
	t_list	*tmp;

	tmp = (*lb);
	i = 0;
	tmp2 = copie_b(&tmp);
	// ////printf("los sommet de tmp2 == %d\n", tmp2->data);
	i = all_rrb(tmp2, idxs, i);
	// affichelist(*lb);
	// ////printf("i === %d\n", i);
	return (i);
}

int	check_before_rb(t_list **lb, t_index_b *idxs)
{
	t_list	*tmp2;
	int		i;
	t_list	*tmp;

	tmp = (*lb);
	i = 0;
	tmp2 = copie_b(&tmp);
	// ////printf("taille tmo == %d\n", ft_lstsize(tmp2));
	while ((tmp2) != NULL && (tmp2)->data > idxs->save
		&& (tmp2)->data != min_int(tmp2))
	{
		// ////printf("&tmp2 == %d\n", tmp2->data);
		rb_copy(&tmp2);
		i++;
	}
	// ////printf("&tmp2 == %d\n", tmp2->data);
	delete_list(&tmp2);
	return (i);
}

int	all_rrb(t_list *tmp2, t_index_b *idxs, int i)
{
	while (idxs->save < tmp2->data)
	{
		rrb_copy(&tmp2);
		i++;
	}
	// ////printf("IIII == %d\n", i);
	if (idxs->save > tmp2->data)
	{
		i = main_rrb_copy(&tmp2, idxs, i);
		i++;
		if (tmp2->data < idxs->save)
			i = do_rrb_copy(&tmp2, idxs, i);
		else
		{
			delete_list(&tmp2);
			return (i - 1);
		}
	}
	delete_list(&tmp2);
	return (i);
}

int	main_rrb_copy(t_list **tmp2, t_index_b *idxs, int i)
{
	while ((*tmp2) != NULL && (idxs->save > (*tmp2)->data
			&& (*tmp2)->data != max_int(*tmp2)))
	{
		rrb_copy(tmp2);
		i++;
	}
	rrb_copy(tmp2);
	// ////printf("IIII2 ==a %d\n", i);
	return (i);
}

int	do_rrb_copy(t_list **tmp2, t_index_b *idxs, int i)
{
	while ((*tmp2) != NULL && idxs->save > (*tmp2)->data
		&& (*tmp2)->data != max_int(*tmp2))
	{
		rrb_copy(tmp2);
		i++;
	}
	return (i);
}

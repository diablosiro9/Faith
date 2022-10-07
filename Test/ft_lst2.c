/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:50:43 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	return (lst);
}

void	ft_lstdeletelast(t_list *lst)
{
	t_list	*del;
	t_list	*temp;

	del = NULL;
	temp = NULL;
	// //////printf("lst == %d\n", lst->data);
	// //////printf("ftlstsize == %d\n", ft_lstsize(lst));
	temp = lst;
	// //////printf("tmpm = %d\n", temp->data);
	if (temp && temp->next && !temp->next->next)
	{
		// //////printf("entrado mutchacho\n");
		del = temp->next;
		// //////printf("del free = ->%d\n", del->data);
		free(del);
		temp->next = NULL;
	}
	else
	{
		// //////printf("entrado mutchcho\n");
		// //////printf("ftlstsize == %d\n", ft_lstsize(lst));
		// //////printf("tmp->next->next == %d\n", temp->next->next->data);
		while (temp->next->next != NULL)
			temp = temp->next;
		del = temp->next;
		// //////printf("del free = ->%d\n", del->data);
		free(del);
		temp->next = NULL;
	}
}

void	ft_lstdeletefirst(t_list **l)
{
	t_list	*tmp;

	tmp = NULL;
	if (l == NULL || *l == NULL)
		return ;
	tmp = *l;
	*l = (*l)->next;
	free(tmp);
}

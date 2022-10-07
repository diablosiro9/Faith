/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:32:33 by dojannin          #+#    #+#             */
/*   Updated: 2022/09/06 14:31:29 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*la;
	int		i;
	t_list	*lb;
	t_list	*tmp;
	int		j;

	la = NULL;
	lb = NULL;
	tmp = NULL;
	i = 0;
	j = 0;
	if (ac == 0 || ac == 1)
		return (0);
	if (ac == 2)
		la = maybe_you(ac, av, la, tmp);
	else
		la = or_you(ac, av, la, tmp);
	if (doublon(&la) == 0)
		return (0);
	do_your_life(&la, &lb);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	delete_list(t_list **l)
{
	t_list	*tmp;

	tmp = (*l);
	while ((*l)->next != NULL)
	{
		tmp = (*l);
		(*l) = (*l)->next;
		free(tmp);
	}
	free(*l);
}

int	size_double(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:54:52 by dojannin          #+#    #+#             */
/*   Updated: 2022/09/06 14:54:21 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_c(const char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	count_char_c( char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_check_c(s[i], c) == 1)
			i++;
		if (s[i] && ft_check_c(s[i], c) == 0)
		{
			count++;
			while (s[i] && ft_check_c(s[i], c) == 0)
				i++;
		}
	}
	return (count);
}

char	*ft_alloc_str(char const *s, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (s[i] && ft_check_c(s[i], c) == 0)
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] && ft_check_c(s[i], c) == 0)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_c;
	char	**dst;

	i = 0;
	if (!s)
		return (NULL);
	nb_c = count_char_c(s, c);
	dst = malloc(sizeof(char *) * (nb_c + 2));
	if (dst == NULL)
		return (NULL);
	nb_c = 0;
	while (s[i])
	{
		while (s[i] && ft_check_c(s[i], c) == 1)
			i++;
		if (s[i] && ft_check_c(s[i], c) == 0)
		{
			dst[nb_c++] = ft_alloc_str((s + i), c);
			while (s[i] && ft_check_c(s[i], c) == 0)
				i++;
		}
	}
	dst[nb_c] = NULL;
	return (dst);
}

void	change_data(t_list **l, int pos, int new)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *l;
	if (pos > ft_lstsize(*l))
		return ;
	while (i < pos && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->data = new;
}

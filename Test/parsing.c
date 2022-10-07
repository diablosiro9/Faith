/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:34:32 by dojannin          #+#    #+#             */
/*   Updated: 2022/09/06 15:02:57 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*maybe_you(int ac, char **av, t_list *la, t_list *tmp)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	j = 0;
	if (ac == 2)
	{
		if (str_letter(av[1]) == 0)
			lagalere();
		tab = ft_split(av[1], ' ');
		if (tab == NULL)
			return (NULL);
		i = 0;
		while (tab[i])
		{
			tmp = malloc_cell(ft_atoi(tab[i]));
			if (tmp)
				ft_lstadd_back(&la, tmp);
			i++;
		}
		free_tab(tab);
	}
	return (la);
}

t_list	*or_you(int ac, char **av, t_list *la, t_list *tmp)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac > 2)
	{
		while (av[i])
		{	
			if (str_letter(av[i]) == 0)
				lagalere();
			tmp = malloc_cell(ft_atoi(av[i]));
			ft_lstadd_back(&la, tmp);
			i++;
		}
	}
	return (la);
}

void	lagalere(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	check_error(char **av)
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	while (av[i++])
	{
		if ((av[i][j] >= 'a' && av[i][j] <= 'z')
			|| (av[i][j] >= 'A' && av[i][j] <= 'Z'))
		{
			lagalere();
		}
		i++;
	}
}

int	str_letter(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z')
			|| (s[i] >= 'A' && s[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

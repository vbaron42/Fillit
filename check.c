/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 20:59:59 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/06 18:26:08 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_co(char **tetri, int l, int i)
{
	int		co;

	co = 0;
	if (i != 3 && tetri[l][i + 1] == '#')
		co++;
	if (l != 3 && tetri[l + 1][i] == '#')
		co++;
	if (i != 0 && tetri[l][i - 1] == '#')
		co++;
	if (l != 0 && tetri[l - 1][i] == '#')
		co++;
	return (co);
}

int			check_tetri(char **tetri)
{
	int		co;
	int		l;
	int		i;

	co = 0;
	l = 0;
	while (l < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetri[l][i] == '#')
				co += check_co(tetri, l, i);
			i++;
		}
		l++;
	}
	if (co == 6 || co == 8)
		return (1);
	return (0);
}

int			ft_check_ligne(char *f, int p, int l)
{
	int		c;

	c = 0;
	while (c < 4)
	{
		if (f[(p * 21) + (l * 5) + c] != '.' &&
		f[(p * 21) + (l * 5) + c] != '#')
			return (0);
		c++;
	}
	if (f[(p * 21) + (l * 5) + 4] != '\n')
		return (0);
	else
		return (1);
}

int			check_tab(char *f)
{
	int		p;
	int		l;

	p = 0;
	while (p < 26)
	{
		l = 0;
		while (l < 4)
		{
			if (ft_check_ligne(f, p, l) == 0)
				return (0);
			l++;
		}
		if (f[p * 21 + 20] == '\0')
			return (1);
		if (f[p * 21 + 20] != '\t')
			return (0);
		p++;
	}
	return (0);
}

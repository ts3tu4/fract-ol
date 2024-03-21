/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:53:22 by mnanke            #+#    #+#             */
/*   Updated: 2024/03/22 00:27:56 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

double	ft_atof_process(char *s, double dot, int i, double rtn)
{
	while (s[i])
	{
		if (!ft_isnum(s[i]))
		{
			if (s[i] == '.')
				break ;
			exit(0);
		}
		rtn = rtn * 10 + s[i] - '0';
		i++;
	}
	if (s[i] && s[i] == '.')
	{
		i++;
		while (s[i])
		{
			if (!ft_isnum(s[i]))
				exit(0);
			rtn = rtn * 10 + s[i] - '0';
			i++;
			dot *= 10;
		}
	}
	return (rtn / dot);
}

double	ft_atof(char *s)
{
	double	rtn;
	double	symbol;
	double	dot;
	int		i;

	symbol = 1;
	dot = 1;
	rtn = 0;
	i = 0;
	if (s[i] == '-')
	{
		symbol *= -1;
		i++;
	}
	rtn = (ft_atof_process(s, dot, i, rtn) * symbol);
	return (rtn);
}

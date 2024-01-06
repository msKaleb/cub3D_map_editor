/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j < msoria-j@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:07:38 by msoria-j          #+#    #+#             */
/*   Updated: 2023/04/25 11:10:39 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

static int	check_args(char *str)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	while (str[i])
		i++;
	if (i == 0 || i == 1)
		return (-1);
	i = 0;
	while (str[i])
	{
		aux = str[i];
		if (aux == '-' || aux == '+' || aux == ' ')
			return (-1);
		j = i + 1;
		while (str[j])
		{
			if (aux == str[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ret_value(char n, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (n == base[i] - '0')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		nbr;
	int		baselen;
	int		i;

	if (check_args(base) == -1)
		return (0);
	i = 0;
	if (str[0] == '-')
		i++;
	baselen = 0;
	while (base[baselen])
		baselen++;
	nbr = 0;
	while (str[i])
	{
		if (ret_value(str[i] - '0', base) == -1)
			return (0);
		nbr = (nbr * baselen) + ret_value(str[i] - '0', base);
		i++;
	}
	if (str[0] == '-')
		nbr *= -1;
	return (nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:44:05 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/01/20 15:37:26 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_power_of_x(int nbr, int length)
{
	int	i;
	int	scale;

	i = 0;
	while (nbr >= length)
	{
		nbr /= length;
		i++;
	}
	scale = 1;
	while (i)
	{
		scale = scale * length;
		i--;
	}
	return (scale);
}

int	ft_base_is_valid(char *base)
{
	int		is_valid;
	int		i;
	int		j;

	is_valid = 1;
	i = 0;
	while (base[i] && is_valid)
	{
		if (base[i] == '+' || base[i] == '-')
			is_valid = 0;
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				is_valid = 0;
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		is_valid = 0;
	return (is_valid);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	_nbr;
	unsigned int	size;
	unsigned int	scale;

	_nbr = nbr;
	size = ft_strlen(base);
	scale = ft_power_of_x(nbr, size);
	if (!ft_base_is_valid(base))
		return ;
	while (scale != 1)
	{
		ft_putchar(base[_nbr / scale]);
		_nbr = _nbr % scale;
		scale /= size;
	}
	ft_putchar(base[_nbr]);
}

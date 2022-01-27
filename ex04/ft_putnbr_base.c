/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:44:05 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/01/27 10:17:27 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	ft_base_is_valid(char *base)
{
	int		i;
	int		j;
	int		c;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		c = 0;
		while (base[j])
		{
			if (base[j] == base[i])
				c++;
			if (c > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_rec(unsigned int nbr, char *base, unsigned int size)
{
	if (nbr > size - 1)
		ft_putnbr_base_rec((nbr / size), base, size);
	ft_putchar(base[nbr % size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	_nbr;

	if (!ft_base_is_valid(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		_nbr = -nbr;
	}
	else
		_nbr = nbr;
	ft_putnbr_base_rec(_nbr, base, ft_strlen(base));
}

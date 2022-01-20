/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:44:03 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/01/20 14:35:39 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_power_of_ten(int length)
{
	int	i;
	int	scale;

	i = 1;
	scale = 1;
	while (i < length)
	{
		scale = scale * 10;
		i++;
	}
	return (scale);
}

int	ft_count_length(int nb)
{
	int	length;

	length = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

void	ft_putnbr(int nb)
{
	int				length;
	int				i;
	int				scale;
	unsigned int	tmp;

	i = 0;
	tmp = nb;
	if (nb < 0)
	{
		tmp = nb * -1;
		ft_putchar('-');
	}
	length = ft_count_length(nb);
	scale = ft_power_of_ten(length);
	while (i < length)
	{
		ft_putchar(tmp / scale % 10 + 48);
		scale = scale / 10;
		i++;
	}
}

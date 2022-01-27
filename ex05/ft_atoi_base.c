/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:44:06 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/01/27 11:10:46 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_char_is_whitespace(char c)
{	
	int		i;
	char	ws[6];

	i = 0;
	ws[0] = ' ';
	ws[1] = '\f';
	ws[2] = '\n';
	ws[3] = '\r';
	ws[4] = '\t';
	ws[5] = '\v';
	while (i < 6)
		if (c == ws[i++])
			return (1);
	return (0);
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

int	ft_atoi_base_beepboop(char *str, char *base)
{
	int	i;
	int	j;
	int	result;
	int	size;
	int	is_in_base;

	result = 0;
	size = ft_strlen(base);
	i = -1;
	while (str[++i])
	{
		j = -1;
		is_in_base = 0;
		while (base[++j])
		{
			if (base[j] == str[i])
			{
				result = result * size + j;
				is_in_base = 1;
			}
		}
		if (is_in_base == 0)
			return (result);
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;

	if (!ft_base_is_valid(base))
		return (0);
	i = 0;
	sign = 1;
	while (ft_char_is_whitespace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	return (ft_atoi_base_beepboop(str + i, base) * sign);
}

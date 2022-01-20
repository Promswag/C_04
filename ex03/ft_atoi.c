/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:44:04 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/01/19 12:58:24 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{	
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_char_is_whitespace(char c)
{	
	int		i;
	char	whitespace[6];

	i = 0;
	whitespace[0] = ' ';
	whitespace[1] = '\f';
	whitespace[2] = '\n';
	whitespace[3] = '\r';
	whitespace[4] = '\t';
	whitespace[5] = '\v';
	while (i < 6)
		if (c == whitespace[i++])
			return (1);
	return (0);
}

int	ft_sign_handle(char c, int sign)
{
	if (c == '-')
		return (-sign);
	return (sign);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			sign = ft_sign_handle(str[i++], sign);
		else if (ft_char_is_whitespace(str[i]))
			i++;
		else if (ft_char_is_numeric(str[i]))
		{
			result = result * 10 + str[i] - 48;
			i++;
		}
		else
			break ;
	}
	return (result * sign);
}

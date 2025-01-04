/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:20:40 by dfeve             #+#    #+#             */
/*   Updated: 2024/11/11 14:28:19 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	int	result;

	result = c;
	if (c >= 'a' && c <= 'z')
		result -= 32;
	return (result);
}
/*
int main()
{
	printf("%c", (char)ft_toupper('a'));
}*/
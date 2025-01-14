/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:09:28 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/09 15:48:13 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthex(unsigned int num, char *base, size_t *len)
{
	char	*str;

	str = ft_nbr_base(num, base);
	ft_putstr(str, len);
	free(str);
}

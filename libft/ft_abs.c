/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 03:38:44 by vbaron            #+#    #+#             */
/*   Updated: 2017/01/16 18:53:30 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_abs_d(double n)
{
	return ((n < 0) ? -n : n);
}

int		ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}
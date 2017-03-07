/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:46:26 by vbaron            #+#    #+#             */
/*   Updated: 2017/03/07 13:30:56 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light			*ft_read_lgt_param(int fd, char *line, int l)
{
	t_light		*lgt;

	if (get_next_line_safe(fd, &line) != 1)
		ft_error_l("object without parameters\n", l);
	if (ft_strncmp(line, "{", 1) != 0)
		ft_error_l("open parameters with a '{'\n", l);
	if (!(lgt = (t_light *)malloc(sizeof(t_light))))
		ft_error("Malloc error\n");
	l++;
	if (get_next_line_safe(fd, &line) == 1)
		lgt->pos = ft_read_coo(ft_check_syntax(line, "	origin = (", l), l);
	else
		ft_error_l("no origin\n", l);
	if (get_next_line_safe(fd, &line) == 1)
		lgt->pow = ft_atoi_d(ft_check_syntax(line, "	power = ", l + 1));
	else
		ft_error_l("no power\n", l + 1);
	if (lgt->pow < 0 || lgt->pow > 1)
		ft_error_l("power can vary between 0.0 and 1.0\n", l + 1);
	if (get_next_line_safe(fd, &line) == 1)
		lgt->r = ft_atoi_d(ft_check_syntax(line, "	radius = ", l + 2));
	else
		ft_error_l("no radius\n", l + 2);
	if (get_next_line_safe(fd, &line) == 1)
		lgt->color = ft_atoi_16(ft_check_syntax(line, "	color = ", l + 3));
	else
		ft_error_l("no color\n", l + 3);
	if (get_next_line_safe(fd, &line) != 1 || ft_strncmp(line, "}", 1) != 0)
		ft_error_l("close parameters with a '}'\n", l + 4);
	return (lgt);
}

t_light			*ft_lstadd_lgt(int fd, char *line, t_light *all_lgt, int l)
{
	t_light		*lgt;
	t_light		*tmp;

	lgt = ft_read_lgt_param(fd, line, l);
	if (lgt)
		lgt->next = NULL;
	if (all_lgt == NULL)
		return (lgt);
	tmp = all_lgt;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = lgt;
	return (lgt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:38:03 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/24 10:10:07 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_error(char	*cnt, int error)
{
	if (error == 0)
		ft_putstr_fd(cnt, 1);
	if (error == 1)
		ft_putstr_fd(cnt, 1);
	if (error == 2)
		ft_putstr_fd(cnt, 1);
	exit (error);
}	

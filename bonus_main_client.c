/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:32:57 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/24 11:17:14 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	rebut(int sig)
{
	(void)sig;
	write(1, "Rebuda senyal\n", 26);
}

void	ft_send(int pid, char letter)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (((letter >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("iError_send_SIGUSR1", 1);
		}
		if (((letter >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("oError_send_SIGUSR2", 1);
		}
		usleep(600);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	signal(SIGUSR1, rebut);
	if (argc != 3)
		ft_error("Error_arguments", 1);
	message = argv[2];
	pid = ft_atoi(argv[1]);
	while (*message)
	{
		ft_send(pid, *message);
		message ++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:32:35 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/24 11:13:51 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_receipt(int sig, int pid)
{
	static int	cont = 0;
	static char	letter = 0;
	(void)pid;	
	if (sig == SIGUSR1)
		letter = letter | 1 << cont;
	cont ++ ;
	if (cont == 8)
	{
		write(1, &letter, 1);
		cont = 0;
		letter = 0;
	}
}

void	get(int sig, siginfo_t *info, void *context)
{
	int	pid;

	(void)context;
	pid = info->si_pid;
	ft_receipt(sig, pid);
}

int	main(void)
{
	struct sigaction	sig;
	char				*pid;

	sig.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sig.sa_mask) == -1)
		ft_error("Error_inici_signals", 2);
	sig.sa_sigaction = get;
	pid = ft_itoa(getpid());
	ft_putstr_fd("PID_SERVIDOR:", 1);
	write(1, pid, ft_strlen(pid));
	free (pid);
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		ft_error("Error_senyal", 3);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_error("Error_senyal", 3);
	while (1)
		pause();
	return (0);
}

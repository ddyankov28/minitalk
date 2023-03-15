/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:59:32 by ddyankov          #+#    #+#             */
/*   Updated: 2023/01/23 13:26:41 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	handle_signal(int signum)
{
	static int	i;
	static int	byte;

	if (signum == SIGUSR1)
		byte = byte + (1 << (7 - i));
	i++;
	if (i == 8)
	{
		printf("%c", byte);
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_printf("PID is: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
/* signal sets a function to handle a signal, and usleep pauses the process
 * and lets handle_signal to be called*/

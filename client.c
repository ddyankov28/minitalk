/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:46:23 by ddyankov          #+#    #+#             */
/*   Updated: 2023/01/23 13:34:59 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	send_binary_char_to_server(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1);
		bit--;
	}
}
/* bit = 7 to check from 7 - 0 because 1 byte has 8 bits.The first if condition
 * checks if the result after bitshifting is 1 and then sends the signal for 1
 * in binary and the next is for 0,usleep pauses the execution of the program*/

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Please enter the server PID and the string");
		return (1);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_binary_char_to_server(pid, av[2][i]);
		i++;
	}
	send_binary_char_to_server(pid, '\n');
	return (0);
}
/* The if condition is to handle errors, the pid is getting the Process ID
 * and at the end we send a newline char, because else cannot print*/

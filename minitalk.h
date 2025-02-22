/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:30:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/21 03:16:59 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_message
{
	unsigned char	c;
	int				bit_position;
}	t_message;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

void	ft_handle_signal(int signal, siginfo_t *info, void *context);
void	ft_setup_signals(void);
void	ft_print_pid(void);

void	ft_send_char(int pid, unsigned char c);
void	ft_send_string(int pid, char *str);

#endif

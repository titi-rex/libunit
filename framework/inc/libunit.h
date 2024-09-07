/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:55:43 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/05 20:33:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

# define NAME_MAX_LENGHT 32
# define TIMEOUT 2
# define LOG_BUFFER_SIZE 300

# define FLAG_STDIN			0b00000001
# define FLAG_TIMEOUT_NO	0b00000010
# define FLAG_TIMEOUT_L		0b00000100
# define FLAG_PERF	0b00001000

# define FLAG_B 0b00010000
# define FLAG_C 0b00100000
# define FLAG_D 0b01000000
# define FLAG_E 0b10000000


typedef int		(*t_test_func)(void);
typedef void	(*t_verbose)(void);

typedef struct s_test
{
	char			name[NAME_MAX_LENGHT];
	size_t			id;
	size_t			time;
	uint8_t			flags;
	uint8_t			status;
	t_test_func		function;
	t_verbose		scenario;
	struct s_test	*next;
}					t_test;

int		_get_log_fd(int op, const char *filename);
int		test_logger_init(int flags, const char *name);
int		test_logger(const char *format, ...);
void	test_loader(t_test **test_list, char *test_name, t_test_func function);
int		test_launcher(t_test **test_list);

#endif

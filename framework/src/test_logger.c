/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:25:12 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/05 20:23:52 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdarg.h>
//protect against bad use
int	_get_log_fd(int op, const char *filename)
{
	static int	fd = -1;

	if (op == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (op == -1)
		close(fd);
	return (fd);
}

int	test_logger_init(int flags, const char *name)
{
	if (flags == 0)
		return (0);
	_get_log_fd(0, name); // format name
	return (0);
}

int	test_logger(const char *format, ...)
{
	char	buffer[LOG_BUFFER_SIZE];
	int		fd_log;
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = vsnprintf(buffer, LOG_BUFFER_SIZE, format, args);
	va_end(args);

	write(1, buffer, strlen(buffer));
	fd_log = _get_log_fd(1, NULL);
	if (fd_log > 0)
		write(fd_log, buffer, strlen(buffer));

	return (ret);
}

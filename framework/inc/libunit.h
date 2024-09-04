/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:55:43 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/04 23:04:52 by tlegrand         ###   ########.fr       */
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

# define NAME_MAX_LENGHT 32
# define TIMEOUT 2

typedef int	(*t_test_func)(void);

typedef struct s_test
{
	char			name[NAME_MAX_LENGHT];
	size_t			id;
	int				status;
	t_test_func		function;
	struct s_test	*next;
}					t_test;

void	test_loader(t_test **test_list, char *test_name, t_test_func function);
int		test_launcher(t_test **test_list);

#endif

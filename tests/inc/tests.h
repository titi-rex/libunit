/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:41:50 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/04 23:08:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int	strlen_launcher(void);
int	ok_short(void);
int	ok_long(void);
int	ko_bad_result(void);
int	ko_segv(void);
int	ko_buse(void);
int	ko_timeout(void);

#endif

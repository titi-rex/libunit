/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:41:12 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/05 20:36:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int	strlen_launcher(void)
{
	t_test	*test;

	// test_logger_init(1, "strlen.log");
	test_logger("STRLEN: \n", NULL); // open log file
	test = NULL;
	test_loader(&test, "OK short", &ok_short);
	test_loader(&test, "OK long", &ok_long);
	test_loader(&test, "KO bad result", &ko_bad_result);
	test_loader(&test, "Null test", &ko_segv);
	test_loader(&test, "Bus Error test", &ko_buse);
	test_loader(&test, "Sleep test", &ko_timeout);
	return (test_launcher(&test));
}

/*
./test strlen strcpy
*/
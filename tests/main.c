/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:41:33 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/05 20:44:04 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int	main(int ac, char **arg)
{
	int	ret;

	ret = 0;
	(void)ac;
	(void)arg;

	if (ac == 1)
	{
		ret += strlen_launcher();
		
	}
	else
	{
		//loop through arg and call launcher
	}
	return (ret);
}

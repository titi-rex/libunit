/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:58:05 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/04 22:15:31 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	test_format_status_exit(t_test *test)
{
	char	*msg;

	if (test->status == 0)
		msg = "[OK]";
	else if (test->status == -1)
		msg = "[KO]";
	else
		msg = "[malformed test]";
	printf("\t> %s: %s\n", test->name, msg);
	return (test->status);
}

int	test_format_status_signal(t_test *test)
{
	char	*msg;

	if (test->status == SIGSEGV)
		msg = "[SEGV]";
	else if (test->status == SIGBUS)
		msg = "[BUS]";
	else if (test->status == SIGABRT)
		msg = "[ABRT]";
	else if (test->status == SIGALRM)
		msg = "[TIMEOUT]";
	else
		msg = "[unhandled signal]";
	printf("\t> %s: %s\n", test->name, msg);
	return (-1);
}

int	test_execute(t_test *test)
{
	int	pid;
	int	wstatus;

	pid = fork();
	if (pid == 0)
	{
		// add stdin
		alarm(TIMEOUT);
		exit(test->function());
	}
	else if (pid == -1)
		return (-1); // add error
	if (wait(&wstatus) == -1)
		printf("wait error\n");
	else if (WIFEXITED(wstatus))
	{
		test->status = WEXITSTATUS(wstatus);
		return (test_format_status_exit(test));
	}
	else if (WIFSIGNALED(wstatus))
	{
		test->status = WTERMSIG(wstatus);
		return (test_format_status_signal(test));
	}
	return (-2);// add error
}

void	test_clear(t_test *head)
{
	t_test	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

int	test_launcher(t_test **test_list)
{
	int	res;
	int	succes;
	int	total;

	res = 0;
	succes = 0;
	total = 0;
	while (*test_list)
	{
		if (test_execute(*test_list) == 0)
			succes++;
		else
			res = -1;
		total = (*test_list)->id;
		(*test_list) = (*test_list)->next;
	}
	printf("success: %d/%d\n", succes, total);
	test_clear(*test_list);
	test_list = NULL;
	return (res);
}

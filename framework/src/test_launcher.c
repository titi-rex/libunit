#include "libunit.h"


int test_format_status_exit(int status)
{
    char*   msg;

    if (status == 0)
        msg = "[OK]";
    else if (status == -1)
        msg = "[KO]";
    else
        msg = "[malformed test]";
    printf("\t> %s: %s\n", test->name, msg);
    return (status);
}

int test_format_status_signal(int status)
{
    char*   msg;

    if (status == SIGSEGV)
        msg = "[SEGV]";
    else if (status == SIGBUS)
        msg = "[BUS]";
    else if (status == SIGABRT)
        msg = "[ABRT]";
    else
        msg = "[unhandled signal]";
    printf("\t> %s: %s\n", test->name, msg);
    return (-1);
}

int test_execute(t_test* test)
{
    int pid;

    pid = fork()
    if (pid == 0)
    {
        //add timeout
        //add stdin 
        exit(test->function());
    }
    else if (pid == -1)
        return (-1); // add error
    else
    {
        int     wstatus;
        if (wait(&wstatus) == -1)
            printf("wait error\n");
        else if (WIFEXITED(wstatus))
            return (test_format_status_exit(WEXITSTATUS(wstatus)));
        else if (WIFSIGNALED(wstatus))
            return(test_format_status_signal(WTERMSIG(wstatus)));
    }

}

int test_launcher(t_test** test_list)
{
    int res = 0;
    int succes = 0;
    int total = 0;

    while (*test_list)
    {
        if (test_execute(*test_list) == 0)
            succes++;
        else
            res = -1;
        total = test_list->id;
        test_list = test_list->next;
    }
    printf("success: %d/%d\n", succes, total);
    return (res);
}

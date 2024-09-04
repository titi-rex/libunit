#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <sys/type.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define NAME_MAX_LENGHT 32

typedef int (*f)(void) t_test_func;

typedef struct s_test {
    char            name[NAME_MAX_LENGHT];
    size_t          id;
    int             success;
    t_test_func     function;
    struct s_test*  next;
}   t_test;


void    test_loader(t_test** test_list, char* test_name, t_test_func function);
int     test_launcher(t_test** test_list);

# endif

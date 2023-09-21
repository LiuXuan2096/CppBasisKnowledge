#include <43func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(3, argc);
    int lhs = atoi(argv[1]);
    int rhs = atoi(argv[2]);
    printf("lhs + rhs = %d\n", lhs + rhs);
    printf("pid = %d\n", getpid());
}
#include <43func.h>

int main()
{
    printf("before exec! pid = %d\n", getpid());
    char *argvector[] = {"./add", "3", "4", NULL};
    execv("add.out", argvector);
    printf("after exec!\n");
}
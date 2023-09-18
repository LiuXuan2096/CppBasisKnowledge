#include <43func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc, 3);
    int fdr = open(argv[1], O_RDONLY);
    int fdw = open(argv[2], O_WRONLY);\
    puts("pipe open");
    char buf[4096] = {0};
    fd_set rdset;
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(fdr, &rdset);
        select(fdr + 1, &rdset,NULL,NULL,NULL);
        if (FD_ISSET(fdr, &rdset))
        {
            puts("msg from pipe");
            memset(buf, 0, sizeof(buf));
            int ret = read(fdr, buf, sizeof(buf));
            if (ret == 0)
            {
                printf("end!\n");
                break;
            }
            puts(buf);
        }
        if (FD_ISSET(STDIN_FILENO,&rdset))
        {
            puts("msg from stdin");
            memset(buf, 0, sizeof(buf));
            int ret = read(STDIN_FILENO, buf, sizeof(buf));
            if (ret == 0)
            {
                write(fdw, "you are a good man.", 19);
                break;
            }
            write(fdw, buf, strlen(buf));
        }
    }
}
#include <43func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc, 3);
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open fdr");
    int fdw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    ERROR_CHECK(fdw, -1, "open fdw");
    char buf[4096] = {0};
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        ssize_t ret = read(fdr, buf, sizeof(buf));
        if (ret == 0)
        {
            break;
        }
        write(fdw, buf, ret); // 第三个参数是ret表示读多少写多少
    }
    close(fdr);
    close(fdw);
}
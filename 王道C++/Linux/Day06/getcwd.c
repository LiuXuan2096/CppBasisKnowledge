#include <43func.h>

int main()
{
    char buf[1024] = {0};
    char* ret = getcwd(buf, sizeof(buf));
    ERROR_CHECK(ret, NULL, "getcwd");
    printf("ret = %p, ret = %s\n", ret, ret);
    printf("buf = %p, buf = %s\n", buf, buf);

    return 0;
}
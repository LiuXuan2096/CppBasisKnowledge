// 自己实现一个ls命令
#include <43func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc, 2);
    DIR *drip = opendir(argv[1]);
    ERROR_CHECK(drip, NULL, "opendir");
    struct dirent * pdirent;
    while ((pdirent = readdir(drip)) != NULL)
    {
        printf ("indoe = %ld, reclen = %d, type = %d, name = %s\n",
        pdirent->d_ino, pdirent->d_reclen, pdirent->d_type, pdirent->d_name);
    }
    closedir(drip);
    
}
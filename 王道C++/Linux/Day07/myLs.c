#include <43func.h>

int main(int argc, char *argv[])
{
    ARGS_CHECK(argc, 2);
    DIR *drip = opendir(argv[1]);
    ERROR_CHECK(drip, NULL, "opendir");
    struct dirent * pdirent;
    struct stat statbuf;
    int ret = chdir(argv[1]);
    ERROR_CHECK(ret, -1, "chdir");
    while ((pdirent = readdir(drip)) != NULL)
    {
        ret = stat(pdirent->d_name, &statbuf);
        ERROR_CHECK(ret, -1, "stat");
        printf("%6o %ld %s %s %8ld %s %s\n",
        statbuf.st_mode,
        statbuf.st_nlink,
        getpwuid(statbuf.st_uid)->pw_name,
        getgrgid(statbuf.st_gid)->gr_name,
        statbuf.st_size,
        ctime(&statbuf.st_mtime),
        pdirent->d_name);
    }
    closedir(drip);
}
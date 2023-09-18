#include <43func.h>
int main(int argc, char *argv[]){
    // ./chat2 1.pipe 2.pipe
    ARGS_CHECK(argc,3);
    int fdw = open(argv[1], O_WRONLY);
    int fdr = open(argv[2], O_RDONLY);
    puts("pipe open");
    char buf[4096] = {0};
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        select(fdr+1,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(fdr,&rdset)){
            puts("msg from pipe");
            memset(buf,0,sizeof(buf));
            read(fdr,buf,sizeof(buf));
            puts(buf);
        }
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            puts("msg from stdin");
            memset(buf,0,sizeof(buf));
            read(STDIN_FILENO,buf,sizeof(buf));
            write(fdw,buf,strlen(buf));
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv){
    
    pid_t ppid = fork();
    if(ppid == 0){
        umask(0);
        int fd = open("log_cpu.log",O_WRONLY|O_CREAT|O_TRUNC);
        setsid();
        close(0);
        close(1);
        close(2);
        char* buf = (char*)malloc(100*sizeof(char));
        while(1){
            
            FILE *fp = popen("top -bn2 | grep '%Cpu' | tail -1", "r");
            fread(buf,100,1, fp);
            write(fd, buf,strlen(buf));
            sleep(1);
        }
    }
    return(0);

}

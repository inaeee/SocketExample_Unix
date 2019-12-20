open_socket.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
        //파일 및 소켓번호
        int fd1, fd2, sd1, sd2;
        //파일열기
        fd1=open("/etc/passwd", O_RDONLY, 0);
        printf("/etc/passwd's file descriptor = %d\n", fd1);
        //스트림형 소켓 열기
        sd1=socket(PF_INET, SOCK_STREAM, 0);
        printf("stream socket descriptor = %d\n", sd1);

        //데이터그램형 소켓 열기
        sd2=socket(PF_INET,SOCK_DGRAM,0);
        printf("datagram socket desriptor = %d\n", sd2);

        //또 다른 파일 열기
        fd2=open("/etc/hosts",O_RDONLY, 0);
        printf("/etc/hosts's file descriptor = %d\n", fd2);
        //파일 및 소켓 닫기
        close(fd2);
        close(fd1);
        close(sd2);
        close(sd1);
        return 0;
}

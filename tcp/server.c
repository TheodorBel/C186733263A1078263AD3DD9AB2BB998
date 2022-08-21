#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[]) {
    int listenfd = 0, connfd = 0; //файл дескриптор - интовая переменная
    struct sockaddr_in serv_addr, client_addr;
    socklen_t addrlen; //какая-то нужная штука

    char sendBuff[1025];

    listenfd = socket(AF_INET, SOCK_STREAM, 0); //af inet ipv4 протокол а sock stream соедение
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET; //по дефолту всегда аф инет
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(2121); // номер порта в нужный формат

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); //Присваивание сокету имени

    listen(listenfd, 10); //Слушаем новые подключения
    printf("server started\n");

    addrlen = sizeof(client_addr);
    connfd = accept(listenfd, (struct sockaddr*)&client_addr, &addrlen);
    if(connfd)
            printf("new connection\n");

    while(1) {
        bzero(sendBuff, 1025);
        read(connfd, sendBuff, 1025);
        printf("client: %s", sendBuff);
        fgets(sendBuff, 1025, stdin);
        write(connfd, sendBuff, strlen(sendBuff));

        sleep(1);
     }
     close(connfd);
     close(listenfd);
}

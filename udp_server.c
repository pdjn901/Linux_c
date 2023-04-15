/***< usp server*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>



//user def
#define BUFF_LEN 20
// #define PORT 52000
#define PORT 4455
#define MAXLINE 1024


int main()
{

    printf("\n udp has been start");

    /**< socket_des_serv*/

    /**< server struct initialization*/

    struct sockaddr_in server_address;

    /**< client address*/
    struct sockaddr_in client_address;

    /**< buffer for to store received data */
    char buff_receiv[BUFF_LEN];
    char *sending_message_hello = "sending hello to client";

    //server_address registration
    memset(&server_address,0,sizeof(server_address));
    memset(&client_address,0,sizeof(client_address));

    server_address.sin_family       = AF_INET; //IPV4
    server_address.sin_addr.s_addr  = INADDR_ANY;
    server_address.sin_port         = htons(PORT);

    /**< create socket for server*/
    int socket_des_serv = socket(AF_INET,SOCK_DGRAM,0);
    if (socket_des_serv < 0)
        {
            printf("s\n ocket creation error\t");
            exit(EXIT_FAILURE);
        }
        else{
            printf("\n socket created\t");
        }

    /*< bind */
    if (bind(socket_des_serv,(const struct sockaddr*)&server_address, sizeof(server_address)) < 0)
        {
            printf("\n bind error\t");
            exit(EXIT_FAILURE);
        }
        else{
            printf("\n binded\t");
        }


    int rec_len = sizeof(client_address);
    /**< server to receive from client*/
    // if( recvfrom(socket_des_serv,(char *)&buff_receiv,MAXLINE,MSG_WAITALL,(struct sockaddr*)&client_address,(socklen_t*)&rec_len) < 0)
    // int rec_status = recvfrom(socket_des_serv,(char *)&buff_receiv,MAXLINE,MSG_WAITALL,(struct sockaddr*)&client_address,(socklen_t*)&rec_len);
    // int rec_status = recvfrom(socket_des_serv,(char *)&buff_receiv,MAXLINE,MSG_WAITALL,(struct sockaddr*)&client_address,(socklen_t*)&rec_len);
    int rec_status = recv(socket_des_serv,(void *)&buff_receiv,100,0);
    
    printf("\n recv_status is %d",rec_status);
    if(rec_status < 0)
    {
        printf("\n received data failed from client\t");
    }else{
        printf("\n receive data from client is = %s \n",buff_receiv);
    }



    /**< server to send to the buff data to client address */
    // if( sendto(socket_des_serv,(const char*)sending_message_hello,strlen(sending_message_hello),MSG_CONFIRM ,(const struct sockaddr*)&client_address,sizeof(client_address)) < 0)
    // int send_status = sendto(socket_des_serv,(const char*)sending_message_hello,strlen(sending_message_hello),MSG_CONFIRM ,(const struct sockaddr*)&client_address,sizeof(client_address));
    //     printf("\n send_status is %d",send_status);
    //     if(send_status < 0)
    //     {
    //         printf("\n sending failed to client ");
    //     }else{
    //         printf("\n sending data to client is = %s\n",sending_message_hello);
    //     }

    close(socket_des_serv);


}


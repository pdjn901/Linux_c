#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// #define BUFSZ 16
#define BUFSZ 1316 //video read

/***< udp */
/************udp_receive_code**********/
// udp server socket tested working fine
#include <sys/stat.h>
#include <arpa/inet.h>
#include <netinet/udp.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <threads.h>

#define UDP_PORT 4455
// #define SER_IP_ADDR "1.1.1.45" //own laptop
#define SER_IP_ADDR "127.0.0.1" //own laptop
#define CLI_IP_ADDR "1.1.1.6"
// #define UDP_PORT_CRIO 4456


/**< udp comm*/
#define VIDEO_FRAME_SIZE 1316
#define HALF_MAJOR_FRAME_UDP_ITERATION 19
#define MAX_SIZE_OF_VIDEO_MAJOR_FRAME 25004 //19*1316 = 25004 bytes, and here 25004/470(for each minor frame) =53.2 for each half second 53.2 rows/minor frames

int socket_des_serv; //udp socket(server)
unsigned char buff_receiv[BUFSZ];
int rec_status;



/**< load channel.txt files into buffer[22]*/
// void load_csv(); /**< csv load function*/


void socket_close_handle_sigint(int sig);
void receive_udp_client_data_here();

/***< udp program */

/***< udp main */
void main(){
    
    printf("\n udp has been start");
    struct sigaction act;
    act.sa_handler = socket_close_handle_sigint;
    sigaction(SIGINT,&act,NULL);


    establish_udp_server_socket(); //establish udp comm

    // video_read_main();  //reading video file and send 

    receive_udp_client_data_here();//receive udp video data
    // receive_udp_client_data_here();

}



/**< close socks on ctrl+c*/
void socket_close_handle_sigint(int sig)
{
	printf("\n\nctrl+c, Caught signal %d\n", sig);
    int udp_ret = close(socket_des_serv);
    printf("close udp_ret is %d",udp_ret);

    #ifdef TCP
    int tcp_ret = close(hSocket);
    printf("close tcp_ret is %d",tcp_ret);
    #endif

    exit(0);
}


/***<establish udp comm*/
void establish_udp_server_socket()
{
    struct sockaddr_in server_address;
    struct sockaddr_in client_address; //udp 

    /**< client address*/
    // struct sockaddr_in client_address;

    /**< buffer for to store received data */
    // uint8_t buff_receiv[UDP_SERVER_MSG_BUFF_SIZE_1316];
    // char *sending_message_hello = "sending hello to client";

    //server_address registration
    memset(&server_address,0,sizeof(server_address));
    memset(&client_address,0,sizeof(client_address));

    // server_address.sin_family       = AF_INET; //IPV4
    // // server_address.sin_addr.s_addr  = INADDR_ANY;
    // server_address.sin_port         = htons(UDP_PORT);

    server_address.sin_family       = AF_INET; //IPV4
    server_address.sin_addr.s_addr  = inet_addr(SER_IP_ADDR);
    server_address.sin_port         = htons(UDP_PORT);

    // //udp client address
    // client_address.sin_family       = AF_INET;
    // client_address.sin_addr.s_addr  = inet_addr(CLI_IP_ADDR);
    // client_address.sin_port         = htons(UDP_PORT_CRIO);

    // //vlc client
    // client_address_vlc.sin_family   = AF_INET;
    // client_address_vlc.sin_addr.s_addr=inet_addr(CLI_VLC_IP_ADDR);
    // client_address_vlc.sin_port     = htons(UDP_PORT);


    /**< create socket for server*/
    socket_des_serv = socket(AF_INET,SOCK_DGRAM,0);
    if (socket_des_serv < 0)
    {
        printf("\n socket creation error\t");
        exit(EXIT_FAILURE);
    }
    else{
        printf("\n socket created\t");
    }

    printf("\n after socket");
    // struct timeval tv;
    // tv.tv_sec = 11;
    // tv.tv_usec = 0;
    // setsockopt(socket_des_serv, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(struct timeval));


    int option_value = 1;
    int rc = setsockopt(socket_des_serv, SOL_SOCKET, SO_OOBINLINE, (int *)&option_value, sizeof(int));

    printf("\n after setsockopt");

    /*< bind */
    if (bind(socket_des_serv,(const struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        printf("\n bind error\t");
        exit(EXIT_FAILURE);
    }
    else{
        printf("\n binded\t");
    }
    printf("\n after bind");

    //receive udp video data here
    receive_udp_client_data_here();

    

}

void receive_udp_client_data_here(){
    // unsigned char buff_receiv[BUFSZ];
    rec_status = recv(socket_des_serv,(void *)&buff_receiv,BUFSZ,0);
    
    printf("\n recv_status is %d",rec_status);
    if(rec_status < 0)
    {
        printf("\n received data failed from client\t");
    }else{
        printf("\n receive data from client is = %s \n",buff_receiv);
    }
}













// void video_read_main() {

//     unsigned char buf[BUFSZ] = {0};
//     // size_t bytes = 0, i, readsz = sizeof buf;
//     size_t bytes = 0, i;
//     int readsz = sizeof(buf);
//     // FILE *fp = argc > 1 ? fopen (argv[1], "rb") : stdin;
//     FILE *fp = fopen ("VIDEO_0108012348.264", "rb");


//     if (!fp) {
//         fprintf (stderr, "error: file open failed '%s'.\n", fp);
//         return 1;
//     }

//     /* read/output BUFSZ bytes at a time */
//     int count = 0;
//     // while ( (feof(fp) != true) && ((bytes = fread (buf, sizeof *buf, readsz, fp)) == readsz)) {
//     while ( (feof(fp) != true) && ((bytes = fread (buf, sizeof *buf, readsz, fp)) == readsz)) {
//         for (i = 0; i < readsz; i++){
//             // printf (" 0x%02x", buf[i]);
//         }
//         count += 1;
//         printf("\n bytes_size := %d, count is:%d",bytes,count);
//         putchar ('\n'); 
//         // break;  //tmp
//     }
//     for (i = 0; i < bytes; i++) /* output final partial buf */
//         // printf ("at[%d]:= 0x%02x", i,buf[i]);
//     putchar ('\n');
//     printf("\n pertial bytes :%d",bytes);

//     if (fp != stdin)
//         fclose (fp);

//     return 0;
// }

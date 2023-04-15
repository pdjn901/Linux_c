#include <stdio.h>
#include <string.h>
#include <signal.h>

int main(){
    // int ret = strcmp(SIGINT, SIGINT);
     int system_sig_array[] = {SIGHUP,
                                    SIGINT,
                                    SIGQUIT,SIGILL,SIGTRAP,SIGABRT,SIGBUS,SIGFPE,SIGUSR1,SIGSEGV,SIGUSR2,SIGPIPE,SIGALRM,SIGTERM,SIGSTKFLT,SIGCHLD, 
                                    SIGCONT, SIGTSTP,SIGTTIN,SIGTTOU,SIGURG,SIGXCPU,SIGXFSZ,SIGVTALRM,SIGPROF,SIGWINCH,SIGIO,SIGPWR,SIGSYS,SIGSYS,
                                    SIGRTMIN,
                                    SIGRTMIN+1,SIGRTMIN+2,SIGRTMIN+3,SIGRTMIN+4,SIGRTMIN+5,SIGRTMIN+6,SIGRTMIN+7,SIGRTMIN+8,SIGRTMIN+9,SIGRTMIN+10,SIGRTMIN+11,SIGRTMIN+12,SIGRTMIN+13,SIGRTMIN+14,SIGRTMIN+15,SIGRTMAX-14,SIGRTMAX-13,SIGRTMAX-12,SIGRTMAX-11,SIGRTMAX-10,SIGRTMAX-9,SIGRTMAX-8,SIGRTMAX-7,SIGRTMAX-6,SIGRTMAX-5,SIGRTMAX-4,SIGRTMAX-3,SIGRTMAX-2,SIGRTMAX-1,SIGRTMAX
                                };
   
    int user_array[] = {SIGINT,SIGRTMIN+1};


    // for(int i = 0; i < sizeof(user_array)/sizeof(int); i++) 
    // {
    //     // if (SIGINT == SIGSTOP)
    //     for(int j = 0; j < sizeof(system_sig_array)/sizeof(int); j++) 
    //     {
    //         if(user_array[i] == system_sig_array[j]) 
    //         {
    //             printf("ret is success at signal_number[%d] & system_sig_array[%d], i:%d,j:%d \n",user_array[i],system_sig_array[j],i,j);
    //         }
    //         else
    //         {
    //             printf("if fail at signal[%d]\n",system_sig_array[j]);
    //             //ignore the signal usig sigaction
    //         }
    //     }    
    // }

    int count_i = sizeof(system_sig_array)/sizeof(int);
    int count_j = sizeof(user_array)/sizeof(int);
    int temp = -1;
    for(int i = 0; i < count_i; i++) 
    {
        // if (SIGINT == SIGSTOP)
        for(int j = 0; j < count_j; j++) 
        {   temp = i;
            while (1)
            {
                //system_sig_array[i] == user_array[j]

                if(j < count_j)
                {
                    if(system_sig_array[i] == user_array[j])
                    {
                        printf("both signals match, system_sig_array[%d] & user_array_sig[%d], i:%d, j:%d \n",system_sig_array[i],user_array[j],i,j);
                        
                    }
                    j += 1;
                }
                else
                {   
                    //j limit crossed, break here.
                    //ignore the signal usig sigaction
                    printf("if fail at signal[%d]\n",system_sig_array[j]);
                    j = temp;
                    break;
                }

            }
        }    
    }
}

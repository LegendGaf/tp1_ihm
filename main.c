#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

// definition de la variable de commande, en attente IDLE par defaut
unsigned int curChar = 0;

// signal handler to update a new recived command
void sigRT_handler(int unused, siginfo_t *info, void *unused_ptr) {
    curChar = info->si_value.sival_int;
}

int main(void) {
    // Install signal handler
    struct sigaction signalHandling;
    signalHandling.sa_flags = SA_SIGINFO;
    signalHandling.sa_sigaction = sigRT_handler;
    sigfillset(&signalHandling.sa_mask);
    sigaction(SIGRTMIN, &signalHandling, NULL);

    unsigned char s_cmdPID[15];
    FILE *cmd = popen("pidof serverLEDs", "r");

    // Check that only one instance of the server is running on the system
    fgets(s_cmdPID, 15, cmd);
    pclose(cmd);
    if (strchr(s_cmdPID, ' ') != NULL) {
        printf("Error: One instance of PORTE server is already running !\n");
        return EXIT_FAILURE;
    }

    // Initialisation des LEDs utilisant le script
    system("/root/01-cmdLEDs/LEDs_off.sh");
    // Infinite loop to handle recived characters
    char list[4][50] = {{"/sys/class/leds/beaglebone:green:usr0/brightness"},
                        {"/sys/class/leds/beaglebone:green:usr1/brightness"},
                        {"/sys/class/leds/beaglebone:green:usr2/brightness"},
                        {"/sys/class/leds/beaglebone:green:usr3/brightness"}};
    FILE *led;
    for (int i=0; i < 4; i++) {
        led = fopen(list[i], "w+");
        if (led == NULL) {
            printf("Error open file led!");
            return 0;
        }
        fputs("1", led);
        fflush(led);
        sleep(1);
        fputs("0", led);
        fflush(led);
        sleep(1);
        fclose(led);
    }
    
    char x[100];
    
    while (1) {
        if (curChar) {
            // remplacez le printf par le clignottement de la LED 0 afin de faire
            // le code morse du caractere ASCII correspondant.
            // char x[100];  @H faire sortir la declaration de la boucle infinie.
            scanf("%s", &x); // je pense qu'on doit faire sortir cette ligne du test de curChar !!
            
            printf("--> %02X\n", curChar); // ?? what does curChar means
            
            curChar = 0;
        }
        //scanf("%s", &x);
        
    }
    return EXIT_SUCCESS;
}

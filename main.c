#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#define ThreeScale 3
#define OneScale 1
#define FourScale 4
void pointOff();
void hyphen();
void espLetter();
void espWord();
void morseOut(char);


// definition de la variable de commande, en attente IDLE par defaut
unsigned int curChar = 0;

// signal handler to update a new recived command
void sigRT_handler(int unused, siginfo_t *info, void *unused_ptr) {
    curChar = info->si_value.sival_int;
}
void pointOn(){
    FILE *led;
    led = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w+");
    if (led == NULL) {
        printf("Error open file led!");
        return 0;
    }
    fputs("1", led);
    fflush(led);
    sleep(OneScale);
    fclose(led);
}
void pointOff(){
    FILE *led;
    led = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w+");
    if (led == NULL) {
        printf("Error open file led!");
        return 0;
    }
    fputs("0", led);
    fflush(led);
    sleep(OneScale);
    fclose(led);
}
void hyphen(){
    FILE *led;
    led = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w+");
    if (led == NULL) {
        printf("Error open file led!");
        return 0;
    }
    fputs("1", led);
    fflush(led);
    sleep(ThreeScale);
    fclose(led);
}
void espLetter(){
    FILE *led;
    led = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w+");
    if (led == NULL) {
        printf("Error open file led!");
        return 0;
    }
    fputs("0", led);
    fflush(led);
    sleep(ThreeScale);
    fclose(led);
}
void espWord(){
    FILE *led;
    led = fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w+");
    if (led == NULL) {
        printf("Error open file led!");
        return 0;
    }
    fputs("0", led);
    fflush(led);
    sleep(FourScale);
    fclose(led);
}
void morseOut(char character) {
    switch (character) {
        case 'A':
            pointOn();
            pointOff();
            hyphen();
            break;
        case 'B':
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case 'C':
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            break;
        case 'D':
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case 'E':
            pointOn();
            break;
        case 'F':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            break;
        case 'I':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            break;
        case 'J':
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            break;
        case 'K':
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            break;
        case 'L':
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case 'M':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            break;
        case 'N':
            hyphen();
            pointOff();
            pointOn();
            break;
        case 'O':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            break;
        case 'P':
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            break;
        case 'Q':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            break;
        case 'R':
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            break;
        case 'S':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case 'T':
            hyphen();
            break;
        case 'U':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            ()
            break;
        case 'V':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            break;
        case 'W':
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            break;
        case 'X':
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            break;
        case 'Y':
            hyphen();
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            break;
        case 'Z':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case '1':
            (pointOn);
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            break;
        case '2':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            break;
        case '3':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            break;
        case '4':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            hyphen();
            break;
        case '5':
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case '6':
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();

            break;
        case '7':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            pointOff();
            pointOn();
            break;
        case '8':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            pointOff();
            pointOn();

            break;
        case '9':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            pointOn();
            break;
        case '0':
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            pointOff();
            hyphen();
            break;
        case ' ':
            espWord();
            break;
        default:
            printf("Error this character %c is  no recognized",character);
    }
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
    int i = 0;
    while (1) {
        if (curChar) {
            scanf("%s", &x);
            while (x[i]!='\0'){
                morseOut(x[i]);
                espLetter();
                i++;
            }
            curChar = 0;
        }
    }
    return EXIT_SUCCESS;
}

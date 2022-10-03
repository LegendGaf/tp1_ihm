#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void action_button(int x) {
    if (x == 0) {
        // Initialisation des LEDs utilisant le script
        system("/root/01-cmdLEDs/LEDs_off.sh");
// Infinite loop to handle recived characters
        char list[4][50] = {{"/sys/class/leds/beaglebone:green:usr0/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr1/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr2/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr3/brightness"}};
        FILE *led;
        for (int i = 0; i < 4; i++) {
            led = fopen(list[i], "w+");
            if (led == NULL) {
                printf("Error open file led!");
                exit(EXIT_SUCCESS);
            }
            fputs("1", led);
            fflush(led);
            sleep(1);
            fclose(led);
        }
    } else if (x == 1) {
// Initialisation des LEDs utilisant le script
        system("/root/01-cmdLEDs/LEDs_off.sh");
// Infinite loop to handle recived characters
        char list[4][50] = {{"/sys/class/leds/beaglebone:green:usr0/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr1/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr2/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr3/brightness"}};
        FILE *led;
        for (
                int i = 0;
                i < 4; i++) {
            led = fopen(list[i], "w+");
            if (led == NULL) {
                printf("Error open file led!");
                exit(EXIT_SUCCESS);
            }
            fputs("0", led);
            fflush(led);
            sleep(1);
            fclose(led);

        }
    } else if (x == 2) {
// Initialisation des LEDs utilisant le script
        system("/root/01-cmdLEDs/LEDs_off.sh");
// Infinite loop to handle recived characters
        char list[4][50] = {{"/sys/class/leds/beaglebone:green:usr0/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr1/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr2/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr3/brightness"}};
        FILE *led;
        for (
                int i = 0;
                i < 4; i++) {
            led = fopen(list[i], "w+");
            if (led == NULL) {
                printf("Error open file led!");
                exit(EXIT_SUCCESS);
            }
            while (sleep(6) == 0) {
                fputs("1", led);
                fflush(led);
                sleep(1);
                fputs("0", led);
                fflush(led);
                sleep(1);
                fclose(led);
            }
        }
    }
}

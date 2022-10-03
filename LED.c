void cli
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
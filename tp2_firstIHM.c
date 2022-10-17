#include <cdk/cdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
void action_button(int);
void action_button(int x) {
    if (x == 0) {
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
// Infinite loop to handle recived characters
        char list[4][50] = {{"/sys/class/leds/beaglebone:green:usr0/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr1/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr2/brightness"},
                            {"/sys/class/leds/beaglebone:green:usr3/brightness"}};
        FILE *led;
        int tmp = 2;
        while (tmp != 0) {
            for (int i = 0; i < 4; i++) {
                led = fopen(list[i], "w+");
                if (led == NULL) {
                    printf("Error open file led!");
                    exit(EXIT_SUCCESS);
                }
                fputs("1", led);
                fflush(led);
                sleep(1);
                fputs("0", led);
                fflush(led);
                sleep(1);
                fclose(led);
            }
            tmp--;
        }
    }
}

int main() {
    // Initialisation des LEDs utilisant le script
    system("/root/01-cmdLEDs/LEDs_off.sh");

    CDKSCREEN    *cdkscreen;
    WINDOW       *cursesWin;
    CDKDIALOG    *question;
    char *buttons[] = {"</24>ON", "</24>OFF", "</24>Blink"};
    char *message[10], *mesg[10], temp[100];
    int selection;

/* Initialisation */
    cursesWin = initscr();
    cdkscreen = initCDKScreen (cursesWin);

/* Initialisation des couleurs CDK */
    initCDKColor();

    /* texte de la question. */
    message[0]   = "<C>Pour allumer les Leds  clique sur \"ON\"";
    message[1]   = "<C>Pour eteindre les Leds clique sur \"OFF\"";
    message[2]   = "<C>Pour clignoter les Leds clique sur \"Clignoter\"";


    question = newCDKDialog (cdkscreen,
                             5,             /* coordonnee sur x : colonne de debut*/
                             5,             /* coordonnee sur y : ligne de debut en partant du haut */
                             message,       /* le tableau de caractere contenant la question */
                             3,             /* le nombre de lignes de la question */
                             buttons,       /* le tableau de caract¦res contenant les boutons */
                             3,             /* le nombre de boutons */
                             A_UNDERLINE,   /* Attribut ncurses du bouton selectionne */
                             FALSE,         /* Ligne separatrice? */
                             TRUE,          /* Dessiner une boite? */
                             FALSE);        /* Dessiner une ombre? */
    selection = activateCDKDialog (question, 0);

    /* Comment on a quitte et ce qu'on a repondu */
    if (question->exitType == vESCAPE_HIT) /* Sortie du widget par la touche ESC */
    {
        mesg[0] = "<C>Ceci est une fenetre de type popupLabel";
        mesg[1] = "<C>Elle regroupe un label centre et une fonction";
        mesg[2] = "<C>d'attente d'appui sur une touche quelconque";
        mesg[3] = "";
        mesg[4] = "<C>Vous avez quitte le dialog avec la touche Esc";
        mesg[5] = "<C>Appuyez sur une touche";
        popupLabel (cdkscreen, mesg, 6);
    }
    else if (question->exitType == vNORMAL) /* Sortie du widget par une selection */
    {
        mesg[0] = "<C>Ceci est une fenetre de type popupLabel";
        mesg[1] = "<C>Elle regroupe un label centre et une fonction";
        mesg[2] = "<C>d'attente d'appui sur une touche quelconque";
        mesg[3] = "";
        sprintf (temp, "<C>Vous avez choisi le bouton #%d,%s", selection,buttons[selection]);
        mesg[4] = copyChar(temp); /* fonction de CDK ~ strdup */
        action_button(selection);
        mesg[5] = "<C>Appuyez sur une touche";
        popupLabel (cdkscreen, mesg, 6);
    }

    message[0]   = "<C></U>Une fenetre de dialogue popupDialog";
    message[1]   = " ";
    message[2]   = "<C>Obligatoirement centree";
    message[3]   = "<C>Bouton active en inverse video";
    message[4]   = "<C>Boite et ligne separatrice";
    message[5]   = "<C>pas d'ombre";

    selection=popupDialog(cdkscreen,message,6,buttons,3);

    /* On affiche */
    refreshCDKScreen (cdkscreen);

    /* on nettoie avant de quitter */
    destroyCDKDialog (question);
    destroyCDKScreen (cdkscreen);
    endCDK();
}

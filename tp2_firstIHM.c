#include <cdk/cdk.h>

int main() {
    CDKSCREEN    *cdkscreen;
    WINDOW       *cursesWin;
    CDKDIALOG    *question;
    char *buttons[] = {"</24>Oui", "</24>Non", "</24>Grumpf"};
    char *message[10], *mesg[10], temp[100];
    int selection;

/* Initialisation */
    cursesWin = initscr();
    cdkscreen = initCDKScreen (cursesWin);

/* Initialisation des couleurs CDK */
    initCDKColor();

    /* texte de la question. */
    message[0]   = "<C></U>Une fenetre de dialogue CDKDIALOG";
    message[1]   = " ";
    message[2]   = "<C>On pose une question a";
    message[3]   = "<C>l'utilisateur";
    message[4]   = "<C>et il repond en choix ferme<!R>";
    message[5]   = "<C>avec un des boutons";

    question = newCDKDialog (cdkscreen,
                             5,             /* coordonnee sur x : colonne de debut*/
                             5,             /* coordonnee sur y : ligne de debut en partant du haut */
                             message,       /* le tableau de caractere contenant la question */
                             6,             /* le nombre de lignes de la question */
                             buttons,       /* le tableau de caractères contenant les boutons */
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

#include "C:\Users\ayman\CLionProjects\tp1_ihm\cdk.h"

int main() {

    CDKSCREEN    *cdkscreen;
    WINDOW       *cursesWin;
    CDKLABEL     *monlabel;
    char *letexte[4];

    letexte[0]="</31>Ligne en jaune sur fond cyan. <!31>";
    letexte[1]="</05>Ligne en blanc sur fond bleu. <!05>";
    letexte[2]="</26>Ligne en jaune sur fond rouge.<!26>";
    letexte[3]="<C>Ligne au couleurs par defaut.";

/* Initialisation CDK */
    cursesWin = initscr();
    cdkscreen = initCDKScreen (cursesWin);

/* Initialisation des couleurs CDK */
    initCDKColor();

/* Definition du label */
    monlabel = newCDKLabel(cdkscreen,
            /* coordonnee sur x : colonne de debut*/
                           CENTER,
            /* coordonnee sur y : ligne de debut en partant du haut */
                           CENTER,
            /* le tableau de caractere contenant le label */
                           letexte,
            /* le nombre de lignes a afficher */
                           4,
            /* Dessiner un boite autour? */
                           TRUE,
            /* Dessiner une ombre? */
                           FALSE);

/* On affiche */
    refreshCDKScreen (cdkscreen);

/* On attend que l'utilisateur appuie sur la touch espace */
    waitCDKLabel(monlabel,' ');

/* on nettoie avant de quitter */
    destroyCDKLabel (monlabel);
    destroyCDKScreen (cdkscreen);

    endCDK();
}


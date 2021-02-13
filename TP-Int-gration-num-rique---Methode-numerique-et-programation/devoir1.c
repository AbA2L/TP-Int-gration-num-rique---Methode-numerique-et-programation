#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Déclaration des fonctions mathématiques
long double f(long double x) {
    return 1/(5*pow(x,2)-3*x+7);
}
long double g(long double x) {
    return pow(sin(x), 6)* cos(x);
}
long double h(long double x) {
    return (x*cos(x)-sin(x))/pow(x, 2);
}

// Nomenclature des fonctions
char *functions = "fgh";

// Initialisation d'un Objet Surface:
// Qui est un intervale entre la surface max et la surface min.
typedef struct Surface {
    long double min;
    long double max;
} Surface;

// Fonctions d'integration qui calcule l'itervale de surface.
Surface integ(long double Xmin, long double Xmax, int n, int func, bool display) {

    //Affichage du texte
    if (display) {
        printf("Itégration de %c(x) de Xmin=%Lf à Xmax=%Lf en divisant par n=%d blocks... ", functions[func], Xmin, Xmax, n);
    }

    //
    Surface s;

    s.min = 0;
    s.max = 0;

    long double x, dx = (Xmax-Xmin)/n;

    for (int i=0; i<n; i++) {

        x = n*dx+Xmin;

        switch(func) {
            case 0 :
                s.max += dx * f(x); // Surface supérieure
                s.min += dx * f(x+dx); // Surface inférieure
                break;
            case 1 :
                s.max += dx * g(x); // Surface supérieure
                s.min += dx * g(x+dx); // Surface inférieure
                break;
            case 2 :
                s.max += dx * h(x); // Surface supérieure
                s.min += dx * h(x+dx); // Surface inférieure
                break;
        }

        //valeure absolue
        if (s.min<0) {
            s.min = -s.min;
        }
        if (s.max<0) {
            s.max = -s.max;
        }

    }
    if (display) {
        printf("done\n");
    }

    return s;
}

int intractifUI() {
    //initialisaton des variables input:
    int n; // Valeure de pas
    long double Xmin, Xmax; // Itervale de x
    int func; // Numero de la fonction

    //Saisie des valeurs
    printf("Domaine de X de Xmax à Xmin:\n");
    do {
        printf("Xmin = ");
        scanf("%Lf", &Xmin);
        printf("Xmax = ");
        scanf("%Lf", &Xmax);
    } while (Xmin > Xmax);

    printf("Nombre de dévisions:");
    printf("n = ");
    scanf("%d", &n);

    printf("Veuillez choisir une fonction:\n");
    printf("(0)- f(x)= 1/(5*x²-3x+7)\n");
    printf("(1)- g(x)= Sin(x)⁶ Cos(x)\n");
    printf("(2)- h(x)= ( x*Cos(x) - Sin(x) ) / x²\n");
    do {
        printf("Fonction N° ");
        scanf("%d", &func);
    } while (func < 0 || func > 2);

    // Calcul de l'intervale de surface
    Surface I1 = integ(Xmin, Xmax, n, func, 1);

    //affichage du résultat
    printf("(%Lf, %Lf)\n", I1.min, I1.max);

    return(0);
}

// Courbe de I en fonction de n
int curveI(long double Xmin, long double Xmax, int Nmax, int func) {
    
    FILE *fp=NULL;

    Nmax++;

    // Éditon du nom du fichier
    char filename[10];
    printf("Écriture dans: %s\n", filename);
    strcpy(filename, "*_n.dat");
    
    switch(func) {
        case 0 :
            filename[0] = 'f';
            break;
        case 1 :
            filename[0] = 'g';
            break;
        case 2 :
            filename[0] = 'h';
            break;
    }

    // Ovrir ou créer un fichier
    fp=fopen(filename,"w");
    printf("Itégration de %c(x) de Xmin=%Lf à Xmax=%Lf en divisant par n blocks, 0 < n <= %d  ... ", functions[func], Xmin, Xmax, Nmax);

    Surface I[Nmax];

    fprintf(fp,"# n\t - Imin\t - Imax\n");

    for (int i=0; i<Nmax; i++) {
        // Calcul de l'intervale de surface
        I[i] = integ(Xmin, Xmax, i, func, 0);

        if (i > 0) {
            // Écriture dans le fichier
            fprintf(fp,"%d\t %Lf\t %Lf\n", i, I[i].min, I[i].max);
        }
    }

    printf("done\n");

    
}

int exportDataset() {
    curveI(0, 10, 220, 0); // Courbe I1 en fonction de n
    curveI(0, (M_PI/2), 220, 1); // Courbe I2 en fonction de n
    curveI(0, M_PI, 220, 2); // Courbe I3 en fonction de n

    return 0;
}

int main() {

    // Programme interactif
    //intractifUI();
    // Calcul de l'intervale de surface
    Surface I1;
    
    I1 = integ(0, 10, 10, 0, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);
    I1 = integ(0, 10, 50, 0, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);
    I1 = integ(0, 10, 200, 0, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);

    I1 = integ(0, M_PI/2, 10, 1, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);
    I1 = integ(0, M_PI/2, 50, 1, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);
    I1 = integ(0, M_PI/2, 200, 1, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);

    I1 = integ(0, M_PI, 10, 2, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);
    I1 = integ(0, M_PI, 50, 2, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);
    I1 = integ(0, M_PI, 200, 2, 1);
    printf("(%Lf, %Lf)\n", I1.min, I1.max);

    return 0;
}
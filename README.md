# TP-Int-gration-num-rique---Methode-numerique-et-programation
Intégration numérique - Methode numerique et programation 2020/2021
Intégration numérique
Méthodes numériques et programmation

SAICH Aballache
L2 Physique - Année 2020/2021
Groupe A2 




INTRODUCTION
Une intégrale est une somme : on calcule la somme des valeurs de la fonction f pour x variant de a à b. Mais comme on ne peut pas calculer une infinité de points, on découpe l'intervalle [a..b] en n sous-intervalles de largeur (b-a)/n.
En utilisant la méthode des rectangles: On prend k=(b-a)/n, on fait alors varier x de a à a +(b-a)*(1-1/n) en ajoutant à chaque itération k à x. L'intégrale s'approche alors par la somme des f(x) multipliée par k.
MATERIALS
IDE: VSCode
Language: C
Compilateur: x86_64-linux-gnu GCC
Plotting: GNU Octave
PROCEDURE
Calcule numérique des intégrales avec la méthode des rectangles
Comparaison des valeurs obtenues à la valeur analytique.
L’effet de la valeur du pas sur les résultats.









Calcule numérique des intégrales avec la méthode des rectangles:
Librairies:
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
On commence par déclarer les fonctions à intégrer:
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




Objet Surface: La surface est un intervalle entre [Surface Min, Surface Max].

// Initialisation d'un Objet Surface:
// Qui est un intervalle entre la surface max et la surface min.
typedef struct Surface {
   long double min;
   long double max;
} Surface;

Fonction d'intégration: 
Les arguments: 
Xmin et Xmax: intervalle de x.
n: Nombre de divisions dans l’intervalle de x.
func: Fonction sur laquelle opérer l'intégration.
display: Boolean pour afficher le texte.
    Calcul de la surface d’une division:
Max: s.max = dx * f(x); // Surface supérieure
Min:  s.min = dx * f(x+dx); // Surface inférieure
// Fonctions d'intégration qui calcule l'intervalle de surface.
Surface integ(long double Xmin, long double Xmax, int n, int func, bool display) {
   //Affichage du texte
   if (display) {
       printf("Itégration de %c(x) de Xmin=%Lf à Xmax=%Lf en divisant par n=%d blocks... ", functions[func], Xmin, Xmax, n);
   }
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
Interface utilisateur:
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
Fonction main:
int main() {
 
   // Programme interactif
   intractifUI();
 
   return 0;
}
Compilation et execution:
aba2l@z-book:~/Documents/Studies/S3/Methodes Numeriques et Programmation/TP/Devoir1$ cat compile.sh
 
echo "Compilation du programme..."
gcc devoir1.c -lm -o devoir1
echo "Execution:"
./devoir1
echo "Fin d'éxecution"
rm devoir1
aba2l@z-book:~/Documents/Studies/S3/Methodes Numeriques et Programmation/TP/Devoir1$ ./compile.sh
Compilation du programme...
Execution:
Domaine de X de Xmax à Xmin:
Xmin = 0
Xmax = 10
Nombre de dévisions:n = 10
Veuillez choisir une fonction:
(0)- f(x)= 1/(5*x²-3x+7)
(1)- g(x)= Sin(x)⁶ Cos(x)
(2)- h(x)= ( x*Cos(x) - Sin(x) ) / x²
Fonction N° 0
)Itégration de f(x) de Xmin=0.000000 à Xmax=10.000000 en divisant par n=10 blocks... done
(0.017271, 0.020964)
Fin d'éxecution
Comparaison des valeurs obtenues à la valeur analytique:
Calcul des intégrales quand n=(10, 50, 200):
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
Valeurs retourné par notre fonction d'intégration:
Compilation du programme...
Execution:
Itégration de f(x) de Xmin=0.000000 à Xmax=10.000000 en divisant par n=10 blocks... done
(0.017271, 0.020964)
Itégration de f(x) de Xmin=0.000000 à Xmax=10.000000 en divisant par n=50 blocks... done
(0.020137, 0.020964)
Itégration de f(x) de Xmin=0.000000 à Xmax=10.000000 en divisant par n=200 blocks... done
(0.020753, 0.020964)
Itégration de g(x) de Xmin=0.000000 à Xmax=1.570796 en divisant par n=10 blocks... done
(0.000000, 0.000000)
Itégration de g(x) de Xmin=0.000000 à Xmax=1.570796 en divisant par n=50 blocks... done
(0.000000, 0.000000)
Itégration de g(x) de Xmin=0.000000 à Xmax=1.570796 en divisant par n=200 blocks... done
(0.000000, 0.000000)
Itégration de h(x) de Xmin=0.000000 à Xmax=3.141593 en divisant par n=10 blocks... done
(0.000000, 0.000000)
Itégration de h(x) de Xmin=0.000000 à Xmax=3.141593 en divisant par n=50 blocks... done
(0.000000, 0.000000)
Itégration de h(x) de Xmin=0.000000 à Xmax=3.141593 en divisant par n=200 blocks... done
(0.000000, 0.000000)
Fin d'éxecution
Valeurs analytiques:
Calculé avec l’outil en ligne: https://www.integral-calculator.com/
I1 = 0.298752
I2 = 0.142857
I3 = 0.142857


DATA
FONCTION
Dérivée en fonction de n (S Max; S Min)
VALEUR
ANALYTIQUE DE L’INTÉGRALE
n = 10
n =50
n = 200
f(x)
(0.017271, 0.020964)
(0.020137, 0.020964)
(0.020753, 0.020964)
0.298752
g(x)
(0.000000, 0.000000)
(0.000000, 0.000000)
(0.000000, 0.000000)
0.142857
h(x)
(0.000000, 0.000000)
(0.000000, 0.000000)
(0.000000, 0.000000)
0.000000
    REMARQUES
Plus la valeur du pas n est grande, plus I se rapproche de la valeur analytique.
On arrive pas à calculer l’intégrale de g(x), on va supposer que c’est par manque de précision (On a toujours les mêmes résultats si on remplace tous les float par long float).










L’effet de la valeur du pas sur les résultats:
La valeur du pas k est inversement proportionnelle au nombre de divisions n.
 k=xmax-xminn
L’intégration I en fonction de n:
Fonction d'extraction des données:
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
Dessin graphique avec Octave:
data = load('f_n.dat');
n= data(:,1);
Smin = data(:,2);
Smax = data(:,3);
subplot (1,3,1, "align");
plot (n, Smin, "r-", n, Smax, "g-", n, 0.020964, "k.-",
10, data(10, 2), "cx",
10, data(10, 3), "bx",
50, data(50, 2), "cx",
50, data(50, 3), "bx",
200, data(200, 2), "cx",
200, data(200, 3), "bx");
xlim([0 205])
ylim([0 0.025])
grid on;
grid minor;
xlabel ("n");
ylabel ("Surface");
title ("Variation de I1 en fonction de n");
legend ("I1min", "I1max", "Integrale de f");
data = load('g_n.dat');
n= data(:,1);
Smin = data(:,2);
Smax = data(:,3);
subplot (1,3,2, "align");
plot (n, Smin, "r-", n, Smax, "g-", n, 0.000000, "k.-",
10, data(10, 2), "cx",
10, data(10, 3), "bx",
50, data(50, 2), "cx",
50, data(50, 3), "bx",
200, data(200, 2), "cx",
200, data(200, 3), "bx");
xlim([0 205])
ylim([-0.01 0.12])
grid on;
grid minor;
xlabel ("n");
ylabel ("Surface");
title ("Variation de I2 en fonction de n");
legend ("I2min", "I2max", "Integrale de g");
data = load('h_n.dat');
n= data(:,1);
Smin = data(:,2);
Smax = data(:,3);
subplot (1,3,3, "align");
plot (n, Smin, "r-", n, Smax, "g-", n, 0.000000, "k.-",
10, data(10, 2), "cx",
10, data(10, 3), "bx",
50, data(50, 2), "cx",
50, data(50, 3), "bx",
200, data(200, 2), "cx",
200, data(200, 3), "bx");
xlim([0 205])
ylim([-0.12 1])
grid on;
grid minor;
xlabel ("n");
ylabel ("Surface");
title ("Variation de I3 en fonction de n");
legend ("I3min", "I3max", "Integrale de h");











Pour obtenir les graphiques suivants:





RÉSULTATS
On remarque dans tous les graphiques que plus n tends vers l’infini I tends vers la valeur analytique de l’intégrale.
CONCLUSION
On peut calculer approximativement l'intégrale d’une fonction numériquement en tendant le nombre de divisions n vers l’infini.
Selon la relation entre k et n on peut en déduire que quand k tends vers 0 on auras I qui tends vers la valeur analytique du calcul l’intégrale.
CODE SOURCE:
Joint à ce fichier
Code source disponible sur GitHub: https://github.com/AbA2L/TP-Int-gration-num-rique---Methode-numerique-et-programation




REFERENCES
https://www.developpez.net/forums/d1901/c-cpp/c/calcul-integral-c/#post11443
https://notebooks.lecluse.fr/maths/ts/algorithmique/2020/03/07/TS-Activite-methode-rectangles.html
https://cboumaths.files.wordpress.com/2020/04/lcm2020_37.pdf

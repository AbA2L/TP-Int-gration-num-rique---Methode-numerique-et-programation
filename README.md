# TP Intégration numérique - Methode numerique et programation
Intégration numérique - Methode numerique et programation 2020/2021
Intégration numérique
Méthodes numériques et programmation

AbA2L
L2 Physique - Année 2020/2021

   ##INTRODUCTION
Une intégrale est une somme : on calcule la somme des valeurs de la fonction f pour x variant de a à b. Mais comme on ne peut pas calculer une infinité de points, on découpe l'intervalle [a..b] en n sous-intervalles de largeur (b-a)/n.
En utilisant la méthode des rectangles: On prend k=(b-a)/n, on fait alors varier x de a à a +(b-a)*(1-1/n) en ajoutant à chaque itération k à x. L'intégrale s'approche alors par la somme des f(x) multipliée par k.

   ##MATERIALS
      - IDE: VSCode
      - Language: C
      - Compilateur: x86_64-linux-gnu GCC
      - Plotting: GNU Octave
   ##PROCEDURE
      - Calcule numérique des intégrales avec la méthode des rectangles
      - Comparaison des valeurs obtenues à la valeur analytique.
      - L’effet de la valeur du pas sur les résultats.

   ##RÉSULTATS
On remarque dans tous les graphiques que plus n tends vers l’infini I tends vers la valeur analytique de l’intégrale.

   ##CONCLUSION
On peut calculer approximativement l'intégrale d’une fonction numériquement en tendant le nombre de divisions n vers l’infini.
Selon la relation entre k et n on peut en déduire que quand k tends vers 0 on auras I qui tends vers la valeur analytique du calcul l’intégrale.

   ##CODE SOURCE:
      - Joint à ce fichier.
      - Code source disponible sur GitHub: https://github.com/AbA2L/TP-Int-gration-num-rique---Methode-numerique-et-programation




   ##REFERENCES
https://www.developpez.net/forums/d1901/c-cpp/c/calcul-integral-c/#post11443
https://notebooks.lecluse.fr/maths/ts/algorithmique/2020/03/07/TS-Activite-methode-rectangles.html
https://cboumaths.files.wordpress.com/2020/04/lcm2020_37.pdf

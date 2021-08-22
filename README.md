# 42 get_next_line
## Note obtenue 102/100
### Rendu pour compiler et fonctionner sous MacOS Mojave

Petit projet dont le but est de recoder une fonction permettant d'obtenir la première ligne non lue d'un fichier. (ou d'un file descriptor). 

Le prototype de la fonction est le suivant :
  int get_next_line(char **line, int fd);

### Paramètres    
**line : pointeur sur un char * qui permettra de stocker la ligne lue.  
fd     : numéro du file descriptor dans lequel on veut lire.  
  
### Valeurs de retour
1 : Une ligne a été lue avec succès.  
0 : La derniere ligne a été lue avec succés.  
-1 : Erreur.  
 
### Fonctions autorisés 
read : permet de lire dans un fichier.   
malloc : fonction qui permet d'allouer de la mémoire.   
free : permet de rendre au systéme la mémoire empruntée par malloc.   

### Notions apprises 
Fonctionnement des variables static dans le corps d'une fonction en C.  
Utilisation d'un buffer de taille défini par l'utilisateur.

### Protocole utilisé pour venir à bout du projet.
Vérifier si le fd existe.
Si oui, commencez à lire le fichier par bloc de la taille défini par le BUFFER_SIZE entre 1 et 1.000.000 par exemple.  

Analyser la ligne : Si elle contient un "\n", cela signifie un saut à la ligne.  
Dans ce cas là,  allouer la place nécessaire dans le paramètre line et récuperer tout les caractères jusqu'au "\n" dans le paramètre "\.   

Les caractères suivants seront stockés dans un static char[BUFFER_SIZE] et on retourne 1 pour indiquer qu'une ligne à été lue.
Ils pourront être récupéres au prochain appel de get_next_line.
Si elle ne contient pas de "\n", stocker les caractères lues et relire un bloc de la taille défini par BUFFER_SIZE. 
Et ainsi de suite jusqu'a trouver un "\n".  

Si elle contient un "\0", c'est a dire un EOF (End of file = fin de fichier). 
Même protocole que dans le cadre d'un "\n" mais on retournera 0 pour indiquer une fin de fichier.  

Toute erreur quelque soit sa forme, impossible d'ouvrir le fd, erreur d'allocation mémoire par exemple fera retourner un -1 a get_next_line.

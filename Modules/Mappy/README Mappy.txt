Explication de Mappy :

Figure : contient Vector de Point
Point : X, Y
Axes : Point + Orientation
Map : contient Vector de Figures
Qmaths, quelques trucs mathématiques, qu'on a déjà dans General/Math je crois. Je vais fusionner plus tard.


* La configuration de la carte se fait dans le constructeur de la classe Map (Map.cpp).
 On y rajoute des polygones (figures). Il faut bien créer les points dans l'ordre.

 * La classe restangle je ne l'est pas encore testée.

* La classe axes représente un robot : 1 point (X,Y) et une orientation.

* Dans la classe mappy, je réalise un calcul d'intersection, je vais par la suite le mettre dans une méthode séparée.


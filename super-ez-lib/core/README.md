# core

Le module core est une couche construite au-dessus de la bibliothèque EZDraw++ et qui a pour but de la cacher.
Cela nous permet en suite de construire par-dessus d’autres modules avec plus de « cohésion » que si nous avions utilisé EZDraw++ directement.

### Application
C’est une simple surcharge de la classe EZDraw.

### Window
C’est une EZWindow avec en plus :
- le gestion d’évènements qui passe par KeyEvent et MouseEvent
- une méthode updateEvent qui est appelée à un intervalle de temps fixe
- les méthodes de dessin délégué à Canvas

#### TODO
- Pouvoir changer l'intervalle de temps entre les updateEvent

### Point
Une classe qui représente un point en 2D, mais qui fait beaucoup plus :
- les coordonnées peuvent être relative à un autre point
- plusieurs points peuvent être regroupé pour synchroniser leurs coordonnées
- un système de correction de coordonnées

#### TODO
- Remplacer le système de correction de coordonnées avec les std::function par de l’héritage
- Être compatible avec BOOST serialization

### Color
Une couleur pouvant être manipulé avec le système [RGB](https://fr.wikipedia.org/wiki/Rouge_vert_bleu) ou [HSV](https://fr.wikipedia.org/wiki/Teinte_Saturation_Valeur).

### Font
Représente une police fournie par défaut.

### Image
C'est une EZImage qui utilise Pixel.

#### TODO
- Pouvoir être utilisé comme un conteneur de la STL
- Être compatible avec BOOST serialization

### Pixel
Le même principe qu'EZPixel mais en utilisant la classe Color.

#### TODO
- Être compatible avec BOOST serialization

### Canvas et KeyEvent TODO
- Pouvoir afficher les accents provenant du code et du clavier

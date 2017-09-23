# core

Le module core est une couche construite par-dessus la bibliothèque EZDraw++.
Le reste de l'application est donc indépendant de l'interface d'EZDraw++.
Des fonctionnalités qui ne sont pas dans EZDraw++ ont aussi été ajouté.

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

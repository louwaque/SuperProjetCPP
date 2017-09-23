# graphics

Le module graphics apporte toutes les fonctionnalités de dessins d'objet complexe, comme des formes ou des images.

### GraphicsItem

C'est la classe qui représente un objet dessinable.
L'objet peut changer de couleur, de position, ...

Un arbre de GraphicsItem peut être construit pour créer des compositions d'objet complexe.
L'idée principale et de rendre la position des (objets) enfants relative à celle de leur (objet) parent.
Ainsi bouger le parent fait bouger tous ses enfants.

#### TODO
- Revoir la gestion de la mémoire, car mettre des shared_ptr partout n'est pas vraiment une solution
- Revoir la gestion du focus

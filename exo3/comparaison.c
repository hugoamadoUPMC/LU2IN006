/*Pour comparer les temps de calcul entre les deux structures (liste chaînée et table de hachage) pour la recherche d'un ouvrage par son numéro, son titre et son auteur, nous devons considérer plusieurs facteurs :

Recherche par numéro :

Liste chaînée : La recherche par numéro dans une liste chaînée implique de parcourir la liste jusqu'à trouver le livre correspondant au numéro recherché. Dans le pire des cas, la complexité de cette opération 
est linéaire par rapport à la taille de la liste.
Table de hachage : En utilisant la clé (numéro) comme indice dans la table de hachage, la complexité de la recherche est généralement constante, en supposant que les collisions sont gérées efficacement.
Recherche par titre ou auteur :

Liste chaînée : La recherche par titre ou auteur dans une liste chaînée implique également de parcourir la liste et de comparer les titres ou auteurs jusqu'à trouver la correspondance. Dans le pire des cas, 
la complexité est linéaire.
Table de hachage : La recherche par titre ou auteur dans une table de hachage est similaire à la recherche par numéro. Cependant, la qualité de la fonction de hachage peut affecter les performances. 
Si les collisions sont fréquentes, la complexité de la recherche peut être linéaire dans le pire des cas.
Comparaison des performances :

Pour un grand nombre d'ouvrages, la table de hachage est généralement plus efficace pour la recherche par numéro, titre ou auteur, surtout si la fonction de hachage est bien choisie et les collisions sont minimisées.
La liste chaînée peut être plus simple à implémenter, mais elle peut devenir inefficace pour les grandes collections d'ouvrages, en particulier pour les recherches par titre ou auteur.
En termes de temps de calcul, la table de hachage offre généralement des performances meilleures, surtout pour les recherches par auteurs dans notre cas. La table de hachage permet de se rapprocher rapidement de
l'élément rechercher.
En résumé, la structure la plus appropriée dépend de plusieurs facteurs tels que la taille de la collection, la fréquence des opérations de recherche, et la qualité des données. 
Pour une recherche efficace sur de grandes collections d'ouvrages, la table de hachage est souvent préférable, mais pour des ensembles de données plus petits ou des opérations de recherche moins fréquentes, 
une liste chaînée peut être adéquate.*/


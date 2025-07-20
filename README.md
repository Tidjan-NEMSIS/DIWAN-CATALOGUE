# Diwan-catalogue

**Diwan-catalogue** est une application Qt 6.9 moderne pour la gestion de maisons, avec analyse de performance de fonctions de hachage et visualisation graphique.

## Fonctionnalités principales
- Gestion de maisons (ajout, suppression, recherche, navigation)
- 4 photos par maison (2 intérieures, 2 extérieures)
- Table de hachage avec 3 fonctions (f1, f2, f3) + mode sans hachage
- Analyse de performance (QElapsedTimer, export CSV/JSON)
- Visualisation des courbes avec Qt Charts
- Interface moderne : thème sombre, glassmorphisme, menus Windows

## Installation
1. **Qt 6.9** (Qt Creator recommandé)
2. **Python 3.x** (pour générer la base de données)

## Génération de la base de données
```bash
cd data
python generate_maison_db.py
```

## Compilation et exécution
- **Avec Qt Creator** :
  1. Ouvrir `Diwan-catalogue.pro`
  2. Sélectionner un kit Qt 6.9
  3. Compiler et exécuter
- **Avec CMake** :
  ```bash
  mkdir build && cd build
  cmake ..
  cmake --build .
  ./GestionImmobiliere
  ```

## Structure du projet
```
/src         – sources C++
/images      – 4 photos par maison
/data        – maison.db, script Python, SQL
/docs        – README, justifications, captures UI
/build       – fichiers générés
```

## Interface graphique
- Menu Windows : Base, Maison, FonctionHachage, Courbes, Aide, Quitter
- Zone photo (navigation Précédent/Suivant)
- Style sombre et glassmorphique

## Logique métier
- TableHachage (chaînage linéaire)
- Fonctions de hachage f1, f2, f3
- Persistance SQLite
- Export CSV/JSON
- Courbes Qt Charts

## Auteurs
- Adaptation et refonte : [Votre nom]
- Projet d'origine : https://github.com/alimar440/TurboSearch

## Captures d'écran
*(À insérer après build)*



## Fonctionnalités

### Page d'Accueil

![Page d'Accueil](images/page_accueil.png)

Accédez à toutes les fonctionnalités depuis la page d'accueil.

### Insertion

![Insertion](images/page_insertion.png)

Ajoutez de nouvelles voitures avec des informations détaillées.

### Recherche

![Recherche](images/page_recherche.png)

Trouvez rapidement des voitures par matricule.

### Suppression

![Suppression](images/page_suppression.png)

Supprimez des enregistrements de voitures par matricule.

### Affichage

![Affichage](images/visualisation_donnees.png)

Visualisez la liste des voitures enregistrées.



## Installation

1. Clonez le dépôt :
   ```sh
   git clone https://github.com/alimar440/turbosearch.git

# Gestion Immobilière

Application de gestion de biens immobiliers développée en C++/Qt avec une table de hachage.

## Fonctionnalités

- Gestion complète des biens immobiliers (ajout, modification, suppression, recherche)
- Stockage optimisé avec table de hachage
- Interface graphique moderne avec thème sombre et effets glassmorphisme
- Gestion des photos (jusqu'à 4 photos par bien)
- Analyse des performances des fonctions de hachage
- Export/Import des données
- Base de données SQLite

## Prérequis

- Qt 6.2 ou supérieur
- Compilateur C++17 (GCC, MSVC, ou Clang)
- CMake 3.16 ou supérieur
- SQLite 3

## Installation

### Windows

1. Installer Qt 6 via le Qt Online Installer
2. Cloner le repository :
   ```bash
   git clone https://github.com/votre-repo/gestion-immobiliere.git
   cd gestion-immobiliere
   ```
3. Configurer avec CMake :
   ```bash
   mkdir build
   cd build
   cmake ..
   ```
4. Compiler :
   ```bash
   cmake --build .
   ```

### Linux

1. Installer les dépendances :
   ```bash
   sudo apt-get update
   sudo apt-get install qt6-base-dev qt6-charts-dev sqlite3
   ```
2. Suivre les mêmes étapes que pour Windows (2-4)

## Structure du Projet

```
gestion-immobiliere/
├── src/
│   ├── models/         # Classes métier (Maison, TableHachage)
│   ├── database/       # Gestion de la base SQLite
│   ├── ui/            # Interface graphique
│   └── utils/         # Utilitaires (Performance, etc.)
├── data/              # Base de données et scripts SQL
├── images/            # Photos d'exemple
├── docs/              # Documentation
└── build/             # Dossier de compilation
```

## Utilisation

1. Lancer l'application
2. Charger la base de données via le menu "Base > Charger"
3. Utiliser les menus pour :
   - Gérer les biens (ajouter, modifier, supprimer)
   - Changer la fonction de hachage
   - Visualiser les performances
   - Exporter les données

## Fonctions de Hachage

L'application implémente trois fonctions de hachage différentes :

1. F1 : Hachage par division
   - Utilise le modulo pour distribuer les clés
   - Simple et efficace pour des distributions uniformes

2. F2 : Hachage par multiplication
   - Utilise la méthode de Knuth
   - Meilleure distribution pour des clés similaires

3. F3 : Hachage par chaînage
   - Combine division et multiplication
   - Optimisé pour réduire les collisions

## Performance

Les performances sont mesurées pour :
- Temps d'insertion
- Temps de recherche
- Nombre de collisions
- Taux d'occupation

Les résultats peuvent être exportés en CSV ou JSON.

## Contribution

1. Fork le projet
2. Créer une branche pour votre fonctionnalité
3. Commiter vos changements
4. Pousser vers la branche
5. Ouvrir une Pull Request

## Licence

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

# Documentation technique – Diwan-catalogue

## Fonctions de hachage
- **f1** : Somme des codes ASCII modulo taille (simple, rapide, mais sensible aux permutations)
- **f2** : Polynôme de Horner (meilleure répartition, classique pour les chaînes)
- **f3** : Multiplication par un nombre premier (bonne dispersion, inspirée de Java)

## Chaînage linéaire
- Permet de gérer efficacement les collisions
- Simple à implémenter et à analyser
- Adapté à une table de taille dynamique

## Utilisation avancée
- Modifier la taille de la table pour tester l'impact sur les collisions
- Exporter les mesures en CSV/JSON pour analyse externe
- Utiliser Qt Charts pour comparer visuellement les fonctions

## Captures d'écran
*(À ajouter après exécution)*

## Exports de performance
*(À ajouter après tests)*

## TODO
- Rédiger la documentation utilisateur finale
- Ajouter des exemples d'utilisation avancée 
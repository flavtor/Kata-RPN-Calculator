# RPN Calculator

Ce projet implémente un calculateur RPN (Reverse Polish Notation) en C.
en se limitant aux opérateurs suivants :
- "+"
- "-"
- "*"


## Structure du projet

- `main.c` : Point d'entrée du programme
- `rpn_calculator.c` : Contient la logique du calculateur RPN
- `rpn_calculator.h` : Header file pour le calculateur RPN
- `tests.c` : Contient les tests unitaires
- `Makefile` : Pour compiler le projet et exécuter les tests avec la couverture de code

## Prérequis

Avant de commencer, assurez-vous d'avoir les outils suivants installés :

- **GCC** : Le compilateur C pour compiler le code.
- **Make** : Utilisé pour automatiser le processus de compilation et de nettoyage.

### Installation des prérequis

Pour installer GCC et Make sur Linux (Ubuntu ou Debian) :

```bash
sudo apt update
sudo apt install gcc make
```

## Compilation et exécution

Pour compiler le programme principal :

```sh
make main
./main
```
Pour compiler et exécuter les tests :
```sh
make tests
./tests
```
Pour générer le rapport de couverture de code :
```sh
gcov rpn_calculator.c
```

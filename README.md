# RPN Calculator

Ce projet implémente un calculateur RPN (Reverse Polish Notation) en C.

## Structure du projet

- `main.c` : Point d'entrée du programme
- `rpn_calculator.c` : Contient la logique du calculateur RPN
- `rpn_calculator.h` : Header file pour le calculateur RPN
- `tests.c` : Contient les tests unitaires
- `Makefile` : Pour compiler le projet et exécuter les tests avec la couverture de code

## Compilation et exécution

Pour compiler le programme principal :

```sh
make main
./main

Pour compiler et exécuter les tests :

make tests
./tests

Pour générer le rapport de couverture de code :

gcov rpn_calculator.c

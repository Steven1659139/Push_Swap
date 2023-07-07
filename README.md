# Push_Swap

Push_Swap est un projet de l'école 42. L'objectif de ce projet est de trier des données sur une pile, avec un ensemble d'instructions limité, en moins de coups possibles. Pour cela, nous disposons de deux piles appelées pile A et pile B.

## Description

Le but de ce projet est de créer un programme capable de trier une pile de nombres entiers en utilisant les opérations suivantes :

- `sa` : échange les deux premiers éléments au sommet de la pile A.
- `sb` : échange les deux premiers éléments au sommet de la pile B.
- `ss` : `sa` et `sb` en même temps.
- `pa` : déplace le premier élément de la pile B au sommet de la pile A.
- `pb` : déplace le premier élément de la pile A au sommet de la pile B.
- `ra` : fait une rotation de la pile A vers le haut.
- `rb` : fait une rotation de la pile B vers le haut.
- `rr` : `ra` et `rb` en même temps.
- `rra` : fait une rotation de la pile A vers le bas.
- `rrb` : fait une rotation de la pile B vers le bas.
- `rrr` : `rra` et `rrb` en même temps.

## Utilisation

1. **Compilation** :
   Pour compiler Push_Swap, naviguez jusqu'au répertoire du projet et utilisez la commande `make`. Cela créera deux exécutables : `push_swap` et `checker`.

    ```bash
    make
    ```

2. **Exécution** :
   
    - Pour exécuter `push_swap`, utilisez l'exécutable suivi d'une liste d'entiers distincts. Le programme renverra une série d'instructions qui trieront la liste.

        ```bash
        ./push_swap 4 67 3 87 23
        ```

    - Pour exécuter `checker`, utilisez l'exécutable suivi d'une liste d'entiers distincts puis entrez les instructions de tri une par une. `checker` indiquera si les instructions trient correctement la liste.

        ```bash
        ./checker 4 67 3 87 23
        sa
        rra
        ```

## Licence

Ce projet est sous licence [MIT](LICENSE).

# Push_swap

Projet de l'École 42 : trier une pile de nombres entiers en utilisant le
moins de mouvements possible, avec seulement deux piles (`a` et `b`) et un
jeu d'instructions limité.

## Principe

Le programme reçoit en argument une liste de nombres entiers distincts,
placés au départ dans la pile `a`. Il doit afficher sur la sortie standard
la suite d'instructions qui permet de trier `a` par ordre croissant, en
utilisant au besoin une pile auxiliaire `b` comme espace de travail.

Instructions disponibles :

| Instruction | Effet |
|---|---|
| `sa` / `sb` / `ss` | échange les deux premiers éléments de `a` / `b` / des deux |
| `pa` / `pb` | déplace le premier élément de `b` vers `a` / de `a` vers `b` |
| `ra` / `rb` / `rr` | fait remonter le premier élément de `a` / `b` / des deux en dernière position |
| `rra` / `rrb` / `rrr` | fait descendre le dernier élément de `a` / `b` / des deux en première position |

Un programme `checker` (fourni avec le sujet, binaires `checker_linux` /
`checker_Mac` inclus) rejoue ces instructions sur la pile de départ et
valide que le résultat est trié.

## Algorithme

- Les nombres sont d'abord **indexés** (`index.c`, `biggy.c`) : chaque
  valeur reçoit un rang relatif, ce qui permet de raisonner sur des
  positions plutôt que sur les valeurs brutes.
- Les listes de petite taille (2, 3, 4 ou 5 éléments) sont triées par des
  cas particuliers câblés à la main (`small_list.c`), nettement plus
  rapides qu'un algorithme général sur un si petit nombre d'éléments.
- Pour les listes plus grandes, les éléments sont répartis entre les piles
  `a` et `b` par paquets (**padding**/chunks, calculés dans `padding.c` et
  `mediane.c`), puis réinjectés dans `a` dans le bon ordre
  (`butterfly.c`). La taille des paquets est adaptée au nombre
  d'éléments à trier pour limiter le nombre total de rotations et de push.
- Le parsing des arguments (`parsing_utils.c`, `ft_atol.c`) vérifie que les
  entrées sont des entiers valides (dans les bornes d'un `int`), rejette
  les doublons et gère les listes déjà triées sans effectuer de mouvement
  inutile.

## Compilation

```bash
make        # compile push_swap (dépend de libft/, compilée automatiquement)
make clean  # supprime les fichiers objets
make fclean # supprime aussi l'exécutable
make re     # fclean + all
```

## Utilisation

```bash
./push_swap 2 1 3 6 5 8
./push_swap "4 67 3 87 23"
```

Sans argument, ou avec une seule valeur, le programme ne produit aucune
instruction. Une entrée invalide (non numérique, hors bornes `int`,
doublon) retourne une erreur.

### Vérifier le résultat

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker_Mac $ARG   # ou checker_linux sur Linux
```

Compter le nombre de mouvements générés :

```bash
./push_swap $ARG | wc -l
```

## Structure

- `push_swap.c` — point d'entrée et parsing initial.
- `parsing_utils.c`, `ft_atol.c` — validation et conversion des arguments.
- `butterfly.c`, `padding.c`, `mediane.c` — cœur de l'algorithme de tri par
  paquets pour les grandes listes.
- `small_list.c`, `biggy.c`, `number.c` — tri spécialisé des petites listes
  et recherche de min/max.
- `index.c` — indexation des valeurs et détection d'une liste déjà triée.
- `move_rrr_sasb.c`, `move_pa_ra.c`, `pop_and_push.c` — implémentation des
  onze instructions de pile.
- `push_swap_utils.c`, `ft_lst_functions.c`, `ft_datalstsize.c` — gestion de
  la liste chaînée et libération mémoire.
- `libft/` — bibliothèque C personnelle (projet `libft` de 42) utilisée
  comme dépendance.

# Corewar
Projet Final de 1ère année à {Epitech}.

## Intro
Le but de ce projet est de créer des champions qui se départagerons dans une arène nommée Machine Virtuelle afin d'en prendre le contrôle.
Le jeu va donc crée une **Machine Virtuelle** dans laquelle des programmes (écrit par le joueur) feront face dans le seul et unique but de survivre en éxécutant un certain nombre d'instructions.

Le projet est divisé en trois parties distinctes:

  **Assembleur:**
  
Les champions sont écrits sur un language basé sur l'assembleur à savoir le "RedCode".  
Les fichiers vont par la suite être transformer en éxécutable afin de pouvoir être utilisés par la Machine Virtuelle.

  **Machine Virtuelle:**

C'est l'arène où les champions se confrontent. Elle charge les différents champions et leur dédie l'espace mémoire nécessaire à leur éxécution. Elle doit être capable d'en gérer plusieurs à la fois.

  **Champions:**

Les champions sont crées en language assembleur de manière à être interprétable par la Machine Virtuelle.  
Ils doivent être capable de se confronter les uns aux autres et de sortir victorieux de l'arène.


## Utilisation

### Lancement de l'assembleur

Après avoir cloné le projet, exécutez la commande ```make``` pour installer l'assembleur.

Une fois installé, lancez l'assembleur avec la commande suivante:

```./asm [fichier_à_compiler.s] && hexdump -C [fichier_à_compiler.cor] ```

La fonction ```hexdump``` permet de convertir les fichiers en hexa afin qu'ils soit plus lisibles.

Pour voir les différents arguments possibles, veuillez vous référez au ```-help```.

### Lancement de la machine virtuelle

Pour lancer la machine virtuelle, rien de plus simple:

```./corewar [champions_1.cor] [champion_2.cor] [champion_3.cor] [champion_4.cor]```

Pour lancer le client graphique, il est nécessaire d'avoir installer la lib Ncurses.

Voici un rappel des différents arguments possibles :

```
USAGE
  ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
  
DESCRIPTION
  -dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn’t  
                  already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)
 
  -n prog_number sets the next program’s number. By default, the first free number in the parameter order
  
  -a load_address sets the next program’s loading address. When no address is specified,  
                  optimize the addresses so that the processes are as far away from each  
                  other as possible. The addresses are MEM_SIZE modulo
 ```

## Trailer

[![Corewar](https://www.djahid-bousba.com/static/media/corewar.ee0e946c.png)](https://www.youtube.com/watch?v=ty-CPU3o9Ow)

## Auteur 

  * **Djahid Bousba** - [Djahid.Bousba](https://www.djahid-bousba.com/)
  * **Laurent Sferlazza**
  * **Hugo Gualtieri**
  * **Lucas Torrent**

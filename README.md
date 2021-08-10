# Avalanche simulation

### Useful links

[game of life example with SFML | GitHub](https://github.com/brainstew927/game-of-life/blob/master/src/gameLogic.cpp)

[SFML](https://www.sfml-dev.org/index.php)

#### cmake

[Get started with CMake tools on linux | VSCode Tuto](https://code.visualstudio.com/docs/cpp/CMake-linux)

[cmake doc (3.21.1)](https://cmake.org/cmake/help/latest/manual/cmake.1.html)



## Instructions

Je t’ai mis les
liens interressants pour la construction du programme du tipe :

-https://www.mathenjeans.fr/sites/default/files/comptes-rendus/avalanche_simulator_casagrande.pdf

C’est en
anglais mais tu devrais comprendre, ça donne un programme en C++ et
explique à quoi il sert, il a pas l’air mal.

-http://pcsi.kleber.free.fr/IPT/doc/TP07_avalanches.pdf

C’est le même
principe expliqué  en français et pour un programme en python

* -Etudes
  expérimentales d'avalanches granulaires (archives-ouvertes.fr)
* Avalanches
  granulaires en milieu fluide (archives-ouvertes.fr)
* Modélisation
  granulaire d’une avalanche (enseeiht.fr)

Ce sont des
liens pour mieux comprendre au cas où t’en aurais besoin

-https://github.com/lcox74/Project-Avalanche

Ça j’ai pas
tout compris c’est en anglais mais ca  parle d’algorithme sur les
avalanches au cas où

Si tu as des
meilleurs idées pour nous sauver d’un fiascos possible ne te gênes
pas, mais l’algorithme 1 semble pas mal du tout pour l’instantPour mon cher Flouzi que j’aime beaucoup malgré ses quelques

défauts (vraiment pas nombreux) comparé à ses IMMENCES qualités
(vraiment très nombreuses)

## Installation

### sfml

Follow the [official SFML guide](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

`sudo apt-get install libsfml-dev`: install sfml.

### CMake

Use [KitWare](https://apt.kitware.com/) APT repository to download the latest version of CMake. Follow the post by [Teocci](https://askubuntu.com/users/454224/teocci) on this [StackOverflow issue about CMake newest version install](https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line), to install the latest version of CMake.

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ ~❯❯ cmake --version
cmake version 3.21.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## build & run

1. Move to`build/`.
2. Pre-build with`cmake ..` to pre-build Makefile and sources. The`..` specify to put this build inside the cwd.
3. Build with`make`. This generate the executable.
4. Run the executable.

Example:

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ avalanche❯❯ cd build/
(base)  ❮ onyr ★  kenzae❯ ❮ build❯❯ cmake ..
-- Configuring done
-- Generating done
-- Build files have been written to: /home/onyr/Documents/code/matthieu/avalanche/build
(base)  ❮ onyr ★  kenzae❯ ❮ build❯❯ make
Consolidate compiler generated dependencies of target avalanche
[ 50%] Building CXX object CMakeFiles/avalanche.dir/src/Main.cpp.o
[100%] Linking CXX executable avalanche
[100%] Built target avalanche
(base)  ❮ onyr ★  kenzae❯ ❮ build❯❯ ./avalanche 
```


## commands

### CMake

`cmake -S . -B ./build/`: run CMake to build the project. `-S` is the source directory where the `CMakeLists.txt` file is located.

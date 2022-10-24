# Avalanche simulation

### Useful links

[game of life example with SFML | GitHub](https://github.com/brainstew927/game-of-life/blob/master/src/gameLogic.cpp)

[SFML](https://www.sfml-dev.org/index.php) and [SFML tutos](https://www.sfml-dev.org/tutorials/2.5/)

#### C++ recalls

[basic object instantiation: heap vs stack](https://stackoverflow.com/questions/677632/different-methods-for-instantiating-an-object-in-c)

There are two ways to make/create an object in c++.

First one is :

```cpp
MyClass myclass; // if you only need to call the default constructor  
MyClass myclass(12); // if you need to call constructor with parameters*
```

Second one is :

```cpp
MyClass *myclass = new MyClass();// if you only need to call the default constructor
MyClass *myclass = new MyClass(12);// if you need to call constructor with parameters
```

In c++ if you use the `new` keyword, object will be stored in heap.

#### cmake

[Get started with CMake tools on linux | VSCode Tuto](https://code.visualstudio.com/docs/cpp/CMake-linux)

[Getting started with cmake | RIP Tutorial](https://riptutorial.com/cmake)

[cmake doc (3.21.1)](https://cmake.org/cmake/help/latest/manual/cmake.1.html)

#### SFML

[Opening and managing a SFML window](https://www.sfml-dev.org/tutorials/2.5/window-window.php)

##### button

[Create a button in SFML | StackExchange](https://gamedev.stackexchange.com/questions/142308/how-to-create-a-button-in-sfml?newreg=7f438ea1e8194a20aa72034854efa888)

[SFML Button class](https://termspar.wordpress.com/2019/04/11/c-sfml-textbox-and-button-classes/)

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

### Manual method

1. Move to `build/`.
2. Pre-build with `cmake ..` to pre-build Makefile and sources. The `..` specify to put this build inside the cwd.
3. Build with `make`. This generate the executable.
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

### Automated method

I made a custom `.sh` file and a custom target in CMake so that the generated `build/Makefile` has a rule `run_avalanche` target to build and run the program.

1. Go to `build/`.
2. Run `make run_avalanche`

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ build❯❯ make run_avalanche
/home/onyr/Documents/code/matthieu/avalanche/build
-- Configuring done
-- Generating done
-- Build files have been written to: /home/onyr/Documents/code/matthieu/avalanche/build
Consolidate compiler generated dependencies of target avalanche
[100%] Built target avalanche
```

## commands

### CMake

`cmake -S . -B ./build/`: run CMake to build the project. `-S` is the source directory where the `CMakeLists.txt` file is located.

#### weird problem with CMAKE

I had suddenly this problem, while trying to recompile the project months after... I went to `./build/` and tried to build using `cmake ..`:

```shell
(base)  ❮ onyr ★  kenzae❯ ❮ build❯❯ cmake ..
-- The CXX compiler identification is unknown
CMake Error at CMakeLists.txt:4 (project):
  The CMAKE_CXX_COMPILER:

    /usr/bin/x86_64-linux-gnu-g++-7

  is not a full path to an existing compiler tool.

  Tell CMake where to find the compiler by setting either the environment
  variable "CXX" or the CMake cache entry CMAKE_CXX_COMPILER to the full path
  to the compiler, or to the compiler name if it is in the PATH.


-- Configuring incomplete, errors occurred!
See also "/home/onyr/Documents/code/matthieu/avalanche/build/CMakeFiles/CMakeOutput.log".
See also "/home/onyr/Documents/code/matthieu/avalanche/build/CMakeFiles/CMakeError.log".
```

I solved the issue by telling explicitly which path to use in CMake, thanks to [StackOverflow](.

`sudo cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ ..` : Here, the `sudo` is mandatory.


## TODO

* [X]~~Add list of UIObject and sort the list by a custom comparator, from minimum z (closest to the viewer) to max z (furthust to the viewer).~~ No need for such a system since we are not in a game where elements are going to be displayed with different levels of depth depending of the y coordinate.
* [X] Make a 2D array contiguous in memory of ints representing snow amount in each cell.
* [ ] Understand how to specify `-std=c++1z` as a linking flag with `CMake`.
* [ ] Fix board evolution not displayed.
* [ ] Make a function to get the index of the cell given the mouse coordinates.
* [ ] Make a eventHandle() function to handle right and left mouse click to add/remove snow in clicked cell.
* [ ] Make a pause/continue system based on the button.
* [ ] Display the number of iterations.

Possible improvements:

* [ ] Make a reset button.
* [ ] Make a text field to add custom number of cells.
* [ ] Make a .exe executable for windows.

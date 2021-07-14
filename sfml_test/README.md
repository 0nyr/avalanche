# Compile and RUN SFML app

[Official tutorial](https://www.sfml-dev.org/tutorials/2.5/start-linux.php)

Now let's compile it:

```
g++ -c main.cpp
```

In case you installed SFML to a non-standard path, you'll need to tell the compiler where to find the SFML headers (.hpp files):

```
g++ -c main.cpp -I<sfml-install-path>/include
```

Here, *`<sfml-install-path>`* is the directory where you copied SFML, for example */home/me/sfml* .

You must then link the compiled file to the SFML libraries in order to get the final executable. SFML is made of 5 modules (system, window, graphics, network and audio), and there's one library for each of them.
To link an SFML library, you must add "-lsfml-xxx" to your command line, for example "-lsfml-graphics" for the graphics module (the "lib" prefix and the ".so" extension of the library file name must be omitted).

```
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
```

If you installed SFML to a non-standard path, you'll need to tell the linker where to find the SFML libraries (.so files):

```
g++ main.o -o sfml-app -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system
```

We are now ready to execute the compiled program:

```
./sfml-app
```

If SFML is not installed in a standard path, you need to tell the dynamic linker where to find the SFML libraries first by specifying LD_LIBRARY_PATH:

```
export LD_LIBRARY_PATH=<sfml-install-path>/lib && ./sfml-app
```

If everything works, you should see a small window with a green circle in it.

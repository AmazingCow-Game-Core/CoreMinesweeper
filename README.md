Core Minesweeper 
====

Made with <3 by [Amazing Cow](http://www.amazingcow.com).

<!-- ####################################################################### -->

## Intro:
This is a Game Core for Minesweeper Game.   
You can use it as a "lib" for making Minesweeper Game in C++ concentrating 
your efforts in making a cool game interface and letting the logic of the 
game alone.


<!-- ####################################################################### -->

## Dependencies:

This core needs to use the [CoreCoord](http://www.github.com/amazingcow/CoreCoord) 
lib. The core itself ```#include``` the ```CoreCoord``` without any hardcoded paths
so you must ensure that you point to the correct include dir in your compiler settings.   
This is usually done in g++/clang++ like:

```bash
$ g++ -I/path/to/CoreCoord/ ...
```

You can find a example in the ```Makefile```.


<!-- ####################################################################### -->

## Files:
We tried to separated the files in a very organized form.   
Here is a list of them:

* ```Block.h```
* ```CoreMinesweeper.h```
* ```CoreMinesweeper_Types.h```
* ```CoreMinesweeper_Utils.h```
* ```GameCore.h```


<!-- ####################################################################### -->

## More info:
We tried to document the Core extensively, so we think that is pretty ease to 
get what the Core is doing, the API calls and stuff.   
Anyway if you didn't understand something let us know sending a mail to 
***help_opensource@amazingcow.com***  with the subject filled with the
name of this repo.


<!-- ####################################################################### -->

## License:
This software is released under GPLv3.


<!-- ####################################################################### -->

## TODO:
Check the TODO file.


<!-- ####################################################################### -->

## Others:
Check our repos and take a look at our [open source site](http://opensource.amazingcow.com).

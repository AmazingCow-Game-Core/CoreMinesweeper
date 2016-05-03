//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        main.cpp                                  //
//            █ █        █ █        CoreMinesweeper                           //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//


//This guard is to ease the usage of the CoreMinesweeper,
//so it's users won't need to worry about removing any files
//since is very unlikely that this flag is defined elsewhere.
#ifdef __AMAZINGCORE_COREMINESWEEPER_TEST_ENABLED__

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../include/CoreMinesweeper.h"

USING_NS_COREMINESWEEPER;
using namespace std;

void usage()
{
    cout << "Amazing Cow - CoreMinesweeper Test Game" << endl;
    cout << "Usage:" << endl;
    cout << "<binary-name> width height mines" << endl;
    cout << "Ex: ./testgame    4      8    10" << endl;
    cout << "Ex: ./testgame    4      8    10" << endl;

    exit(1);
}

int main(int argc, const char *argv[])
{
   if(argc != 5)
       usage();

    auto width     = atoi(argv[1]);
    auto height    = atoi(argv[2]);
    auto mines     = atoi(argv[3]);
    auto showMines = atoi(argv[4]);

    GameCore core(width, height, mines, 1);

    while(core.getStatus() == GameCore::Status::Continue)
    {
        //Print board info.
        cout << "Board Open" << endl;
        cout << core.ascii(showMines);

        cout << "----------------" << endl;
        cout << "Board Closed" << endl;
        cout << core.ascii() << endl;

        cout << "Flags Count: " << core.getFlagsCount() << endl;

        //Get input mode.
        char o;
        cout << "[f]lag - [o]pen: ";
        cin >> o;

        //Get the coord.
        cout << "Coord:";
        CoreCoord::Coord coord;
        cin >> coord.y >> coord.x;

        //Make move.
        if(o == 'f')
            core.toggleFlagAt(coord);
        else
            core.openBlockAt(coord);

        cout << endl;
    }

    //Game Over...
    cout << "Game over with status: ";
    cout << ((core.getStatus() == GameCore::Status::Victory)
             ? "Victory"
             : "Defeat")
         << endl;
}

#endif // __AMAZINGCORE_COREMINESWEEPER_TEST_ENABLED__ //

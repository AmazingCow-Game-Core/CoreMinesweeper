//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        main.cpp                                  //
//             ████████████         Minesweeper Core                          //
//           █              █       Copyright (c) 2015 AmazingCow             //
//          █     █    █     █      www.AmazingCow.com                        //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
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
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//


//This guard is to ease the usage of the MinesweeperCore,
//so it's users won't need to worry about removing any files
//since is very unlikely that this flag is defined elsewhere.
#ifdef __AMAZINGCORE_MINESWEEPERCORE_TEST_ENABLED__

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../include/MinesweeperCore.h"

USING_NS_MINESWEEPERCORE;
using namespace std;

void usage()
{
    cout << "Amazing Cow - MinesweeperCore Test Game" << endl;
    cout << "Usage:" << endl;
    cout << "  <binary-name> width height mines showMines" << endl;
    cout << "Ex: ./testgame 4 8 10 1 //1 Show mines" << endl;
    cout << "Ex: ./testgame 4 8 10 0 //0 DONT Show mines" << endl;

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

    GameCore core(width, height, mines);

    while(core.getStatus() == GameCore::Status::Continue)
    {
        cout << "Board" << endl;
        if(showMines)
            cout << core.asciiOpen() << endl;
        else
            cout << core.ascii() << endl;

        CoreCoord::Coord coord;
        cin >> coord.x >> coord.y;

    }
}

#endif // __AMAZINGCORE_MINESWEEPERCORE_TEST_ENABLED__ //

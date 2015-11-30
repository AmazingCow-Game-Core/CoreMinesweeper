//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        Block.h                                   //
//             ████████████         CoreMinesweeper                           //
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

#ifndef __CoreMinesweeper_include_Block_h__
#define __CoreMinesweeper_include_Block_h__

//std
#include <vector>
//CoreMinesweeper.
#include "CoreMinesweeper_Utils.h"
//CoreCoord.
#include "Coord.h"

NS_COREMINESWEEPER_BEGIN

class Block
{
    // Friends //
public:
    friend class GameCore;

    // Constants/Enums/Typedefs //
public:
    ///@brief
    const static int kMineNumber;
    ///@brief
    typedef std::vector<std::vector<Block>> Board;

    // CTOR / DTOR //
public:
    ///@brief
    Block();
    ///@brief
    ~Block();

    // Public Methods //
public:
    ///@brief
    ///@returns
    int getNumber() const;

    ///@brief
    ///@returns
    const CoreCoord::Coord& getCoord() const;


    ///@brief
    ///@returns
    bool isMine() const;

    ///@brief
    ///@returns
    bool isFlagged() const;

    ///@brief
    ///@returns
    bool isUncovered() const;


    ///@brief
    ///@returns
    bool toggleFlag();

    ///@brief
    ///@returns
    void uncover();

    // Private Methods //
private:
    //This methods are meant to accessed by GameCore class.
    void setNumber(int number);
    void incrementNumber();
    void setCoord(const CoreCoord::Coord &coord);

    // iVars //
private:
    int              m_number;
    bool             m_isFlagged;
    bool             m_isUncovered;
    CoreCoord::Coord m_coord;
};

NS_COREMINESWEEPER_END
#endif // defined(__CoreMinesweeper_include_Block_h__) //

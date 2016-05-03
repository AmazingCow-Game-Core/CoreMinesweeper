//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        Block.h                                   //
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

#ifndef __CoreMinesweeper_include_Block_h__
#define __CoreMinesweeper_include_Block_h__

//std
#include <vector>
//CoreMinesweeper.
#include "CoreMinesweeper_Utils.h"
//CoreCoord.
#include "CoreCoord.h"


NS_COREMINESWEEPER_BEGIN

class Block
{
    // Friends //
public:
    friend class GameCore;

    // Constants / Enums / Typedefs //
public:
    ///@brief
    ///     Meta-value indicating that this block is a mine.
    ///@see isMine().
    const static int kMineNumber;

    ///@brief Typedef just to reduce verbosity.
    typedef std::vector<std::vector<Block>> Board;


    // CTOR / DTOR //
public:
    ///@brief Default CTOR.
    Block();
    ///@brief Default DTOR.
    ~Block();

    // Public Methods //
public:
    ///@brief
    ///     Gets the number of adjacent mines from this block. \n
    ///     If the number is equal to kMineNumber this block represents a mine.
    ///@returns The number of adjacent mines, or kMineNumber if it is mine.
    ///@see isMine(), kMineNumber.
    int getNumber() const;

    ///@brief
    ///     Gets the coord of this block in GameCore's Board.
    ///@returns The coord for this block.
    ///@see GameCore::getBlockAt(), GameCore::getBoard().
    const CoreCoord::Coord& getCoord() const;


    ///@brief
    ///     Gets if this blocks represents a mine or not.
    ///@returns True if it is a mine, false otherwise.
    ///@see getNumber(), kMineNumber.
    bool isMine() const;

    ///@brief
    ///     Gets if this block is flagged.
    ///@returns True if it is flagged, false otherwise.
    bool isFlagged() const;

    ///@brief
    ///     Gets if this block is flagged.
    ///@returns True if it is flagged, false otherwise.
    bool isUncovered() const;


    // Private Methods //
private:
    //This methods are meant to accessed by GameCore class.
    void setNumber(int number);
    void incrementNumber();

    void setCoord(const CoreCoord::Coord &coord);

    bool toggleFlag();
    void uncover();


    // iVars //
private:
    int              m_number;
    bool             m_isFlagged;
    bool             m_isUncovered;
    CoreCoord::Coord m_coord;
};

NS_COREMINESWEEPER_END
#endif // defined(__CoreMinesweeper_include_Block_h__) //

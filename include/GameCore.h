//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.h                                //
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

#ifndef __MinesweeperCore_include_GameCore_h__
#define __MinesweeperCore_include_GameCore_h__

//std
#include <vector>
#include <random>
//MinesweeperCore.
#include "MinesweeperCore_Utils.h"
#include "Block.h"
//CoreCoord.
#include "Coord.h"

NS_MINESWEEPERCORE_BEGIN

class GameCore
{
    // Enums/Constants/Typedefs //
public:
    ///@brief When GameCore is constructed using the kRandomSeed, it will
    ///generate an actual seed based in random factors. This is a meta seed
    ///only to indicating the a random seed must be generated.
    ///@see getSeed.
    static const int kRandomSeed;

    ///@brief Defines the possible states for GameCore.
    enum class Status
    {
        Victory,  ///< Game is over     - Player Won.
        Defeat,   ///< Game is over     - Player Lose
        Continue, ///< Game is not over - Keep playing.
    };


    // CTOR/DTOR //
public:
    ///@brief
    GameCore(int boardWidth, int boardHeight,
             int minesCount, int seed = kRandomSeed);


    // Public Methods //
public:
    //Flag.
    ///@brief
    ///@returns
    const Block& toggleFlagAt(const CoreCoord::Coord &coord);

    ///@brief
    ///@returns
    const CoreCoord::Coord::Vec& getFlagCoords() const;

    ///@brief
    ///@returns
    int getFlagsCount() const;


    //Blocks.
    ///@brief
    ///@returns
    CoreCoord::Coord::Vec openBlockAt(const CoreCoord::Coord &coord);

    ///@brief
    ///@returns
    const Block& getBlockAt(const CoreCoord::Coord &coord) const;

    ///@brief
    ///@returns
    const CoreCoord::Coord::Vec& getUncoveredBlockCoords() const;

    ///@brief
    ///@returns
    int getUncoveredBlocksCount() const;


    //Board.
    ///@brief
    ///@returns
    const Block::Board& getBoard() const;


    //Game stuff.
    ///@brief
    ///@returns
    Status getStatus() const;

    ///@brief
    ///@returns
    int getMinesCount() const;

    ///@brief
    ///@returns
    int getSeed() const;


    //Ascii.
    ///@brief
    ///@returns
    std::string ascii() const;

    ///@brief
    ///@returns
    std::string asciiOpen() const;


    //Helpers.
    ///@brief
    ///@returns
    bool isValidCoord(const CoreCoord::Coord &coord) const;

    // Private Methods //
private:
    //Init.
    void initRandomGenerator();
    void initBoard();

    //Helpers.
    Block& getBlockAt(const CoreCoord::Coord &coord);
    CoreCoord::Coord::Vec openBlockHelper(const CoreCoord::Coord &coord);

    // iVars //
private:
    Block::Board          m_board;
    CoreCoord::Coord::Vec m_uncoveredBlockCoords;
    CoreCoord::Coord::Vec m_flagCoords;

    Status m_status;
    int    m_minesCount;
    int    m_boardWidth;
    int    m_boardHeight;
    int    m_seed;
};

NS_MINESWEEPERCORE_END
#endif // defined(__MinesweeperCore_include_GameCore_h__) //

//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.h                                //
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

#ifndef __CoreMinesweeper_include_GameCore_h__
#define __CoreMinesweeper_include_GameCore_h__

//std
#include <vector>
//CoreMinesweeper.
#include "Block.h"
#include "CoreMinesweeper_Utils.h"
//CoreCoord.
#include "CoreCoord.h"
//CoreRandom
#include "CoreRandom.h"


NS_COREMINESWEEPER_BEGIN

class GameCore
{
    // Enums / Constants / Typedefs //
public:
    enum class Status
    {
        Victory,  ///< Game is over     - Player Won.
        Defeat,   ///< Game is over     - Player Lose
        Continue, ///< Game is not over - Keep playing.
    };


    // CTOR/DTOR //
public:
    ///@brief
    ///     Constructs the GameCore.
    ///@param boardWidth
    ///     The width of game Board - Must be > 0.
    ///@param boardWidth
    ///     The height of game Board - Must be > 0.
    ///@param minesCount
    ///     How many mines will be placed in this Board -
    ///     Must be <= (boardWith * boardHeight)
    ///@param seed
    ///     The seed used to generate the random numbers. -
    ///     Default is CoreRandom::Random::kRandomSeed.
    ///@note
    ///     The CTOR will not validate the given arguments.
    ///     Is user's responsibility to pass valid values.
    ///@warning
    ///     If invalid values are given the behavior is unpredictable.
    GameCore(int boardWidth, int boardHeight,
             int minesCount,
             int seed = CoreRandom::Random::kRandomSeed);


    // Public Methods //
public:
    //Flag.
    ///@brief
    ///     Toggle a flag for block at given coord. \n
    ///     A flag only will be toggled if the block
    ///     isn't already uncovered.
    ///@param coord
    ///     The block coord - It must be valid in game Board.
    ///@returns
    ///     The affected block
    ///@warning
    //      This method will not check the validity of coord.
    ///     Users must pass a valid coord, or behavior is undefined.
    ///@see
    ///     Block::isUncovered(), Block::isFlagged(),
    ///     getFlagCoords(), getFlagsCount(), isValidCoord(),
    ///     openBlockAt().
    const Block& toggleFlagAt(const CoreCoord::Coord &coord);

    ///@brief
    ///     Gets all coords of Blocks that are flagged.
    ///@returns A vector of coords of Flagged blocks.
    ///@see Block::isFlagged(), toggleFlagAt(), getFlagsCount().
    const CoreCoord::Coord::Vec& getFlagCoords() const;

    ///@brief
    ///     Gets how many blocks are flagged.
    ///@returns How many blocks are flagged.
    ///@see Block::isFlagged(), toggleFlagAt(), getFlagsCoords().
    int getFlagsCount() const;


    //Blocks.
    ///@brief
    ///     Open a block at given coord. \n
    ///     The block will be opened only if it
    ///     isn't flagged nor already opened. \n
    ///     Opening a block can trigger one, or more blocks
    ///     to being opened too. This happens when them haven't
    ///     mines or flagged blocks in surrounding coords. \n
    ///     The Game Status can change at this method, so users
    ///     should call getStatus() to check if game was win, or lose.
    ///@param coord
    ///     The coord of block that will be opened. -
    ///     While this method will check the validity of the coord,
    ///     invalid coords will receive empty vectors in response.
    ///@returns
    ///     All the affected coords. The coords that player choose and passed
    ///     as argument to this method will be returned at index 0, if it
    ///     could be opened, all other coords that was opened in the reaction
    ///     isn't in a particular order.
    ///@note
    ///     While isn't strict needed to pass valid coords to this method
    ///     it will return nothing but a empty vector if the coord isn't valid.
    ///@see
    ///     Block, Block::isUncovered(), Block::isFlagged(),
    ///      isValidCoord(), toggleFlagAt(), getStatus().
    CoreCoord::Coord::Vec openBlockAt(const CoreCoord::Coord &coord);

    ///@brief Gets the block at coord.
    ///@param coord
    ///     The coord of block - This MUST be valid in Board bounds.
    ///@warning This method will not check the coord validity.
    ///@returns The block.
    ///@see isValidCoord(), Block.
    const Block& getBlockAt(const CoreCoord::Coord &coord) const;

    ///@brief
    ///     Gets all coords of Blocks that are uncovered.
    ///@returns A vector of coords of Uncovered blocks.
    ///@see Block::isUncovered(), openBlockAt(), getUncoveredBlocksCount().
    const CoreCoord::Coord::Vec& getUncoveredBlockCoords() const;

    ///@brief
    ///     Gets how many blocks are uncovered.
    ///@returns How many blocks are uncovered.
    ///@see Block::isUncovered(), openBlockAt(), getUncoveredBlocksCoords().
    int getUncoveredBlocksCount() const;


    //Board.
    ///@brief
    ///     Gets the whole Board.
    ///     Intent to ease the Game Board inspection, so instead of
    ///     doing a loop of getBlockAt() you can get all blocks in one shot.
    ///@returns The Board.
    const Block::Board& getBoard() const;


    //Game stuff.
    ///@brief
    ///     Get the current status of game.
    ///     Should be called after each openBlockAt() to
    ///     check if game is won, or lose.
    ///@returns The game status.
    ///@see openBlockAt().
    Status getStatus() const;

    ///@brief How many mines were placed in this game.
    ///@returns The number of mines.
    int getMinesCount() const;

    ///@brief
    ///     The actual seed used by CoreRandom::Random
    ///     to generate the game.
    ///@returns The seed used.
    ///@see CoreRandom::Random.
    int getSeed() const;


    //Ascii.
    ///@brief
    ///     Gets the nice representation of Board.
    ///     Intent for debug only :D
    ///@parm showMines
    ///     If true, the mines will be visible.
    ///@returns The string representing the board.
    std::string ascii(bool showMines = false) const;


    //Helpers.
    ///@brief
    ///     Checks if the given coord is in Board bounds.
    ///     Users should use this method to validate the coords,
    ///     before passing it to the other GameCore methods.
    ///@returns True if coord is valid, false otherwise.
    bool isValidCoord(const CoreCoord::Coord &coord) const;


    // Private Methods //
private:
    //Init.
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

    CoreRandom::Random m_random;
};


NS_COREMINESWEEPER_END
#endif // defined(__CoreMinesweeper_include_GameCore_h__) //

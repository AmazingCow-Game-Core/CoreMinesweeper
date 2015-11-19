//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.cpp                              //
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

//Header
#include "../include/GameCore.h"
//std
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <iostream>
using namespace std;

//Usings
USING_NS_MINESWEEPERCORE;

// Enums/Constants/Typedefs //
const int GameCore::kRandomSeed = -1;

// CTOR/DTOR //
GameCore::GameCore(int boardWidth, int boardHeight,
                   int minesCount, int seed /* = kRandomSeed */) :
    //m_board                - Initialized in initBoard.
    //m_uncoveredBlockCoords - Default initialized.
    //m_flagCoords           - Default initialized.
    m_status     (Status::Continue),
    m_minesCount (minesCount),
    m_boardWidth (boardWidth),
    m_boardHeight(boardHeight),
    m_seed       (seed)
{
    initRandomGenerator();
    initBoard();
}

// Public Methods //
//Flag.
const Block& GameCore::toggleFlagAt(const Coord &coord)
{
    auto &block  = getBlockAt(coord);
    auto flagged = block.toggleFlag();
    
    //If block is now flagged add it to flagged coords.
    //If block is NOT flagged remove it from flagged coords.
    auto it = std::find(begin(m_flagCoords), end(m_flagCoords), coord);

    if(flagged && it != end(m_flagCoords))
        m_flagCoords.erase(it);
    else if(!flagged && it == end(m_flagCoords))
        m_flagCoords.push_back(coord);
    
    return block;
}
const Coord::CoordVec& GameCore::getFlagCoords() const
{
    return m_flagCoords;
}
int GameCore::getFlagsCount() const
{
    return static_cast<int>(m_flagCoords.size());
}

//Blocks.
Coord::CoordVec GameCore::openBlockAt(const Coord &coord)
{
    auto openedCoords = Coord::CoordVec();

    //Coord is not on the board bounds or
    //the game is already over - we don't have to anything more...
    if(!isValidCoord(coord) || m_status != Status::Continue)
        return openedCoords;

    //Open all possible blocks.
    openedCoords = openBlockHelper(coord);
 
    //Update the uncovered coords.
    m_uncoveredBlockCoords.insert(end  (m_uncoveredBlockCoords),
                                  begin(openedCoords),
                                  end  (openedCoords));
    
    //No blocks was opened.
    if(openedCoords.empty())
        return openedCoords;
    
    
    //Check status.
    const auto &block  = getBlockAt(openedCoords[0]);
    //Player hit a mine - Game is Over.
    if(block.isMine())
    {
        m_status = Status::Defeat;
    }
    //Player uncovered all non-mine block - Game is Over.
    else if(getUncoveredBlocksCount() + m_minesCount == (m_boardHeight * m_boardWidth))
    {
        m_status = Status::Victory;
    }
    
    
    return openedCoords;
}

const Block& GameCore::getBlockAt(const Coord &coord) const
{
    return m_board[coord.y][coord.x];
}
const Coord::CoordVec& GameCore::getUncoveredBlockCoords() const
{
    return m_uncoveredBlockCoords;
}
int GameCore::getUncoveredBlocksCount() const
{
    return static_cast<int>(m_uncoveredBlockCoords.size());
}

//Board.
const Block::Board& GameCore::getBoard() const
{
    return m_board;
}

//Game stuff.
GameCore::Status GameCore::getStatus() const
{
    return m_status;
}
int GameCore::getMinesCount() const
{
    return m_minesCount;
}
int GameCore::getSeed() const
{
    return m_seed;
}

//Ascii.
std::string GameCore::ascii() const
{
    std::stringstream ss;

    for(const auto &line : m_board)
    {
        for(const auto &block : line)
        {
            if(block.isUncovered())
            {
                if(block.getNumber() == 0)
                    ss << ".";
                else
                    ss << block.getNumber();
            }
            else if(block.isFlagged())
                ss << "F";
            else if(block.isMine())
                ss << "*";
            else
                ss << "x";
        }
        ss << std::endl;
    }
    return ss.str();
}
std::string GameCore::asciiOpen() const
{
    std::stringstream ss;

    for(const auto &line : m_board)
    {
        for(const auto &block : line)
        {
            if(block.isUncovered())
            {
                if(block.getNumber() == 0)
                    ss << ".";
                else
                    ss << block.getNumber();
            }
            else if(block.isFlagged())
                ss << "F";
            else if(block.isMine())
                ss << "*";
            else
                ss << block.getNumber();
        }
        ss << std::endl;
    }
    return ss.str();
}

//Helper.
bool GameCore::isValidCoord(const Coord &coord) const
{
    return (coord.y >= 0 && coord.y < static_cast<int>(m_board.size()))
        && (coord.x >= 0 && coord.x < static_cast<int>(m_board[coord.y].size()));
}


// Private Methods //
//Init.
void GameCore::initRandomGenerator()
{
    if(m_seed == GameCore::kRandomSeed)
        m_seed = static_cast<int>(time(nullptr));

    srand(m_seed);
}
void GameCore::initBoard()
{
    //Play nice with memory...
    m_board.reserve(m_boardHeight);

    //Fill the Board with "Empty" Blocks...
    for(auto i = 0; i < m_boardHeight; ++i)
    {
        //Add line of blocks.
        m_board.push_back(std::vector<Block>());
        //Play nice with memory...
        m_board[i].reserve(m_boardWidth);

        for(auto j = 0; j < m_boardWidth; ++j)
        {
            Block block;
            block.setCoord(Coord(i, j));
            m_board[i].push_back(block);
        }
    }

    //Initialize ALL Mines.
    for(auto i = 0; i < m_minesCount; ++i)
    {
        //Continue while a valid Mine position is found.
        while(true)
        {
            int y = rand() % m_boardHeight;
            int x = rand() % m_boardWidth;

            auto &block = m_board[y][x];
            
            //Already is a mine, don't need do anything more.
            if(block.isMine())
                continue;

            //Set as Mine.
            block.setNumber(Block::kMineNumber);
            
            //Update all surrounding coords values.
            for(auto coord : block.getCoord().getSurroundingCoords())
            {
                if(!isValidCoord(coord))
                    continue;

                auto &surroundBlock = getBlockAt(coord);
                surroundBlock.incrementNumber();
            }
            
            //Mine was placed.
            break;
        }
    }
}

//Helpers.
Block& GameCore::getBlockAt(const Coord &coord)
{
    return m_board[coord.y][coord.x];
}
Coord::CoordVec GameCore::openBlockHelper(const Coord &coord)
{
    Coord::CoordVec openedCoords;
    
    //Coords is out of Board, we don't have nothing more to do.
    if(!isValidCoord(coord))
        return openedCoords;
    
    auto &block = getBlockAt(coord);
    
    //Block is already uncovered or is flagged.
    //So we don't have nothing more to do.
    if(block.isUncovered() || block.isFlagged())
        return openedCoords;
    
    //Uncover the block and add it into the opened coords.
    block.uncover();
    openedCoords.push_back(coord);
    
    //Uncovered a non zero block, so just open it and return.
    if(block.getNumber() == Block::kMineNumber ||
       block.getNumber() != 0)
    {
        return openedCoords;
    }
    
    //Now recursively try open for all surrounding blocks.
    for(auto surroundCoord : coord.getSurroundingCoords())
    {
        //Not a valid coord, don't bother call it...
        if(!isValidCoord(surroundCoord))
            continue;
        
        auto surroundOpened = openBlockHelper(surroundCoord);
        openedCoords.insert(end  (openedCoords),
                            begin(surroundOpened),
                            end  (surroundOpened));
    }
    
    return openedCoords;
}
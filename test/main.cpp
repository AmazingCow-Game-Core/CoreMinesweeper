#include "../include/MinesweeperCore.h"
#include <iostream>

USING_NS_MINESWEEPERCORE;
using namespace std;

int main()
{
    GameCore core(7, 7, 5);

//    cout << core.ascii() << endl;
    
    while(core.getStatus() == GameCore::Status::Continue)
    {
        cout << core.ascii() << endl;
        cout << "Coord: " << endl;
        
        Coord coord;
        cin >> coord.y >> coord.x;
        
        core.openBlockAt(coord);
    }
}

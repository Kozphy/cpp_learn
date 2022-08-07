#include <iostream>
#include "player.h"



int main() {
    Player p1("Basketball");
    p1.set_first_name("John");
    p1.set_last_name("Lows");
    cout << "player: " << p1 << endl;
    return 0;
}
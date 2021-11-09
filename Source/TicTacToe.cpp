
#include "Includes/UtilityLib.hpp"
#include <Windows.h>

int
main () {

    SceneManager scene;
    UInt8        var;

    scene.Init ();
    TicTacToe::Init ();

    scene.Draw ();  

    while (1) {

        if (_kbhit ()) {

            var = _getch ();               

            scene.UpdateInput (var);
            scene.Draw ();  
        }
    }

    return 0;
}
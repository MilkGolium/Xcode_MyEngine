#include "MyEngine.h"

int main(void) {
    InitWindow(640, 480, "Window name");
    InitEngineTime();
    
    while (GameShouldQuit()) {
        UpdateDeltaTime();
        Rend();
    }
    
    CleanUp();
    return 0;
}

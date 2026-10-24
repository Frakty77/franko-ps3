#include <stdio.h>
#include <ppu-types.h>
#include <rsx/rsx.h>
#include <io/pad.h>

int main(int argc, char* argv[]) {
    printf("Franko PS3 - Start silnika PSL1GHT!\n");

    // Inicjalizacja padów PS3
    ioPadInit(7);

    padData pad;
    
    while(1) {
        ioPadGetInfo(&pad);
        if(pad.status[0]) {
            // Jeśli naciśnięto przycisk, wychodzimy
            if(pad.button[0] & PAD_START) {
                printf("Wyjście z gry...\n");
                break;
            }
        }
    }

    return 0;
}

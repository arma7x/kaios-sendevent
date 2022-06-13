#include <stdlib.h>
#include <stdio.h>


void send_event(char* evt, int key) {
    char command[500];
    sprintf(command, "adb shell sendevent %s 1 %d 1 ; adb shell sendevent %s 0 0 0 ;adb shell sendevent %s 1 %d 0 ;adb shell sendevent %s 0 0 0", evt, key, evt, evt, key, evt);
    system(command);
    // printf("%s\n\r", command);
}

int main() {
    int input;

    for (;;) {
        system("/bin/stty raw");
        input = getchar();
        printf(" => %d\n\r", input);
        system("/bin/stty cooked");
        switch (input) {
            case 13:
                send_event("dev/input/event0", 352);
                break;
        }
        // printf("\33[2K\r");
    }
    return 0;
}

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
            case 80: // Shutdown => F1
                system("adb shell sendevent dev/input/event3 1 116 108 ; adb shell sendevent dev/input/event3 0 0 0 ;adb shell sendevent dev/input/event3 1 116 103 ;adb shell sendevent dev/input/event3 0 0 0");
                break;
            case 81: // Screen On/Off => F2
                send_event("dev/input/event3", 116);
                break;
            case 82: // SoftLeft => F3
                send_event("dev/input/event0", 139);
                break;
            case 83: // SoftRight => F4
                send_event("dev/input/event0", 158);
                break;
            case 13: // Enter => Enter
                send_event("dev/input/event0", 352);
                break;
            case 65: // Up => Up
                send_event("dev/input/event4", 103);
                break;
            case 66: // Down => Down
                send_event("dev/input/event3", 108);
                break;
            case 67: // Right => Right
                send_event("dev/input/event0", 106);
                break;
            case 68: // Left => Left
                send_event("dev/input/event0", 105);
                break;
            case 8: // Backspace/EndCall => Backspace
                send_event("dev/input/event4", 116);
                break;
            case 9: // Call => Tab
                send_event("dev/input/event0", 231);
                break;
        }
        // printf("\33[2K\r");
    }
    return 0;
}

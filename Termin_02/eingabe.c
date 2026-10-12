#include "eingabe.h"
#include <stdio.h>
#include <string.h>

int gibTextEin(const char* prefix, char* buffer, int buflen) {
    printf(prefix);
    if(fgets(buffer, buflen, stdin)) {
        buffer[strlen(buffer)-1] = '\0';
        while (getchar() != '\n') ;
        buffer[buflen-1] = '\0';
        return 1;
    }
   return 0;
}

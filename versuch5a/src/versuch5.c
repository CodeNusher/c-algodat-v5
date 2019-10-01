#include <stdio.h>
#include "b64utils.h"
#include "b64decode.h"

#define BLOCK_SIZE  1024

int main()
{
    char src[BLOCK_SIZE+1], dest[BLOCK_SIZE+1];
    int anz;
    
    /* Einlesen eines ASCIIZ-String der in base64 codiert ist */
    getFilteredString(src, BLOCK_SIZE);

    /* Decodiere den String in src und lege das Ergebnis in
       dest ab
     */    
    anz=b64DecodeString(dest, src);

    if (anz<0)
        puts("Fehler im base64-String!");
    else
        /* Ausgabe des Strings */
        putData(dest, anz);
    
    return 0;
}

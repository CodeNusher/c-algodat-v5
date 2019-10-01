#ifndef _B64UTILS_H
#define _B64UTILS_H

/* Ein-/Ausgaberoutinen */
void getFilteredString(char block[], unsigned maxSize);
void putData(const char block[], unsigned blockSize);

/* Konvertierfunktionen */
char b64ResultFirstByte(int b64first, int b64second); 
char b64ResultSecondByte(int b64second, int b64third); 
char b64ResultThirdByte(int b64third, int b64fourth); 

#endif

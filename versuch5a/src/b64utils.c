/*
 * b64utils.c
 *
 *  Created on: 01.10.2019
 *      Author: pliss
 */
#include <stdio.h>
#include "b64utils.h"

char b64ResultFirstByte(int b64first, int b64second){
	char result = -1;
	if(b64first>=0 && b64first<=63 && b64second>=0 && b64second<=63){
		result = (b64first<<2) + (b64second>>4);
	}
	return (char)result;
}

char b64ResultSecondByte(int b64second, int b64third){
	char result = -1;
	if(b64second>=0 && b64second<=63 && b64third>=0 && b64third<=63){
		result = (b64second<<4) + (b64third>>2);
	}
	return (char)result;
}

char b64ResultThirdByte(int b64third, int b64fourth){
	char result = -1;
	if(b64third>=0 && b64third<=63 && b64fourth>=0 && b64fourth<=63){
		result = ((b64third<<6) + b64fourth);
	}
	return (char)result;
}

void getFilteredString(char block[], unsigned maxSize){
	char c;
	int i=0;
	while((c=getchar()) != EOF && (i<maxSize)){
		if(c!=' ' && c!='\t' && c!='\v' && c!='\n' && c!='\r'){
			block[i] = c;
			block[i+1] = '\0';
			i++;
		}
	}
}

void putData(const char block[], unsigned blockSize){
	int i;
	for(i=0; i<blockSize; i++){
		putchar(block[i]);
	}
}

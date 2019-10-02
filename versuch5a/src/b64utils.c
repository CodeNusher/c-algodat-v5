/*
 * b64utils.c
 *
 *  Created on: 01.10.2019
 *      Author: pliss
 */
#include "b64utils.h"

char b64ResultFirstByte(int b64first, int b64second){
	if(b64first>=0 && b64first<=63 && b64second>=0 && b64second<=63){
		return (b64first<<2) + (b64second>>4);
	}
}

char b64ResultSecondByte(int b64second, int b64third){
	if(b64second>=0 && b64second<=63 && b64third>=0 && b64third<=63){
		return (b64second<<4) + (b64third>>2);
	}
}

char b64ResultThirdByte(int b64third, int b64fourth){
	if(b64third>=0 && b64third<=63 && b64fourth>=0 && b64fourth<=63){
		return (b64third<<6) + b64fourth;
	}
}

void getFilteredString(char block[], unsigned maxSize){

}

void putData(const char block[], unsigned blockSize){

}

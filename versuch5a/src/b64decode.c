#include "b64decode.h"

/* Suche zum entsprechenden Zeichen den base64-Wert */
int searchIndex(char ch)
{
    int result=-1;
    int i;
    char b64Codes[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    /* Durchsuche das Array bis das Ende des Strings erreicht wird
       oder das Zeichen ch gefunden wurde. */
    for (i=0; result==-1 && b64Codes[i]!='\0', i++) ;
        if (b64Codes[i]==ch) 
            result=i;
    /* Gebe den gefunden Index zurueck oder -1 im Fehlerfall */  
    return result;
}

/* Dekodiere den uebergebenen String 'src' und
   speichere das Resultat in das Array 'dest'.

   Der Speicher fuer 'dest' muss vom Aufrufer bereitgestellt werden.
*/
int b64DecodeString(char dest[], const char src[])
{
    int length=0, i=0;
    int error=0;
    char ch1, ch2;
    int index1, index2;
    
    /* Durchlaufe das Array */
    while (!error && (ch1=src[i])!='\0' && (ch2=src[i+1])!='\0')
    {
        if (ch1!='=' && ch2!='=')
        {
            /* Ermittle die base64-Werte aus den ASCII-Zeichen */
            index1=searchIndex(ch1);
            index2=searchIndex(ch2);
            /* Sollten die ermittelten Werte gueltig sein,
               dann setze die Dekodierung fort
            */
            if (index1!=-1 && index2!=-1)
            {
                switch (i % 4)
                {
                    case 0:
                            dest[length++]=b64ResultFirstByte(index1, index2); 
                            break;
                    case 1:
                            dest[length++]=b64ResultSecondByte(index1, index2); 
                            break;
                    case 2:
                            dest[length++]=b64ResultThirdByte(index1, index2); 
                            break;
                    case 3:
                            break;
                    
                }
            }
            else
                error=1;
        }
        i++;
    }
    
    /* Gebe die Laenge des dekodierten String zurueck
       oder -1 im Fehlerfall 
    */
    return (error) ? -1 : length;
}


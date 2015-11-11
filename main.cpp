#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <string>

using namespace std;


const int MAX = 100;


typedef string STRING;

typedef bool BOOL;

typedef string WORD;


/*

    structure describing a word entry in the dictionary

*/


typedef struct entry {

      int count;                  /* frequency count for a particular word */

      WORD w;                     /* the word itself */

      struct entry *nextWord;     /* pointer to next entry */

} ENTRY;


/*

    structure describing the dictionary

*/


typedef  struct dict {

     int maxEntries;	  /* maximum number of entries allowed; this is an artificial limit */

                                   /* link lists can be as big as you want. This limit ensures that   */

                                   /* this code tries to behave like the previous ones */



     int numWords;                 /* number of words in the dictionary */

     ENTRY *Words;                 /* pointer to the entries in the dictionary */

} DICT;





/*

  you will have to write code for these 5 functions.

*/


ENTRY *LocateWord(DICT& , WORD);

BOOL FullDictionary(DICT&);

BOOL InsertWord(DICT&,WORD);

WORD GetNextWord(void);

void DumpDictionary(DICT&);


/*

  note that these are global variables so that they are already initialized to 0

*/


DICT dictionary={MAX,0,0};  /* your dictionary                                                                */

WORD word;                 /*   */



BOOL InsertWord(DICT &dict, WORD word)

{

/*

  adds word to dictionary , if word can't be added returns false else returns true


*/

entry tmp;
tmp.count = 1;
tmp.w = word;

if (dict.maxEntries != dict.numWords)
	{
	int i = dict.numWords;
	dict.Words -> nextWord[i] = tmp;
	}

}


void DumpDictionary(DICT &dict) {

/*

  will sort the dictionary, and display the contents

*/

entry ptr[dict.numWords];
for (int i = 0; i < dict.numWords; i++)
	{
	dict.Words -> nextWord[i] = ptr[i];
	}

}


WORD GetNextWord(void){

/*

   will retrieve next word in input stream. Word is defined just as in assignment #1

   returns WORD or empty string if no more words in input stream

*/
char ch;
int newLine= 0;
WORD tmp;
while( cin.good() )
	{
    ch = cin.get();
    if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
    	{
    	ch = tolower(ch);
    	tmp.push_back (ch); /* make room for ch in the WORD */
        newLine = 1;
        }
    else
    if (newLine) return tmp;
    }


}


BOOL FullDictionary(DICT &dict) {

/*

   if dictionary is full, return true else false

 */

if (dict.maxEntries == dict.numWords) return true;
else return false;

}


ENTRY *LocateWord(DICT &dict, WORD word) {

/*

   will determine if dictionary contains word. if found, returns pointer to entry else returns  0

*/

entry tmp;
tmp.nextWord = dict.Words;
for (int i = 0; i = dict.numWords; i++)
	{
	if (tmp.nextWord -> w == word)
		{
		return tmp.nextWord;
		} 
	else tmp.nextWord = tmp.nextWord -> nextWord;
	if (i = dict.numWords) return 0;
	}


}


int main (void) {

    ENTRY *pos;


    while (1) {

       word = GetNextWord();

       if ( word.empty() )  {

           DumpDictionary(dictionary);

           break;

       }

       if ((pos = LocateWord(dictionary,word)) >  0 )

           pos->count++;

       else

           if (!InsertWord(dictionary,word))
		   	{
		   	cout << "dictionary full" << word <<  "cannot be added\n";
		   	} 

    }

    return 0;

}


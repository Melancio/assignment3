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



ENTRY *LocateWord(DICT& , WORD);

BOOL FullDictionary(DICT&);

BOOL InsertWord(DICT&,WORD);

WORD GetNextWord(void);

void DumpDictionary(DICT&);



DICT dictionary={MAX,0,0};  // your dictionary                                                                */

WORD word;

int times = 1;

/*
  adds word to dictionary , if word can't be added returns false else returns true
*/
BOOL InsertWord( DICT &dict, WORD word)
{

    if (dict.maxEntries == dict.numWords) return false;

    entry *tmp;


    tmp->nextWord = dict.Words;

    while (tmp->nextWord != NULL){
        tmp = tmp->nextWord;
    }
    tmp->nextWord = tmp;
    return true;
}


/*
  will sort the dictionary, and display the contents
*/
void DumpDictionary(DICT &dict)
{

    entry *ptr;
    ptr->nextWord = dict.Words;
    for (int i = 0; i < dict.numWords; i++)
        {
        cout << ptr->w;
        ptr = ptr->nextWord;
        }


}

/*
   will retrieve next word in input stream. Word is defined just as in assignment #1
   returns WORD or empty string if no more words in input stream
*/
WORD GetNextWord(void)
{

WORD w;
char ch;
bool inword = false;

while( cin.good() )
{
 ch = cin.get();
 if ( isalpha(ch) )  /* function test if ch is A-Z, a-z */
    {
       w.push_back(ch);
       inword= true;
    }
 else if (inword) return w;
}

return w;

}



/*
   if dictionary is full, return true else false
 */
BOOL FullDictionary(DICT &dict)
{
if (dict.maxEntries == dict.numWords) return true;
else return false;
}

/*
   will determine if dictionary contains word. if found, returns pointer to entry else returns  0
*/
ENTRY *LocateWord(DICT &dict, WORD word)
{
    //cout << "IN LOCATEWORD" << times++;
    entry *tmp;
    tmp->nextWord = dict.Words;
        for (int i = 0; i < dict.numWords; i++)
            {
            if (tmp->nextWord->w == word)
                {
                return tmp->nextWord;
                }
            else tmp = tmp->nextWord;
            if (i = dict.numWords) return 0;
            }

}


int main (void)
{

    ENTRY *pos = new ENTRY;

/*
    pos->count = 1;
    pos->w = "hello";
    dictionary.Words = pos;

    DumpDictionary(dictionary);
*/


    while (1)
    {
       word = GetNextWord();
       if ( word.empty() )
        {
        cout << "no more words";
            DumpDictionary(dictionary);
            break;
        }


       if ((pos = LocateWord(dictionary,word)) >  0 ) pos->count++;
       else
           if (dictionary.numWords == dictionary.maxEntries)
		   	{
		   	cout << "dictionary full " << word <<  " cannot be added\n";
		   	}
            else (InsertWord(dictionary, word));
    }

    return 0;

}


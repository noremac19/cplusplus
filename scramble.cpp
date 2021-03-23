// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Scramble the letters of this string randomly
void permute(char items[], int len);

/* Delete the array below and replace by reading in words from a file 
   in main() */

int main(int argc, char* argv[]){
    
    srand(time(0));
    char guess[80];
    char buff[41]; 
    bool wordGuessed = false;
    int numTurns = 10;    
    
  /* Add code to declare the wordBank array, read in each word
     and store it */
    if (argc < 2){
        cout << "Enter the file name of the wordbank." << endl;
        return 0;
    }
    
    ifstream ifile (argv[1]);
    int numWords;
    ifile >> numWords;
    
    if (ifile.fail()){
        cout << "The file could not be opened." << endl;
        return 1;
    }
    
    if (ifile.fail()){
        cout << "The integer could not be read." << endl;
        return 1;
    }
    
    char** wordBank = new char* [numWords];
    int i = 0;
    
    while (ifile >> buff){
        int slen = strlen(buff);
        wordBank[i] = new char[slen + 1];
        strncpy(wordBank[i], buff, slen + 1);
        i++;
    }
    
    
  // Pick a random word from the wordBank
    int target = rand() % numWords;
    int targetLen = strlen(wordBank[target]);

  // Make a dynamically-allocated copy of the word and scramble it
    char* word = new char[targetLen+1];
    strcpy(word, wordBank[target]);
    permute(word, targetLen);

  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
    while(!wordGuessed && numTurns > 0){
        cout << "Scrambled word: " << word << endl;
        cout << "What do you guess the original word is? ";
        cin >> guess;
    /* Complete the next line of code */
      
    wordGuessed = (strcmp(guess, wordBank[target])) == 0; // ADD code to check if the guess is equal to the chosen word.
                  // wordGuessed should be true if they are equal, and false otherwise
        
    numTurns--;   // Every guess counts as a turn
    }
    
    if(wordGuessed){
        cout << "You win!" << endl;
    }else{
        cout << "Too many turns...You lose!" << endl;
    }
  /* Free up any necessary memory */
    
    delete [] word;
    for (int i = 0; i < numWords; i++){
        delete[] wordBank[i];
    }
    delete [] wordBank;
    return 0;
}

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len){
  for (int i = len-1; i > 0; --i){
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}


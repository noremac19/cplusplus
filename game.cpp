//
//  main.cpp
//  Hangman
//
//  Created by Cameron Walcott on 10/2/19.
//  Copyright © 2019 Cameron Walcott. All rights reserved.
//

// hangman.cpp
// Hangman game illustrates string library functions,
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char answer[], const char* targetWord, char guess, int numChars);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn",
                          "science", "engineer"};

const int numWords = 10;
int n = 0;
int numTurns = 10;
int i = 0;

int main()
{
  srand(time(0));
  char guess;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the
                  //  user guesses the letter
    cout << targetWord << endl;
    strcpy(word,targetWord);
    int numChars = strlen(word) ;
    word[numChars] = '\0';
    for(int i=0; i<numChars; i++){
        word[i] = '*';
    }
    int turns = numTurns;
    for(int b=0; b<=numTurns; b++){
        cout << "Current word: " << word << endl;
        cout << turns << "remain. Enter a letter to guess: " << endl;
        cin >> guess;
        processGuess(word, targetWord, guess, numChars);
        turns = turns-1;
        if(strchr(word, '*')){
            continue;
        }else{
            break;
        }
        
    }
    if(strcmp(word, targetWord)==0){
        cout << "The word was: " << word << ". You win!" << endl;
    }else{
        cout << "Too many turns. You lose!" << endl;
    }
    



  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed




  // Print out end of game status


    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char answer[], const char* targetWord, char guess, int numChars){
        for(n=0; n<=numChars; n++){
            if(targetWord[n] == guess){
                answer[n] = targetWord[n];
            }
        }
    return 0;
}



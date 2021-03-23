//
//  main.cpp
//  twentyone
//
//  Created by Cameron Walcott on 10/3/19.
//  Copyright © 2019 Cameron Walcott. All rights reserved.
//

/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name:
 * USC email:
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] =
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
    int a;
    int b;
    int temp;
    for(a=NUM_CARDS-1; a>0; a--)
    {
        b = rand() % (a+1);
        temp = cards[b];
        cards[b] = cards[a];
        cards[a] = temp;
    }
            
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  /******** You complete ****************/
    cout << type[id % 13];
    cout << '-' << suit[id / 13];


}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
    return value[id % 13];

}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
    for(int a=0; a<numCards; a++)
    {
        printCard(hand[a]);
        cout << " ";
    }
    cout << endl;



}

/**
 * Should return the total score of the provided hand.
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
    int aces = 0;
    int sum = 0;
    for(int a = 0; a<numCards; a++) 
    {
        sum = sum+cardValue(hand[a]);
        if(cardValue(hand[a])==11)
        {
            aces++;
        }
    }
    while(aces!=0 && sum>21)
    {
        if(sum>21)
        {
            sum = sum-10;
        }
        aces--;
    }
    return sum;


}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
    char playagain;
    int a;
    do{
        for(a =0; a<52; a++){ //shuffles the cards
            cards[a] = a;
        }
        shuffle(cards);
        phand[0] = cards[0];
        phand[1] = cards[2];
        dhand[0] = cards[1];
        dhand[1] = cards[3];
        
        cout << "Dealer:"; // outputs dealer's card
        cout << '?'; // outputs ?
        cout << " ";
        printCard(dhand[1]);
        cout << endl;
        
        cout << "Player:"; // lists both of players' cards
        printCard(phand[0]);
        cout << " ";
        printCard(phand[1]);
        cout << endl;
        
        char decision; // decide to either hit or stay
        int pc = 2;
        int carddrawn = 4;
        int dc = 2;
    // series of conditional statements related to blackjack and the sum of 21
        if(getBestScore(dhand,pc)==21){
            while(getBestScore(dhand,dc)<17){
                dhand[dc] = cards[carddrawn];
                dc++;
                carddrawn++;
                if(getBestScore(dhand,dc)==21){
                    cout << "Tie " << endl;
                }
            }
            cout << "Win " << getBestScore(phand, pc) << " " << getBestScore(dhand, dc) << endl;
            cout << "Play again? (y/n)" << endl; // asks user if they want to play again
            cin >> playagain;
            continue;
        }
        
        cout << "Type 'h' to hit or 's' to stand" << endl;
        cin >> decision;
        
        while(getBestScore(phand,pc)<21 && decision == 'h'){
            phand[pc] = cards[carddrawn];
            pc++;
            carddrawn++;
            printHand(phand, pc);
            if(getBestScore(phand,pc)<21){
                cout << "Type 'h' to hit or 's' to stand" << endl;
                cin >> decision;
            }
        }
        if(getBestScore(phand,pc) == 21 || decision == 's'){
            while(getBestScore(dhand,dc)<17){
                dhand[dc] = cards[carddrawn];
                dc++;
                carddrawn++;
                if(getBestScore(dhand,dc)==21){
                    cout << "Lose" << endl;
                }
            }
        }
        // what happens if player busts
        if(getBestScore(phand,pc)>21){ 
            cout << "Lose " << getBestScore(phand,pc) << " " << getBestScore(dhand,dc) << endl;
        // what happens if dealer busts
        }else if(getBestScore(dhand,dc)>21){
            cout << "Dealer Busts" << endl;
            cout << "Win " << getBestScore(phand,pc) << " " << getBestScore(dhand,dc) << endl;
        // what happens if player and dealer tie
        }else if(getBestScore(dhand,dc)==getBestScore(phand,pc)){
            cout << "Tie " << getBestScore(phand,pc) << " " << getBestScore(dhand,dc) << endl;
        // what happens if player's hand > dealer's hand. Then player wins
        }else if(getBestScore(dhand,dc)<getBestScore(phand,pc)){
            cout << "Win " << getBestScore(phand,pc) << " " << getBestScore(dhand,dc) << endl;
        // what happens if player's hand < dealer's hand. Then player wins
        }else{
            cout << "Lose " << getBestScore(phand,pc) << " " << getBestScore(dhand,dc) << endl;
        }
        cout << "Play again? (y/n)" << endl; // asks user if they want to play again
        cin >> playagain;
    }while(playagain=='y');


  return 0;
}
    


//
//  main.cpp
//  CardDeck
//
//  Created by 20071032 on 05/04/2017.
//  Copyright © 2017 20071032. All rights reserved.
//
/*
	Since the assignment text was unclear in some area's I 
	decided to go with the player placing back the cards once 
	he requested the user-defined amount of cards.
	In other words, I don't remove any cards from the deck.

	Since this part was not explicitly stated, I will go with that
	approach
*/

#include <string>
#include "Deck.h"


void getUsersResponse(int& usersChoice, std::string& prompt);
void displayMenu();
void displayInstructions();
void displayHand(const std::vector<Card>& cards);

//The main function
int main(int argc, const char * argv[]) {
	Deck deck;					//A single deck of 52 cards
	int choice = -1;			//Player's choice for the menu options
	int hand = -1;				//Number of cards player requested
	std::string prompt = ">> ";	//Prompt for getting player's response

	displayInstructions();
	displayMenu();
	getUsersResponse(choice, prompt);

	//While player didn't selected Exit option
	while (choice != 0) {
		switch (choice) {
		case 1:		//Player requests x amount of cards
			prompt = "How many cards do you want : ";
			getUsersResponse(hand, prompt);
			displayHand(deck.getHand(hand));
			break;
		case 2:		//Player wants to shuffle the cards
			deck.shuffle();
			std::cout << "Cards shuffled\n";
			break;
		default:	//Incorrect option
			std::cout << "Wrong command entered!\n\n";
			break;
		}

		displayMenu();
		prompt = ">> ";
		getUsersResponse(choice, prompt);
	}
	
	return 0;
}

//Display the menu options to the Player
void displayMenu() {
	std::cout << "\n1) Get x amount of cards\n" <<
		"2) Shuffle cards\n" <<
		"0) Exit\n";
}

//Display the cards the Player requested
void displayHand(const std::vector<Card>& cards) {
	for (std::vector<Card>::const_iterator iter = cards.begin(); iter != cards.end(); ++iter) {
		std::cout << *iter << std::endl;
	}
}

//Display the intructions 
void displayInstructions() {
	std::cout << "A Deck Of Cards program!\n\n" <<
		"The deck contains 52 cards of all four suits:\n" <<
		"H = Hears, D = Diamonds, S = Spades, C = Clubs\n" <<
		"As well as the values each card holds : \n" <<
		"A = Ace, K = King, Q = Queen, J = Jack, T = 10\n" <<
		"The rest of the values are numbered\n\n" <<
		"The Player can request a hand with x number of cards\n" <<
		"and shuffle the deck.\n\n" <<
		"Note: Unless you shuffle the deck, the cards you get will \n" <<
		"be the same (obviously). Since we weren't specified, I will \n" <<
		"take it as the player puts back the cards after looking at them\n";
}

//Get Players reponse to a prompt
void getUsersResponse(int& usersChoice ,std::string& prompt) {
	std::cout << prompt;
	std::cin >> usersChoice;
}

//Overriding the << operator from the Card class
std::ostream& operator<< (std::ostream& os, const Card& c) {
	os << "Card's suit : " << c.m_suit << "  Card's value : " << c.m_value;
	return os;
}

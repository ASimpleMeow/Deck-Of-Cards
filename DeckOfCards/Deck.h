//
//  Deck.hpp
//  CardDeck
//
//  Created by 20071032 on 05/04/2017.
//  Copyright © 2017 20071032. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include  <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include "Card.h"

//Deck class
class Deck {
private:
	/*
	Demonstration of composition, Deck contains Cards
	Due to grammar mistakes in the brief, I took it as
	both the vector and and the cards in the vector should be 
	in the Heap
	*/
	std::vector<Card*>* m_cards = new std::vector<Card*>();
public:
	Deck();					//Default constructor
	Deck(const Deck& d);	//Copy constructor
	~Deck();				//Destructor
	const std::vector<Card> getHand(int cards);	//Getter for the cards
	void shuffle();			//Shuffle the cards randomly
};

#endif /* Deck_hpp */
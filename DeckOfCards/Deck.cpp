//
//  Deck.cpp
//  CardDeck
//
//  Created by 20071032 on 05/04/2017.
//  Copyright © 2017 20071032. All rights reserved.
//

#include "Deck.h"

//Default constructor
Deck::Deck() {
	//Reserve the space in the vector for 52 cards
	//Seed the random for the shuffle
	m_cards->reserve(52);
	srand(static_cast<unsigned int>(time(0)));

	//Prepare all the necessary suits and values
	char suits[4] = { 'H','D','C','S' };
	char values[13] = { 'A','K','Q','J','T','9','8','7','6','5','4','3','2' };

	//Add the Card to Heap memory and the m_cards vector
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			m_cards->push_back(new Card(suits[i], values[j]));
		}
	}

	shuffle();	//Give the deck a shuffle so it's not ordered
}

//Copy constructor
Deck::Deck(const Deck& d){
	//Allocate the space for the m_cards vector
	m_cards = new std::vector<Card*>(d.m_cards->size());

	//Add all the cards and place them on the Heap
	for (std::size_t i = 0; i < d.m_cards->size(); ++i)
		(m_cards->at(i)) = new Card(d.m_cards->at(i)->getSuit(), d.m_cards->at(i)->getValue());

}

//Destructor
Deck::~Deck() {
	//Delete all cards on the Heap in the m_cards vector
	for (std::vector<Card*>::const_iterator iter = m_cards->begin(); iter != m_cards->end(); ++iter)
		delete *iter;
	
	delete m_cards;	//Delete the m_cards vector
	m_cards = 0;	//NULL the m_cards pointer
}

//Returns the hand of cards the Player requested
const std::vector<Card> Deck::getHand(int cards) {
	std::vector<Card> hand; //Players hand
	hand.reserve(cards);	//Reserve the space for the said amount of cards
	
	//Add the cards for the hand
	for (std::vector<Card*>::const_iterator iter = m_cards->begin(); iter != m_cards->end(); ++iter) {
		hand.push_back(*(*iter));
		--cards;
		if (cards <= 0) break;
	}
	return hand;
}

//Shuffle the cards randomly using the random_shuffle algorithm
void Deck::shuffle() {
	std::random_shuffle(m_cards->begin(), m_cards->end());
}

//
//  Card.cpp
//  CardDeck
//
//  Created by 20071032 on 05/04/2017.
//  Copyright © 2017 20071032. All rights reserved.
//

#include "Card.h"

//Constructor for the class
Card::Card(char suit, char value) :
	m_suit(suit), m_value(value) {
}

//Getter for the suit
const char& Card::getSuit() {
	return this->m_suit;
}

//Getter for the value
const char& Card::getValue() {
	return this->m_value;
}
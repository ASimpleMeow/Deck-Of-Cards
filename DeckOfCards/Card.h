//
//  Card.hpp
//  CardDeck
//
//  Created by 20071032 on 05/04/2017.
//  Copyright © 2017 20071032. All rights reserved.
//

#ifndef CARD_H
#define CARD_H

#include <iostream>

//Card class
class Card {
private:
	char m_suit;	//Card's suit
	char m_value;	//Card's value
public:
	Card(char suit, char value);	//Constructor
	const char& getSuit();			//Getter for m_suit
	const char& getValue();			//Getter for m_value
	//friend member function overriding the << operator for the output stream
	friend std::ostream& operator<< (std::ostream& os, const Card& c);
};

#endif /* Card_hpp */

#include <iostream>
#include"Card.h"

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
	int value;

    if(!m_IsFaceUp)
    {
        return 0;
    }
    switch(m_Rank)
    {
    case ACE:
        value=1;
        break;
    case TWO:
        value=2;
        break;
    case THREE:
        value=3;
        break;
    case FOUR:
        value=4;
        break;
    case FIVE:
        value=5;
        break;
    case SIX:
        value=6;
        break;
    case SEVEN:
        value=7;
        break;
    case EIGHT:
        value=8;
        break;
    case NINE:
        value=9;
        break;
    case TEN:
        value=10;
        break;
    case JACK:
        value=10;
        break;
    case QUEEN:
        value=10;
        break;
    case KING:
        value=10;
        break;
    }

	// problem 12.3

	return value;
}

bool Card::CheckRank()
{
    if (m_Rank==ACE)
    return true;
    else return false;
}
void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

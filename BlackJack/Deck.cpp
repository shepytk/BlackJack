
#include <algorithm>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"

Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
    Clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}

void Deck::Shuffle()
{
    std::random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
    if (m_Cards.size()!=0)
    {
        Card* temp;
        temp=this->m_Cards.back();
        aHand.Add(temp);
        m_Cards.pop_back();
    }
    else std::cout<<("No card to deal!\n");


}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    std::cout << std::endl;
    //continue to deal a card as long as generic player isn't busted and
    //wants another hit
    while ( !(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting() )
    {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.IsBusted())
		{
            aGenericPlayer.Bust();
		}
    }
}



#include <iostream>
#include "Hand.h"
#include <vector>
#include "Card.h"
Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total=0;
	int num_ACE=0;
	std::vector<Card*>::const_iterator j;
	for(j=m_Cards.begin();j!=m_Cards.end();++j)
    {
        total += (*j)->GetValue();
        num_ACE=num_ACE+(*j)->CheckRank();
    }
    if (num_ACE && total+10<21)
        total=total+10;
    // problem 12.5

    return total;
}

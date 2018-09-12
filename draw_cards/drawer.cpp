#include "drawer.h"
#include <cassert>
using namespace std;
using namespace CARD_DRAWER;
double CARD_DRAWER::Card::GetChance()
{
	return chance_;
}

Card& CARD_DRAWER::Card::GetCard(int id)
{
	return cards.at(id);
}

CARD_DRAWER::Card::Card(int id, std::string name, double chance):
	id_(id),
	name_(name),
	chance_(chance)
{
}

void CARD_DRAWER::Group::AddCard(int id)
{
	cards_.push_back(id);
}

int CARD_DRAWER::Group::ReturnCardByChance()
{
	double chance_sum = 0;
	for (auto id : cards_)
	{
		chance_sum += Card::GetCard(id).GetChance;
	}
	double result = rand() / static_cast<double>(RAND_MAX)*chance_sum;
	for (auto id : cards_)
	{
		double card_chance = Card::GetCard(id).GetChance;
		if (card_chance >= result)
		{
			return id;
		}
		else
		{
			result -= card_chance;
		}
	}
	assert(false);
}

int CARD_DRAWER::Group::ReturnCardByRandom()
{
	int num = cards_.size();
	uniform_int_distribution<int> dis(0,num-1);
	default_random_engine e(time(NULL));
	int result = dis(e);
	return result;
}

CARD_DRAWER::Rule::Rule(bool if_limit, int limit, Group limit_group):
	if_limit_(if_limit),
	limit_(limit),
	limit_group_(limit_group)
{
	assert(if_limit);
}
// ½öÏÞfalse
CARD_DRAWER::Rule::Rule(bool if_limit):
if_limit_(if_limit)
{
	assert(!if_limit);
}

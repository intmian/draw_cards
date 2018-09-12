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

CARD_DRAWER::Rule::Rule(bool if_limit, int limit, Group limit_group,bool limit_group_return_random):
	if_limit_(if_limit),
	limit_(limit),
	limit_group_(limit_group),
	limit_group_return_random_(limit_group_return_random)
{
	assert(if_limit);
}
// ����false
CARD_DRAWER::Rule::Rule(bool if_limit):
if_limit_(if_limit)
{
	assert(!if_limit);
}

int CARD_DRAWER::Drawer::Draw()
{
	if (rule_.if_limit_)
	{
		now++;
		if (now == rule_.limit_)
		{
			now = 0;
			if (rule_.limit_group_return_random_)
				return rule_.limit_group_.ReturnCardByRandom();
			else
				return rule_.limit_group_.ReturnCardByChance();
			assert(false);
		}
	}
	double  chance_sum = 0;
	for (auto id : cards_)
	{
		chance_sum += Card::GetCard(id).GetChance;
	}
	uniform_real_distribution<double> dis(0,chance_sum);
	default_random_engine e(time(NULL));
	double result = dis(e);

	for (int id : cards_)
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

std::vector<int> CARD_DRAWER::Drawer::Draw(int n)
{
	vector<int> result;
	while (n--)
	{

	}
}
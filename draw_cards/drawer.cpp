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

CARD_DRAWER::Rule::Rule(int draw_cards_num,bool if_limit, int limit, Group limit_group,bool limit_group_return_random):
	draw_cards_num_(draw_cards_num),
	if_limit_(if_limit),
	limit_(limit),
	limit_group_(limit_group),
	limit_group_return_random_(limit_group_return_random)
{
	assert(if_limit);
}
// 仅限false
CARD_DRAWER::Rule::Rule(int draw_cards_num,bool if_limit):
	draw_cards_num_(draw_cards_num),
	if_limit_(if_limit)
{
	assert(!if_limit);
}

int CARD_DRAWER::Drawer::Draw()
{
	if (rule_.if_limit_)  // 存在保底的情况下
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
			// 保底重置机制
			if (in_group(id))
			{
				now = 0;
			}
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
		result.push_back(Draw());  // 关于其他的规则全部体现在draw 不带参的方法中
	}
	return result;
}

bool CARD_DRAWER::Drawer::in_group(int id)
{
	for (auto card : rule_.limit_group_.cards_)
	{
		if (id == card)
		{
			return false;
		}
	}
	return false;
}

Result CARD_DRAWER::Drawer::StartUntilGetCard(vector<int> card_need)
{
	map<int, bool> if_out;
	for (auto it : card_need)
	{
		if_out[it] = false;
	}
	bool flag = false;
	while (!flag)
	{
		
	}
}

Result CARD_DRAWER::Drawer::StartUntilLimit(int limit)
{
	vector<int> cards_drawed;
	now = 0;
	while (limit - now <= rule_.draw_cards_num_ && limit >= rule_.draw_cards_num_)
	{
		vector<int> temp = Draw(rule_.draw_cards_num_);
		now += rule_.draw_cards_num_;
	}
	for (int i = 0; i < limit % rule_.draw_cards_num_;i++)
	{
		// TODO
	}
	return Result(cards.size(),cards);
}

void CARD_DRAWER::Drawer::SetRule(Rule rule)
{
	rule_ = rule;
}

void CARD_DRAWER::Drawer::AddCard(int card)
{
	cards_.push_back(card);
}


#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <ctime>
namespace CARD_DRAWER
{
	class Card
	{
	private:
		int id_;
		std::string name_;
		double chance_;
	public:
		double GetChance();
		static std::vector<Card> cards;
		static Card& GetCard(int id);  // id同索引
		Card(int id,std::string name,double chance);
	};
	class Group
	{
	private:
		std::vector<int> cards_;
	public:
		void AddCard(int id);
		int ReturnCardByChance();
		int ReturnCardByRandom();
	};
	class Rule
	{
	public:
		bool if_limit_;
		int limit_;
		Group limit_group_;
		Rule(bool if_limit,int limit,Group limit_group);
		Rule(bool if_limit);
	};
	class Result
	{
	public:
		std::vector<int> card_get_;
		int num;
	};
	class Drawer
	{
	private:
		Rule rule_;
		std::vector<int> cards_;
		int now;  // 保底计数
		Card Draw();
		Card Draw(int n);
	public:
		Result StartUntilGetCard();
		Result StartUntilLimit(int limit);
		void SetRulr(Rule rule);
		void AddCard(Card card);
	};
}
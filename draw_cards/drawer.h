#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <ctime>
#include <map>
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
	public:
		std::vector<int> cards_;
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
		bool limit_group_return_random_;
		bool draws_protect_;
		int draws_protect_limit_;
		int draw_cards_num_;
		Rule(int draw_cards_num,bool if_limit,int limit,Group limit_group,bool limit_group_return_random);
		Rule(int draw_cards_num,bool if_limit);
	};
	class Result
	{
	public:
		std::vector<int> card_get_;
		int num_;
		Result(int n,std::vector<int> card_get) :
			num_(n),card_get_(card_get)
		{
		}
	};
	class Drawer
	{
	private:
		Rule& rule_;
		std::vector<int> cards_;
		int now;  // 保底计数 抽前记得置零
		int Draw();  // 保底归他
		double chance_sum_;
		std::vector<int> Draw(int n);  // 多抽奖励归他
		// 仅负责抽，不负责统计
		bool in_group(int id);
	public:
		Result StartUntilGetCard(vector<int> card_need);
		Result StartUntilLimit(int limit);
		void SetRule(Rule rule);
		void AddCard(int card);  // 仅输入id
	};
}
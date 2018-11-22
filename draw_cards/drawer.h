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
		static std::vector<Card> cards;  // 全局的卡库
		static Card& GetCard(int id);  // id同索引
		Card(int id,std::string name,double chance);
		// chance代表了权重
	};
	class Group
	{
	private:
	public:
		std::vector<int> cards_;
		void AddCard(int id);
		int ReturnCardByChance();
		// 根据概率返回卡
		int ReturnCardByRandom();
		// 随机从卡组里返回卡
	};
	class Rule
	{
	public:
		bool if_limit_;  // 保底
		int limit_;  // 保底次数 倒数制
		Group limit_group_;  // 保底抽取的组
		bool limit_group_return_random_;  // 随机返回或者按照概率 同时包括多抽以及保底
		bool if_draws_protect_;  // 多抽必出
		Group draws_group_;  //多抽保底区
		int draw_cards_num_;  // 抽了多少卡
		Rule(
			int draw_cards_num,
			bool if_limit, 
			int limit,
			Group limit_group,
			bool if_draws_protect,
			Group draws_group,
			bool limit_group_return_random);
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
		Result StartUntilGetCard(std::vector<int> card_need);
		Result StartUntilLimit(int limit);
		void SetRule(Rule rule);
		void AddCard(int card);  // 仅输入id
	};
}
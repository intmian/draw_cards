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
		static Card& GetCard(int id);  // idͬ����
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
		bool limit_group_return_random_;
		bool draws_protect_;
		int draws_protect_limit_;
		Rule(bool if_limit,int limit,Group limit_group,bool limit_group_return_random);
		Rule(bool if_limit);
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
		int now;  // ���׼��� ��ǰ�ǵ�����
		int Draw();
		double chance_sum_;
		std::vector<int> Draw(int n);
		// ������飬������ͳ��
	public:
		Result StartUntilGetCard(vector<int> card_need);
		Result StartUntilLimit(int limit);
		void SetRule(Rule rule);
		void AddCard(int card);  // ������id
	};
}
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
		static std::vector<Card> cards;  // ȫ�ֵĿ���
		static Card& GetCard(int id);  // idͬ����
		Card(int id,std::string name,double chance);
		// chance������Ȩ��
	};
	class Group
	{
	private:
	public:
		std::vector<int> cards_;
		void AddCard(int id);
		int ReturnCardByChance();
		// ���ݸ��ʷ��ؿ�
		int ReturnCardByRandom();
		// ����ӿ����ﷵ�ؿ�
	};
	class Rule
	{
	public:
		bool if_limit_;  // ����
		int limit_;  // ���״��� ������
		Group limit_group_;  // ���׳�ȡ����
		bool limit_group_return_random_;  // ������ػ��߰��ո��� ͬʱ��������Լ�����
		bool if_draws_protect_;  // ���س�
		Group draws_group_;  //��鱣����
		int draw_cards_num_;  // ���˶��ٿ�
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
		int now;  // ���׼��� ��ǰ�ǵ�����
		int Draw();  // ���׹���
		double chance_sum_;
		std::vector<int> Draw(int n);  // ��齱������
		// ������飬������ͳ��
		bool in_group(int id);
	public:
		Result StartUntilGetCard(std::vector<int> card_need);
		Result StartUntilLimit(int limit);
		void SetRule(Rule rule);
		void AddCard(int card);  // ������id
	};
}
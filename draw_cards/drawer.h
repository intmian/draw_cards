#pragma once
#include <vector>

namespace CARD_DRAWER
{
	class Rule // ��ӵĳ鿨���� ��װ��Drawer�ڲ�
	{
	public:
		int limit_;
		bool if_limit_; // ����
		bool limit_method_; // False �����ȡ True �̶���ȡ
		Group limit_group_; // ����
	};

	enum draw_attitude
	{
	};

	class Card// ָ��Ƭ������
	{
	private:
	public:
		double probability_;

		Card(int probability) :
			probability_(probability)
		{}
	};
	class Card_after  // ������
	{
	private:
		const Card& card_kind_;  // ����
	public:
		const Card& Get_kind()
		{
			return card_kind_;
		}
		Card_after(const Card& kind) :
			card_kind_(kind)
		{}
	};
	class Group // �Ƕ�������������ĳһ�������� ���������ظ�
	{
	public:
		std::vector<Card> return_cards();
		const bool if_top_; // չʾ�Ƿ�Ϊ������
		const Group & Father_; // ����
		bool add_card(Card card);
	private:
		std::vector<Card> cards_; // ��������������п���
		std::string name_;
	};

	class Drawer // �鿨���ⲿ�ӿ� �鿨��
	{
	private:
		std::vector<Group> groups_;
		bool addgroup(Group group);
		bool if_full();
		Rule rule_;
		int limit_now_;// �����Ѿ���ı���
		Card draw(); // ��һ��
		vector<Card> draw(int draw_number); // һ�γ��� ʮ��֮���
		vector<vector<Card>> results;  // ��һ��Ƕ�׵����鿨�˵Ĳ�ͬ�ν�� �ڶ���
	public:
	};
}
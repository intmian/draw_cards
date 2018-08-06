#pragma once
#include <vector>



namespace CARD_DRAWER
{
	class Card// ָ��Ƭ������
	{
	private:

	public:
		double probability_;

		Card(int probability) :
			probability_(probability)
		{}

	};

	class Group // �Ƕ�������������
	{
	public:
		std::vector<Card> return_cards();
		const bool if_top_; // չʾ�Ƿ�Ϊ������
		const Group * Father_; // ����
	private:
		std::vector<Card> cards_; // ��������������п���
		std::string name_;
	};

	class Drawer // �鿨���ⲿ�ӿ� �鿨��
	{
	private:
		std::vector<Group> groups_;
		Rule rule_;
		int limit_now_;// �����Ѿ���ı���

	};

	class Rule // ��ӵĳ鿨���� ��װ��Drawer�ڲ�
	{
	public:
		int limit_;
		bool if_limit_; // ����
		bool limit_method_; // False �����ȡ True �̶���ȡ
		Group limit_group_; // ����
	};
}
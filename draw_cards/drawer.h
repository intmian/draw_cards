#pragma once
#include <vector>

namespace CARD_DRAWER
{
	class Rule // 添加的抽卡规则 封装在Drawer内部
	{
	public:
		int limit_;
		bool if_limit_; // 保底
		bool limit_method_; // False 随机抽取 True 固定抽取
		Group limit_group_; // 保底
	};

	enum draw_attitude
	{
	};

	class Card// 指卡片的种类
	{
	private:
	public:
		double probability_;

		Card(int probability) :
			probability_(probability)
		{}
	};
	class Card_after  // 单个卡
	{
	private:
		const Card& card_kind_;  // 种类
	public:
		const Card& Get_kind()
		{
			return card_kind_;
		}
		Card_after(const Card& kind) :
			card_kind_(kind)
		{}
	};
	class Group // 非顶级组必须包含在某一顶级组内 组名不可重复
	{
	public:
		std::vector<Card> return_cards();
		const bool if_top_; // 展示是否为顶级组
		const Group & Father_; // 父组
		bool add_card(Card card);
	private:
		std::vector<Card> cards_; // 父组包含子组所有卡牌
		std::string name_;
	};

	class Drawer // 抽卡的外部接口 抽卡者
	{
	private:
		std::vector<Group> groups_;
		bool addgroup(Group group);
		bool if_full();
		Rule rule_;
		int limit_now_;// 现在已经抽的保底
		Card draw(); // 抽一次
		vector<Card> draw(int draw_number); // 一次抽多个 十连之类的
		vector<vector<Card>> results;  // 第一层嵌套单个抽卡人的不同次结果 第二层
	public:
	};
}
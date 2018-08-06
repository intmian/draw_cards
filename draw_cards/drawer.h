#pragma once
#include <vector>



namespace CARD_DRAWER
{
	class Card// 指卡片的种类
	{
	private:

	public:
		double probability_;

		Card(int probability) :
			probability_(probability)
		{}

	};

	class Group // 非顶级组必须包含在
	{
	public:
		std::vector<Card> return_cards();
		const bool if_top_; // 展示是否为顶级组
		const Group * Father_; // 父组
	private:
		std::vector<Card> cards_; // 父组包含子组所有卡牌
		std::string name_;
	};

	class Drawer // 抽卡的外部接口 抽卡者
	{
	private:
		std::vector<Group> groups_;
		Rule rule_;
		int limit_now_;// 现在已经抽的保底

	};

	class Rule // 添加的抽卡规则 封装在Drawer内部
	{
	public:
		int limit_;
		bool if_limit_; // 保底
		bool limit_method_; // False 随机抽取 True 固定抽取
		Group limit_group_; // 保底
	};
}
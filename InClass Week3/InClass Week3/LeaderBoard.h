#ifndef LEADERBOARD_HEADER_H
#define LEADERBOARD_HEADER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <XEngine.h>

using std::map;
using std::string;
using std::vector;


class LeaderBoard
{
public:
	LeaderBoard() {}
	~LeaderBoard() {}

	struct LeaderBoardItem
	{
		string playerName;
		int score;
	};

	void InitializeData(map<string, int> data);

	void PrintLeaderBoard();

private:
	vector<LeaderBoardItem> m_leaders;
};

#endif
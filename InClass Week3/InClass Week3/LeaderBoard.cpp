#include "LeaderBoard.h"

void LeaderBoard::InitializeData(map<string, int> data)
{
	m_leaders.clear();
	std::map<string, int>::iterator it = data.begin();

	for (; it != data.end(); ++it)
	{
		m_leaders.push_back({ it->first, it->second });
	}
}

void LeaderBoard::PrintLeaderBoard()
{
	if (std::size(m_leaders) <= 0)
	{
		return;
	}

	float xPos = 275.0f;
	float yPos = 110.0f;
	string text;
	vector<LeaderBoardItem>::iterator it = m_leaders.begin();
	for (; it != m_leaders.end(); ++it)
	{
		text += (it->playerName + ": " + std::to_string(it->score));
		text += "\n";
	}
	const char* print = text.c_str();
	X::DrawScreenText(print, xPos, yPos, 24.0f, X::Math::Vector4(1.0f, 1.0f, 1.0f, 0.0f));

}
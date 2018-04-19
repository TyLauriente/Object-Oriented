#include <XEngine.h>
#include "LeaderBoard.h"

//Globals are bad
LeaderBoard* pLeaderBoard;

void Initialize();
void Terminate();

bool Update(float deltaTime)
{
	X::DrawScreenText("*** LeaderBoard ***", 275.0f, 80.0f, 24.0f, X::Math::Vector4(0.0f, 1.0f, 1.0f, 0.0f));
	pLeaderBoard->PrintLeaderBoard();
	return X::IsKeyPressed(X::Keys::ESCAPE);
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	X::Start();
	Initialize();

	X::Run(Update);

	Terminate();
	X::Stop();
}

void Initialize()
{
	std::map<string, int> data =
	{
		{"Ty", 1354},
		{"Bhavil", 2},
		{"Jackob", 3},
		{"Juan", 1},
		{"Trump", 0},
		{"Gill", 7},
		{"The F'ing Queen", 500000}
	};
	pLeaderBoard = new LeaderBoard();
	pLeaderBoard->InitializeData(data);
}

void Terminate()
{
	delete pLeaderBoard;
}
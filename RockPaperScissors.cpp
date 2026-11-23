#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };
int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
struct stGameResults
{
	short GameRounds = 0;
	short Player1WonTimes = 0;
	short Computer2WonTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string	WinnerName = "";

};
struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;

};
short ReadHowManyRounds()
{
	short Rounds = 1;
	do
	{
		cout << "How Many Rounds 1 yo 10 ? ";
		cin >> Rounds;
	} while (Rounds < 1 || Rounds > 10);
	return Rounds;
}
enGameChoice ReadPlayerChoice()
{
	short Choice = 1;
	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? : ";
		cin >> Choice;
	} while (Choice < 1 || Choice>3);

	return (enGameChoice)Choice;
}

string ChoiceName(enGameChoice Choice)
{
	string ArrGameChoice[3] = { "Stone","Paper","Scissors" };
	return ArrGameChoice[Choice - 1];
}
string WinnerName(enWinner Winner)
{
	string ArrWinnerName[3] = { "Player","Computer","No Winner" };
	return ArrWinnerName[Winner - 1];
}
enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}
void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n_____________________Round [" << RoundInfo.RoundNumber << "]___________________" << endl << endl;
	cout << "Player Choice   : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner    : " << RoundInfo.WinnerName << endl;
	cout << "________________________________________________\n\n";

}
enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}
stGameResults FillGameResults(int GameRounds, short Player1WonTimes,
	short ComputerWonTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.GameRounds = GameRounds;
	GameResults.Player1WonTimes = Player1WonTimes;
	GameResults.Computer2WonTimes = ComputerWonTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WonTimes, ComputerWonTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;


}
string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
	}
	return t;
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}
	return enWinner::Player;
}
stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerWinTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player)
			PlayerWinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWonTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWonTimes, DrawTimes);
}
void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F"); // turn screen to Green
		break;
	case enWinner::Computer:
		system("color 4F"); // turn screen to Red
		cout << "\a";
		break;
	default:
		system("color 6F"); // turn screen to Yellow
		break;
	}
}
void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "_________________________[ Game Results ]__________________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 Won Times  : " << GameResults.Player1WonTimes << endl;
	cout << Tabs(2) << "Computer Won Times : " << GameResults.Computer2WonTimes << endl;
	cout << Tabs(2) << "Draw Times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "___________________________________________________________________\n\n";
	SetWinnerScreenColor(GameResults.GameWinner);

}
void ShowGameOverScreen()
{

	cout << Tabs(2) << "___________________________________________________________________\n\n";
	cout << Tabs(2) << "                    +++ G a m e O v e r +++ \n";
	cout << Tabs(2) << "___________________________________________________________________\n\n";



}
void ResetScreen()
{
	system("cls");
	system("color 0F");
}
void StartGame()
{

	char PlayerAgain = 'Y';
	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);



		cout << endl << Tabs(3) << "Do you want to Play Again? Y/N ? ";
		cin >> PlayerAgain;
	} while (PlayerAgain == 'Y' || PlayerAgain == 'y');



}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	
	system("pause");
}








#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayTheGame();


int main()
{
	PrintIntro();
	PlayGame();
	AskToPlayTheGame();
	return 0; // exit the game
}


// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcom to Bulls and Cows, a fun word game.\n";
	cout << "Can you guyess the " << WORD_LENGTH;
	cout << " letter Isogram I'm thinking of?\n";
	cout << endl;
	return;
}


void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		if (count < NUMBER_OF_TURNS) {
			cout << endl;
		}
	}
}


// get  a guess from the player
string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}


bool AskToPlayTheGame()
{	
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



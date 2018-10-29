#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayTheGame();


int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayTheGame();
	} while (bPlayAgain);
	return 0; // exit the game
}


// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcom to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guyess the " << WORD_LENGTH;
	std::cout << " letter Isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	FBullCowGame BCGame; //instance of new game
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		if (count < NUMBER_OF_TURNS) {
			std::cout << std::endl;
		}
	}
}


// get  a guess from the player
std::string GetGuess()
{
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayTheGame()
{	
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



/* This is the console excutable that makes use of the BullCow Class.
This acts as the ciew in an MVC pattern, as is responsible for all
user intertarction. For game logic see FBullCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayTheGame();

FBullCowGame BCGame; //instance a new game

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
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcom to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guyess the " << WORD_LENGTH;
	std::cout << " letter Isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO chnage from for to while loop once we are vlaidating tries

	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess();  // TODO make loop checking vlaid

		// Submit valid guess to the game
		// Print the number of bulls and cows


		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarise game
}


// get  a guess from the player
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayTheGame()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



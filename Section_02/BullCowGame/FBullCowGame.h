#pragma once
#include <string>

using FString = std::string;
using int32 = int;


//all values initialised to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	
	// counts bulls and cows, and increasing try number assuming valid guess
	FBullCowCount SubmitGuess(FString);
	

private:
	// see constructor for initialisaton
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
};
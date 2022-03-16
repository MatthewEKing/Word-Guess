// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The Hidden Word is: %s. \nIt is %i letters long"), *HiddenWord, HiddenWord.Len()); // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    //Initialize Variables
    HiddenWord = TEXT("test");
    Lives = HiddenWord.Len();
    bGameOver = false;

    // Welcome Message
    PrintLine(TEXT("Welcome To Word Guess!\nGuess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You Have %i Lives"), Lives);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    ClearScreen();
    PrintLine(TEXT("\nPress Enter to Play Again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("Correct Answer!"));
        EndGame();
        return;
    }

    //if (!IsIsogram)
    //{
    //    //check if isogram
    //    PrintLine(TEXT()"No Repeating Letters, guess again")
    //}

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Try Again, \nYou have %i lives left"), Lives);
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        return;
    }

    --Lives;
    PrintLine(TEXT("Lost A Life"));

    if (Lives <= 0)
    {
        PrintLine(TEXT("No More Lives!"));
        PrintLine(TEXT("\nThe hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }

    PrintLine(TEXT("Guess Again, you have %i lives left"), Lives);
    //Check Isogram
    //Check Number of Characters (position and if they are right or wrong)
}
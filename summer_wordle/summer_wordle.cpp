// summer_wordle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<vector>
#include <random>
using namespace std;
void displayInYellow(char);
void displayInGrey(char);
void displayInGreen(char);
string chooseWord(int);
const string GREY = "\033[90m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RESET = "\033[0m";
int main()
{
	random_device myEngine;
	uniform_int_distribution<int> randomInt(0, 5756);
	int number = randomInt(myEngine);

	int attempt = 0;
	string guess;
	
	cout << "WORDLE" << endl <<
		"Guess the 5 letter word" << endl;

	string wrd = chooseWord(number);
				
	while (attempt < 5)
	{
		cout << "Attempt " << attempt + 1 <<":"<< endl;

		int upper = 0;
		char guess2[6] = "*****";
		string chosenWord=wrd;
		cin >> guess;
		while (guess.length() != 5)
		{
			cout << "Word should be 5 letters long" << endl;
			cin >> guess;
		}
		for (int count = 0; count < guess.length(); count++)
		{
			int index;// Used as a subscript to search the array
			index = 0;


			int position; // To record the position of search value
			position = -1;
			bool found = false; // Flag to indicate if value was found
			while (index < guess.length() && !found)
			{
				if (guess[count] == chosenWord[index] && count == index) // If the value is found
				{
					found = true; // Set the flag
					position = index; // Record the value's subscript }
				}
				index++; // Go to the next element }

			}

			if (position != -1)
			{

				guess[position] = toupper(chosenWord[position]);
				chosenWord[position] = '*';
			}


		}
		for (int count = 0; count < guess.length(); count++)
		{
			int index;// Used as a subscript to search the array
			index = 0;


			int position; // To record the position of search value
			position = -1;
			bool found = false; // Flag to indicate if value was found
			while (index < guess.length() && !found)
			{
				if (guess[count] == chosenWord[index]) // If the value is found
				{
					found = true; // Set the flag
					position = index; // Record the value's subscript }
				}
				index++; // Go to the next element }
				
			}

			if (position != -1)
			{
				guess2[count] = guess[count];
				guess[count] = '-';
				chosenWord[position] = '*';
			}

		}




		
		for (int count = 0; count < guess.length(); count++)
		{
			if (isupper(guess[count]))
			{
				displayInGreen(guess[count]);
				upper++;
			}

			else if (guess[count] == '-')
				displayInYellow(toupper(guess2[count]));
			else
				displayInGrey(toupper(guess[count]));
		}
		cout << endl;
		if (upper == 5)
		{
			cout << "You got the word" << endl;
			break;
		}
		attempt++;
	}
	if (attempt == 5)
	{
		cout <<"You did not get the word. The word was " << wrd;
	}
					return 0;

}
void displayInGreen(char letter)
{
	cout << GREEN << letter << RESET;
}

void displayInGrey(char letter)
{
	cout << GREY << letter << RESET;
}
void displayInYellow(char letter)
{
	cout << YELLOW << letter << RESET;
}

string chooseWord(int num)
{
	string chosenWord;
	ifstream file("words.txt"); // Replace "input.txt" with the path to your text file

	if (file.is_open()) {
		vector<string> words;
		string word;

		// Read all words from the file and store them in the vector
		while (file >> word) {
			words.push_back(word);
		}

		file.close();

		if (!words.empty()) {
			// Choose a specific word from the vector
			chosenWord = words[num]; // Example: selecting the third word (index 2)

			//cout << "Chosen word: " << chosenWord << endl;
		}
		else {
			cout << "No words found in the file." << endl;
		}
	}
	else {
		cout << "Failed to open file." << endl;
	}
	return chosenWord;
}
#include "stdafx.h"
#include "WordList.h"

//This script was used to check how many words has. It was a part of main for testing purposes but now it is as a standalone script.

const std::string wordFileName("words.txt");

int WordLengthWmountCheck() {

	std::ifstream wordFile(wordFileName);
	std::string word;
	int arr[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	const int ArrayOffset = 1;

	// Read past the copyright notice at the top of words.txt
	while (std::getline(wordFile, word) && word != "---")
	{
		// do nothing
	}
	// Read each line in the file
	while (std::getline(wordFile, word))
	{

		bool isValid = true;


		for (int i = 0; i < word.length(); i++)
		{
			if (isalpha(word[i]))
			{
				word[i] = toupper(word[i]);
			}
			else
			{
				isValid = false;
				break;
			}
		}

		// If it's a good word, add it to the list.
		if (isValid)
		{
			arr[word.length() - ArrayOffset] += 1;
		}
	}
	for (int i = 0; i < (sizeof(arr) / sizeof(*arr)); i++)
	{
		std::cout << arr[i] << std::endl;
	}

	return 0;
}
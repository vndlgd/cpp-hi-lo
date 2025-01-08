#include <iostream>

int main()
{
	int guess{};
	int answer{3}; // use a random number generator to make this better
	std::cout << "Lets play Hi-Lo!\n";
	for (int i{0}; i < 5; i++)
	{
		std::cout << "Guess the number: ";
		std::cin >> guess;
		if (guess > answer)
		{
			std::cout << "Too High\n";
		}
		else if (guess < answer)
		{
			std::cout << "Too Low\n";
		}
		else if (guess == answer)
		{
			std::cout << "You guessed correct! You won!\n";
			break;
		}
	}
	if (guess != answer)
	{
		std::cout << "You lost. The correct answer was " << answer << '\n';
	}
	return 0;
}

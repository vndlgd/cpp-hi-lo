#include <iostream>
#include <limits>

int GetInteger();
void IgnoreLine();
bool HasUnextractedInput();
bool ClearFailedExtraction();

int GetInteger()
{
    while (true) {
        int guess{};
        std::cout << "Guess the number: ";
        std::cin >> guess;
        if (!std::cin) {
            std::cin.clear();
            IgnoreLine();
            continue;
        }
        if (HasUnextractedInput()) {
            IgnoreLine();
            continue;
        }
        if (ClearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }
        IgnoreLine();
        return guess;
    }
}

void IgnoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool HasUnextractedInput()
{
    return !std::cin.eof()  && std::cin.peek() != '\n';
}

bool ClearFailedExtraction()
{
    if (!std::cin) {
        if (std::cin.eof()) {
            std::exit(0);
        }

        std::cin.clear();
        IgnoreLine();

        return true;
    }
    return false;
}

int main()
{
    int guess{};
    const int answer{3}; // use a random number generator to make this better
    std::cout << "Lets play Hi-Lo!\n";
    for (int i{0}; i < 5; i++)
    {
        guess = GetInteger();
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

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void greet()
{
    cout << "Hello!" << endl;
}

void farewell()
{
    cout << "Goodbye!" << endl;
}

void age_guesser()
{
    // Generate a random age between 1 and 100
    int guessed_age = rand() % 100 + 1;

    cout << "I'm going to guess your age. Let me try..." << endl;
    cout << "Is your age " << guessed_age << "?" << endl;

    char response;
    cout << "Enter 'y' if it's correct, 'n' if not,'q' to quit";
    cin >> response;

    if (response == 'y' || response == 'Y')
    {
        cout << "I guessed it right! Your age is " << guessed_age << "." << endl;
    }
    else if (response == 'n' || response == 'N')
    {
        cout << "Oh, your age is not as i guessed. Let me try again!" << endl;
        age_guesser(); // Recursive call for another guess
    }
    else if (response == 'q' || response == 'Q')
    {
        cout << "quitting";
        return;
    }
    else
    {
        cout << "Sorry, I didn't understand your response. Please try again." << endl;
    }
}

void chat()
{
    string user_input;
    while (true)
    {
        cout << "You: ";
        getline(cin, user_input);

        if (user_input.find("hello") != string::npos || user_input.find("hi") != string::npos)
        {
            greet();
        }
        else if (user_input.find("bye") != string::npos || user_input.find("goodbye") != string::npos)
        {
            farewell();
            break;
        }
        else if (user_input.find("age") != string::npos || user_input.find("guess") != string::npos)
        {
            age_guesser();
        }
        else
        {
          
            cout <<"I'm not sure I understand."<< endl;
        }
    }
}

int main()
{
    srand(time(0));
    cout << "Welcome to the Simple Chatbot!" << endl;
    cout << "Feel free to say hello, ask me to guess your age, or just chat with me." << endl;
    while (true)
        chat();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to ask a question and get user input
string ask_question(string question)
{
    cout << question;
    string input;
    getline(cin, input);
    for (int i = 0; i < input.size(); ++i)
    {
        input[i] = tolower(input[i]); // Convert to lowercase
    }
    // Trim leading and trailing whitespace
    size_t start = input.find_first_not_of(" \t");
    size_t end = input.find_last_not_of(" \t");
    return (start == string::npos || end == string::npos) ? "" : input.substr(start, end - start + 1);
}

// Function to evaluate employee performance based on given criteria
string evaluate_performance(const vector<string> &criteria)
{
    vector<string> criteria_lowercase = criteria;
    for (int i = 0; i < criteria_lowercase.size(); ++i)
    {
        for (int j = 0; j < criteria_lowercase[i].size(); ++j)
        {
            criteria_lowercase[i][j] = tolower(criteria_lowercase[i][j]); // Convert to lowercase
        }
    }

    if (find(criteria_lowercase.begin(), criteria_lowercase.end(), "punctuality") != criteria_lowercase.end())
    {
        return "Employee has shown consistent punctuality in attendance.";
    }
    else if (find(criteria_lowercase.begin(), criteria_lowercase.end(), "productivity") != criteria_lowercase.end() ||
             find(criteria_lowercase.begin(), criteria_lowercase.end(), "efficiency") != criteria_lowercase.end())
    {
        return "Employee has demonstrated high productivity and efficiency in tasks.";
    }
    else if (find(criteria_lowercase.begin(), criteria_lowercase.end(), "communication") != criteria_lowercase.end())
    {
        return "Employee effectively communicates with team members and stakeholders.";
    }
    else
    {
        return "Employee performance in this area needs further evaluation.";
    }
}

int main()
{
    cout << "Welcome to the Employee Performance Evaluation System!" << endl;
    cout << "I can help evaluate employee performance based on given criteria." << endl;

    vector<string> criteria;

    // Ask the evaluator about employee performance criteria
    while (true)
    {
        string criterion = ask_question("What performance criterion do you want to evaluate? (Enter 'done' when finished): ");
        if (criterion == "done")
        {
            break;
        }
        criteria.push_back(criterion);
    }

    // Evaluate employee performance based on criteria
    string evaluation = evaluate_performance(criteria);

    // Output evaluation
    cout << "\nPerformance Evaluation: " << evaluation << endl;

    return 0;
}
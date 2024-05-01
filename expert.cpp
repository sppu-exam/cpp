#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::find

using namespace std;

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

string recommend_facility(const vector<string> &symptoms)
{
    vector<string> symptoms_lowercase = symptoms;
    for (int i = 0; i < symptoms_lowercase.size(); ++i)
    {
        for (int j = 0; j < symptoms_lowercase[i].size(); ++j)
        {
            symptoms_lowercase[i][j] = tolower(symptoms_lowercase[i][j]); // Convert to lowercase
        }
    }

    if (find(symptoms_lowercase.begin(), symptoms_lowercase.end(), "chest pain") != symptoms_lowercase.end())
    {
        return "You should go to the nearest hospital's emergency department immediately.";
    }
    else if (find(symptoms_lowercase.begin(), symptoms_lowercase.end(), "fever") != symptoms_lowercase.end() ||
             find(symptoms_lowercase.begin(), symptoms_lowercase.end(), "cough") != symptoms_lowercase.end())
    {
        return "You can visit a nearby clinic or see your primary care physician.";
    }
    else
    {
        return "You might consider scheduling an appointment with a specialist.";
    }
}

int main()
{
    cout << "Welcome to the Hospital and Medical Facility Expert System!" << endl;
    cout << "I can help you find the appropriate medical facility based on your symptoms." << endl;

    vector<string> symptoms;

    // Ask the user about their symptoms
    while (true)
    {
        string symptom = ask_question("What symptom are you experiencing? (Enter 'done' when finished): ");
        if (symptom == "done")
        {
            break;
        }
        symptoms.push_back(symptom);
    }

    // Recommend a medical facility based on symptoms
    string recommendation = recommend_facility(symptoms);

    // Output recommendation
    cout << "\nRecommendation: " << recommendation << endl;

    return 0;
}

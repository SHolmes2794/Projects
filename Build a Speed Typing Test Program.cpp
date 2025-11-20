/*  Build a Speed Typing Test Program.cpp
    Samuel Holmes - Last Updated: 11/13/25 */


#include <iostream>
#include <ctime>
#include <string>
using namespace std;


// Function Declarations
int count_correct_characters(string sentence_to_type, string user_input_sentence, int sentence_length);
float calculate_accuracy_percent(int correct_characters, int total_characters);
void show_typing_results(string user_input_sentence, int correct_characters, int total_characters, float accuracy_percent, float typing_time_seconds);
void show_debug_info(const float* time_pointer, const float* accuracy_pointer);
void start_typing_test();


// Global Variables
string sentence_to_type = "The quick brown fox jumps over the lazy dog.";
int totalChar = 0;
string userSentence = "";
int user_numChar = 0;
float typing_time_seconds = 0;


// Main Function
int main()
{
    // Declare Variables
    char debugYes;
    char replay = 'y';
    
    // Speed Typing Test Loop
    do
    {
        // Run Test
        start_typing_test();

        // Calculate Results
        int correctNumChar = count_correct_characters(sentence_to_type, userSentence, totalChar);
        float accuracyPercent = calculate_accuracy_percent(correctNumChar, totalChar);

        // Show Results
        show_typing_results(userSentence, correctNumChar, totalChar, accuracyPercent, typing_time_seconds);

        // Debug Results
        cout << endl << "Show debug info? (y/n): ";
        cin >> debugYes;
        if (debugYes == 'y' || debugYes == 'Y')
        {
            show_debug_info(&typing_time_seconds, &accuracyPercent);
        }

        // Replay Opportunity
        cout << "Do you want to try again? (y/n): ";
        cin >> replay;
        cout << endl << endl;
        cin.ignore();

    } while (replay == 'y' || replay == 'Y');

    // Game Ended
    cout << "Goodbye! Keep practicing your typing speed!" << endl;
    return 0;
}


// Functions
void start_typing_test()
{
    cout << "============= SPEED TYPING TEST =============" << endl;
    cout << "Type the following exactly as shown:" << endl << "\"" << sentence_to_type << "\"" << endl;
    cout << "Press ENTER when ready..." << endl;

    // Records Time and Gets User Input
    string clear_input;

    time_t startTime = time(0);
    getline(cin, clear_input);
    getline(cin, userSentence);
    time_t endTime = time(0);
    typing_time_seconds = endTime - startTime;

    // Calculates Number of Characters in Given Sentence
    totalChar = 0;
    while (sentence_to_type[totalChar] != '\0')
    {
        totalChar++;
    }

    // Calculates Number of Characters in User Sentence
    user_numChar = 0;
    while (userSentence[user_numChar] != '\0')
    {
        user_numChar++;
    }
}

void show_typing_results(string user_input_sentence, int correct_characters, int total_characters, float accuracy_percent, float typing_time_seconds)
{
    // Shows Results
    cout << endl << "---------------------------------------------" << endl; 
    cout << "Your Typed Sentence:" << endl;
    cout << user_input_sentence << endl << endl;

    cout << "Total Characters (Given): " << total_characters << endl;
    cout << "Total Characters (Typed): " << user_numChar << endl;
    cout << "Correct Characters: " << correct_characters << "/" << total_characters << endl;
    cout << "Accuracy: " << accuracy_percent << "%" << endl;
    cout << "Time Taken: " << typing_time_seconds << " seconds" << endl;
    
    cout << "Typing Speed: " << total_characters / typing_time_seconds << " characters per second" << endl;

    // Feedback Based Solely On Accuracy
    cout << "Feedback: ";
    if (accuracy_percent == 100)
    {
        cout << "Perfect!" << endl;
    }
    else if (accuracy_percent >= 90)
    {
        cout << "Excellent precision!" << endl;
    }
    else if (accuracy_percent >= 75)
    {
        cout << "Good! Just needs more accuracy." << endl;
    }
    else
    {
        cout << "Keep practicing!" << endl;
    }

    cout << "---------------------------------------------" << endl;
}

int count_correct_characters(string sentence_to_type, string user_input_sentence, int sentence_length)
{
    int numCorrect = 0;

    // While loop runs if the user input still has characters OR it hasn't gone over the given sentence_to_type length
    int count = 0;
    while (user_input_sentence[count] != '\0' && count <= sentence_length)
    {
        if (user_input_sentence[count] == sentence_to_type[count])
        {
            numCorrect++;
        }
        count++;
    }

    return numCorrect;
}

float calculate_accuracy_percent(int correct_characters, int total_characters)
{
    if (total_characters == 0)
    {
        return 0;
    }
    else
    {
        return (correct_characters * 100.0) / total_characters;
    }
}

void show_debug_info(const float* time_pointer, const float* accuracy_pointer)
{
    cout << "[DEBUG INFO - Read Only]" << endl;
    cout << "typing_time_seconds @ " << time_pointer << " = " << *time_pointer << endl;
    cout << "accuracyPercent @ " << accuracy_pointer << " = " << *accuracy_pointer << endl << endl;
}
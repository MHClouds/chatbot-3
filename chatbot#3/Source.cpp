#include <iostream>
#include <string>
#include <vector>
#include<ctime>
#include<cstdlib>

//by using vector class we can store elements of a given type in a linear arrangment in a random squence
using namespace std;
//function prototype
void shuffle_answers(vector<string>& answers);
    
   
int main() {
    //the questions that are going to be asked go here

    vector < pair<string, vector<string>>>trivia_questions = {};
    



      //is used to mix the questions up using rand()
        srand(time(0));
    for (int i = 0; i < trivia_questions.size(); i++) {
        int j = rand() % trivia_questions.size();
        swap(trivia_questions[i], trivia_questions[j]);
    }
    //Loop through the questions and ask them
        int score = 0;

        for (int i = 0; i < trivia_questions.size(); i++) {
            string question = trivia_questions[i].first;
            vector<string> answers = trivia_questions[i].second;

            // mix the answers
            shuffle_answers(answers);

            // this will ask the question
            cout << "Question #" << (i + 1) << ": " << question << endl;

            // this will output the answers
            for (int j = 0; j < answers.size(); j++) {
                cout << j + 1 << ". " << answers[j] << endl;
            }

            // user input / answer
            int user_answer;
            cout << "Enter your answer (1-" << answers.size() << "): ";
            cin >> user_answer;
            cin.ignore();

            //check if answer is right/wrong
            if (user_answer == 1) {
                cout << "Correct! Good job!" << endl;
                score++;
            }
            else {
                cout << "Sorry, that's incorrect. The correct answer is: " << answers[0] << endl;
            }
        }
        

   

}
//function definition
void shuffle_answers(vector<string>& answers) {
    srand(time(0));

    for (int i = 0; i < answers.size(); i++) {
        int j = rand() % answers.size();
        swap(answers[i], answers[j]);
    }
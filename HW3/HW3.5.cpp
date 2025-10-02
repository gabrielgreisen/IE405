#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    const int questions = 20;
    char correct[questions];
    char student[questions];

    ifstream correctFile("CorrectAnswers.txt");
    ifstream studentFile("StudentAnswers.txt");

    for (int i = 0; i < questions; i++) {
        correctFile >> correct[i];
        studentFile >> student[i];
    }

    correctFile.close();
    studentFile.close();

    int correctCount = 0;
    for (int i = 0; i < questions; i++) {
        if (student[i] == correct[i]) {
            correctCount++;
        }
    }

    double percentage = ((double)correctCount/questions) * 100;

    cout << "# of correct questions: " << correctCount << endl;
    cout << "Percentage score: " << percentage << "%" << endl;

    if (percentage >= 75.0) {
        cout << "Passed the exam" << endl;
    } else {
        cout << "Failed the exam" << endl;
    }

    return 0;

}
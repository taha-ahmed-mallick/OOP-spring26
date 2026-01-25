#include <iostream>
using namespace std;

class ExamResult {
    int marks;
    char grade;
    void setGrade() {
        if (marks >= 90) {
            grade = 'A';
        } else if (marks >= 80) {
            grade = 'B';
        } else if (marks >= 70) {
            grade = 'C';
        } else if (marks >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }
    public:
        void setMarks(int m) {
            marks = m;
            setGrade();
        }
        void getGrade() {
            cout << "Your grade is: " << grade << endl;
        }
};

int main() {
    ExamResult OOPs;
    int score;
    cout << "Enter your OOPs exam marks: ";
    cin >> score;
    OOPs.setMarks(score);
    OOPs.getGrade();
    return 0;
}
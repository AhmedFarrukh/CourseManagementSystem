#include <iostream>
#include <string>
using namespace std;

class Course{
    private:
        string courseName;
        int numOfStudents;
        string[] studentList;
        string facultyName;
    public:
        Course(string facultyName, courseName, numOfStudents,string[] studentList){
            this->facultyName=facultyName;
            this->courseName=courseName;
            this->numOfStudents=numOfStudents;
            for(int i=0;i<numOfStudents;i++){
                this->studentList[i]=studentList[i];
            }
        }
};

int main() {
    string studentList[]={"Fred Weasley", "George Wesley", "Oliver Wood", "Luna Lovegood", "Ron Weasley",
    "Draco Malfoy", "Harry Potter", "Neville Longbottom", "Ginny Weasley", "Ernie MacMillan",
    "Percy Weasley", "Hermione Granger"};//takes the name of students
    int numOfStudents=sizeof(studentList)/sizeof(studentList[0]);//counts number of students
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include "course.h"
using namespace std;

int main() {

    string studentNames[]={"Fred Weasley", "George Wesley", "Oliver Wood", "Luna Lovegood", "Ron Weasley",
    "Draco Malfoy", "Harry Potter", "Neville Longbottom", "Ginny Weasley", "Ernie MacMillan",
    "Percy Weasley", "Hermione Granger"};//takes the name of students
    int numOfStudents=sizeof(studentNames)/sizeof(studentNames[0]);//counts number of students
    vector<Students> studentList;//holds the student objects
    for(int i=0;i<numOfStudents;i++){
        studentList.push_back(Students(studentNames[i]));
    }//creates student objects
    Course myCourse("Snape","Potions",numOfStudents,studentList);//creates course with these students
    myCourse.printClassList();
    return 0;
}
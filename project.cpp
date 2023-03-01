#include <iostream>
#include <string>
#include <vector>
#include "cms.h"
using namespace std;

int main() {
    Course A("Portions","Learn the art of brewing powerful potions!");
    Course B("Ancient Magic","Learn more about the lives of ancient witches and wizards!");
    Course C("Defence Against Dark Arts","Learn to protect yourself against evil!");
    Course D("Herbology","Learn about magical plants and their uses!");

    vector <Course> teach1;
    teach1.push_back(A);

    vector <Course> teach2;
    teach2.push_back(B);

    vector <Course> teach3;
    teach3.push_back(C);
    teach3.push_back(D);


    vector <Faculty> faculty;
    faculty.push_back(Faculty ("Horace Slughorn", teach1));
    faculty.push_back(Faculty ("Eleazar Fig", teach2));
    faculty.push_back(Faculty ("Severus Snape",teach3));

    vector <Course> courses;
    courses.push_back(A);
    courses.push_back(B);
    courses.push_back(C);
    courses.push_back(D);

    vector <Student> students;
    students.push_back(Student("Harry Potter", courses));
    students.push_back(Student("Ron Weasley", courses));
    students.push_back(Student("Hermione Granger", courses));
    students.push_back(Student("Neville Longbottom", courses));
    students.push_back(Student("Cedric Diggory", courses));
    students.push_back(Student("Luna Lovegood", courses));
    students.push_back(Student("Dean Thomas", courses));
    // courses[0].printCourseDetails();
    // courses[1].printCourseDetails();
    // courses[2].printCourseDetails();
    // courses[3].printCourseDetails();

    cout<<"Welcome to Hogwarts School of Witchcraft and Wizardry!"<<endl;
    return 0;
}
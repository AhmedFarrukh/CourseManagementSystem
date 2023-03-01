#include <iostream>
#include <string>
#include <vector>
#include "cms.h"
using namespace std;
inline void print(int i, string s){cout<<i<<"  "<<s<<endl;}
int main() {
    //Creating Courses
    Course A("Portions","Learn the art of brewing powerful potions!");
    Course B("Ancient Magic","Learn more about the lives of ancient witches and wizards!");
    Course C("Defence Against Dark Arts","Learn to protect yourself against evil!");
    Course D("Herbology","Learn about magical plants and their uses!");
    //Creating vectors of courses for each faculty object
    vector <Course*> teach1;
    teach1.push_back(&A);

    vector <Course*> teach2;
    teach2.push_back(&B);

    vector <Course*> teach3;
    teach3.push_back(&C);
    teach3.push_back(&D);

    //creating faculty objects
    vector <Faculty> faculty;
    faculty.push_back(Faculty ("Horace Slughorn", teach1));
    faculty.push_back(Faculty ("Eleazar Fig", teach2));
    faculty.push_back(Faculty ("Severus Snape",teach3));
    //creating a vector of all courses offered
    vector <Course*> courses;
    courses.push_back(&A);
    courses.push_back(&B);
    courses.push_back(&C);
    courses.push_back(&D);
    //creating students and assigning them classes
    vector <Student> students;
    students.push_back(Student("Harry Potter", courses));
    students.push_back(Student("Ron Weasley", courses));
    students.push_back(Student("Hermione Granger", courses));
    students.push_back(Student("Neville Longbottom", courses));
    students.push_back(Student("Cedric Diggory", courses));
    students.push_back(Student("Luna Lovegood", courses));
    students.push_back(Student("Dean Thomas", courses));

    char view_selection='S';
    cout<<"Welcome to Hogwarts School of Witchcraft and Wizardry!"<<endl;
    do{
        cout<<"You may view the Course Management System as a Student or as a Faculty Member"<<endl;
        cout<<"Press 'S' for Student View"<<endl;
        cout<<"Press 'F' for Faculty View"<<endl;
        cout<<"Press 'E' to exit the system"<<endl;
        cin>>view_selection;
        if(view_selection=='s'||view_selection=='S'){
            //Student View
            //Print List of Students.
            int student_select;
            cout<<"Please enter the index for your name!"<<endl;
            for(int i=0;i<students.size();i++){
                print(i,students[i].getName());
            }
            cin>>student_select;
            //print courses for the student selected
            int course_select;
            do{
            cout<<"Please enter the index for the course whose details are to be accessed"<<endl;
            students[student_select].printCourses();
            print(-1,"Exit Student View");
            cin>>course_select;
            if(course_select==-1){break;}
            //print the different functions available for students
            int option_select;
            cout<<"Please note the options below and enter the appropriate number to proceed"<<endl;
            print(0,"View Course Description");
            print(1,"View Course Details");
            print(2,"View the Syllabus");
            print(3,"View Course Material");
            print(4,"View Grade");
            cin>>option_select;
            if(option_select==0){
                students[student_select].getCourse(course_select).printCourseDescription();
            }
            else if(option_select==1){
                students[student_select].getCourse(course_select).printCourseDetails();
            }
            else if(option_select==2){
                students[student_select].getCourse(course_select).printSyllabus();
            }
            else if(option_select==3){
                students[student_select].getCourse(course_select).printCourseMaterials();
            }
            else if(option_select==4){
                cout<<students[student_select].getGrade(course_select)<<endl;
            }
            else {cout<<"Incorrect option was selected"<<endl;}
            }while(course_select!=-1);
        }
        else if(view_selection=='f'||view_selection=='F'){
            int faculty_select;
            cout<<"Please select the index for your name"<<endl;
            for(int i=0;i<faculty.size();i++){
                print(i,faculty[i].getName());
            }
            cin>>faculty_select;
            int course_select;
            do{
                cout<<"Please select the index for the course whose information is to be viewed/edited"<<endl;
                faculty[faculty_select].printCourses();
                print(-1,"Exit Faculty View");
                cin>>course_select;
                if (course_select==-1){break;}
                int option_select;
                cout<<"Please select the appropriate option to proceed"<<endl;
                print(0,"View Course Description");
                print(1,"View Course Details");
                print(2,"View the Syllabus");
                print(3,"View the Course Materials");
                print(4,"View Class Grades");
                print(5,"Edit Course Description");
                print(6,"Upload Syllabus");
                print(7,"Upload Course Materials");
                print(8,"Set Class Grades");
                cin>>option_select;
                if(option_select==0){
                    faculty[faculty_select].getCourse(course_select).printCourseDescription();
                }
                else if(option_select==1){
                    faculty[faculty_select].getCourse(course_select).printCourseDetails();
                }
                else if(option_select==2){
                    faculty[faculty_select].getCourse(course_select).printSyllabus();
                }
                else if(option_select==3){
                    faculty[faculty_select].getCourse(course_select).printCourseMaterials();
                }
                else if(option_select==4){
                    faculty[faculty_select].getCourse(course_select).printClassGrades();
                }
                else if(option_select==5){
                    faculty[faculty_select].setCourseDescription(course_select);
                }
                else if(option_select==6){
                    faculty[faculty_select].setSyllabus(course_select);
                }
                else if(option_select==7){
                    faculty[faculty_select].setCourseMaterialFile(course_select);
                }
                else if(option_select==8){}
                else {}
            }while(course_select!=-1);
        }
        else if(view_selection!='e'||view_selection!='E'){break;}
        else{cout<<"You have selected an incorrect option"<<endl;}

    }while(view_selection!='e'||view_selection!='E');

    return 0;
}
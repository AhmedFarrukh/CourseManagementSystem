#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Course;
class Member{
    protected:
    string name;
    vector <Course> courses;
};

class Student:private Member{
    private:
        vector <double> grades;//holds grade for each course
    public:
        Student(string name, vector<Course>& courses){//initializes grade vector, and other variables
            this->name=name;
            this->courses=courses;
            for(int i=0;i<courses.size();i++){//creates grades vector and adds student to course object
                grades.push_back(0);
                courses[i].addStudent(this);
            }
        }
        double getGrade(int i){return grades[i];}//returns grade for course with index i
        void printCourses(){
            cout<<"You are enrolled in the following courses, please select the correct number to see more details: "<<endl;
            for(int i=0;i<courses.size();i++){
                cout<<courses[i].getCourseName()<<endl;
            }
        }
        string getName(){return name;}
        //void setGrade(double grade){this->grade=grade;}
};
class Faculty: private Member{
    public:
        Faculty(string name, vector<Course>& courses){
            this->name=name;
            this->courses=courses;
        }
        string getName(){return name;}
};
class Course{
    friend class Faculty;
    private:
        string courseName;
        static int numOfCourses;
        Faculty instructor;
        vector<Student> students;
        string courseDescription;
        int courseNumber;
    public:
        Course(string courseName, string courseDescription){
            this->courseName=courseName;
            this->courseDescription=courseDescription;
            numOfCourses++;
            courseNumber=numOfCourses;
            ofstream outFile1;
            outFile1.open("syllabus"+(char)courseNumber,ios::out);
            if(outFile1.fail()){
                cout<<"There was an error opening the syllabus file"<<endl;
                exit(-1);
            }
            outFile1<<"The syllabus for this class is yet to be updated"<<endl;
            outFile1.close;

            ofstream outFile2;
            outFile2.open("CourseMaterial"+(char)courseNumber,ios::out);
            if(outFile2.fail()){
                cout<<"There was an error opening the course materials file"<<endl;
                exit(-1);
            }
            outFile2<<"The course materials for this class are yet to be updated"<<endl;
            outFile2.close;
        }
        void addStudent(Student newstudent){
            students.push_back(newstudent);
        }
        void addFaculty(Faculty newinstructor){
            this->instructor=newinstructor;
        }
        void printSyllabus(){

        }
        void printCourseMaterials(){

        }
        void printClassList(){
            cout<<"Following is the class list for "<<courseName<<endl;
            for (int i=0;i<students.size();i++){
                cout<<students[i].getName()<<endl;
            }
        }
        void printCourseDetails(){
            cout<<"Name: "<<courseName<<endl;
            cout<<"Description: "<<courseDescription<<endl;
            cout<<"Faculty: "<<instructor.getName()<<endl;
        }
        void printCourseDescription(){
            cout<<courseDescription<<endl;
        }
        void printClassGrades(){
            double sum=0;
            cout<<"The grades are as follows: "<<endl;
            for(int i=0;i<students.size();i++){
                cout<<students[i].getGrade(courseNumber)<<", "<<endl;
                sum+=students[i].getGrade(courseNumber);
            }
            cout<<"The average grade is "<<sum/(double)students.size()<<endl;
        }
};
int Course:: numOfCourses=0;

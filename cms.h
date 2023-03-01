#include <string>// add member class to demonstrate inheritance
#include <vector>
#include <fstream>
using namespace std;
class Course;
class Student{
    private:
        string name;
        vector <Course*> courses;
        vector <double> grades;//holds grade for each course
    public:
        Student(string name, vector<Course*>& courses);
        double getGrade(int i){return grades[i];}//returns grade for course with index i
        void setGrade(Course& course_graded, double g);
        void printCourses();
        string getName(){return name;}
        Course& getCourse(int i);
};
class Faculty{
    private:
        string name;
        vector <Course*> courses;
    public:
        Faculty(){}
        Faculty(string name, vector<Course*>& courses);
        string getName(){return name;}
        void setSyllabus(int i);
        void setCourseMaterialFile(int i);
        void setCourseDescription(int i);
        void setGrades(int i);
        void printCourses();
        Course& getCourse(int i);
        
};
class Course{
    friend class Faculty;
    private:
        string courseName;
        static int numOfCourses;
        Faculty instructor;
        vector<Student*> students;
        string courseDescription;
        int courseNumber;
        string syllabusFile;
        string courseMaterialFile;
    public:
        Course(string courseName, string courseDescription){
            this->courseName=courseName;
            this->courseDescription=courseDescription;
            syllabusFile="syllabus"+courseName+(char)courseNumber;
            courseMaterialFile="coursematerial"+courseName+(char)courseNumber;
            numOfCourses++;
            courseNumber=numOfCourses;
            // ofstream outFile1;
            // outFile1.open(syllabusFile,ios::out);
            // if(outFile1.fail()){
            //     cout<<"There was an error opening the syllabus file"<<endl;
            //     exit(-1);
            // }
            // outFile1<<"The syllabus for this class is yet to be updated"<<endl;
            // outFile1.close();

            // ofstream outFile2;
            // outFile2.open(courseMaterialFile,ios::out);
            // if(outFile2.fail()){
            //     cout<<"There was an error opening the course materials file"<<endl;
            //     exit(-1);
            // }
            // outFile2<<"The course materials for this class are yet to be updated"<<endl;
            // outFile2.close();
        }
        void addStudents(vector<Student*> students){
            this->students=students;
        }
        void addFaculty(Faculty newinstructor){
            instructor=newinstructor;
        }
        void printSyllabus(){//add exception for f
            try{
            ifstream inFile;
            inFile.open(syllabusFile,ios::in);
            if(inFile.fail()){
                throw(syllabusFile);
            }
            char character;
            while(!inFile.eof()){
                character=inFile.get();
                if(character==inFile.eof()){break;}
                cout<<character;
            }
            cout<<endl;
            inFile.close();
            }catch(string syllabusFile){cout<<"There was an error opening the syllabus file.\n Note that the syllabus is only available once the instructor has uploaded it."<<endl;}
        }
        void printCourseMaterials(){
            try{
            ifstream inFile;
            inFile.open(courseMaterialFile,ios::in);
            if(inFile.fail()){
                throw(courseMaterialFile);
            }
            while(!inFile.eof()){
                cout<<inFile.get();
            }
            inFile.close();
            }catch(string courseMaterialFile){cout<<"The course materials file is yet to be updated by the instructor.\nNote that the file is only available once the instructor has uploaded it."<<endl;}
        }
        void printClassList(){
            cout<<"Following is the class list for "<<courseName<<endl;
            for (int i=0;i<students.size();i++){
                cout<<students[i]->getName()<<endl;
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
                cout<<setw(40)<<left<<students[i]->getName()<<setw(5)<<left<<students[i]->getGrade(courseNumber)<<endl;//make pretty
                sum+=students[i]->getGrade(courseNumber);
            }
            cout<<"The average grade is "<<sum/(double)students.size()<<endl;
        }
        string getCourseName(){return courseName;}
};
int Course:: numOfCourses=0;
Student::Student(string name, vector<Course*>& courses){//initializes grade vector, and other variables
            this->name=name;
            this->courses=courses;
            for(int i=0;i<courses.size();i++){//creates grades vector and adds student to course object
                grades.push_back(0);
                //courses[i]->addStudent(*this);
            }
        }
void Student::printCourses(){
            for(int i=0;i<courses.size();i++){
                cout<<i<<"  "<<courses[i]->getCourseName()<<endl;
            }
        }
void Student::setGrade(Course& course_graded, double g){
    int i;
    for(i=0;i<courses.size();i++){
        if(courses[i]->getCourseName()==course_graded.getCourseName()){
            break;
        }
    }
    grades[i]=g;

}
Course& Student::getCourse(int i){return *courses[i];}
void Faculty:: setSyllabus(int i){
            cout<<"Please enter the name for the syllabus file"<<endl;
            string file_name;
            cin>>file_name;
            courses[i]->syllabusFile=file_name;
        }
void Faculty:: setCourseMaterialFile(int i){
            cout<<"Please enter the name for the course materials file"<<endl;
            string file_name;
            cin>>file_name;
            courses[i]->courseMaterialFile=file_name;
        }
void Faculty:: setCourseDescription(int i){
    cout<<"Please enter the new course description"<<endl;
    string newdescription="";
    cin.ignore();
    getline(cin,newdescription);
    courses[i]->courseDescription=newdescription;
}
void Faculty:: setGrades(int i){
    double g;
    cout<<"Please enter the grade for each student"<<endl;
    for(int j=0;j<courses[i]->students.size();j++){
        cout<<setw(20)<<left<<courses[i]->students[j]->getName();
        cin>>g;
        courses[i]->students[j]->setGrade(*courses[i],g);
    }
}
void Faculty::printCourses(){
    for(int i=0;i<courses.size();i++){
        cout<<i<<"  "<<courses[i]->courseName<<endl;
    }
}
Course& Faculty::getCourse(int i){return *courses[i];}
Faculty:: Faculty(string name, vector<Course*>& courses){
            this->name=name;
            this->courses=courses;
            for(int i=0;i<courses.size();i++){
                courses[i]->addFaculty(*this);
            }
        }
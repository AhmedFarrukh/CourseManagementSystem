#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Course; //foward declaration since objects of this lass are referenced in other objects
class Member{ //member class is the parent class for student and faculty class
    protected:
        string name;
        vector<Course*> courses; //vector containing pointer to courses
};
class Student: private Member{//derived class
    private:
        vector <double> grades;//holds grade for each course
    public://function definitions are after all class declarations since classes interact with each other's objects
        Student(string name, vector<Course*>& courses);//constructor
        double getGrade(int i){return grades[i];}//returns grade for course with index i
        int getNumOfCoursesEnrolled(){return courses.size();}//returns the number of courses enrolled
        void setGrade(Course& course_graded, double g);//sets grades for the course inputted
        void printCourses();//prints courses taken
        string getName(){return name;}//returns the name of the student
        Course& getCourse(int i);//return course with specified index
};
class Faculty:private Member{//derived class
    public:
        Faculty(){}
        Faculty(string name, vector<Course*>& courses);//constructor
        string getName(){return name;}//returns object name
        void setSyllabus(int i);//updates the name of syllabus file in course object
        void setCourseMaterialFile(int i);//updates the name of course materials file in course object
        void setCourseDescription(int i);//updates course description string in course object
        void setGrades(int i);//sets grades for all students in class
        void printCourses();//prints the course taught by the faculty member
        Course& getCourse(int i);//returns the course with specified index
        
};
class Course{
    friend class Faculty;//private variables also accessible to faculty class
    private:
        string courseName;
        static int numOfCourses;//static variable keeps track of the number of courses created
        Faculty instructor;//stores the faculty object
        vector<Student*> students;//stores a vector of pointers to student objects
        string courseDescription;
        int courseNumber;
        string syllabusFile;
        string courseMaterialFile;
    public:
        Course(string courseName, string courseDescription){//constructor
            this->courseName=courseName;
            this->courseDescription=courseDescription;
            syllabusFile="syllabus"+courseName+(char)courseNumber;
            courseMaterialFile="coursematerial"+courseName+(char)courseNumber;
            ++numOfCourses;
            courseNumber=numOfCourses;//courseNumber depends on static variable so that there is no overlap
        }
        void addStudents(vector<Student*> students){//adds student pointer to the student vector
            this->students=students;
        }
        void addFaculty(Faculty newinstructor){//adds faculty pointer to the faculty vector
            instructor=newinstructor;
        }
        void printSyllabus(){//prints the contents of the syllabus file. if wrong name is input, or no name input yet, throws an exception
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
        void printCourseMaterials(){//prints the contents of the course materials file. if wrong name is input, or no name input yet, throws an exception
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
        void printClassList(){//prints the entire class list
            cout<<"Following is the class list for "<<courseName<<endl;
            for (int i=0;i<students.size();i++){
                cout<<students[i]->getName()<<endl;
            }
        }
        void printCourseDetails(){//prints the name of course, name of the instructor, and course description
            cout<<"Name: "<<courseName<<endl;
            cout<<"Description: "<<courseDescription<<endl;
            cout<<"Faculty: "<<instructor.getName()<<endl;
        }
        void printCourseDescription(){//prints course description
            cout<<courseDescription<<endl;
        }
        void printClassGrades(){
            double sum=0;
            int j;
            cout<<"The grades are as follows: "<<endl;
            for(int i=0;i<students.size();i++){//prints the grade for each student
                    for(j=0;j<students[i]->getNumOfCoursesEnrolled();j++){//find the relevant index of course in the courses vector held by the student
                        if(students[i]->getCourse(j).getCourseName()==courseName){
                        break;
                        }
                    }
                cout<<setw(40)<<left<<students[i]->getName()<<setw(5)<<left<<students[i]->getGrade(j)<<endl;//make pretty
                sum+=students[i]->getGrade(courseNumber-1);
            }
            cout<<setw(40)<<left<<"The average grade is "<<sum/(double)students.size()<<endl;
        }
        string getCourseName(){return courseName;}
};
int Course:: numOfCourses=0;
Student::Student(string name, vector<Course*>& courses){//initializes grade vector, and other variables
            this->name=name;
            this->courses=courses;
            for(int i=0;i<courses.size();i++){//creates grades vector and adds student to course object
                grades.push_back(0);
            }
        }
void Student::printCourses(){//prints all the courses taken by the student
            for(int i=0;i<courses.size();i++){
                cout<<i<<"  "<<courses[i]->getCourseName()<<endl;
            }
        }
void Student::setGrade(Course& course_graded, double g){//finds the index of the course in students list and updates grade.
    int i;
    for(i=0;i<courses.size();i++){
        if(courses[i]->getCourseName()==course_graded.getCourseName()){
            break;
        }
    }
    grades[i]=g;
}
Course& Student::getCourse(int i){return *courses[i];}//returns the course with specified index.
void Faculty:: setSyllabus(int i){//sets new name for syllabus file in the given course
            cout<<"Please enter the name for the syllabus file"<<endl;
            string file_name;
            cin>>file_name;
            courses[i]->syllabusFile=file_name;
        }
void Faculty:: setCourseMaterialFile(int i){//sets new name for the course materials file in specified course.
            cout<<"Please enter the name for the course materials file"<<endl;
            string file_name;
            cin>>file_name;
            courses[i]->courseMaterialFile=file_name;
        }
void Faculty:: setCourseDescription(int i){//sets new course description for specified course
    cout<<"Please enter the new course description"<<endl;
    string newdescription="";
    cin.ignore();
    getline(cin,newdescription);//getline used as only new line is to be used as delimiter
    courses[i]->courseDescription=newdescription;
}
void Faculty:: setGrades(int i){//allows setting of grades for every student in the class.
    double g;
    cout<<"Please enter the grade for each student"<<endl;
    for(int j=0;j<courses[i]->students.size();j++){
        cout<<setw(20)<<left<<courses[i]->students[j]->getName();
        cin>>g;
        courses[i]->students[j]->setGrade(*courses[i],g);
    }
}
void Faculty::printCourses(){//print all the courses taught by the faculty object
    for(int i=0;i<courses.size();i++){
        cout<<i<<"  "<<courses[i]->courseName<<endl;
    }
}
Course& Faculty::getCourse(int i){return *courses[i];}//return course taught by faculty object with specified index
Faculty:: Faculty(string name, vector<Course*>& courses){//constructor for faculty object
            this->name=name;
            this->courses=courses;
            for(int i=0;i<courses.size();i++){
                courses[i]->addFaculty(*this);
            }
        }
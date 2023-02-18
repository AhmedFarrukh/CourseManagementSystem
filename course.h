#include <string>
#include <vector>
using namespace std;
class Students{
    private:
        string studentName;
        vector <string> studentCourses;
        int numOfCourses=0;
    public:
        Students(string studentName){
            this->studentName=studentName;
        }
        void addCourse(string newCourse){
            studentCourses.push_back(newCourse);
            numOfCourses++;
        }
        string getName(){
            return studentName;
        }
};
class Course{
    private:
        string courseName;
        int numOfStudents;
        vector <Students> studentList;
        string facultyName;
    public:
        Course(string facultyName,string courseName,int numOfStudents,vector<Students> studentList){
            this->facultyName=facultyName;
            this->courseName=courseName;
            this->numOfStudents=numOfStudents;
            for(int i=0;i<numOfStudents;i++){
                this->studentList.push_back(studentList[i]);
                this->studentList[i].addCourse(this->courseName);
            }
        }
        void printClassList(){
            for(int i=0;i<numOfStudents;i++){
            cout<<studentList[i].getName()<<endl;
            }
        }
};
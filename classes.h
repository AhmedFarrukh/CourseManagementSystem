class Course{
    private:
        string courseName;
        int numOfStudents;
        vector <Students> studentList;
        string facultyName;
    public:
        Course(string facultyName, courseName, numOfStudents,vector<Students> studentList){
            this->facultyName=facultyName;
            this->courseName=courseName;
            this->numOfStudents=numOfStudents;
            for(int i=0;i<numOfStudents;i++){
                this->studentList.push_back(studentList[i]);
                this->studentList[i].addCourse(*this);
            }
        }
};
class Students{
    private:
        string studentName;
        vector <Course> studentCourses;
        int numOfCourses=0;
    public:
        Students(string studentName){
            this->studentName=studentName;
        }
        addCourse(Course newCourse){
            studentCourses.push_back(newCourse);
            numOfCourses++;
        }
};

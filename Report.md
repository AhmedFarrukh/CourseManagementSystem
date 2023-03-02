# Report
## Ahmed Farrukh
### Course Management System
#### Introduction

The aim of my code is to create a simple version for a course management system. 

A course management system is a software tool used to host course information such as syllabi and provide a medium of interaction between teachers and learners<sup>[1]</sup>. In addition, an effective cours management system is supposed to host all the neccessary details of a course, allowing a single platform to be acccessed for all resources regarding a course<sup>[2]</sup>. While a course management system may provide remote learners the only platform for instruction, even in-person teaching enviornmnets greatly benefit from the presence of an online course management system<sup>[3]</sup>.

The program should store data about courses, allow students to view information about the courses they are enrolled in and allow faculty to view and edit information about the courses that they are teaching. In addition, the program should also mantain data about which courses are offered, who is teaching them and who is enrolled in these courses. A course management system, the likes of which are used in universities, mantains large sets of data that needs to be stored orderly<sup>[4]</sup>. This challenge needs to be tackled using effective ways of storing and sharing information. 

#### Approach
In terms of the functionality of the system, I implemented the following functions.
Students should be able to see a list of the courses they are enrolled in and for each course, be able to:
- View Course Descripton
- View Course Details (Course Name, Faculty Name, Course Description)
- View the syllabus
- View Course Materials
- View Grade

Faculty should be able to see a list of course they are teaching and for each course, be able to:
- View Course Description
- View Course Details
- View Course Materials
- View Class' Grades
- Edit the Course Description
- Upload the Syllabus
- Upload Course Materials
- Set Class Grades
- Print Class List

To achieve this, I created three classes: Course, Student and Faculty. 

Course stores the following information:
- Course Name
- Course Number
- Faculty Object
- A Vector of Pointers to Student Objects
- Course Description
- Name of the Syllabus File
- Name of the Course Materials file

Faculty stores the following information:
- Name of the Instructor
- A Vector of Pointers to Courses taught by the Faculty member

Student stores the following information:
- Name of the Student
- A Vector of Pointers to the Courses the Student is Enrolled in
- A Vector of Grades

The objects are, therefore, all interconnected to each other. By creating these three classes, the program is able to store data about all three entities (students, teacher and courses) and how they all relate to each other. 

#### Solution
A class called Member was created that represents a member of the university. Each object of the Member class holds a name variable a vector of points to the course it is associated to. Both Student and Faculty class are inherited members of the 
The following class diagrams show the different classes that were implemented, their data members and member functions.
![Class Diagram](images/ClassDiagram.drawio.png)

As can been seen in the class diagram, each class maintains access to objects of another class. Course objects have a Faculty data member and a vector of pointers to students enrolled in the course. Both Faculty and Student classes hold vectors to courses they are associated with. The interdependence of classes creates problems during declarations. To solve this challengle, Student and Faculty class were declared in the header file first, but their functions were not defined, only declared. Next, Course class was declared. Finally, the functions of Faculty and Student classes were also declared. By following this pattern, each class is declared before its objects are manipulated by the function of another class, and the code runs without error.

Following is the flow in my main function:

Here is how you highlight a code snippet:

```c++
#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!";
  return 0;
}
```

Here is how you insert a screenshot of your code (or any other image):

![img caption text](images/console.png)
#### References
<sup>[1]</sup> https://cft.vanderbilt.edu/guides-sub-pages/course-management-systems/#:~:text=A%20course%20management%20system%20

<sup>[2]</sup> https://elearningindustry.com/cms-vs-lms-key-differences-course-management-systems-learning-management-systems

<sup>[2]</sup> http://web2integration.pbworks.com/f/COURSE+MANAGEMENT+SYSTEMS.pdf

<sup>[4]</sup> https://www.programmingwithbasics.com/2023/01/student-management-system-project-in-cpp.html

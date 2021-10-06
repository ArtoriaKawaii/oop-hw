//學號:B073040022
//姓名:張浩綸
//#include<bits/stdc++.h>//include all standard libaray
#include<iostream>
#include<string>
using std::string;
using std::istream;
using std::ostream;
using std::endl;
using std::cin;
using std::cout;
/*class UniversityStaff*/
class UniversityStaff{
    private:
        string name;
    public:
        UniversityStaff(){}
        UniversityStaff(string theName){name = theName;}
        UniversityStaff(const UniversityStaff& theObject){name = theObject.name;}
        UniversityStaff& operator=(const UniversityStaff& rtSide);
        friend istream& operator>>(istream& inStream, UniversityStaff& staffObject);
        friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject);
};
UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide){
    name = rtSide.name;
    return *this;
}
//Didn't use
istream& operator>>(istream& is, UniversityStaff& staffObject){
    is >> staffObject.name;
    return is;
}
ostream& operator<<(ostream& os, const UniversityStaff& staffObject){
    os << staffObject.name;
    return os;
}
/*class Student*/
class Student{
    protected:
        UniversityStaff name;
        string universityName;
        int registrationNumber;
        UniversityStaff proctor;
    public:
        Student(){}
        Student(UniversityStaff name, string universityName, int registrationNumber, UniversityStaff proctor);
        Student(const Student& student);
        Student& operator=(const Student& student);
        friend ostream& operator<<(ostream& os, const Student& student);
};
Student::Student(UniversityStaff name, string universityName, int registrationNumber, UniversityStaff proctor){
    this->name = name;
    this->universityName = universityName;
    this->registrationNumber = registrationNumber;
    this->proctor = proctor;
}
Student::Student(const Student& student){
    name = student.name;
    universityName = student.universityName;
    registrationNumber = student.registrationNumber;
    proctor = student.proctor;
}
Student& Student::operator=(const Student& student){
    name = student.name;
    universityName = student.universityName;
    registrationNumber = student.registrationNumber;
    proctor = student.proctor;
    return *this;
}
ostream& operator<<(ostream& os, const Student& student){
    os << "Name: " << student.name << endl;
    os << "University: " << student.universityName << endl;
    os << "registration number: " << student.registrationNumber << endl;
    os << "proctor: " << student.proctor << endl;
    return os;
}
/*class ScienceStudent*/
class ScienceStudent : public Student{
    private:
        string course;
        string graduate;//Undergraduate or Postgraduate
    public:
        ScienceStudent();
        ScienceStudent(UniversityStaff name, string universityName, int registrationNumber, UniversityStaff proctor, string course, string graduate);
        ScienceStudent(const ScienceStudent& scienceStudent);
        ScienceStudent& operator=(const ScienceStudent& scienceStudent);
        friend ostream& operator<<(ostream& os, const ScienceStudent& scienceStudent);
};
ScienceStudent::ScienceStudent() : Student(){}
ScienceStudent::ScienceStudent(UniversityStaff name, string universityName, int registrationNumber, UniversityStaff proctor, string course, string graduate) : Student(name, universityName, registrationNumber, proctor){
    this->course = course;
    this->graduate = graduate;
}
ScienceStudent::ScienceStudent(const ScienceStudent& scienceStudent) : Student(scienceStudent){
    course = scienceStudent.course;
    graduate = scienceStudent.graduate;
}
ScienceStudent& ScienceStudent::operator=(const ScienceStudent& scienceStudent){
    Student::operator=(scienceStudent);
    course = scienceStudent.course;
    graduate = scienceStudent.graduate;
    return *this;
}
ostream& operator<<(ostream& os, const ScienceStudent& scienceStudent){
    os << (Student)scienceStudent;
    os << "science discipline: " << scienceStudent.course << endl;
    os << "undergraduate or postgraduate course: " << scienceStudent.graduate << endl;
    return os;
}

int main(){
    int loop;
    cin >> loop;
    cin.ignore(10, '\n');
    for(int i = 0; i < loop; i++){
        string name;
        getline(cin, name);
        string universityName;
        getline(cin, universityName);
        int registrationNumber;
        cin >> registrationNumber;
        cin.ignore(10, '\n');
        string proctor;
        getline(cin, proctor);
        string course;
        getline(cin, course);
        string graduate;
        getline(cin, graduate);
        ScienceStudent student(name, universityName, registrationNumber, proctor, course, graduate);
        cout << student;
        cin.ignore(10, '\n');
        if(i != loop-1)
            cout << endl;
    }
    return 0;
}
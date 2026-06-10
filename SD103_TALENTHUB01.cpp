// : This file contains the 'main' function. Program execution begins and ends there.
//USE CAMELCASE !!!!!

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <cctype> //std::isalpha
#include <random>
#include <iomanip> // std::setw and std::setfill
#include <conio.h> 
#include <algorithm>

using namespace std;


class User {

private:

    string firstName;
    string lastName;
    int idNumber;
    string address;
    string email;
    int phoneNumber;
    int courseCount;
    // Add credentials to User or Student. Putting them here makes sense if all Users sign in.
    string username;
    string password;
    string course1;
    string course2;
    string course3;

public:

    User(string firstName, string lastName, int idNumber, string address, string email,int phoneNumber, int courseCount, string username, string password, string course1, string course2, string course3) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->idNumber = idNumber;
        this->address = address;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->courseCount = courseCount;
        this->username = username;
        this->password = password;
        this->course1 = course1;
        this->course2 = course2;
        this->course3 = course3;

        }
        bool authenticate(const string & uname, const string & pass) {
            return (username == uname && password == pass);
        }

        void getInfo() {

            cout << "\n | First name: " << firstName;
            cout << "\n | Last name: " << lastName;
            cout << "\n | ID Number: " << idNumber << endl;
            cout << "\n | Courses registered: " << courseCount << endl;
        }

        int getidNumber() const{
            return idNumber;
        }

        string getName() const {
            return firstName + " " + lastName;
        }
        string getfirstName() const {
            return firstName;
        }

        int getCourseCount() {
            return courseCount;
        }

};


class Student : public User {

private:
    std::string name;

    //vector here for courses enrolled
    vector<string> coursesEnrolled;

public:

    Student(string firstName, string lastName, int idNumber, string address, string email, int phoneNumber ,int courseCount, string username, string password, string course1, string course2, string course3)
        : User(firstName, lastName, idNumber, address, email,phoneNumber, courseCount, username, password, course1, course2, course3) {
    }

    static Student createStudent(string firstName, string lastName, int idNumber, string address, string email, int phoneNumber, int courseCount, string username, string password, string course1, string course2, string course3) {
        // Here, email acts as the username, and we can pass a default or temporary password like "password123"
        Student s(firstName, lastName, idNumber, address, email, phoneNumber, courseCount, username, password, course1, course2,course3);
        s.enrollCourse(course1);
        s.enrollCourse(course2);
        s.enrollCourse(course3);
        return s;
    }

    void getInfo() {
        User::getInfo();
    }

    void enrollCourse(string courseName) {
        coursesEnrolled.push_back(courseName);
    }

    void getCourseNames() {
        cout << "Courses enrolled: " << endl;
        for (int i = 0; i < coursesEnrolled.size(); i++) {
            cout << "\n | " << coursesEnrolled[i] << endl;
        }
    }

    int getidNumber() const{
        return User::getidNumber();
    }
   
    vector<string> getCoursesEnrolledList() const {
        return coursesEnrolled;
    }

};

class Course {
private:
    std::string courseName;

public:

    Course(string courseName) {
        this->courseName = courseName;
    }

    string getName() {
        return courseName;
    }

};

void tempKey() {
    char tempKey;
    tempKey = _getch();
}


int main()
{
   

    //run 1 = admin
    int run = 1;
    int program = 1;
    int signin = 1;
    int signInOption = 1;
    int option, studentOption;

   

    cout << "Hello World!\n";

    vector<Student> dmtcStudents;

    vector<Student> intlStudents;

    //Vector for available course
    vector<Course> availableCourses;

    //Vector for course student list - TBC
    vector<Student> courseStudentList;

    //MAP for username and password registered
    map<string, string> userDatas;

    //MAP for admin username and password
    map<string, string> adminDatas;

    //-------Sample contents---------------------
    // not sure if I can use this code below 
    //Student s2 = Student::createStudent("Britney", "Spranks", 123456, "1234 Street",  "bSpranks@gmail",123456, 0, "bSpranks","password123", "course1: Empty", "course1: Empty", "course1: Empty");
    //NOTE: do not intialize idNumber starting with 0!
    Student student1("Spongebob", "Squarepants", 81008100, "01 Pineapple Bay", "spongebob@gmail.com", 0225145, 0, "sBobSquarepants", "password123", "Fishery","Planktology","Burgerpreneur");
    Student student2("Avril", "Squarepants", 81008101, "01 Pineapple Bay", "spongebob@gmail.com", 0225145, 0, "aLavigne", "password123", "Fishery","Planktology","Burgerpreneur");
    Student student3("Rom", "Jerusalem", 81008101, "7 Howard Hunter Ave", "rjerusalem2026@gmail.com", 0225145, 0, "romulus", "jerusalem", "Fishery","Planktology","Burgerpreneur");
    

    Student student4("international", "student", 321, "Bluegrey Avenue", "Email@email.com", 1234567, 0, "username", "password", "Math", "Algebra", "Calculus");
    Student student5("James", "Wong", 7654, "Stonefields Avenue", "Email@email.com", 1234567, 0, "jWong", "password123", "Mechanical Engineering", "Algebra", "Calculus");

    

    dmtcStudents.push_back(student2);
    dmtcStudents.push_back(student3);
    dmtcStudents.push_back(student1);
    intlStudents.push_back(student4);
    intlStudents.push_back(student5); //James Wong
    

    //Sample user data for sign in
    userDatas["rjerusalem2016@gmail.com"] = "password123";
    userDatas["rom"] = "rom";
    userDatas["ram"] = "ram";

    Course course1("Web Development");
    Course course2("Data Science");
    Course course3("Cybersecurity");
    Course course4("Cloud Computing");

    availableCourses.push_back(course1);
    availableCourses.push_back(course2);
    availableCourses.push_back(course3);
    availableCourses.push_back(course4);

    //-------ADMIN USERS
    adminDatas["admin01@systems.com"] = "admin01";
    adminDatas["admin01"] = "admin01";

    //-----------------------------------------------------------------------   
    //   STUDENT START

    cout << "\nstudent4 ID = " << student4.getidNumber();
    cout << "\nstudent5 ID = " << student5.getidNumber() << endl;

    while (program == 1) {

        cout << "\n---------------------------------|" << endl;
        cout << "\n------------T********------------|" << endl;
        cout << "[1] Student Sign in" << endl;
        cout << "[2] Student Sign up" << endl;
        cout << "[3] Admin Sign in" << endl;
        cin.clear();
        cin >> run;

        switch (run) {

        case 1: // STUDENT SIGN IN SCREEN
        {
            cout << "------STUDENT SIGN IN------|" << endl;
            cout << "[1] Login | [2] Back to main menu" << endl;
            cin >> signInOption;
            if (cin.fail() || signInOption != 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break; // Breaks out to the main loop safely
            }

            string username, password;
            cout << "\n---------------------------------|" << endl;
            cout << "\n--------STUDENT SIGN IN----------|" << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            Student* currentStudent = nullptr;

            for (auto& student : dmtcStudents) {
                if (student.authenticate(username, password)) {
                    currentStudent = &student;
                    break;
                }
            }

            if (currentStudent == nullptr) {
                for (auto& student : intlStudents) {
                    if (student.authenticate(username, password)) {
                        currentStudent = &student;
                        break;
                    }
                }
            }

            if (currentStudent != nullptr) {
                cout << "Signin successful!\n" << endl;
                system("cls");
                
                // LOGGED IN STATE

                bool studentLoggedIn = true;
                while (studentLoggedIn) {
                    cout << "\n---------------------------------|" << endl;
                    cout << "\n--- Student Management System ---|" << endl;
                    cout << "Welcome, " << currentStudent->getName() << "!" << endl;
                    cout <<"ID No.: " << currentStudent->getidNumber() << endl;;
                    currentStudent->getCourseNames();
                    cout << "---------------------------------|" << endl;

                    cout << "\n[1] Sign-up to additional course" << endl;
                    cout << "[2] Logout" << endl;
                    cin >> studentOption;

                    if (studentOption == 1) {
                        int courseOption;
                        cout << "Available courses: \n";
                        for (int i = 0; i < availableCourses.size(); i++) {
                            cout << "[" << i + 1 << "] " << availableCourses[i].getName() << endl;
                        }
                        cout << "Select a course to enroll: ";
                        cin >> courseOption;

                        if (courseOption >= 1 && courseOption <= availableCourses.size()) {
                            string selectedCourse = availableCourses[courseOption - 1].getName();
                            currentStudent->enrollCourse(selectedCourse);

                            
                            cout << "\nSuccessfully enrolled in " << selectedCourse << "!\n";
                        }
                        else {
                            cout << "\nInvalid course option.\n";
                        }
                    }
                    else if (studentOption == 2) {
                        cout << "Logging out...\n";
                        studentLoggedIn = false; // Gracefully drops back out to the welcome login menu
                    }
                }
            }
            else {
                cout << "Invalid username or password.\n";
            }
            break;
        }
        //STUDENT SIGN UP START
        case 2: {
            string pwAttempt1, pwAttempt2;
            string studentEmail, firstName, lastName;
            int idNumber, mobileNumber, studentType;
            bool domestic = true;
            cout << "\n---------------------------------" << endl;
            cout << "\n--- Student Management System ---" << endl;
            cout << "\n---------------------------------" << endl;
            cout << "\n-------- STUDENT SIGN UP --------" << endl;
            cout << "\n---------------------------------" << endl;
            cout << "\n";

            cout << "Please fill in the details below:";
            cout << "\n";
            cout << "\n(This will serve as your username)";
            cout << "\nEmail: ";
            cin >> studentEmail;

            while (true) {

                cout << "\npassword: ";
                cin >> pwAttempt1;
                cout << "\nConfirm password: ";
                cin >> pwAttempt2;
                if (pwAttempt1 == pwAttempt2) {
                    
                    break;
                }
                else {
                    cout << "Passwords do not match. Please try again.\n";


                }
            }


            cout << "\nFirst name: ";
            cin >> firstName;
            cout << "\nLast name: ";
            cin >> lastName;
            cout << "Mobile number:";
            cin >> mobileNumber;


            cout << " [1] Domestic | [2] International" << endl;
            cin >> studentType;

            //random idNumber generator below
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> distrib(0, 9999);

            int random_num = distrib(gen);

            vector <int> student_numbers;
            int newStudentNumber = 20260000 + random_num;
            idNumber = newStudentNumber;

            if (studentType == 1) {
                Student newStudent(firstName, lastName, idNumber, "Not set", studentEmail, mobileNumber, 0, studentEmail, pwAttempt1, "None", "None", "None");
                dmtcStudents.push_back(newStudent);
                userDatas[studentEmail] = pwAttempt1;



            }
            else if (studentType == 2) {
                Student newStudent(firstName, lastName, idNumber, "Not set", studentEmail, mobileNumber, 0, studentEmail, pwAttempt1, "None", "None", "None");
                intlStudents.push_back(newStudent);
                userDatas[studentEmail] = pwAttempt1;


            }

            else {
                cout << "Invalid selection. Please select 1 for Domestic or 2 for International.\n";
            }

            cout << "\n-----------------------------------------" << endl;
            cout << "\n-------- REGISTRATION SUCCESSFUL --------" << endl;
            cout << "\n-----------------------------------------" << endl;
            cout << "Registration successful for user: " << studentEmail << endl;
            cout << "Your ID number is: " << idNumber << endl;
            cout << "You can now sign in using your email and password." << endl;
            cout << "\n";

            run = 1;
            break;



        }
              //-------------------------------------------------------------------------------------------    
              //   ADMIN START
        case 3: {

            string username, password;
            cout << "\n---------------------------------|" << endl;
            cout << "\n----------ADMIN SIGN IN----------|" << endl;
            cout << "Enter given email and password: " << endl;
            cout << "Email: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (adminDatas.find(username) != adminDatas.end() && adminDatas[username] == password) {
                cout << "Login successful!\n" << endl;
                cin.clear();
            }
            else {

                cout << "Invalid username or password." << endl;

                break;
            }

            bool adminLoggedIn = true;
            while (adminLoggedIn) {
                cout << "\n---------------------------------" << endl;
                cout << "\n--- Student Management System ---" << endl;
                cout << "\n---------------------------------" << endl;
                cout << "\n--------      ADMIN       -------" << endl;
                cout << "\n---------------------------------" << endl;
                cout << "\n---------------------------------" << endl;
                cout << "\n---------------------------------" << endl;
               
                cout << "[1] Search student by name or ID number [WIP]" << endl;
                cout << "[2] View domestic students list " << endl;
                cout << "[3] View international students list " << endl;
                cout << "[4] View all students list " << endl;
                cout << "[5] Remove a Student [WIP]" << endl;
                cout << "[0] Logout " << endl;

                cin >> option;

                switch (option) {
               

                case 1: {  //SEARCH STUDENT BY NAME - WORKING
                        
                    cout << "----------------------------\n";
                    cout << "---Search student by name---\n";
                    cout << "Name: ";
                    //input target name
                    string targetName;
                    cin >> targetName;
                    //search the vector
                    //check if student is found - in domestic -------------------------------/
                        //Using Lambda parameter 's'
                        auto it = find_if(dmtcStudents.begin(), dmtcStudents.end(),
                                        [&targetName](const Student& s)
                                        {
                                          return s.getfirstName() == targetName;
                                        });

                        if (it != dmtcStudents.end()) 
                        {
                            cout << "Domestic | Student found:\n";
                            it->getInfo();
                        }
                        else 
                        {
                            cout << "Domestic| Student not found.\n";
                        }

                        /*----for international students------------------------------------*/
                        auto it2 = find_if(intlStudents.begin(),intlStudents.end(),
                                           [&targetName](const Student& s)
                        {
                            return s.getfirstName() == targetName;
                        });
                        if (it2 != intlStudents.end())
                        {
                            cout << "\nInternational | Student found:\n";
                            it2->getInfo();
                        }
                        else 
                        {
                            cout << "International | Student not found.\n";
                        }
                        
                        break;
                }

                case 2: { // VIEW DOMESTIC STUDENTS - working
                    cout << "[2] Selected\n";
                    cout << "\nDomestic students Enrolled:" << endl;
                    for (int i = 0; i < dmtcStudents.size(); i++) {
                        dmtcStudents[i].getInfo();
                    }
                    cout << "\n--------------------" << endl;
                    cout << "Press any key to go back " << endl;
                    char backValue;
                    cin >> backValue;

                    break;
                }

                case 3: { // VIEW INTERNATIONAL STUDENTS - working
                    cout << "[3] Selected\n";
                    cout << "\nInternational students Enrolled:" << endl;
                    for (int i = 0; i < intlStudents.size(); i++) {
                        intlStudents[i].getInfo();
                    }
                    cout << "\n--------------------" << endl;
                    cout << "Press any key to go back " << endl;
                    char backValue;
                    cin >> backValue;

                    break;
                }

                case 4: { //VIEW ALL STUDENTS - working
                    cout << "[4] Selected\n";
                    cout << "\n-------------------------------|" << endl;
                    cout << "\nDomestic students Enrolled:" << endl;
                    for (int i = 0; i < dmtcStudents.size(); i++) {
                        dmtcStudents[i].getInfo();
                    }

                    cout << "\n--------------------" << endl;
                    cout << "\n-------------------------------|" << endl;
                    cout << "\nInternational students enrolled:" << endl;

                    for (int i = 0; i < intlStudents.size(); i++) {
                        intlStudents[i].getInfo();
                    }
                    cout << "\n--------------------" << endl;
                    
                    break;
                }

                case 5: { //REMOVE A STUDENT - WORKING

                    cout << "[5] Selected\n";
                    cout << "Enter the ID number of the student you want to remove: ";
                    int removeId;
                    cin >> removeId;
                    bool found = false;
                    //-------
                    auto it = find_if(
                        intlStudents.begin(),
                        intlStudents.end(),
                        [&removeId](const Student& s)
                        {
                            return s.getidNumber() == removeId;
                        });

                    if (it != intlStudents.end())
                    {
                        cout << "Removing student: "
                            << it->getName() << endl;

                        intlStudents.erase(it);

                        cout << "Student removed successfully.\n";
                    }
                    else
                    {
                        cout << "Student not found.\n";
                    }

                    break;
                }

                case 0: { //LOGOUT
                    cout << "[7] Selected\n";
                    adminLoggedIn = false;
                    system("cls");
                    break;



                }


                      //switch end
                }

                //While adminLoggedIn end
            }

            //While run==2 end
        }

              //option end
        }
        //while end
    }

    //main end
}



//Update: 09 JUNE 2026
/*
     STUDENT
        - Enroll Courses are working fine - SOLVED
        - but still need to get rid off the x3 Empty fields on the Student landing page

     ADMIN
        - View Student List - Domestic / International / ALL   -- WORKING
        - Remove Student                                       -- WORKING
        - Search student by idNumber                           -- WORKING

     TO DO: 
     
     ADMIN
        - Add a course : Course Name | Description

    ISSUES:
    ID Number workaround:
    valid Id Number - to use on removing /searching student - is the one generated from registering



*/

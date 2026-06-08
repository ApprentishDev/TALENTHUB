// : This file contains the 'main' function. Program execution begins and ends there.
//USE CAMELCASE !!!!!

#include <iostream>
#include <vector>
#include <map>
#include <cctype> //std::isalpha
#include <random>
#include <iomanip> // std::setw and std::setfill
#include <conio.h> 

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

        string getName() const {
            return firstName + " " + lastName;
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
    int option, stOption;

   

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
    Student s2 = Student::createStudent("Britney", "Spranks", 123456, "1234 Street",  "bSpranks@gmail",123456, 0, "bSpranks","password123", "course1: Empty", "course1: Empty", "course1: Empty");

    Student student1("Spongebob", "Squarepants", 81008100, "01 Pineapple Bay", "spongebob@gmail.com", 0225145, 0, "sBobSquarepants", "password123", "Fishery","Planktology","Burgerpreneur");
    

    Student student4("firstName", "lastName", 0123456, "Bluegrey Avenue", "Email@email.com", 1234567, 0, "username", "password", "Math", "Algebra", "Calculus");

    Student currentStudent("firstName", "lastName", 0123456, "Bluegrey Avenue", "Email@email.com", 1234567, 0, "username", "password", "Math", "Algebra", "Calculus");

    dmtcStudents.push_back(s2);
    dmtcStudents.push_back(student1);
    intlStudents.push_back(student4);
    

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

    while (program == 1) {

        cout << "\n---------------------------------|" << endl;
        cout << "\n------------T********------------|" << endl;
        cout << "[1] Student Sign in" << endl;
        cout << "[2] Student Sign up" << endl;
        cout << "[3] Admin Sign in" << endl;
        cin.clear();
        cin >> run;

        switch (run) {

        case 1:
        {

            cout << "------STUDENT SIGN IN------|" << endl;
            cout << "[1] Login | [2] Back to main menu" << endl;
            cin >> signin;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                break;
            }

            switch (signin)
            {
            case 1:
            {

                string username, password;
                cout << "\n---------------------------------|" << endl;
                cout << "\n--------STUDENT SIGN IN----------|" << endl;
                cout << "Enter username and password: " << endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

              


                // Use currentStudent to track who successfully authenticated
                Student* currentStudent = nullptr;

                // 1. Scan domestic students vector directly
                for (auto& student : dmtcStudents) 
                {
                    if (student.authenticate(username, password)) 
                    {
                        currentStudent = &student;
                        break;
                    }
                }

                // 2. If not found in domestic, scan international students vector
                if (currentStudent == nullptr) 
                {
                    for (auto& student : intlStudents) 
                    {
                        if (student.authenticate(username, password)) 
                        {
                            currentStudent = &student;
                            break;
                        }
                    }
                }

                // 3. Check if we found a valid matching student
                if (currentStudent != nullptr) {
                    cout << "Signin successful!\n" << endl;

                    // Clear screen and load the menu
                    system("cls");
                    cout << "\n---------------------------------|" << endl;
                    cout << "\n--- Student Management System ---|" << endl;
                    cout << "\n---------------------------------|" << endl;
                    cout << "\n--------     STUDENT     --------|" << endl;
                    cout << "\n---------------------------------|" << endl;

                    if (currentStudent) {
                        cout << "Welcome, " << currentStudent->getName() << "!" << endl;
                        cout << "Courses enrolled: " << currentStudent->getCourseCount() << "/3\n";

                        // Print the actual course names if they have any
                        currentStudent->getCourseNames();
                        cout << "---------------------------------|" << endl;
                    }

                    cout << "\n[1] Sign-up to additional course (" << availableCourses.size() << ")" << endl;
                    cout << "\n[2] Logout" << endl;
                    cin >> stOption;
                    switch (stOption)
                    {
                        case 1:
                        {
                            int courseOption;
                            cout << "[1] Selected\n";
                            cout << "------------------------------| \n";
                            cout << "Available courses: \n";
                            for (int i = 0; i < availableCourses.size(); i++)
                            {
                                cout << "\n[" << i + 1 << "] " << availableCourses[i].getName() << endl;
                            }
                            cout << "Select a course to enroll: \n";
                            cin >> courseOption;
                            switch (courseOption)
                            {

                                case 1:
                                {
                                    cout << "[1] " << availableCourses[0].getName() << " selected\n";
                                    cout << "Successfully enrolled to " << availableCourses[0].getName() << endl;
                                    break;
                                }
                                
                                case 2:
                                {
                                    cout << "[2] " << availableCourses[1].getName() << " selected\n";
                                    cout << "Successfully enrolled to " << availableCourses[1].getName() << endl;
                                    break;
                                }
                                case 3:
                                {
                                    cout << "[3] " << availableCourses[2].getName() << " selected\n";
                                    cout << "Successfully enrolled to " << availableCourses[2].getName() << endl;
                                    break;
                                }

                            }

                            break;
                        }//case 1 end

                        case 2:
                        {
                            cout << "[2] Selected\n";
                            run = 0;
                            break;
                        }//case2 end

                    }//switch stOption end
                }

            }

            
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
               

                case 1: {  //SEARCH STUDENT BY NAME or ID NUMBER

                }

                case 2: { // VIEW DOMESTIC STUDENTS - working
                    cout << "[3] Selected\n";
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
                    cout << "[4] Selected\n";
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
                    cout << "[5] Selected\n";
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

                case 5: { //REMOVE A STUDENT

                    cout << "[6] Selected\n";
                    cout << "Enter the ID number of the student you want to remove: ";
                    int removeId;
                    cin >> removeId;
                    bool found = false;


                }

                case 0: { //LOGOUT
                    cout << "[7] Selected\n";
                    adminLoggedIn = false;
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

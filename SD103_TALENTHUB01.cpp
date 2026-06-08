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
    int courseCount;






public:

    User(string firstName, string lastName, int idNumber, int ccourseCount) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->idNumber = idNumber;
        this->courseCount = ccourseCount;
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

};





class Student : public User {

private:
    std::string name;

    //vector here for courses enrolled
    vector<string> coursesEnrolled;

public:


    Student(string firstName, string lastName, int idNumber, int courseCount) : User(firstName, lastName, idNumber, courseCount) {
    };

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
    /* cout << "Press any key to continue..." << endl;*/
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
    Student student2("Britney", "Spranks", 20260052, 0);
    Student student1("Spongebob", "Squarepants", 20262345, 0);
    Student student3("Batman", "Mbiyonde", 20261998, 0);

    Student student4("Ron", "James", 20263119, 0);

    Student currentStudent("Current", "User", 0, 0);

    dmtcStudents.push_back(student2);
    dmtcStudents.push_back(student1);
    intlStudents.push_back(student4);
    dmtcStudents.push_back(student3);

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
                // CODE WHEN A CHARACTER IS INPUTTED
                cin.clear(); // 1. Clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 2. Discard the bad input

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

                Student* loggedInStudent = nullptr;

                if (userDatas.find(username) != userDatas.end() && userDatas[username] == password) {
                    cout << "Signin successful!\n" << endl;

                    // Find the student object by username (email) and set loggedInStudent pointer
                    for (auto& student : dmtcStudents) {
                        if (student.getName() == username) {
                            loggedInStudent = &student;
                            break;
                        }
                    }
                    if (!loggedInStudent) {
                        for (auto& student : intlStudents) {
                            if (student.getName() == username) {
                                loggedInStudent = &student;
                                break;
                            }
                        }
                    }
                    // If not found, you may want to handle this case (e.g., error message)
                }

                // ... then, when printing courses enrolled, use the pointer safely:
                if (loggedInStudent) {
                    cout << "Courses enrolled: " << loggedInStudent->getCoursesEnrolledList().size() << "/3\n";
                    cout << "\n------------------------------| \n";
                    for (const string& course : loggedInStudent->getCoursesEnrolledList()) {
                        cout << "Course: " << course << endl;
                    }
                }
                else {
                    cout << "No student is currently logged in.\n";
                }

                system("cls");
                cout << "\n---------------------------------|" << endl;
                cout << "\n--- Student Management System ---|" << endl;
                cout << "\n---------------------------------|" << endl;
                cout << "\n--------     STUDENT     --------|" << endl;
                cout << "\n---------------------------------|" << endl;

                if (loggedInStudent) {
                    cout << "Courses enrolled: " << loggedInStudent->getCoursesEnrolledList().size() << "/3\n";
                }

                cout << "\n[1] Sign-up to additional course (" << availableCourses.size() <<")"<<endl;
                cout << "\n[2] Logout" << endl;
                cin >> stOption;
                switch (stOption)
                {
                case 1:
                {
                    int  courseOption;
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

                        case 1: //WIP
                        {
                            cout << "[1] " << availableCourses[0].getName() << " selected\n";
                            //Doesn't work
                            // Student:coursesEnrolled.push_back(availableCourses[0]);

                            cout << "Successfully enrolled to " << availableCourses[0].getName() << endl;
                            break;
                        }
                        break;
                        case 2:
                        {
                            cout << "[2] " << availableCourses[1].getName() << " selected\n";
                            availableCourses.push_back(availableCourses[1]);

                            cout << "Successfully enrolled to " << availableCourses[1].getName() << endl;
                            break;
                        }
                        case 3:
                        {
                            cout << "[3] " << availableCourses[2].getName() << " selected\n";
                            availableCourses.push_back(availableCourses[2]);
                            cout << "Successfully enrolled to " << availableCourses[2].getName() << endl;
                            break;
						}

                    //switch break
                    }

                    break;
                    //case 1 end
                }

                case 2:
                {
                    cout << "[2] Selected\n";
                    run = 0;
                    break;
                }

                }
            }

            }

            break;
            //While run==1 end
        }


        //STUDENT SIGN UP START - NO FUNCTION
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
            //
            // ------RANDOM START   Add Random number generator for ID number

            std::random_device rd;
            std::mt19937 gen(rd());

            // Define the range for any 4-digit number
            std::uniform_int_distribution<> distrib(0, 9999);

            int random_num = distrib(gen);

            vector <int> student_numbers;
            int newStudentNumber = 20260000 + random_num;
            idNumber = newStudentNumber;

            // ------RANDOM END   --------------------------------------------|

            if (studentType == 1) {
                // Add domestic student logic here
                Student newStudent(firstName, lastName, idNumber, 0);
                //Add to domestic student vector
                dmtcStudents.push_back(newStudent);
                //Add to userData map
                userDatas[studentEmail] = pwAttempt1;



            }
            else if (studentType == 2) {
                // Add international student logic here
                Student newStudent(firstName, lastName, idNumber, 0);
                //Add to domestic student vector
                intlStudents.push_back(newStudent);
                //Add to userData map
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

            //getline
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
                cout << "[1] Add Student " << endl;
                cout << "[2] Search student by name or ID number [WIP]" << endl;
                cout << "[3] View domestic students list " << endl;
                cout << "[4] View international students list " << endl;
                cout << "[5] View all students list " << endl;
                cout << "[6] Remove a Student [WIP]" << endl;
                cout << "[7] Logout " << endl;

                cin >> option;

                switch (option) {
                case 1: { //WORKING

                    string firstName, lastName;
                    int idNumber;
                    int status;
                    cout << "[1] Selected\n";
                    //Add student code
                    cout << "Enter student name: ";
                    cin >> firstName;
                    cout << "Enter student last name: ";
                    cin >> lastName;
                    cout << "Enter student ID: ";
                    cin >> idNumber;
                    cout << "Select the one that applies (1 for Domestic, 2 for International): ";
                    cin >> status;

                    if (status == 0) {
                        cout << "Invalid selection. Please select 1 for Domestic or 2 for International.\n";
                    }
                    if (status == 1) {
                        Student newStudent(firstName, lastName, idNumber, 0);
                        dmtcStudents.push_back(newStudent);

                        for (int i = 0; i < dmtcStudents.size(); i++) {
                            dmtcStudents[i].getInfo();
                        }
                        break;
                    }
                    if (status == 2) {
                        Student newStudent(firstName, lastName, idNumber, 0);
                        intlStudents.push_back(newStudent);

                        for (int i = 0; i < intlStudents.size(); i++) {
                            intlStudents[i].getInfo();
                        }
                        break;
                    }
                    else {
                        cout << "Invalid selection. Please select 1 for Domestic or 2 for International.\n";
                    }


                    break;
                }


                case 2: {  //SEARCH STUDENT BY NAME or ID NUMBER

                }

                case 3: { // VIEW DOMESTIC STUDENTS - working
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

                case 4: { // VIEW INTERNATIONAL STUDENTS - working
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

                case 5: { //VIEW ALL STUDENTS - working
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
                    _getch();


                    break;
                }

                case 6: { //REMOVE A STUDENT

                    cout << "[6] Selected\n";
                    cout << "Enter the ID number of the student you want to remove: ";
                    int removeId;
                    cin >> removeId;
                    bool found = false;


                }

                case 7: { //LOGOUT
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



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

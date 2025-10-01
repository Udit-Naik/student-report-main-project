#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstring>
using namespace std;
int publishResult = 0;
void home();  // To create a home page where user can decide his user mode
void intro(); // To create a Intro page of the system
void exit();  // an exit page after user shut down system
void loginAsAdmin();
void loginAsFaculty();
void loginAsStudent();

// admin features
void adminMenu();
void addNewStudent();
void addNewFaculty();
void viewExistingStudentRecord(int);
void viewExistingFacultyRecord(int);
void modifyExistingStudentDetails(int);
void modifyExistingFacultyDetails(int);
void deleteFacultyData(int);
void deleteStudentData(int);

// faculty Specific Feature
void uploadStudentMarks(int);
void viewSpecificStudentMarks(int);

// student specific feature
void viewResultOfAllStudents();

// query system
void studentSendQuery(int);
void studentViewQueries(int);
void facultyViewQueries(int);
void facultyReplyToQuery(int);

class schoolMember
{
public:
    char name[40];
    char address[200];
    char phone[40];
    char dob[40];
    char pass[20];
};

class student : public schoolMember
{
public:
    int roll;
    char id[40];
    char standard[20];
    float math, physics, computer, chemistry, english, percentage;
    void calculatePercentage()
    {
        percentage = (math + physics + computer + chemistry + english) / 5;
    }
};

class faculty : public schoolMember
{
public:
    int id;
    char depart[40];
};

// query record between student and faculty
class Query
{
public:
    int queryId;
    int studentRoll;
    int facultyId;
    char message[200];
    char reply[200];
    char status[20]; // PENDING, ACCEPTED, DECLINED, REPLIED
};

int main()
{
    system("color a");
    system("cls");
    intro();
    home();
    return 0;
}

void intro() // Function to create a Intro Page of the Project
{

    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *****  *     *****  ***    * * *    *****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *      *     *     *   *  *  *  *   *        " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *****  *     *     *   *  *  *  *   *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t *  *  *  *      *     *     *   *  *  *  *   *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  * * *   *****  ****  *****  ***   *  *  *   *****     " << endl;
    Sleep(300);
    cout << endl;
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(500);
    cout << "\t\t\t\t  THIS IS STUDENT RECORD MANAGEMENT SYSTEM" << endl;
    Sleep(500);
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(500);
    cout << "\npress enter to continue...";
    cin.get();
}

// Function that can be called to create a Home page where you can select "How do you want to login in the System as?"
void home()
{
    char c;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t  ====================STUDENT RECORD MANAGEMENT SYSTEM====================" << endl;
    cout << endl;
    cout << "\n\n\t\t\t\t==========HOME PAGE==========\n\n"
         << endl;
    cout << "\n\n";
    cout << "\t\t\t\t Select User type from following:" << endl;
    cout << endl;
    cout << "\t\t\t\t1. Login as Admin\n\n";
    cout << "\t\t\t\t2. Login as Faculty\n\n";
    cout << "\t\t\t\t3. Login as Student\n\n";
    cout << "\t\t\t\t4. Shut the system\n\n";
    cout << "ENTER YOUR CHOICE : ";
    cin >> c;
    system("cls");
    switch (c)
    {
    case '1':
    {
        loginAsAdmin();
        break;
    }
    case '2':
    {
        loginAsFaculty();
        break;
    }
    case '3':
    {
        loginAsStudent();
        break;
    }
    case '4':
    {
        exit();
        break;
    }
    }
}

// Function to create a thanks page after user wants to exit the system, user can also go to home page without runnnig program again
void exit()
{
    char c;
    system("cls");
    system("color e");
    cout << "\n\n\t\t     THANK YOU FOR USING THIS SOFTWARE" << endl;
    cout << "\n\n";
   
    cout << "\n\n";
    cout << "Input 'H' to back to home page... ";
    cin.ignore();
    cin >> c;
    if (c == 72 || c == 104)
    {
        home();
    }
}

// function to create login as admin section
void loginAsAdmin()
{
    char ch;
    string pass, id;
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t Login As Admin \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\t\t\t\t\t Enter your Id and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t\t ID: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t\t Password: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13)
    { // character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    if (id == "admin" && pass == "admin") // use both id and password of admin menu as admin
        adminMenu();
    else
    {
        cout << "\n\n\tEnter Valid ID or Password\n\n";
        cout << endl;
        cout << "\t Press 'H' to select login options again...";
        char a;
        cin >> a;
        if (a == 'h' || a == 'H')
            home();
    }
}

// admin menu with his features
void adminMenu()
{
begin:
    system("cls");
    system("color c");
    int cc;
    cout << "\n\n\n\t\t\t\t\t\t Welcome Admin\n\n\n";
    cout << "\t\t\t\t=================MAIN MENU================\n\n"
         << endl;
    cout << "\t\t\t\t1. View and Publish Result\n\n";
    Sleep(300);
    cout << "\t\t STUDENT :\n\n";
    Sleep(300);
    cout << "\t\t\t\t 2. Add a new Student\n\n";
    Sleep(300);
    cout << "\t\t\t\t 3. View existing Student record\n\n";
    Sleep(300);
    cout << "\t\t\t\t 4. Modify existing Student record.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 5. Upload Student Marks.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 6. View Specific Student Marks.\n\n";
    Sleep(300);
    cout << "\t\t\t\t 7. Delete Student record.\n\n";
    Sleep(300);
    cout << "\t\t Faculty :\n\n";
    Sleep(300);
    cout << "\t\t\t\t 8. Add a new Faculty\n\n";
    Sleep(300);
    cout << "\t\t\t\t 9. View existing Faculty\n\n";
    Sleep(300);
    cout << "\t\t\t\t 10. Modify existing faculty record\n\n";
    Sleep(300);
    cout << "\t\t\t\t 11. Delete existing faculty record\n\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t 12. Log Out\n\n";
    cout << "\t\t\t\t==============================" << endl;
    Sleep(300);
    cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-12> : ";
    Sleep(300);
    cin >> cc;
    cout << endl;
    system("cls");
    switch (cc)
    {
    case 1:
    {
        viewResultOfAllStudents();
        goto begin;
        break;
    }
    case 2:
    {
        addNewStudent();
        goto begin;
        break;
    }
    case 3:
    {
        int n;
        cout << "\n\nENTER STUDENT ROLL NUMBER TO VIEW HIS PROFILE : ";
        cin >> n;
        viewExistingStudentRecord(n);
        goto begin;
        break;
    }
    case 4:
    {
        int n;
        cout << "\n\nENTER STUDENT ROLL NUMBER TO MODIFY HIS PROFILE : ";
        cin >> n;
        modifyExistingStudentDetails(n);
        goto begin;
        break;
    }
    case 5:
    {
        int n;
        cout << "\n\nENTER STUDENT ROLL NUMBER TO UPLOAD MARKS : ";
        cin >> n;
        uploadStudentMarks(n);
        goto begin;
        break;
    }
    case 6:
    {
        int n;
        cout << "ENTER STUDENT ROLL NUMBER : ";
        cin >> n;
        viewSpecificStudentMarks(n);
        goto begin;
        break;
    }
    case 7:
    {
        int n;
        cout << "\n\nENTER STUDENT ROLL NO TO DELETE HIS RECORD : ";
        cin >> n;
        deleteStudentData(n);
        goto begin;
        break;
    }
    case 8:
    {
        addNewFaculty();
        goto begin;
        break;
    }
    case 9:
    {
        int n;
        cout << "\n\nENTER FACULTY ID TO VIEW HIS PROFILE : ";
        cin >> n;
        viewExistingFacultyRecord(n);
        goto begin;
        break;
    }
    case 10:
    {
        int n;
        cout << "\n\nENTER FACULTY ID TO MODIFY HIS PROFILE DATA : ";
        cin >> n;
        modifyExistingFacultyDetails(n);
        goto begin;
        break;
    }
    case 11:
    {
        int n;
        cout << "\n\nENTER FACULTY ID TO DELETE HIS RECORD : ";
        cin >> n;
        deleteFacultyData(n);
        goto begin;
        break;
    }
    case 12:
    {
        home();
        break;
    }
    }
}

void viewResultOfAllStudents()
{
    system("cls");
    student s;
    ifstream infile;
    bool check = false;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tALL STUDENTS REPORT CARDS FOR REVIEW " << endl;
    cout << "==================================================================================" << endl;
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        cout << "\t\t\t\tSTUDENT NAME : " << s.name << endl
             << endl;
        cout << "\t\t\t\tSTUDENT ADMISSION ID NUMBER : " << s.id << endl
             << endl;
        cout << "\t\t\t\tSTUDENT ROLL NUMBER : " << s.roll << endl
             << endl;
        cout << "\t\t\t\tMATH      : " << s.math << endl
             << endl;
        cout << "\t\t\t\tPHYSICS   : " << s.physics << endl
             << endl;
        cout << "\t\t\t\tCHEMISTRY : " << s.chemistry << endl
             << endl;
        cout << "\t\t\t\tENGLISH   : " << s.english << endl
             << endl;
        cout << "\t\t\t\tCOMPUTER  : " << s.computer << endl
             << endl;
        cout << "\t\t\t\tPERCENTAGE: " << s.percentage << endl
             << endl;
        cout << "==================================================================================\n"
             << endl;
        check = true;
    }
    infile.close();
    if (check == false)
        cout << "\t\t\t\tNO RECORD FOUND... " << endl
             << endl;
    if (check == true)
    {
        cout << "\n\nFor Publishing Result press 1 for not press 0 : ";
        /* this will give access to students to view their marks
            otherwise when student see their result it will show
            result not uploaded yet */
        cin >> publishResult;
        if (publishResult == 1)
        {
            cout << "\n\nResult Published to STUDENT PORTAL\n\n";
        }
    }
    cout << "\tpress enter to continue....";
    cin.ignore();
    cin.get();
}

void addNewStudent()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Student.txt", ios::app | ios::binary);
    if (outfile.fail())
    {
        cout << "THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n\n";
    cout << "\t\t\t\t======= Add A Student ========\n\n";
    cout << "ENTER FULL NAME : ";
    cin.ignore();
    cin.getline(s.name, 40);
    cout << "ENTER Admission Id : ";
    cin.getline(s.id, 40);
    cout << "ENTER D.O.B : ";
    cin.getline(s.dob, 40);
    cout << "ENTER PHONE NUMBER : ";
    cin.getline(s.phone, 40);
    cout << "ENTER ADDRESS : ";
    cin.getline(s.address, 200);
    cout << "ENTER CLASS STANDARD : ";
    cin.getline(s.standard, 20);
    cout << "Set A Password For the User : ";
    cin.getline(s.pass, 20);
    cout << "ENTER ROLL NUMBER (INT Value) : ";
    cin >> s.roll;
    outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void viewExistingStudentRecord(int n)
{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\n\t\t\t\t========== STUDENT PROFILE ==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll == n)
        {
            cout << "\t\t\t\t NAME : " << s.name << endl;
            cout << "\t\t\t\t ADMISSION ID NUMBER : " << s.id << endl;
            cout << "\t\t\t\t ROLL NUMBER : " << s.roll << endl;
            cout << "\t\t\t\t D.O.B : " << s.dob << endl;
            cout << "\t\t\t\t STANDARD : " << s.standard << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << s.phone << endl;
            cout << "\t\t\t\t ADDRESS : " << s.address << endl;
            cout << "\t\t\t\t PASSWORD : " << s.pass << endl;
            cout << "\t\t\t\t======================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void modifyExistingStudentDetails(int n)
{
    system("cls");
    student s;
    fstream infile;
    infile.open("Student.txt", ios::binary | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\n\t\t\t\t==========MODIFY STUDENT PROFILE==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char *>(&s), sizeof(student));
        {
            if (s.roll == n)
            {
                cout << "\t\t\t\t NAME : " << s.name << endl;
                cout << "\t\t\t\t ADMISSION ID NUMBER : " << s.id << endl;
                cout << "\t\t\t\t ROLL NUMBER : " << s.roll << endl;
                cout << "\t\t\t\t D.O.B : " << s.dob << endl;
                cout << "\t\t\t\t STANDARD : " << s.standard << endl;
                cout << "\t\t\t\t PHONE NUMBER :" << s.phone << endl;
                cout << "\t\t\t\t ADDRESS :" << s.address << endl;
                cout << "\t\t\t\t PASSWORD : " << s.pass << endl;
                cout << "\n\t\t\t\t=============================================" << endl;
                cout << "\t\t\t\t\tENTER THE NEW INFORMATION" << endl;
                cout << "\t\t\t\t=============================================" << endl;
                cout << "\n\t\t\t\tENTER FULL NAME : ";
                cin.ignore();
                cin.getline(s.name, 40);
                cout << "\t\t\t\tENTER Admission Id : ";
                cin.getline(s.id, 40);
                cout << "\t\t\t\tENTER D.O.B : ";
                cin.getline(s.dob, 40);
                cout << "\t\t\t\tENTER PHONE NUMBER : ";
                cin.getline(s.phone, 40);
                cout << "\t\t\t\tENTER ADDRESS : ";
                cin.getline(s.address, 200);
                cout << "\t\t\t\tENTER CLASS STANDARD : ";
                cin.getline(s.standard, 20);
                cout << "\t\t\t\tSet A Password For the User : ";
                cin.getline(s.pass, 20);
                cout << "\t\t\t\tENTER ROLL NUMBER (INT Value) : ";
                cin >> s.roll;
                int pos = (-1) * static_cast<int>(sizeof(student));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char *>(&s), sizeof(student));
                cout << endl;
                cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY updated" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void deleteStudentData(int n)
{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::binary);
    if (!infile)
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Record3.txt", ios::binary);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t===========DELETE A STUDENT RECORD==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll != n)
        {
            outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
        }
    }
    infile.close();
    outfile.close();
    remove("Student.txt");
    rename("Record3.txt", "Student.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void uploadStudentMarks(int n)
{
    system("cls");
    student s;
    fstream infile;
    infile.open("Student.txt", ios::binary | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\t\t\t\t==========UPLOAD STUDENT MARKS==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char *>(&s), sizeof(student));
        {
            if (s.roll == n)
            {
                cout << "\t\t\t\t NAME : " << s.name << endl;
                cout << "\t\t\t\t ROLL NUMBER : " << s.roll << endl;
                cout << "\t\t\t\t D.O.B : " << s.dob << endl;
                cout << "\t\t\t\t STANDARD : " << s.standard << endl;
                cout << "\n\t\t\t\t=============================================" << endl;
                cout << "\t\t\t\t\t  UPLOAD MARKS BELOW" << endl;
                cout << "\t\t\t\t=============================================" << endl;
                cout << "\n\t\t\t\tENGLISH : ";
                cin >> s.english;
                cout << "\t\t\t\tMATH : ";
                cin >> s.math;
                cout << "\t\t\t\tPHYSICS : ";
                cin >> s.physics;
                cout << "\t\t\t\tCHEMISTRY : ";
                cin >> s.chemistry;
                cout << "\t\t\t\tCOMPUTER : ";
                cin >> s.computer;
                s.calculatePercentage();
                int pos = (-1) * static_cast<int>(sizeof(student));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char *>(&s), sizeof(student));
                cout << endl;
                cout << "\n\t\t\t\tMarks Uploaded Successfully" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void viewSpecificStudentMarks(int n)
{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\t\t\t\t========== STUDENT REPORT CARD ==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll == n)
        {
            cout << "\t\t\t\t NAME : " << s.name << endl;
            cout << "\t\t\t\t ROLL NUMBER : " << s.roll << endl;
            cout << "\t\t\t\t D.O.B : " << s.dob << endl;
            cout << "\t\t\t\t STANDARD : " << s.standard << endl;
            cout << "\t\t\t\t==============================" << endl;
            cout << "\t\t\t\t PHYSICS   : " << s.physics << endl;
            cout << "\t\t\t\t MATH      : " << s.math << endl;
            cout << "\t\t\t\t CHEMISTRY : " << s.chemistry << endl;
            cout << "\t\t\t\t ENGLISH   : " << s.english << endl;
            cout << "\t\t\t\t COMPUTER  : " << s.computer << endl;
            cout << endl;
            cout << "\t\t\t\t PERCENTAGE : " << s.percentage << "%" << endl;
            cout << "\t\t\t\t==============================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void addNewFaculty()
{
    system("cls");
    faculty f;
    ofstream outfile;
    outfile.open("Faculty.txt", ios::app | ios::binary);
    if (outfile.fail())
    {
        cout << "THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n";
    cout << "\t\t\t\t=======Add A Faculty ========\n\n";
    cout << "ENTER FULL NAME : ";
    cin.ignore();
    cin.getline(f.name, 40);
    cout << "ENTER PHONE NUMBER : ";
    cin.getline(f.phone, 40);
    cout << "ENTER D.O.B : ";
    cin.getline(f.dob, 40);
    cout << "ENTER ADDRESS : ";
    cin.getline(f.address, 200);
    cout << "ENTER Department: ";
    cin.getline(f.depart, 40);
    cout << "Set a Password: ";
    cin.getline(f.pass, 40);
    cout << "ENTER Faculty Id (INT type): ";
    cin >> f.id;
    outfile.write(reinterpret_cast<char *>(&f), sizeof(faculty));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void viewExistingFacultyRecord(int n)
{
    system("cls");
    faculty f;
    ifstream infile;
    infile.open("Faculty.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\t\t\t\t========== FACULTY PROFILE ==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&f), sizeof(faculty)))
    {
        if (f.id == n)
        {
            cout << "\t\t\t\t NAME : " << f.name << endl;
            cout << "\t\t\t\t FACULTY ID NUMBER : " << f.id << endl;
            cout << "\t\t\t\t D.O.B : " << f.dob << endl;
            cout << "\t\t\t\t DEPARTMENT : " << f.depart << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << f.phone << endl;
            cout << "\t\t\t\t ADDRESS : " << f.address << endl;
            cout << "\t\t\t\t PASSWORD : " << f.pass << endl;
            cout << "\t\t\t\t======================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void modifyExistingFacultyDetails(int n)
{
    system("cls");
    faculty f;
    fstream infile;
    infile.open("Faculty.txt", ios::binary | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\t\t\t\t==========MODIFY FACULTY PROFILE==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char *>(&f), sizeof(faculty));
        {
            if (f.id == n)
            {
                cout << "\t\t\t\t NAME : " << f.name << endl;
                cout << "\t\t\t\t FACULTY ID NUMBER : " << f.id << endl;
                cout << "\t\t\t\t D.O.B : " << f.dob << endl;
                cout << "\t\t\t\t DEPARTMENT : " << f.depart << endl;
                cout << "\t\t\t\t PHONE NUMBER : " << f.phone << endl;
                cout << "\t\t\t\t ADDRESS : " << f.address << endl;
                cout << "\t\t\t\t PASSWORD : " << f.pass << endl;
                cout << "\n\t\t\t\t=========================================" << endl;
                cout << "\t\t\t\t\tENTER THE NEW INFORMATION" << endl;
                cout << "\t\t\t\t=========================================" << endl;
                cout << "\n\t\t\t\tENTER FULL NAME : ";
                cin.ignore();
                cin.getline(f.name, 40);
                cout << "\t\t\t\tENTER PHONE NUMBER : ";
                cin.getline(f.phone, 40);
                cout << "\t\t\t\tENTER D.O.B : ";
                cin.getline(f.dob, 40);
                cout << "\t\t\t\tENTER ADDRESS : ";
                cin.getline(f.address, 200);
                cout << "\t\t\t\tENTER Department: ";
                cin.getline(f.depart, 40);
                cout << "\t\t\t\tSet a Password: ";
                cin.getline(f.pass, 40);
                cout << "\t\t\t\tENTER Faculty Id (INT type): ";
                cin >> f.id;
                int pos = (-1) * static_cast<int>(sizeof(faculty));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char *>(&f), sizeof(faculty));
                cout << endl;
                cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY updated" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void deleteFacultyData(int n)
{
    system("cls");
    faculty f;
    ifstream infile;
    infile.open("Faculty.txt", ios::binary);
    if (!infile)
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Record2.txt", ios::binary);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t===========DELETE A FACULTY RECORD==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&f), sizeof(faculty)))
    {
        if (f.id != n)
        {
            outfile.write(reinterpret_cast<char *>(&f), sizeof(faculty));
        }
    }
    infile.close();
    outfile.close();
    remove("Faculty.txt");
    rename("Record2.txt", "Faculty.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void loginAsFaculty()
{
    char cc, ch;
    string password;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t Login As Faculty \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\t\t\t\t Enter your Faculty Id and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t Faculty Id: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t Password: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13)
    { // character 13 is enter
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    system("cls");
    faculty f;
    ifstream infile;
    infile.open("Faculty.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    while (infile.read(reinterpret_cast<char *>(&f), sizeof(faculty)))
    {
        if (f.id == id && f.pass == password)
        {
        start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t  Welcome " << f.name << "\n\n\n";
            cout << "\t\t\t\t=================FACULTY MENU================\n\n"
                 << endl;
            cout << "\t\t\t\t1. View profile\n\n";
            Sleep(300);
            cout << "\t\t STUDENT :\n";
            Sleep(300);
            cout << "\t\t\t\t 2. View existing Student record\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Upload Student Marks.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 4. View Specific Student Marks.\n\n";
            Sleep(300);
            cout << "\t\t QUERIES :\n";
            Sleep(300);
            cout << "\t\t\t\t 5. View student queries\n\n";
            Sleep(300);
            cout << "\t\t\t\t 6. Reply to a query\n\n";
            Sleep(300);
            cout << "\t\t\t\t 7. Log Out\n\n";
            cout << "\t\t\t\t==============================" << endl;
            Sleep(300);
            cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-7> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                viewExistingFacultyRecord(f.id);
                goto start;
                break;
            }
            case '2':
            {
                int k;
                cout << "\n\nENTER STUDENT ROLL NUMBER TO VIEW HIS PROFILE : ";
                cin >> k;
                viewExistingStudentRecord(k);
                goto start;
                break;
            }
            case '3':
            {
                int k;
                cout << "\n\nENTER STUDENT ROLL NUMBER TO UPLOAD MARKS : ";
                cin >> k;
                uploadStudentMarks(k);
                goto start;
                break;
            }
            case '4':
            {
                int k;
                cout << "\n\nENTER STUDENT ROLL NUMBER TO VIEW HIS RESULT : ";
                cin >> k;
                viewSpecificStudentMarks(k);
                goto start;
                break;
            }
            case '5':
            {
                facultyViewQueries(f.id);
                goto start;
                break;
            }
            case '6':
            {
                facultyReplyToQuery(f.id);
                goto start;
                break;
            }
            case '7':
            {
                home();
                break;
            }
            }
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
    {
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press 'H' key to continue...";
        char a;
        cin >> a;
        if (a == 'h' || a == 'H')
            home();
    }
}

void loginAsStudent()
{
    char cc, ch;
    string password;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t    Login As Student \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\t\t\t\t Enter your Roll No and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t Roll No: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t Password: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13)
    { // character 13 is enter
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    system("cls");
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll == id && s.pass == password)
        {
        start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t\t Welcome " << s.name << "\n\n\n";
            cout << "\t\t\t\t================= STUDENT MENU ================\n\n"
                 << endl;
            cout << "\t\t\t\t 1. View profile\n\n";
            Sleep(300);
            cout << "\t\t\t\t 2. Send query to faculty.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. View my queries.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 4. View Result.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 5. Log Out\n\n";
            cout << "\t\t\t\t==============================" << endl;
            Sleep(300);
            cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-5> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                viewExistingStudentRecord(s.roll);
                goto start;
                break;
            }
            case '2':
            {
                studentSendQuery(s.roll);
                goto start;
                break;
            }
            case '3':
            {
                studentViewQueries(s.roll);
                goto start;
                break;
            }
            case '4':
            {
                if (publishResult == 1)
                    viewSpecificStudentMarks(s.roll);
                else
                {
                    cout << "\n\n\n\t\tResult Not Uploaded Yet. Contact Admin \n\n";
                    cout << "\t\tpress enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                goto start;
                break;
            }
            case '5':
            {
                home();
                break;
            }
            }

            equality = true;
        }
    }
    infile.close();
    if (equality == false)
    {
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press 'H' key to continue...";
        char a;
        cin >> a;
        if (a == 'h' || a == 'H')
            home();
    }
}

// ============================= QUERY SYSTEM IMPLEMENTATION =============================

int getNextQueryId()
{
    ifstream infile;
    infile.open("Queries.txt", ios::binary);
    if (!infile)
    {
        return 1;
    }
    Query q;
    int maxId = 0;
    while (infile.read(reinterpret_cast<char *>(&q), sizeof(Query)))
    {
        if (q.queryId > maxId)
            maxId = q.queryId;
    }
    infile.close();
    return maxId + 1;
}

void studentSendQuery(int studentRoll)
{
    system("cls");
    cout << "\n\n\t\t\t\t========== SEND QUERY ==========" << endl;
    int facultyId;
    cout << "\nEnter Faculty Id to send query: ";
    cin >> facultyId;
    cin.ignore();
    char msg[200];
    cout << "Enter your query (max 199 chars): ";
    cin.getline(msg, 200);

    Query q;
    q.queryId = getNextQueryId();
    q.studentRoll = studentRoll;
    q.facultyId = facultyId;
    std::strncpy(q.message, msg, sizeof(q.message));
    q.message[sizeof(q.message) - 1] = '\0';
    q.reply[0] = '\0';
    std::strncpy(q.status, "PENDING", sizeof(q.status));
    q.status[sizeof(q.status) - 1] = '\0';

    ofstream outfile;
    outfile.open("Queries.txt", ios::app | ios::binary);
    if (outfile.fail())
    {
        cout << "\nTHE FILE COULD NOT BE OPENED...";
        cout << "\npress enter to continue...";
        cin.get();
        return;
    }
    outfile.write(reinterpret_cast<char *>(&q), sizeof(Query));
    outfile.close();
    cout << "\nQuery sent successfully. Your Query ID is: " << q.queryId << "\n";
    cout << "\npress enter to continue...";
    cin.get();
}

void studentViewQueries(int studentRoll)
{
    system("cls");
    cout << "\n\n\t\t\t\t========== MY QUERIES ==========" << endl;
    ifstream infile;
    infile.open("Queries.txt", ios::binary);
    if (infile.fail())
    {
        cout << "\nNo queries found." << endl;
        cout << "\npress enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    Query q;
    bool any = false;
    while (infile.read(reinterpret_cast<char *>(&q), sizeof(Query)))
    {
        if (q.studentRoll == studentRoll)
        {
            cout << "\n----------------------------------------------\n";
            cout << "Query ID   : " << q.queryId << "\n";
            cout << "Faculty Id : " << q.facultyId << "\n";
            cout << "Status     : " << q.status << "\n";
            cout << "Message    : " << q.message << "\n";
            if (std::strlen(q.reply) > 0)
                cout << "Reply      : " << q.reply << "\n";
            any = true;
        }
    }
    infile.close();
    if (!any)
    {
        cout << "\nNo queries found." << endl;
    }
    cout << "\npress enter to continue...";
    cin.ignore();
    cin.get();
}

void facultyViewQueries(int facultyId)
{
    system("cls");
    cout << "\n\n\t\t\t\t========== STUDENT QUERIES ==========" << endl;
    ifstream infile;
    infile.open("Queries.txt", ios::binary);
    if (infile.fail())
    {
        cout << "\nNo queries available." << endl;
        cout << "\npress enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    Query q;
    bool any = false;
    while (infile.read(reinterpret_cast<char *>(&q), sizeof(Query)))
    {
        if (q.facultyId == facultyId)
        {
            cout << "\n----------------------------------------------\n";
            cout << "Query ID     : " << q.queryId << "\n";
            cout << "Student Roll : " << q.studentRoll << "\n";
            cout << "Status       : " << q.status << "\n";
            cout << "Message      : " << q.message << "\n";
            if (std::strlen(q.reply) > 0)
                cout << "Reply        : " << q.reply << "\n";
            any = true;
        }
    }
    infile.close();
    if (!any)
    {
        cout << "\nNo queries available." << endl;
    }
    cout << "\npress enter to continue...";
    cin.ignore();
    cin.get();
}

void facultyReplyToQuery(int facultyId)
{
    system("cls");
    cout << "\n\n\t\t\t\t========== REPLY TO QUERY ==========" << endl;
    ifstream check;
    check.open("Queries.txt", ios::binary);
    if (check.fail())
    {
        cout << "\nNo queries available." << endl;
        cout << "\npress enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    Query q;
    bool anyOpen = false;
    while (check.read(reinterpret_cast<char *>(&q), sizeof(Query)))
    {
        if (q.facultyId == facultyId)
        {
            cout << "\n[ID: " << q.queryId << "] Roll: " << q.studentRoll << ", Status: " << q.status << "\n";
            cout << "Message: " << q.message << "\n";
            if (std::strlen(q.reply) > 0)
                cout << "Reply: " << q.reply << "\n";
            anyOpen = true;
        }
    }
    check.close();
    if (!anyOpen)
    {
        cout << "\nNo queries available." << endl;
        cout << "\npress enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "\nEnter Query ID to manage (or 0 to cancel): ";
    int qid;
    cin >> qid;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    if (qid == 0)
        return;
    cin.ignore();

    cout << "\nChoose action: \n";
    cout << "  1) Accept (mark ACCEPTED)\n";
    cout << "  2) Decline (mark DECLINED)\n";
    cout << "  3) Reply (mark REPLIED)\n";
    cout << "Enter choice: ";
    char action;
    cin >> action;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore();

    char rep[200] = {0};
    if (action == '3')
    {
        cout << "Enter reply (max 199 chars): ";
        cin.getline(rep, 200);
    }

    fstream io;
    io.open("Queries.txt", ios::binary | ios::in | ios::out);
    if (io.fail())
    {
        cout << "\nTHE FILE COULD NOT BE OPENED...";
        cout << "\npress enter to continue...";
        cin.get();
        return;
    }
    bool updated = false;
    while (!io.eof() && !updated)
    {
        streampos pos = io.tellg();
        io.read(reinterpret_cast<char *>(&q), sizeof(Query));
        if (!io)
            break;
        if (q.queryId == qid && q.facultyId == facultyId)
        {
            if (action == '1')
            {
                std::strncpy(q.status, "ACCEPTED", sizeof(q.status));
                q.status[sizeof(q.status) - 1] = '\0';
            }
            else if (action == '2')
            {
                std::strncpy(q.status, "DECLINED", sizeof(q.status));
                q.status[sizeof(q.status) - 1] = '\0';
            }
            else if (action == '3')
            {
                std::strncpy(q.reply, rep, sizeof(q.reply));
                q.reply[sizeof(q.reply) - 1] = '\0';
                std::strncpy(q.status, "REPLIED", sizeof(q.status));
                q.status[sizeof(q.status) - 1] = '\0';
            }
            io.seekp(pos);
            io.write(reinterpret_cast<char *>(&q), sizeof(Query));
            updated = true;
        }
    }
    io.close();
    if (updated)
    {
        cout << "\nReply sent successfully." << endl;
    }
    else
    {
        cout << "\nQuery not found." << endl;
    }
    cout << "\npress enter to continue...";
    cin.get();
}

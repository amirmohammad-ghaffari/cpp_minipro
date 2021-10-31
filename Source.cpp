#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

struct Student
{
    string first_name;
    string last_name;
    string id;
    double grade;
};

bool CheckFile(fstream &);
void ChangeGrade(vector<Student> &, string, double);
bool ReadFile(vector <Student> &, fstream &);
void WriteFile(vector <Student> &, fstream &);

int main()
{
    cout << setprecision(2) << fixed << setfill('0');
    fstream myfile("C:/Users/Ahmad/Desktop/CPP/Info.txt", ios::in | ios::out);
    vector <Student> all;
    if (ReadFile(all, myfile))
    {
        ChangeGrade(all, "1372969291", 19.99);
        ChangeGrade(all, "6439169183", 9.75);
        ChangeGrade(all, "8192667246", 0);
    }
    WriteFile(all, myfile);
    myfile.close();
    return 0;
}

bool CheckFile(fstream &mf)
{
    if (!mf)
    {
        cerr << "File not found!" << endl;
        return false;
    }
    return true;
}

void ChangeGrade(vector<Student> &all_s, string s_id, double s_grade)
{
    for(auto &temp : all_s)
    {
        if (temp.id == s_id)
        {
            temp.grade = s_grade;
        }
    }
}

bool ReadFile(vector <Student> &all_s, fstream & myfile)
{
    if (CheckFile(myfile))
    {
        Student mystudent;
        for (size_t i = 0; i < 30; i++)
        {
            myfile >> mystudent.first_name;
            myfile >> mystudent.last_name;
            myfile >> mystudent.id;
            myfile >> mystudent.grade;
            all_s.push_back(mystudent);
        }
        return true;
    }
    else
    {
        return false;
    }
}

void WriteFile(vector <Student> &all_s, fstream &myfile)
{
    myfile << setprecision(2) << fixed << setfill('0');
    for(auto temp : all_s)
    {
        myfile << temp.first_name << " " << temp.last_name << " " <<
            temp.id << " " << setw(5) << temp.grade << endl;
    }
}

/*
    myfile << setprecision(2) << fixed << setfill('0');
    srand(time(0));
    for (size_t i = 0; i < 30; i++)
    {
        string first_name = "";
        string last_name = "";
        string id = "";
        double avg = 0;
        char flag;
        for (size_t i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                flag = static_cast<char>(rand() % 26 + 65);
                first_name += flag;
            }
            else
            {
                flag = static_cast<char>(rand() % 26 + 97);
                first_name += flag;
            }
        }
        for (size_t i = 0; i < 7; i++)
        {
            if (i == 0)
            {
                flag = static_cast<char>(rand() % 26 + 65);
                last_name += flag;
            }
            else
            {
                flag = static_cast<char>(rand() % 26 + 97);
                last_name += flag;
            }
        }
        for (size_t i = 0; i < 10; i++)
        {
            flag = static_cast<char>(rand() % 10 + 48);
            id += flag;
        }

        avg = rand() % 21;
        if (avg != 20)
        {
            int x = rand() % 100;
            double y = x / 100.0;
            avg += y;
        }
        myfile << first_name << " " << last_name << " " <<
            id << " " << setw(5) << avg << endl;
    }
*/
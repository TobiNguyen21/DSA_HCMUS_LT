#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a struct to represent a student
struct Student
{
    string name;
    double grade;
};

// Define a struct to represent a class
struct Class
{
    string className;
    int capacity;
    vector<Student> students;
    int count;
};

// add class
void addClass(int classNum, vector<Class> &classes)
{
    for (int i = 0; i < classNum; i++)
    {
        Class newClass;
        cout << "\n--------------------------------------------------------\n";
        cout << "class " << i + 1 << endl;
        cout << "Class name: ";
        cin.ignore();
        getline(cin, newClass.className);
        cout << "Capacity: ";
        cin >> newClass.capacity;

        // cout << "Student: ";
        for (int j = 0; j < newClass.capacity; j++)
        {
            Student newStudent;
            cout << "\nStudent Name " << j + 1 << ": ";
            cin.ignore();
            getline(cin, newStudent.name);
            cout << "Grade: ";
            cin >> newStudent.grade;
            newClass.students.push_back(newStudent);
        }
        classes.push_back(newClass);
    }
}

// print class with grade > 8 and student >5
void printClass(int classNum, vector<Class> &classes)
{
    for (int i = 0; i < classNum; i++)
    {
        int count = 0;
        for (int j = 0; j < classes.at(i).capacity; j++)
        {
            if (classes.at(i).students.at(j).grade > 8)
            {
                count += 1;
                if (count > 5)
                {
                    cout << classes.at(i).className << " ";
                    break;
                }
            }
        }
    }
}

// class with the largest capacity
string maxCapacityClass(int classNum, vector<Class> &classes)
{
    int maxCapacity = classes.at(0).capacity;
    for (int i = 0; i < classNum; i++)
    {
        if (classes.at(i).capacity > maxCapacity)
        {
            maxCapacity = classes.at(i).capacity;
        }
    }

    for (int i = 0; i < classNum; i++)
    {
        if (classes.at(i).capacity == maxCapacity)
        {
            return classes.at(i).className;
        }
    }
    return "";
}

// class with the smallest capacity
string minCapacityClass(int classNum, vector<Class> &classes)
{
    int minCapacity = classes.at(0).capacity;
    for (int i = 0; i < classNum; i++)
    {
        if (classes.at(i).capacity < minCapacity)
        {
            minCapacity = classes.at(i).capacity;
        }
    }

    for (int i = 0; i < classNum; i++)
    {
        if (classes.at(i).capacity == minCapacity)
        {
            return classes.at(i).className;
        }
    }
    return "";
}

int findMaxGrade(int classNum, vector<Class> &classes)
{
    int maxGrade = 0;
    for (int i = 0; i < classNum; i++)
    {
        for (int j = 0; j < classes.at(i).capacity; j++)
        {
            if (classes.at(i).students.at(j).grade > maxGrade)
            {
                maxGrade = classes.at(i).students.at(j).grade;
            }
        }
    }
    return maxGrade;
}

// The student with the highest grade
Student studentWithMaxGrade(int maxGrade, int classNum, vector<Class> &classes)
{

    for (int i = 0; i < classNum; i++)
    {
        for (int j = 0; j < classes.at(i).capacity; j++)
        {
            if (classes.at(i).students.at(j).grade == maxGrade)
            {
                return classes.at(i).students.at(j);
            }
        }
    }
    return {};
}

// Class with the student has max garde
Class findClassMaxGrade(int maxGrade, int classNum, vector<Class> &classes)
{
    int max = 0;
    for (int i = 0; i < classNum; i++)
    {
        classes.at(i).count = 0;
        for (int j = 0; j < classes.at(i).capacity; j++)
        {
            if (classes.at(i).students.at(j).grade == maxGrade)
            {
                classes.at(i).count += 1;
            }
        }
    }

    for (int i = 0; i < classNum; i++)
    {
        if (classes.at(i).count > max)
        {
            max = classes.at(i).count;
        }
    }

    for (int i = 0; i < classNum; i++)
    {
        if (classes.at(i).count == max)
        {
            return classes.at(i);
        }
    }

    return {};
}

int main()
{
    int classNum;
    vector<Class> classes;

    cout << "Class Numbers: ";
    cin >> classNum;

    // a Enter the list of classes
    addClass(classNum, classes);

    cout << "\n--------------------------------------------------------";
    // b
    cout << "\nclass with 5 excellent students :";
    printClass(classNum, classes);

    // // c
    cout << "\nclass with the largest capacity: ";
    cout << maxCapacityClass(classNum, classes);

    // // d
    cout << "\nclass with the smallest capacity: ";
    cout << minCapacityClass(classNum, classes);

    // // e
    int maxGrade = findMaxGrade(classNum, classes);
    cout << "\nThe student with the highest grade: ";
    cout << studentWithMaxGrade(maxGrade, classNum, classes).name << " with grade: " << studentWithMaxGrade(maxGrade, classNum, classes).grade;

    // f
    cout << "\nClass with the student has max garde: ";
    cout << findClassMaxGrade(maxGrade, classNum, classes).className;

    return 0;
}

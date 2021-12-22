#ifndef STUDENT
#define STUDENT

#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ios>

// Define
enum RankedAcademy
{
    Excellent,
    VeryGood,
    Good,
    Average,
    BelowAverage,
};

enum Subject
{
    MATH,
    PHYSICS,
    CHEMISTRY,
    AVERAGESCORE
};

struct StudentData
{
    char studentName[50], studentID[50];
    float mathScore, physicsScore, chemistryScore, averageScore;
    RankedAcademy rankedAcademy;
};

// Setup class Student
class Student
{
public:
    // Constructor
    Student()
    {
        strcpy(this->studentData.studentID, "");
        strcpy(this->studentData.studentName, "");
        this->studentData.mathScore = 0;
        this->studentData.physicsScore = 0;
        this->studentData.chemistryScore = 0;
        this->studentData.averageScore = 0;
        this->studentData.rankedAcademy = Excellent;
    };
    Student(char studentID[50], char studentName[50], float mathScore, float physicsScore, float chemistryScore)
    {
        strcpy(this->studentData.studentID, studentID);
        strcpy(this->studentData.studentName, studentName);
        this->studentData.mathScore = mathScore;
        this->studentData.physicsScore = physicsScore;
        this->studentData.chemistryScore = chemistryScore;
        this->studentData.averageScore = 0;
        this->studentData.rankedAcademy = Excellent;
        // this->calcScore();
    }

    Student(StudentData studentData)
    {
        studentData.averageScore = (studentData.averageScore) ? studentData.averageScore : 0;
        studentData.rankedAcademy = (studentData.rankedAcademy) ? studentData.rankedAcademy : Excellent;
        this->studentData = studentData;
        // this->calcScore();
    }

    // Setter by reference
    void setStudent(char studentID[50], char studentName[50], float mathScore, float physicsScore, float chemistryScore)
    {
        strcpy(this->studentData.studentID, studentID);
        strcpy(this->studentData.studentName, studentName);
        this->studentData.mathScore = mathScore;
        this->studentData.physicsScore = physicsScore;
        this->studentData.chemistryScore = chemistryScore;
        // this->calcScore();
    }

    // Setter by StudentData
    void setStudent(StudentData studentData)
    {
        this->studentData = studentData;
        // this->calcScore();
    }

    // Getter
    StudentData getStudent()
    {
        return this->studentData;
    }

    // Print student data
    void printStudent()
    {
        std::string RankLabels[5] = {"Xuat sac", "Kha", "Trung binh", "Yeu", "Kem"};
        std::cout << std::setw(10) << this->studentData.studentID;
        std::cout << std::setw(20) << this->studentData.studentName;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << this->studentData.mathScore;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << this->studentData.physicsScore;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << this->studentData.chemistryScore;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << this->studentData.averageScore;
        std::cout << std::setw(15) << RankLabels[this->studentData.rankedAcademy] << std::endl;
        std::cout << std::endl;
    }

    // Calculate average score
    void calcScore()
    {
        StudentData data = this->getStudent();
        this->studentData.averageScore = (data.mathScore + data.physicsScore + data.chemistryScore) / 3;
        this->studentData.rankedAcademy = this->calcRankedAcademy(this->studentData.averageScore);
    }

private:
    StudentData studentData;

    RankedAcademy calcRankedAcademy(float averageScore)
    {
        RankedAcademy rank = Excellent;
        if (averageScore >= 9)
            rank = Excellent;
        else if (averageScore >= 8)
            rank = VeryGood;
        else if (averageScore >= 7)
            rank = Good;
        else if (averageScore >= 5)
            rank = Average;
        else
            rank = BelowAverage;

        return rank;
    }
};

// Setup class StudentList
class StudentList
{
public:
    // Constructor
    StudentList()
    {
        this->studentCount = 0;
        this->studentList.clear();
    }

    // Methods
    void clearStudentList()
    {
        this->studentCount = 0;
        this->studentList.clear();
    }

    // Add a student to the list
    void addStudent(Student student)
    {
        std::cout << "Adding student " << student.getStudent().studentName << " to list" << std::endl;
        this->studentList.push_back(student);
        this->studentCount++;
    }

    // Add a series of students to the list
    void addStudents(StudentList studentList)
    {
        for (int i = 0; i < studentList.getStudentCount(); i++)
        {
            this->addStudent(studentList.getStudent(i));
        }
    }

    //Get students list size
    int getStudentCount()
    {
        return this->studentCount;
    }

    // Get a student from the list
    StudentData getStudent(int index)
    {
        if (index < 0 || index >= this->studentCount)
            return StudentData();
        return this->studentList[index].getStudent();
    }

    // Remove a student from the list
    void removeStudent(int index)
    {
        if (index < 0 || index >= this->studentCount)
            return;
        this->studentList.erase(this->studentList.begin() + index);
        this->studentCount--;
    }
    // Calculate average score of all students
    void calcScore()
    {
        for (int i = 0; i < this->studentList.size(); i++)
            this->studentList[i].calcScore();
    }

    // Print all students in the list
    void printStudentList()
    {
        std::system("cls");
        std::cout << "=================================== DANH SACH HOC SINH ================================" << std::endl;
        std::cout << "---------------------------------------------------------------------------------------" << std::endl;
        std::cout << std::setw(10) << "Ma so";
        std::cout << std::setw(15) << "Ten";
        std::cout << std::setw(15) << "Toan";
        std::cout << std::setw(9) << "Ly";
        std::cout << std::setw(10) << "Hoa";
        std::cout << std::setw(10) << "TB";
        std::cout << std::setw(15) << "Xep loai" << std::endl;
        std::cout << "---------------------------------------------------------------------------------------" << std::endl;
        for (int i = 0; i < this->studentList.size(); i++)
        {
            this->studentList[i].printStudent();
        }
        std::cout << "---------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Danh sach co: " << std::setw(10) << this->studentCount << " hoc sinh" << std::endl;
        std::cout << std::endl;
    }

protected:
    std::vector<Student> studentList;
    int studentCount;
};

class StudentManager : public StudentList
{
public:
    // Constructor
    StudentManager()
    {
        StudentList();
    }

    // Method
    // Top 10 students
    StudentList getTop10(Subject subject)
    {
        StudentList top10;
        for (int i = 0; i < this->getStudentCount(); i++)
        {
            if (subject == CHEMISTRY)
            {
                if (this->getStudent(i).chemistryScore >= 8)
                    top10.addStudent(this->getStudent(i));
            }
            else if (subject == PHYSICS)
            {
                if (this->getStudent(i).physicsScore >= 8)
                    top10.addStudent(this->getStudent(i));
            }
            else if (subject == MATH)
            {
                if (this->getStudent(i).mathScore >= 8)
                    top10.addStudent(this->getStudent(i));
            }
            else if (subject == AVERAGESCORE)
            {
                if (this->getStudent(i).averageScore >= 8)
                    top10.addStudent(this->getStudent(i));
            }
        }
        return top10;
    }

    // Sort by average score
    void sortStudentList()
    {
        for (int i = 0; i < this->studentList.size(); i++)
            for (int j = i + 1; j < this->studentList.size(); j++)
                if (this->studentList[i].getStudent().averageScore > this->studentList[j].getStudent().averageScore)
                {
                    Student temp = this->studentList[i];
                    this->studentList[i] = this->studentList[j];
                    this->studentList[j] = temp;
                }
    }

    // Remove a student from the list if subject score is below max_value
    void removeStudentsWithCondition(Subject subject, float max_value)
    {
        for (int i = 0; i < this->getStudentCount(); i++)
        {
            if (subject == CHEMISTRY)
            {
                if (this->getStudent(i).chemistryScore <= max_value)
                    this->removeStudent(i);
            }
            else if (subject == PHYSICS)
            {
                if (this->getStudent(i).physicsScore <= max_value)
                    this->removeStudent(i);
            }
            else if (subject == MATH)
            {
                if (this->getStudent(i).mathScore <= max_value)
                    this->removeStudent(i);
            }
            else if (subject == AVERAGESCORE)
            {
                if (this->getStudent(i).averageScore <= max_value)
                    this->removeStudent(i);
            }
        }
    }

    // Save student list to file
    void saveStudentList(const char *filePath)
    {
        std::fstream file;
        file.open(filePath, std::ios::out | std::ios::binary | std::ios::trunc);
        StudentData studentData;

        for (int i = 0; i < this->getStudentCount(); i++)
        {
            studentData = this->getStudent(i);
            file.write(reinterpret_cast<char *>(&studentData), sizeof(studentData));
        }
        file.close();
    }

    // Load student list from file
    void readStudentList(const char *filePath)
    {
        std::fstream file;
        file.open(filePath, std::ios::in | std::ios::binary | std::ios::ate);

        if (!file.good())
        {
            std::cout << "File not found!" << std::endl;
            return;
        }

        StudentData studentData;

        this->clearStudentList();
        int size = file.tellg();
        int n = size / sizeof(StudentData);
        for (int i = 0; i < n; i++)
        {
            file.seekg(i * sizeof(StudentData));
            file.read(reinterpret_cast<char *>(&studentData), sizeof(studentData));
            this->addStudent(studentData);
        }

        file.close();
    }
};

#endif
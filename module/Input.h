#ifndef INPUT
#define INPUT
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include "../class/Student.h"
#include "./Validate.h"


// Input students' information then return a StudentList object
STUDENT::StudentList addStudentList()
{
    // Initialize a StudentList object
    STUDENT::StudentList studentList;
    int n;
    int count = 1;

    std::system("cls");
    std::cout << "Trinh nhap danh sach hoc sinh" << std::endl;
    n = Validate::validateNumber<int>("Nhap so luong hoc sinh: ", "Nhap lai so luong hoc sinh");

    // Loop through to add students' information
    while (count <= n)
    {
        STUDENT::StudentData studentData;

        // Input student's information
        std::system("cls");
        std::cout << "Nhap thong tin hoc sinh thu " << count << ": " << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

        strcpy(studentData.studentID, Validate::validateString("Ma hoc sinh: ", "Ma hoc sinh khong hop le"));
        strcpy(studentData.studentName, Validate::validateString("Ten hoc sinh: ", "Ten hoc sinh khong hop le"));
        studentData.mathScore = Validate::ValidateScore("Diem toan: ", "Diem toan khong hop le");
        studentData.physicsScore = Validate::ValidateScore("Diem ly: ", "Diem ly khong hop le");
        studentData.chemistryScore = Validate::ValidateScore("Diem hoa: ", "Diem hoa khong hop le");

        // Review student's information
        std::system("cls");
        std::cout << "Nhap xong thong tin hoc sinh thu " << count << ": " << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Ho ten: " << studentData.studentName << std::endl;
        std::cout << "Ma so: " << studentData.studentID << std::endl;
        std::cout << "Diem toan: " << studentData.mathScore << std::endl;
        std::cout << "Diem ly: " << studentData.physicsScore << std::endl;
        std::cout << "Diem hoa: " << studentData.chemistryScore << std::endl;

        // Navigate: Tiep tuc, Nhap lai, Thoat
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Nhap tiep / Nhap lai / Thoat (y/n/q): ";
        char c;
        std::cin >> c;
        if (c == 'y' || c == 'Y')
        {
            // Add Student
            STUDENT::Student student = STUDENT::Student(studentData);
            studentList.addStudent(student);
            count++;
            continue;
        }
        if (c == 'n' || c == 'N')
            continue;
        else
            break;
    }
    std::system("cls");
    return studentList;
}

#endif
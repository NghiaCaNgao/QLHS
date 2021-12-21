#ifndef INPUT
#define INPUT
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include "../class/Student.h"
#include "./Validate.h"

// float validateFloat(const char *title, const char *errortext = "")
// {
//     bool isValid = true;
//     do
//     {
//         try
//         {
//             isValid = true;
//             std::cout << title;
//             float score = 0;
//             std::cin >> score;
//             if (std::cin.fail())
//             {
//                 std::cin.clear();
//                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                 throw std::invalid_argument("Nhan vao khong phai mot so");
//             }
//             if (score < 0 || score > 10)
//                 throw std::invalid_argument(errortext);

//             return (score);
//         }
//         catch (std::invalid_argument &e)
//         {
//             std::cout << e.what() << std::endl;
//             std::cout << errortext << std::endl;
//             std::cout << "Input khong hop le. Nhap lai. " << std::endl;
//             isValid = false;
//         }
//     } while (!isValid);
// }

char *validateString(const char *title, const char *errortext = "")
{
    bool isValid = true;
    do
    {
        try
        {
            std::cout << title;
            char *input;
            while (iswspace(std::cin.peek()))
                std::cin.ignore();
            std::cin.get(input, 50);
            return input;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << errortext << std::endl;
            std::cout << "Input khong hop le. Nhap lai. " << std::endl;
            isValid = false;
        }
    } while (!isValid);
}

STUDENT::StudentList addStudentList()
{
    // Khoi tao gia tri ban dau
    STUDENT::StudentList studentList;
    int n;
    int count = 1;

    std::system("cls");
    std::cout << "Trinh nhap danh sach hoc sinh" << std::endl;
    n = Validate::validateNumber<int>("Nhap so luong hoc sinh: ", "Nhap lai so luong hoc sinh");

    // Vong lap nhap du lieu
    while (count <= n)
    {
        STUDENT::StudentData studentData;

        // Nhap thong tin hoc sinh
        std::system("cls");
        std::cout << "Nhap thong tin hoc sinh thu " << count << ": " << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

        strcpy(studentData.studentID, validateString("Ma hoc sinh: ", "Ma hoc sinh khong hop le"));
        strcpy(studentData.studentName, validateString("Ten hoc sinh: ", "Ten hoc sinh khong hop le"));
        studentData.mathScore = Validate::ValidateScore("Diem toan: ", "Diem toan khong hop le");
        studentData.physicsScore = Validate::ValidateScore("Diem ly: ", "Diem ly khong hop le");
        studentData.chemistryScore = Validate::ValidateScore("Diem hoa: ", "Diem hoa khong hop le");

        // Xem lai du lieu vua nhap
        std::system("cls");
        std::cout << "Nhap xong thong tin hoc sinh thu " << count << ": " << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Ho ten: " << studentData.studentName << std::endl;
        std::cout << "Ma so: " << studentData.studentID << std::endl;
        std::cout << "Diem toan: " << studentData.mathScore << std::endl;
        std::cout << "Diem ly: " << studentData.physicsScore << std::endl;
        std::cout << "Diem hoa: " << studentData.chemistryScore << std::endl;

        // Lua chon dieu huong: Tiep tuc, Nhap lai, Thoat
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
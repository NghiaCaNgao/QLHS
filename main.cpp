#include <bits/stdc++.h>
#include "./class/Student.h"
#include "./module/Input.h"
#include "./module/Validate.h"

// Defind
const char *filePath = "./Sv1.dat";

// Initialize value
STUDENT::StudentManager studentManager;

void Input()
{
    studentManager.clearStudentList();
    studentManager.addStudents(INPUT::addStudentList());
    studentManager.printStudentList();
    std::system("pause");
}

void CalcAverageScore()
{
    studentManager.calcScore();
    studentManager.printStudentList();
    std::system("pause");
}

void PrintstudentList()
{
    studentManager.printStudentList();
    std::system("pause");
}

void PrintstudentListAfterSorting()
{
    studentManager.sortStudentList();
    studentManager.printStudentList();
    std::system("pause");
}

void Top10ChemistryScore()
{
    STUDENT::StudentList top10 = studentManager.getTop10(CHEMISTRY);
    top10.printStudentList();
    std::system("pause");
}

void AddStudent()
{
    studentManager.addStudents(INPUT::addStudentList());
    studentManager.printStudentList();
    std::system("pause");
}

void RemoveStudentsWithCondition()
{
    float max_value;
    std::system("cls");
    std::cin >> max_value;
    studentManager.removeStudentsWithCondition(PHYSICS, max_value);
    studentManager.printStudentList();
    std::system("pause");
}

void SaveStudentList()
{
    std::system("cls");
    studentManager.saveStudentList(filePath);
    std::cout << "Save into " << filePath << std::endl;
    std::cout << "Save student list successfully!" << std::endl;
    std::system("pause");
}

void ReadStudentList()
{
    std::system("cls");
    studentManager.readStudentList(filePath);
    studentManager.printStudentList();
    std::system("pause");
}

bool action(int choice)
{
    switch (choice)
    {
    case 1:
    {
        Input();
        break;
    }
    case 2:
    {
        CalcAverageScore();
        break;
    }
    case 3:
    {
        PrintstudentList();
        break;
    }
    case 4:
    {
        PrintstudentListAfterSorting();
        break;
    }
    case 5:
    {
        Top10ChemistryScore();
        break;
    }
    case 6:
    {
        AddStudent();
        break;
    }
    case 7:
    {
        RemoveStudentsWithCondition();
        break;
    }
    case 8:
    {
        SaveStudentList();
        break;
    }
    case 9:
    {
        ReadStudentList();
        break;
    }
    case 10:

    {
        return true;
    }
    default:
    {
        return false;
    }
    }
    return false;
}

void menu()
{
    int choice = 10;
    do
    {
        system("cls");
        std::cout << "======== CHUONG TRINH QUAN LY HOC SINH ========" << std::endl;
        std::cout << "1. Nhap danh sach hoc sinh" << std::endl;
        std::cout << "2. Tinh diem trung binh cho cac hoc sinh" << std::endl;
        std::cout << "3. In danh sach hoc sinh" << std::endl;
        std::cout << "4. In danh sach hoc sinh sau khi sap xep" << std::endl;
        std::cout << "5. Danh sach sinh vien co diem hoa cao nhat" << std::endl;
        std::cout << "6. Them hoc sinh" << std::endl;
        std::cout << "7. Xoa danh sach cac hoc sinh co diem ly nho hon diem duoc nhap" << std::endl;
        std::cout << "8. Luu danh sach" << std::endl;
        std::cout << "9. Doc danh sach" << std::endl;
        std::cout << "10. Thoat" << std::endl;
        std::cout << "===============================================" << std::endl;
        // std::cin >> choice;
        choice = Validate::validateNumber<int>("Nhap lua chon cua ban: ", "Lua chon khong hop le. Nhap lai: ");
    } while (!action(choice));
}

int main()
{
    menu();
}
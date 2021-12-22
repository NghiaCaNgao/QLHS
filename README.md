# Chương trình quản lý học sinh

> **Sinh viên thực hiện: BMD**  
> **Ma Sinh vien: 00000001**

## :star: Cách sử dụng

1. Clone repo
   ```shell
   $ git clone https://github.com/NghiaCaNgao/QLHS.git
   ```
2. Change dir to the cloned repo
   ```shell
   $ cd QLHS
   ```
3. Compile
   ```shell
   $ g++ main.cpp -o main
   ```
4. Run
   ```shell
   $ main.exe
   ```

## Tổ chức files

Được chia làm các phần chính như sau:

- `main.cpp` : File chính của chương trình, tạo menu và điều hướng
- **/class**
  - `Student.h`: Chứa các Object Classes
- **/module**
  - `Input.h`: Chứa các functions nhập liệu
  - `Validate.h`: Chưa các functions kiểm tra nhập liệu

## Cấu trúc dữ liệu

Chương trình được tổ chức thành các Module và các Object classes.

```c++
struct StudentData{};
```

```c++
class Student{};
class StudentList{}
class StudentManage : StudentList{}
```

## Cấu trúc classes

### Struct

Khối `Struct` lưu trữ các trường dữ liệu của học sinh:

```c++
struct StudentData
{
    char studentName[50], studentID[50];
    float mathScore, physicsScore, chemistryScore, averageScore;
    RankedAcademy rankedAcademy;
};
```

### Enum

Enum lưu trữ các value cố định

```c++
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
```

### Detail

**Student**

| Methods / Constructors                                                                                                                   | Description                                    |
| ---------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------- |
| `Student()` [public constructor]()                                                                                                       | Khởi tạo `Stduent Object` với các giá trị rỗng |
| `Student(char studentID[50], char studentName[50], float mathScore, float physicsScore, float chemistryScore)` [public constructor]()    | Khởi tạo với các tham chiếu                    |
| `Student(StudentData studentData)` [public constructor]()                                                                                | Khởi tạo với `StudentData`                     |
| `void setStudent(char studentID[50], char studentName[50], float mathScore, float physicsScore, float chemistryScore)` [public method]() | Đặt giá trị mới cho `Stduent Object`           |
| `void setStudent(StudentData studentData)` [public method]()                                                                             | Đặt giá trị bằng `StudentData`                 |
| `StudentData getStudent()` [public method]()                                                                                             | Trả về giá trị của `Stduent Object` hiện tại   |
| `void printStudent()` [public method]()                                                                                                  | In ra giá trị của `Stduent Object` hiện tại    |
| `void calcScore()`                                                                                                                       | Tính toán điểm trung bình và xếp hạng          |
| `StudentData studentData `                                                                                                               | Biến lưu trữ thông tin                         |
| `RankedAcademy calcRankedAcademy(float averageScore)`                                                                                    | Xếp hạng học tập                               |

**StudentList**
| Methods / Constructors | Description |
| ---------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------- |
| `StudentList()` | Khởi tạo đối tượng Student List rỗng
| `clearStudentList() ` | Xóa trắng đối tượng |
| `addStudent(Student student) ` | Thêm một đối tượng Student vào Student List |
| `addStudents(StudentList studentList) ` | Thêm một danh sách Stduent List vào student List hiện có |
| `getStudentCount()` | Lấy số lượng student trong StduentList
| `getStudent(int index) ` | Lấy một student qua index |
| `removeStudent(int index)` | Xóa mọt đối tượng student trong studentList|
| `void calcScore()` | Tính điểm trung bình cho toàn danh sách |
| `printStudentList()` | In danh sách |
| `std::vector<Student> studentList` | Property|
| `int studentCount` | Property |

** StudentManager **
| Methods / Constructors | Description |
| ---------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------- |
| `StudentManager()` | Khởi tạo một danh sách quản lý |
| ` StudentList getTop10(Subject subject)` | Lấy danh sách top 10 theo môn |
| `void sortStudentList()` | Sort Danh sách theo điểm trung bình |
| ` void removeStudentsWithCondition(Subject subject, float max_value)` | Xóa các họ sinh có điểm môn nhỏ hơn max_value|
| `void saveStudentList(const char *filePath)` | Lưu danh sách file |
| `void readStudentList(const char *filePath)` | Đọc danh sách từ file |

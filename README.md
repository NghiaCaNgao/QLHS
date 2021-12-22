# Chương trình quản lý học sinh

>**Sinh viên thực hiện: BMD**  
**Ma Sinh vien: 00000001**

---
## Tổ chức files
Được chia làm phần chính:
- `main.cpp` : File chính của chương trình, tạo menu và điều hướng
- **/class**
    -  `Student.h`: Chứa các Object Classes
- **/module**
    -   `Input.h`: Chứa các functions nhập liệu
    -   `Validate.h`: Chưa các functions kiểm tra nhập liệu
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
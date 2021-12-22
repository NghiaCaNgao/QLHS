# Chương trình quản lý học sinh

>**Sinh viên thực hiện: BMD**  
**Ma Sinh vien: 00000001**

## :start: Cách sử dụng
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

### Detail
**Student**

| Methods / Constructors      | Description                                 |
|-----------------------------|---------------------------------------------|  
| `Student()` > con > public  | Khởi tạo Stduent Object với các giá trị rỗng |
| `Student(char studentID[50], char studentName[50], float mathScore, float physicsScore, float chemistryScore)` | Khởi tạo với các tham chiếu |
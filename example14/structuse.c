/*结构体*/

#include <stdio.h>
#include <string.h>

// 1. 匿名(无名称)结构体类型并初始化
struct {
  char name[20]; // 人名
  unsigned short age; // 年龄
  char genre[8]; // 性别
} person0 = {"male", 29, "male"},
  person00 = {.name="jenny", .age=20, .genre="female"};

// 2.结构标记的声明
// 结构标记: 是用于标识某种特定结构的名字。仅仅是标记一个名字，这个名字不是实际的struct类型。
struct person {
  char name[20]; // 人名
  unsigned short age; // 年龄
  char genre[8]; // 性别
};

// 声明结构体类型的变量
// person不是类型名，struct person才是; 没有struct的person无意义。person本身不是类型。只是一个标记
struct person person1;
struct person person2;

// 结构标记声明与结构体类型变量声明在一起
struct person2 {
    char name[20];
    unsigned short age;
    char genre[8];
} person3, person4;
// 等价于 struct person2 person3; struct person2 person4;

// 3. 结构类型的定义，结构类型是struct {}
// 利用typeof可以定义结构类型的别名，然后用别名去定义结构类型变量
// Person就是实际的结构struct类型，这与结构标记有本质区别。你可以使用Person类型直接声明struct变量。
// TODO:可以像内置类型那样使用Person，例如可以使用它声明struct结构变量。
typedef struct {
    char name[20];
    unsigned short age;
    char genre[8];
} Person;

Person person5;
Person person6;

// 4.初始化struct变量
// 初始化列表：只可以在声明结构体变量的时候指定
// {"limao", 20, "male"};
// 指定初始化
// {.name =  "michael", .age = 20, .genre = "male"};

// 5. 结构作为参数和返回值
// 返回person2名字对应的结构体类型；参数是person2名字对应的 结构体类型
struct person2 change_person(struct person2 a_person)
{
    struct person2 p; // 新的person2结构体变量     
    strcpy(p.name, a_person.name);
    p.age = a_person.age + 5;
    strcpy(p.genre, a_person.genre);

    return p;
}

// 6. 嵌套的数组和结构
#define FIST_NAME_LEN 10
#define LAST_NAME_LEN 10

struct person_name{
    char first[FIST_NAME_LEN + 1];
    char middle_initial;
    char last[LAST_NAME_LEN + 1];
};

// 学生包含人名的字段
struct student {
    struct person_name name;
    int id, age;
    char sex;
} student1, student2;

// 结构数组：是数组；数组中每个元素都是一个结构体
struct student stu_array[10]; // 定义十个学生结构的数组

// person2结构的数组; 直接初始化
struct person2 person2_arr[2] = 
{
    {"michale", 30, "male"}, 
    {"alisa", 27, "female"}
};

int main(void)
{

    printf("name:%s, age:%d, genre:%s\n", person0.name, person0.age, person0.genre);
    printf("name:%s, age:%d, genre:%s\n", person00.name, person00.age, person00.genre);

    // 对结构的操作（访问、结构字段的赋值）
    // 字符数组不能直接用字符串给数组名赋值
    //person2.name = "lee";
    // FIXME: 为何此处可以对person2这个标记赋值，person2本身也是结构体
    // 因为此处person2本质被认为是一个struct person类型
    strcpy(person2.name, "lee");
    person2.age = 30;
    strcpy(person2.genre, "male");
    printf("name:%s, age:%d, genre:%s\n", person2.name, person2.age, person2.genre);

    // person3 变量才是真正的person2 结构体类型。
    strcpy(person3.name, "lee");
    person3.age = 30;
    strcpy(person3.genre, "male");
    printf("name:%s, age:%d, genre:%s\n", person3.name, person3.age, person3.genre);
    struct person2 p = change_person(person3); 
    printf("name:%s, age:%d, genre:%s\n", p.name, p.age, p.genre);

    // TODO: 复合字面量
    struct person2 p2 = change_person((struct person2){.name="michael", .age=18, .genre="male"}); 
    struct person2 p3 = change_person((struct person2){"alisa", 20, "female"}); 
    printf("name:%s, age:%d, genre:%s\n", p2.name, p2.age, p2.genre);
    printf("name:%s, age:%d, genre:%s\n", p3.name, p3.age, p3.genre);

    return 0;
}



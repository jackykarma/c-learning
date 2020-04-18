/* 指针的高级应用 - 动态内存分配 */

// 动态存储分配
// malloc函数——分配内存块，但是不对内存块进行初始化; void *malloc(size_t size)
// calloc函数——分配内存块，并且对内存块进行清零。为数组分配内存并初始化很好。void *calloc(size_t nmemb, size_t size);
// realloc函数——调整先前分配的内存块大小。void *relloc(void *ptr, size_t size);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// * 符在C语言中的用途有两个：
// 1. 作为声明符：声明指针类型的变量
// 2. 作为运算符：表示间接寻址运算法，只能对地址进行操作，比如p是指针(地址)，*p就是指针所指向的地址空间存储的值。
//  修改*p就是修改指针指向的地址空间存储的值。

#define LENGTH 20

typedef struct {
    int age;
    // 字符数组
    char name[LENGTH + 1];
    // 字符指针
    char *genre;
} Person;

// 声明一个结构体变量
Person person;
// 声明一个结构体指针变量
Person *person_pointer;

int main(void)
{
    // 开辟一个int大小的内存
    // 赋值给一个int类型的指针
    // TODO:void *指针可以转换为任何类型指针，此处是int *指针
    int *intp = malloc(sizeof(int));
    // 间接寻址到该内存，修改存储的值
    *intp = 20;
    printf("intp = %d, address=%p\n", *intp, intp);

    // TODO:void *指针可以转换为任何类型指针，此处是结构Person *指针
    person_pointer = malloc(sizeof(Person));

    person_pointer->age = 30;
    // 数组不支持赋值
    strcpy(person_pointer->name, "michael");
    // 指针可以赋值
    person_pointer->genre = "male";

    printf("age:%d, name=%s, genre=%s, pointer=%p\n", person_pointer->age, person_pointer->name, person_pointer->genre, person_pointer);

    // TODO: 释放内存块后，为何指针打印的值不变，也就是内存被释放，但是内存中的数据并没有被清除。
    //  对free的理解是：指针不再指向之前的内存地址
    //  真正的理解：关于free之后，p的之后为何没有改变，仍然还是这个原先堆空间的这个地址，
    //  原因在于free函数仅仅是将malloc申请的内存释放回去，所谓的释放也就是告诉编译器，这块内存已经使用完毕，可以收回了。
    //  但指针所指向的内存值，并不会发生改变。就可以比方说，你租了一套房子，到期后，房子收回归还房东，而此时你可能还拿着房子的钥匙，
    //  这个时候你虽然可以继续访问这个房子(内存)，但已经不属于你，是非法的。也可能有新的租客入驻更改房子的内置，也可能还是这个样子。
    //  取决于不同的房东(编译器)和租客(内容)。
    free(person_pointer);

    printf("after free memory age:%d, name=%s, genre=%s, pointer=%p\n", person_pointer->age, person_pointer->name,
            person_pointer->genre, person_pointer);

    // TODO: 分配6个int类型元素的int数组，并且初始化为0
    int *arr = calloc(6, sizeof(int));
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    arr[5] = 60;

    for(int i = 0; i < 6; i++)
    {
        printf("array[%d] = %d\n", i, arr[i]);
    }

    // TODO: 重新调整内存; 此函数对原始内存数据的影响；目前不清楚其机制
    arr = realloc(arr, 7);
    arr[6] = 70;

    for(int i = 0; i < 7; i++)
    {
        // 部分元素的值被修改了
        printf("array[%d] = %d\n", i, arr[i]);
    }
}



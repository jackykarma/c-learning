/*指向指针的指针*/
// 用处：当函数的实际参数是指针变量时，有时候会希望函数能通过指针指向别处的方式来改变此变量。而不是要对此变量进行各种赋值(少一层操作灵活的空间)
// 此时，做这项工作就需要用到指向指针的指针。

#include <stdio.h>
#include <stdlib.h>

// int型指针
int x = 20;
int *p;
// 指向int型指针的指针
int **pp;

struct Node {
    int value;
    struct Node *next;
};

// 传入*list与**list的区别
// 传入指针的指针意味着
void add_to_list(struct Node **list, int n);

int main(void)
{
    // p这个指针指向的是x，存储的是x的地址
    p = &x;
    // *pp 间接寻址运算符
    // pp这个指针指向的是指针变量p, 存储的是p的地址。
    pp = &p;
    // *pp是一个指针，也就是p，那么**pp=*(*pp) 一层层间接寻址，结果应该就是p指向的地址的内容20
    int b = **pp + 30;

    printf("b=%d, *p=%d, p=%p, *pp=%p, pp=%p\n", b, *p, p, *pp, pp);

    return 0;
}

void add_to_list(struct Node **list, int n)
{
    struct Node *new_node;

    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(-1);
    }
    new_node->value = n;
    // 对指向指针的指针进行间接寻址运算，得出的是链表的第一个节点的指针
    new_node->next = *list;

    // 改变之前指向旧的链表首结点的指向指向
    // TODO:这个解释了在链表示例中，为何传入的first不能改变的原因。
    *list = new_node;
}

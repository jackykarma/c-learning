/* 链表 */

#include <stdio.h>
#include <stdlib.h>

// 链表的时候不能用typeof，因为结构中的结构找不到, 因为Node在后面;因此采用结构标记.
/*typedef struct {
    int value;
    Node *next;
} Node;*/

struct Node {
    int value;
    struct Node *next; // Node作为此结构体的标记名称，出现在前面因此可以找到
};

// 函数原型
struct Node *add_to_list(struct Node *list, int n);

int main(void)
{
    // 初始链表为空, first定义表示指向链表第一个结点的指针
    struct Node *first = NULL;
    // new_node 总是指向新创建的结点
    struct Node *new_node;
    // 动态分配内存
    new_node = malloc(sizeof(struct Node));
    new_node->value = 50;
    // 在first结点前插入结点
    new_node->next = first;

    // 现在first指针变为了新添加的new_node
    first = new_node;

    // 再创建一个新的结点，从表头插入
    new_node = malloc(sizeof(struct Node));

    new_node->value = 100;
    new_node->next = first;

    first = new_node;

    // FIXME:传入参数first进行，函数中改变first但是却没有效果
    new_node = add_to_list(first, 150);
    // 更新first指针指向的位置
    first = new_node;
    printf("value:%d, %d\n", new_node->value, first->value);

    // 链表遍历查询、搜索
    struct Node *p;
    for (p = first; p != NULL; p = p->next)
    {
        printf("value in linkedlist: %d\n", p->value);
    }
}

/************************************************************************************
 * 添加一个新的结点加入到链表的表头
 * 1. 参数list：指针，指向旧链表中首结点的指针
 * 2. 参数n: 需要存储在新结点中的整数。
 * 返回值: 新插入的结点指针
 * **********************************************************************************/
struct Node *add_to_list(struct Node *list, int n)
{
    struct Node *new_node;

    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(-1);
    }
    new_node->value = n;
    new_node->next = list;
    // 改变first指向
    list = new_node;

    return new_node;
}

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *tmp;
    int     start;

    if (argc == 1)
        return (0);

    // 1. فحص المدخلات باستخدام دالة أحمد
    if (!number_checker(argv, argc))
    {
        printf("Error\n");
        return (1);
    }

    // 2. تحديد نقطة البداية لتجاوز الفلاقات
    start = flags_checker(argv, argc);
    if (start < 0)
        return (1);
    
    // لأن argv[0] هو اسم البرنامج، إذا ما في فلاقات start رح يرجع 0، فلازم نخليه 1
    if (start == 0)
        start = 1;

    // 3. بناء الستاك
    stack_a = build_stack_a(argv, argc, start);

    // 4. طباعة الستاك للتأكد من نجاح العملية
    tmp = stack_a;
    printf("--- Stack A ---\n");
    while (tmp != NULL)
    {
        printf("Value: %d | Index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
    printf("---------------\n");

    return (0);
}

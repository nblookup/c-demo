#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <sys/time.h>

void myFun(int);

void (*funP)(int);

struct student {
    int age;
    char *name;
};

typedef struct student stu_type;

void myFun(int);

void my_callback(void *p);

int test_callback(void(*)(void *));

int main() {
    struct timeval tv;

    printf("Hello, World!\n");

    funP = &myFun;
    (*funP)(20);

    srand((unsigned int) (time(NULL) ^ getpid()));

    int i = rand();

    printf("rand is : %d\n", i);

    extern size_t out;
    out = 5;
    printf("out is: %d\n", out);

    stu_type stu;
    stu.age = 18;
    stu.name = "ni hao.";

    printf("age: %d, name: %s\n", stu.age, stu.name);

    gettimeofday(&tv, NULL);

    test_callback(my_callback);

    int m = 65537;
    printf("and: %d\n", m & 65535);

    printf("sizeof long: %d", sizeof(long));

    return 0;
}

void myFun(int x) {
    printf("myFun is %d\n", x);
}

void my_callback(void *p) {
    printf("pointer is %p\n", p);
    printf("call my_callback...\n");
}

int test_callback(void(callback)(void *)) {
    callback(myFun);
}

size_t out;
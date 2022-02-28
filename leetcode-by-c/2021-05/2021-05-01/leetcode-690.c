#include <stdio.h>
#include "../uthash.h"
#include <stdlib.h>

#define MAXN 2000
/* class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
}; */

typedef struct Employee {
    int id;
    int importance;
    int *subordinates;
}Employee;

int main(int argc, char const *argv[])
{
    Employee* employee = (Employee*)malloc(sizeof(Employee));
    
    employee->id = 1;
    employee->importance = 5;
    int a[2] = {2, 3};
    employee->subordinates = a;
    

    return 0;
}

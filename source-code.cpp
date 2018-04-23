//To Do List Source Code

#include <cstdio>
#include <cstring>
#include "function.h"
using namespace std;

int main()
{
    welcome();

    while(true)
    {
        int a = select();
        if(a == 1) add();
        else if(a == 2) show();
        else if(a == 3) delete_item();
        else if(a == 4) reset();
        else if(a == 5) break;
    }

    return 0;
}

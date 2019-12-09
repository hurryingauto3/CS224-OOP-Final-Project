#include <iostream>
#include <stdlib.h> //for system()
#include <windows.h> //for Sleep() and Beep()

using namespace std;

//timer function
void timer(int h, int m, int s)
{
    for(;;)
    {
        if (h == 0 && m == 0 && s == 0)
        {
            break;
        }
        if (m == 60)
        {
            m = 0;
            h++;
        }
        if (s == 60)
        {
            s = 0;
            m++;
        }
        system("cls");
        cout<<h<<":"<<m<<":"<<s++;
        Sleep(1000);
    }
}

int main()
{
    int h=0;
    int m=0;
    int s=1;
    timer(h,m,s);
}

#include<bits/stdc++.h>
 
using namespace std;
// Program to generate text string
// Store output in a file to run for different algorithms
int main()
{
    int size=10000;
    ofstream file("inputtext.txt");
    for (int i = 0; i < size; ++i) 
    {
        //printf("%c",'A'+rand()%2);
        file<<(char)('A'+rand()%2);              //string would have only 'A' and "B"
    }
    return 0;
}
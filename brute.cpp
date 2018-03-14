#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
 
int cou=0; 
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;
 
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
           //printf("Pattern found at index %d \n", i);
          cou++;
    }
}
  
/* Driver program to test above function */
int main()
{
    char txt[20000];
    //scanf("%s",&txt);
    std::ifstream file;
    file.open("inputtext.txt");
    //file>>txt;
    file.getline(txt,19999);
    file.close();
    //printf("100%s100\n",txt );
    //char *pat = "ABABAAABAB";
    //char *pat ="learning";
    char pat[30];

    file.open("pat.txt");
    while(file.getline(pat,29))
    {
    clock_t begin = clock();
    search(pat, txt);
    clock_t end = clock();
    double elapsed_secs = double(end - begin)*1000 / CLOCKS_PER_SEC;
    //cout<<txt<<endl;
    cout<<"Number of matches of \""<<pat<<"\" is "<<cou<<endl<<"Time taken:"<<elapsed_secs<<endl;
    cou=0;
    }
   file.close();

   return 0;
}
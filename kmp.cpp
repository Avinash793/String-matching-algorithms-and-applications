#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cou=0; 
void computeLPSArray(char *pat, int M, int *lps);
 
// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            //printf("Found pattern at index %d \n", i-j);
            cou++;

            j = lps[j-1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
 
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// Driver program to test above function
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
    KMPSearch(pat, txt);
    clock_t end = clock();
    double elapsed_secs = double(end - begin)*1000 / CLOCKS_PER_SEC;
    //cout<<txt<<endl;
    cout<<"Number of matches of \""<<pat<<"\" is "<<cou<<endl<<"Time taken:"<<elapsed_secs<<endl;
    cou=0;
    }
   file.close();

    
    return 0;
}
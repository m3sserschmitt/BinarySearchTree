#include <iostream>
#include <chrono>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>

#include "s.hh"

using namespace std;

uint64_t milliseconds()
{
    uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ms; 
}

uint64_t microsseconds()
{
    uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return us; 
}

void insert_range(S &s, int m, int l, ofstream &outfile)
{
    clock_t start;
    double avg = 0;
    int p = 10;
    double sup = 0;

    for(int i = m; i < l; i ++)
    {
        start = clock();
        s.insert(i);
        avg += clock() - start;

        if(not (i % p))
        {
            avg /= p;

            if(avg > sup/* or not(i % ((m - l) / 100))*/)
            {
                sup = avg;
                outfile << i << " " << sup << "\n";
            }

            avg = 0;
        }
    }
}

void insert_random(S &s, int m, int l, size_t count)
{
    srand( (unsigned)time(NULL) );
    clock_t start;
    int number;
    for(int i = 0; i < count; i ++){
        number = (rand() + m) % l;
        start = clock();
        s.insert(number);
        cout << clock() - start << "\n";
        count --;
        
    }
    // cout << ((double)milliseconds() - (double)start) << "\n";
}

int main(int argc, char **argv)
{   
    S s;
    string op = string(argv[1]);

    ofstream outfile = ofstream();
    outfile.open(op + "_out");

    if(op == "insert_range")
    {
        insert_range(s, atoi(argv[2]), atoi(argv[3]), outfile);
    } else if (op == "insert_random")
    {
        insert_random(s, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    
    return 0;
}

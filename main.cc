#include <iostream>
#include <chrono>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <list>
#include <chrono>

#include "s.hh"

using namespace std;

void calculate(int n, int p, clock_t t, double &sup, double &avg)
{
    avg += t;

    if (not(n % p))
    {
        avg /= p;

        if (avg > sup)
        {
            sup = avg;
            cout << n << " " << sup << "\n";
        }

        avg = 0;
    }
}

void insert_range(S &s, int m, int l)
{
    clock_t start;
    clock_t stop;
    
    double sup = 0;
    int p = 10;
    double avg = 0;

    for (int i = m, k = 1; i < l; i++, k++)
    {
        start = clock();
        s.insert(i);
        stop = clock();
    
        calculate(k, p, stop - start, sup, avg);
    }
}

void insert_random(S &s, int m, int l, size_t count, bool print_output)
{
    clock_t start;
    clock_t stop;
    
    double sup = 0;
    int p = 10;
    double avg = 0;

    int number;

    for (int i = 0; i < count; i++)
    {
        number = (rand() + m) % l;

        start = clock();
        s.insert(number);
        stop = clock();

        if (print_output)
            calculate(i + 1, p, stop - start, sup, avg);

        count--;
    }
}

void search_random_tree(S &s, int m, int l, size_t count, size_t delta)
{
    int division = count / delta;

    clock_t start;
    clock_t stop;
    
    double sup = 0;
    int p = 10;
    double avg = 0;

    int number;

    for (int i = 0; i < delta; i++)
    {
        insert_random(s, m, l, division, 0);

        for (int k = 1; k <= p; k++)
        {
            number = (rand() + m) % l;

            start = clock();
            s.exists(number);
            stop = clock();

            calculate(i * division + k, p, stop - start, sup, avg);
        }
    }
}

void search_random_successor(S &s, int m, int l, size_t count, size_t delta)
{
    int division = count / delta;

    clock_t start;
    clock_t stop;
    
    double sup = 0;
    int p = 10;
    double avg = 0;

    int number;

    for (int i = 0; i < delta; i++)
    {
        insert_random(s, m, l, division, 0);

        for (int k = 1; k <= p; k++)
        {
            number = (rand() + m) % l;

            start = clock();
            try
            {
                s.successor(number);
            }
            catch (const char *)
            {
            }

            stop = clock();

            calculate(i * division + k, p, stop - start, sup, avg);
        }
    }
}

void search_random_kth(S &s, int m, int l, size_t count, size_t delta)
{
    int division = count / delta;

    clock_t start;
    clock_t stop;
    
    double sup = 0;
    int p = 10;
    double avg = 0;

    int number;

    for (int i = 0; i < delta; i++)
    {
        insert_random(s, m, l, division, 0);

        for (int k = 1; k <= p; k++)
        {
            number = rand() % (division * (i + 1));

            start = clock();

            try
            {
                s.kth_element(number);
            }
            catch (const char *)
            {

            }

            stop = clock();

            calculate(i * division + k, p, stop - start, sup, avg);
        }
    }
}

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    string op = argv[1];

    S s;

    if (op == "insert_range")
    {
        insert_range(s, atoi(argv[2]), atoi(argv[3]));
    }
    else if (op == "insert_random")
    {
        insert_random(s, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), 1);
    }
    else if (op == "search_random_tree")
    {
        search_random_tree(s, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    }
    else if (op == "search_random_successor")
    {
        search_random_successor(s, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    }
    else if (op == "search_random_kth")
    {
        search_random_kth(s, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    }

    return 0;
}

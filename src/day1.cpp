#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

#include "file.hpp"
#include "bench.hpp"
#include "day1.hpp"

char* Day1::file;

Day1::Day1(const char *file_name)
{
    file = file::read_file(file_name);
    run();
}

Day1::~Day1()
{
    free(file);
}

int Day1::first()
{
    char* begin = file;
    int sum = 0;

    while (*file)
    {
        int a = 0, b = -1;
        char* start = file;
        char* end = strchr(file, '\n');
        if (!end)
            end = strchr(file, 0);
        file = end + 1;

        for (; start < end; start++) {
            if (*start < '0' || *start > '9')
                continue;
            a = *start - 0x30;
            break;
        }

        for (; end > start; end--) {
            if (*end < '0' || *end > '9')
                continue;
            b = *end - 0x30;
            break;
        }

        if (b == -1)
            sum += a * 11;
        else
            sum += (a * 10) + b;
    }

    file = begin;
    return sum;
}

int Day1::second()
{
    const char* words[]   = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const char* numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    std::map<int, int> idx;
    int sum = 0;

    while (*file)
    {
        idx.clear();

        char* start = file;
        char* end = strchr(file, '\n');
        if (!end)
            end = strchr(file, 0);
        file = end + 1;

        char curr[end - start];
        for (int i = 0; start < end; i++, start++)
            curr[i] = *start;

        for (int i = 0; i < ARR_SIZE(numbers); i++)
        {
            char* n = strstr(curr, numbers[i]);
            char* w = strstr(curr, words[i]);
            char* last;

            if (n != nullptr)
            {
                idx[(int)(n - curr)] = i;

                last = n;
                while ((n = strstr(n + 1, numbers[i])) != nullptr)
                    last = n;
                idx[(int)(last - curr)] = i;
            }

            if (w != nullptr)
            {
                idx[(int)(w - curr)] = i;

                last = w;
                while ((w = strstr(w + 1, words[i])) != nullptr)
                    last = w;
                idx[(int)(last - curr)] = i;
            }
        }

        int a = idx.begin()->second;
        int b = (--idx.end())->second;

        sum += (a * 10) + b;
    }
    return sum;
}

void Day1::run()
{
    Bench::Result r = Bench::Bench(first, second);
    puts("-------- day1 --------");
    printf(" first: %6d | %3ldus\n", r.first, r.time.first);
    printf("second: %6d | %3ldus\n", r.second, r.time.second);
}
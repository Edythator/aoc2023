#include "file.hpp"
#include <stdio.h>
#include <stdlib.h>

namespace file
{
    char* read_file(const char* file_name)
    {
        FILE* file = fopen(file_name, "rb");
        if (!file)
        {
            puts("Couldn't open file.");
            exit(1);
        }
        fseek(file, 0, SEEK_END);
        size_t file_size = ftell(file);
        rewind(file);

        char* buffer = (char*)malloc(file_size + 1);
        if (!buffer)
        {
            puts("Couldn't malloc.");
            exit(1);
        }

        fread(buffer, file_size, 1, file);
        fclose(file);
        buffer[file_size] = 0;

        return buffer;
    }
}
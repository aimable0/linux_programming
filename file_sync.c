#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sync_file(const char *src, const char *dest)
{
    FILE *source = fopen(src, "r");
    FILE *destination = fopen(dest, "w");

    if (!source || !destination)
    {
        perror("File error");
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0)
    {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }
   
    sync_file(argv[1], argv[2]);

    return 0;
}

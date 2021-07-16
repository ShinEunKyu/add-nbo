#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t NtoHl(char* filename)
{
    FILE* file = fopen(filename, "rb");
    uint32_t f;
    size_t read_len = fread(&f, 1, sizeof(uint32_t), file);
    if(read_len != sizeof(uint32_t))
    {
        fprintf(stderr,"File size not %lu Byte!!\n", read_len);
        exit(-1);
    }
    f = ntohl(f);

    fclose(file);
    return f;
}


int main(int argc, char *argv[]) {

    uint32_t f1, f2;
    f1 = NtoHl(argv[1]);
    f2 = NtoHl(argv[2]);
    uint32_t sum = f1 + f2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, sum, sum);
    return 0;
}

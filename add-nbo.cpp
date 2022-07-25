#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include<netinet/in.h>


void usage(void)
{
    printf("./add-nbo [File1] [File2]\n");
}

int main(int argc, char **argv)
{
    if(argc != 3) usage();

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    uint32_t f1,f2;

    fread(&f1, 4, 1, fp1);
    fread(&f2, 4, 1, fp2);

    f1 = ntohl(f1);
    f2 = ntohl(f2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, f1+f2, f1+f2);

    fclose(fp1);
    fclose(fp2);
}

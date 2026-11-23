#include <stdio.h>
#include <string.h>
#define N 3

int main()
{
    struct car
    {
        char brand[15];
        char factory[15];
        float price;
        char engine_no[15];
    } x[N];

    FILE *fin, *fout;
    char req_factory[15], first;
    int i;

    fopen_s(&fin, "vhid.txt", "r");
    if (fin == NULL)
    {
        printf("File vhid.txt isn't opened\n");
        return 1;
    }

    fopen_s(&fout, "res.txt", "w");
    if (fout == NULL)
    {
        printf("File res.txt isn't opened\n");
        return 1;
    }

    for (i = 0; i < N; i++)
    {
        fscanf_s(fin, "%s", x[i].brand, 15);
        fscanf_s(fin, "%s", x[i].factory, 15);
        fscanf_s(fin, "%f", &x[i].price);
        fscanf_s(fin, "%s", x[i].engine_no, 15);
        printf("brand=%s factory=%s price=%.2f engine=%s\n", x[i].brand, x[i].factory, x[i].price, x[i].engine_no);
    }

    printf("Enter the first symbol of the engine number\n");
    scanf_s(" %c", &first, 1);
    printf("Enter the factory\n");
    scanf_s("%s", req_factory, 15);

    for (i = 0; i < N; i++)
    {
        int same_factory = strcmp(x[i].factory, req_factory) == 0;
        int same_first = x[i].engine_no[0] == first;
        int five_digits = strlen(x[i].engine_no) == 5;

        if (same_factory && same_first && five_digits)
        {
            fprintf(fout, "brand=%s factory=%s price=%.2f engine=%s\n", x[i].brand, x[i].factory, x[i].price, x[i].engine_no);
            printf("Suitable: brand=%s factory=%s price=%.2f engine=%s\n", x[i].brand, x[i].factory, x[i].price, x[i].engine_no);
        }
        else
            printf("Car %s is not suitable\n", x[i].brand);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
#include <stdio.h>

struct poly
{
    int c;
    int e;
};

struct poly p1[20], p2[20], p3[20];

int main()
{
    int i, m, n;

    printf("ENTER THE NUMBER OF TERMS IN THE POLYNOMIAL-1: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        printf("[FIRST POLYNOMIAL] ENTER COEFFICIENT AND EXPONENT: ");
        scanf("%d %d", &p1[i].c, &p1[i].e);
    }

    printf("ENTER THE NUMBER OF TERMS IN POLYNOMIAL-2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("[SECOND POLYNOMIAL] ENTER COEFFICIENT AND EXPONENT: ");
        scanf("%d %d", &p2[i].c, &p2[i].e);
    }

    int l1 = 0, l2 = 0, l3 = 0;

    while (l1 < m && l2 < n)
    {
        if (p1[l1].e == p2[l2].e)
        {
            p3[l3].c = p1[l1].c + p2[l2].c;
            p3[l3].e = p1[l1].e;
            l1++, l2++, l3++;
        }
        else if (p1[l1].e > p2[l2].e)
        {
            p3[l3].c = p1[l1].c;
            p3[l3].e = p1[l1].e;
            l1++, l3++;
        }
        else
        {
            p3[l3].c = p2[l2].c;
            p3[l3].e = p2[l2].e;
            l2++, l3++;
        }
    }

    while (l1 < m)
    {
        p3[l3].c = p1[l1].c;
        p3[l3].e = p1[l1].e;
        l1++, l3++;
    }

    while (l2 < n)
    {
        p3[l3].c = p2[l2].c;
        p3[l3].e = p2[l2].e;
        l2++, l3++;
    }

    printf("RESULT: \n");
    for (i = 0; i < l3; i++)
    {
        printf("%dx^%d", p3[i].c, p3[i].e);
        if (i != l3 - 1)
        {
            printf(" + ");
        }
    }
    return 0;
}

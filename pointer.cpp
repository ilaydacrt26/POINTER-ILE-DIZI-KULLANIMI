#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void yerlestir(int *dizi, int N)
{
    for (int i = 0; i < N; i++)
    {
    geri:
        int sayi = rand() % 101;
        for (int j = 0; j < i; j++)
        {
            if (dizi[j] == sayi)
            {
                goto geri;
            }
        }
        dizi[i] = sayi;
    }
}
void Birlestir(int *dizi1, int *dizi2, int N, int *ptr1, int *ptr2)
{
    for (ptr1 = (dizi1 + N), ptr2 = dizi2; ptr2 != (dizi2 + N); ptr1++, ptr2++)
    {
        *ptr1 = *ptr2;
    }
    printf("\nBirlesmis hali ==>");
    for (int i = 0; i < 2 * N; i++)
    {
        printf(" %d ", dizi1[i]);
    }
    printf("\n");
}
void DiziOlustur(int *dizi1, int *dizi2, int N)
{
    yerlestir(dizi1, N);
    yerlestir(dizi2, N);
    printf("N=%d girildi..\n", N);
    printf("Dizi 1 ==>");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", dizi1[i]);
    }
    printf("\nDizi 2 ==>");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", dizi2[i]);
    }
}
void KucuktenBuyugeSirala(int *dizi1, int N, int *ptr1, int *ptr2)
{
    int dizi[2 * N];
    for (ptr1 = dizi1, ptr2 = dizi; ptr1 != (dizi1 + 2 * N); ptr1++, ptr2++)
    {
        *ptr2 = *ptr1;
    }
    int kucuk, indis;
    for (int i = 0; i < 2 * N; i++)
    {
        kucuk = 101;
        for (int j = 0; j < 2 * N; j++)
        {
            if (kucuk > dizi[j])
            {
                kucuk = dizi[j];
                indis = j;
            }
        }
        printf("\n%d ekrana yazdirildi.", kucuk);
        dizi[indis] = 101;
    }
}
void BuyuktenKucugeSirala(int *dizi1, int N, int *ptr1, int *ptr2)
{
    int dizi[2 * N];
    for (ptr1 = dizi1, ptr2 = dizi; ptr1 != (dizi1 + 2 * N); ptr1++, ptr2++)
    {
        *ptr2 = *ptr1;
    }
    int buyuk, indis;
    for (int i = 0; i < 2 * N; i++)
    {
        buyuk = -1;
        for (int j = 0; j < 2 * N; j++)
        {
            if (buyuk < dizi[j])
            {
                buyuk = dizi[j];
                indis = j;
            }
        }
        printf("\n%d ekrana yazdirildi.", buyuk);
        dizi[indis] = -1;
    }
}
int main()
{
    int N;
    do
    {
        printf("\nDiziler kac elemanli olacak: ");
        scanf("%d", &N);
    } while (N <= 0 && N > 101);

    int dizi1[101], dizi2[101];
    int *ptr1, *ptr2;

    yerlestir(dizi1, N);
    printf("1.Dizi ==>");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", dizi1[i]);
    }
    yerlestir(dizi2, N);
    printf("\n2.Dizi ==>");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", dizi2[i]);
    }
    printf("\n");
    int secim = 0;
    do
    {
        printf("\n\n0-Cikis yapilacak.\n1-Dizi kucukten buyuge siralanacak.\n2-Dizi buyukten kucuge siralanacak.\n3-Diziler yeniden olusturalacak.\n");
        do
        {
            printf("Bir secim yapiniz: ");
            scanf("%d", &secim);
        } while (secim != 0 && secim != 1 && secim != 2 && secim != 3);

        printf("\n");
        if (secim == 1) //! kucukten buyuge
        {
            Birlestir(dizi1, dizi2, N, ptr1, ptr2);
            KucuktenBuyugeSirala(dizi1, N, ptr1, ptr2);
        }
        else if (secim == 2) //! buyukten kucuge
        {
            Birlestir(dizi1, dizi2, N, ptr1, ptr2);
            BuyuktenKucugeSirala(dizi1, N, ptr1, ptr2);
        }
        else if (secim == 3) //! yeni diziler olusturup yazma
        {
            do
            {
                printf("\nDiziler kac elemanli olacak: ");
                scanf("%d", &N);
            } while (N <= 0 && N > 101);
            DiziOlustur(dizi1, dizi2, N);
        }
    } while (secim != 0);
    printf("Menuden cikis yapiliyor..\n");
    printf("Menuden cikis yapildi.");
    return 0;
}
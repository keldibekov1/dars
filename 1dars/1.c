#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nomi[50];
    double narxi;
    int miqdori;
} Dori;

Dori dorilar[10] = {
    {1, "Paracetamol", 2500, 100},
    {2, "Ibuprofen", 3000, 50},
    {3, "Amoxicillin", 5000, 20},
    {4, "Ciprofloxacin", 4000, 30},
    {5, "Metformin", 6000, 40},
    {6, "Atorvastatin", 7500, 25},
    {7, "Omeprazole", 3500, 60},
    {8, "Lisinopril", 4500, 15},
    {9, "Amlodipine", 5500, 35},
    {10, "Simvastatin", 6500, 45}};

double kassaga_qushilgan_summa = 0.0;

void dorilar_royxati()
{
    printf("Dorilar ro'yxati:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d) %s - %.2f (Miqdor: %d)\n", dorilar[i].id, dorilar[i].nomi, dorilar[i].narxi, dorilar[i].miqdori);
    }
}

void qolmagan_dorilar()
{

    printf("Omborda qolmagan dorilar:\n");
    for (int i = 0; i < 10; i++)
    {
        if (dorilar[i].miqdori == 0)
        {
            printf("%d) %s\n", dorilar[i].id, dorilar[i].nomi);
        }
    }
}

int main()
{

    int tanlov, dori_id, miqdor;
    double umumiy_summa = 0.0;

    while (1)
    {
        printf("\n1) Dorilar ro'yxati\n2) Dori harid qilish\n3) Omborda qolmagan dorilarni ko'rish\n4) Chiqish\n");
        printf("Tanlovingizni kiriting: ");
        scanf("%d", &tanlov);

        switch (tanlov)
        {
        case 1:
            dorilar_royxati();
            break;
        case 2:
            while (1)
            {
                dorilar_royxati();
                printf("Dori raqamini kiriting (-1 to'xtatish uchun): ");
                scanf("%d", &dori_id);
                if (dori_id == -1)
                {
                    break;
                }
                printf("Miqdorni kiriting: ");
                scanf("%d", &miqdor);

                int topildi = 0;
                for (int i = 0; i < 10; i++)
                {
                    if (dorilar[i].id == dori_id)
                    {
                        topildi = 1;
                        if (dorilar[i].miqdori >= miqdor)
                        {
                            dorilar[i].miqdori -= miqdor;
                            umumiy_summa += dorilar[i].narxi * miqdor;
                        }
                        else
                        {
                            printf("Kechirasiz, omborda bu doridan yetarli miqdorda yo'q.\n");
                        }
                        break;
                    }
                }
                if (!topildi)
                {
                    printf("Kechirasiz, bunday dori mavjud emas.\n");
                }
            }
            printf("Umumiy summa: %.2f sum\n", umumiy_summa);
            char javob;
            printf("Harid qilasizmi? (h/y): ");
            scanf(" %c", &javob);
            if (javob == 'h' || javob == 'H')
            {
                kassaga_qushilgan_summa += umumiy_summa;
                printf("Haridingiz amalga oshirildi. Kassaga qo'shilgan summa: %.2f sum\n", kassaga_qushilgan_summa);
            }
            else
            {
                printf("Harid bekor qilindi.\n");
            }
            umumiy_summa = 0.0;
            break;
        case 3:
            qolmagan_dorilar();
            break;
        case 4:
            printf("Dasturdan chiqilmoqda...\n");
            exit(0);
        default:
            printf("Notog'ri tanlov. Qaytadan urinib ko'ring.\n");
        }
    }
    return 0;
}
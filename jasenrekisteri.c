#include <stdio.h>
#include <string.h>

typedef struct {
    char etunimi[101];
    char sukunimi[101];
    int jasennumero;
    int liittymisvuosi;
    int jasenmaksut[5];
    char poistettu;
}Jasenrekisteri;

Jasenrekisteri lueJasentiedot(void);
void tulostaJasen(Jasenrekisteri op);
void muokkaaJasen(Jasenrekisteri op);

int main(void){
    int syote=0, jasenet = 0, jasennro;

    Jasenrekisteri jasen[10];

    while(syote != 7){
        printf("\n1 Uuden jasenen lisaaminen\n2 Jasenen tietojen poisto\n3 Jasenen tietojen muuttaminen\n4 Tulosta jasen\n");
        printf("5 Tulosta rekisteri\n6 Haku\n7 Lopetus\n");
        printf("\nValintasi >\n");
        scanf("%d", &syote);
        switch (syote){
        case 1:
            jasen[jasenet] = lueJasentiedot();
            jasenet += 1;
            break;
        case 2:
            printf("\nAnna poistettavan jasenen jasennumero >\n");
            scanf("%d", &jasennro);
            for(int i = 0; i < 10; i++){
                if(jasen[i].jasennumero == jasennro)
                    jasen[i].poistettu = 'k';
            }
            break;
        case 3:
            printf("\nAnna muutettavan jasenen jasennumero >\n");
            scanf("%d", &jasennro);
            for(int i = 0; i < 10; i++){
                if(jasen[i].jasennumero == jasennro){
                    int valinta=0, syotto=0;
                    char nimi[256];

                    printf("\n1 Muuta etunimi\n2 Muuta sukunimi\n3 Muuta jasennumero\n4 Muuta liittymisvuosi\n5 Muuta jasenmaksutietoja\n");
                    printf("\nValintasi >\n");
                    scanf("%d", &valinta);
                    switch (valinta){
                    case 1:
                        printf("Anna uusi etunimi >\n");
                        scanf("%s", nimi);
                        strcpy(jasen[i].etunimi, nimi);
                        break;
                    case 2:
                        printf("Anna uusi sukunimi >\n");
                        scanf("%s", nimi);
                        strcpy(jasen[i].sukunimi, nimi);
                        break;
                    case 3:
                        printf("Anna uusi jasennumero >\n");
                        scanf("%d", &syotto);
                        jasen[i].jasennumero = syotto;
                        break;
                    case 4:
                        printf("Anna uusi liittymisvuosi >\n");
                        scanf("%d", &syotto);
                        jasen[i].liittymisvuosi = syotto;
                        break;
                    case 5:
                        printf("Anna uudet jasenmaksutiedot >\n");
                        for(int i = 0; i < 5; i++){
                            printf("Anna vuoden %d liittymismaksu >\n", 2016+i);
                            scanf("%d", &syotto);
                            jasen[i].jasenmaksut[i] = syotto;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 4:
            printf("\nAnna jasennumero >\n");
            scanf("%d", &jasennro);
            for(int i = 0; i < 10; i++){
                if(jasen[i].jasennumero == jasennro)
                    tulostaJasen(jasen[i]);
            }
            break;
        case 5:
            printf("\n***************************\n");
            for(int i = 0; i < jasenet; i++){
                tulostaJasen(jasen[i]);
            }
            break;
        case 6:
            printf("haku\n");
            break;
        default:
            break;
        }
    }
    return 0;
}

Jasenrekisteri lueJasentiedot(void){
    Jasenrekisteri op;
    int vuosi = 2016;

    printf("\nAnna Jasenen Etu- ja Sukunimi >\n");
    scanf("%s %s", op.etunimi, op.sukunimi);
    printf("\nAnna jasennumero >\n");
    scanf("%d", &op.jasennumero);
    printf("\nAnna liittymisvuosi >\n");
    scanf("%d", &op.liittymisvuosi);
    for(int i = 0; i < 5; i++){
        printf("\nAnna vuoden %d jasenmaksu >\n", vuosi+i);
        scanf("%d", &op.jasenmaksut[i]);
    }
    op.poistettu = 'e';
    return(op);
}

void tulostaJasen(Jasenrekisteri op){
    if(op.poistettu != 'k'){
        printf("\n");
        printf("   ETUNIMI: %s\n", op.etunimi);
        printf("  SUKUNIMI: %s\n", op.sukunimi);
        printf("  JASENNRO: %d\n", op.jasennumero);
        printf("LIITTVUOSI: %d\n\n\n", op.liittymisvuosi);
    }
}

void muokkaaJasen(Jasenrekisteri op){
    int valinta=0, syotto=0;
    char nimi[256];

    printf("\n1 Muuta etunimi\n2 Muuta sukunimi\n3 Muuta jasennumero\n4 Muuta liittymisvuosi\n5 Muuta jasenmaksutietoja\n");
    scanf("%d", &valinta);
    switch (valinta){
    case 1:
        printf("Anna uusi etunimi >\n");
        scanf("%s", nimi);
        strcpy(op.etunimi, nimi);
        break;
    case 2:
        printf("Anna uusi sukunimi >\n");
        scanf("%s", nimi);
        strcpy(op.sukunimi, nimi);
        break;
    case 3:
        printf("Anna uusi jasennumero >\n");
        scanf("%d", &syotto);
        op.jasennumero = syotto;
        break;
    case 4:
        printf("Anna uusi liittymisvuosi >\n");
        scanf("%d", &syotto);
        op.liittymisvuosi = syotto;
        break;
    case 5:
        printf("Anna uudet jasenmaksutiedot >\n");
        for(int i = 0; i < 5; i++){
            printf("Anna vuoden %d liittymismaksu >\n", 2016+i);
            scanf("%d", &syotto);
            op.jasenmaksut[i] = syotto;
        }
        break;
    default:
        break;
    }
}
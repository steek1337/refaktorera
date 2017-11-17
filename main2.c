/*
Mer V\x84ljinformation om programets funktionalitet hittar ni i readme filen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "funktioner.h"

int main()
{
    system("chcp 1252");
    system("cls");
    bool exit = false;

    while (exit == false)
    {
        printf("\n");
        int val;

        printf("V\x84lj vilka storheter du vill ber\x85kna:\n\n");
        printf("V\x84lj 1 f\x94r: OHMS LAG\n");
        printf("V\x84lj 2 f\x94r: Rtot\n");
        printf("V\x84lj 3 f\x94r: EFFEKTLAGEN ENKEL\n");
        printf("V\x84lj 4 f\x94r: SKENBAR EFFEKT ENFAS\n");
        printf("V\x84lj 5 f\x94r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
        printf("V\x84lj 6 f\x94r: SKENBAR EFFEKT 3-FAS\n");
        printf("V\x84lj 7 f\x94r: AKTIV EFFEKT 3-FAS\n");
        printf("V\x84lj 0 f\x94r: För ATT AVSLUTA\n");

        scanf("%d", &val);

        if(val == 1)
        {

            printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
            printf("gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
            double r, i;
            printf("Skriv resistans R < 20 000ohm: \n ");
            scanf("%lf", &r);
            if(r > 20000)
            {
                wrong_input();
                //continue;
            }

            printf("Skriv ström I < 440 Ampere: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                wrong_input();
            }

            printf("%f V\n", ohms_lag(r, i));

        }
        else if(val == 2)
        {
            printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n");
            printf("Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n");
            double r1,r2,r3;
            printf("Skriv resistans R1 < 20 000ohm: \n ");
            scanf("%lf", &r1);
            if(r1 > 20000)
            {
                wrong_input();
            }
            printf("Skriv resistans R2 < 20 000ohm: \n ");
            scanf("%lf", &r2);
            if(r2 > 20000)
            {
                wrong_input();
            }
            printf("Skriv resistans R3 < 20 000ohm: \n ");
            scanf("%lf", &r3);
            if(r3 > 20000)
            {
                wrong_input();
            }
            printf("%f Ohm\n", res_tot(r1, r2, r3));
        }
        else if(val == 3)
        {

            printf("Effektlagen enkel För likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
            printf("gånger Strömmen I i Ampere(A): \n\n");
            double u, i;
            printf("Skriv spännngen U i volt(V): \n ");
            scanf("%lf", &u);
            printf("Skriv ström Ampere I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                wrong_input();
            }
            printf("%f W\n", eff_enk(u, i));
        }
        else if(val == 4)
        {

            printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n");
            printf("gånger Strömmen I i ampere(A)\n\n");
            double u, i;
            printf("Skriv spänningen U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv ström I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                wrong_input();
            }
            printf("%f VA\n", sken_eff(u, i));
        }

        else if(val == 5)
        {
            printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger Strömmen I \n");
            printf("i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n");
            double u, i, cos;
            printf("Skriv spänning U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv ström I: \n");
            scanf("%lf", &i);
            if(i > 440){
                wrong_input();
            }
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                wrong_input();
            }
            printf("%f W\n", aktiv_eff(u, i, cos));
        }
        else if(val == 6)
        {
            printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
            printf("gånger Strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n");
            double u, i;
            printf("Skriv spänning U i volt(V) < 400V: \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                wrong_input();
            }

            printf("Skriv ström I i ampere < 440: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                wrong_input();
            }
            printf("%f VA\n", sken_3fas(u, i));
        }
        else if(val == 7)
        {

            printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger Strömmen I i ampere(A)\n");
            printf("gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n");
            double u, i, cos;
            printf("Skriv spänningen U i volt(V): \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                wrong_input();
            }
            printf("Skriv ström I i ampere(A): \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                wrong_input();
            }

            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                wrong_input();
            }

            printf("%f W\n", aktiv_3fas(u ,i, cos));
        }
        else if (val == 0)
        {
            exit = true;
        }
        else
        {
            printf("Fel alternativ försök igen!: \n");
        }
    }

    return 0;
}

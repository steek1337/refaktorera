
/*Detta program �r en r�knare som kan anv�ndas För ell�ra med enbart v�xelsp�nningar och v�xelstr�mmar. R�knaren
tar upp r�kning med sp�nningar i volt(U), resistanser upp till 20 000/ohm(R).
Str�m upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
�ven tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas d�r cosinus fi/cosinus() anv�nds
som effektfaktorn som �r mindre �n 1 och inte mindre �n 0.
Frekvenser i (Hz):  och totala motst�ndet i parallellkopplade kretsar med max 3 motst�nd.

50 Hertz(Hz) Finns det i v�ra uttag i sverige Vid 50 Hz byter �spänningen polaritet och Strömmen riktning 100 gånger per
sekund. spänningen i svenska eluttag pendlar upp och ner fr�n -325 V till +325 V. Att vi talar om 230 V beror p� att det
�r spänningens(v�xelstr�m ~) effektivvärde eller roten ur. spänningen V(U)=Toppvärdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Sp�nning i volt(U)=Resistans i ohm(R)*Str�m i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL För likström: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()

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

        printf("Välj vilka storheter du vill beräkna:\n");
        printf("Välj 1 för: OHMS LAG\n");
        printf("Välj 2 för: Rtot\n");
        printf("Välj 3 för: EFFEKTLAGEN ENKEL\n");
        printf("Välj 4 för: SKENBAR EFFEKT ENFAS\n");
        printf("Välj 5 för: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
        printf("Välj 6 för: SKENBAR EFFEKT 3-FAS\n");
        printf("Välj 7 för: AKTIV EFFEKT 3-FAS\n");
        printf("Välj 0 för: För ATT AVSLUTA\n");

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
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("Skriv ström I < 440 Ampere: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen: \n");
                continue;
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
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("Skriv resistans R2 < 20 000ohm: \n ");
            scanf("%lf", &r2);
            if(r2 > 20000)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("Skriv resistans R3 < 20 000ohm: \n ");
            scanf("%lf", &r3);
            if(r3 > 20000)
            {
                printf("För högt värde, försök igen: \n");
                continue;
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
                printf("För högt värde, försök igen: \n");
                continue;
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
                printf("För högt värde, försök igen: \n");
                continue;
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
                printf("För högt värde, försök igen:\n");
                continue;
            }
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("Fel värde, försök igen\n");
                continue;
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
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("Skriv ström I i ampere < 440: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen: \n");
                continue;
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
                printf("För högt värde, försök igen.\n");
                continue;
            }
            printf("Skriv ström I i ampere(A): \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen.\n");
                continue;
            }

            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("För högt värde, försök igen: \n");
                continue;
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


//====================================//====================================
double ohms_lag(double r, double i){

    double u = i * r;

    return u;
}
//====================================//====================================
double res_tot(double r1, double r2, double r3){


    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;

    return rtot;
}
//====================================//====================================
double eff_enk(double u, double i){

    double p = u * i;

    return p;
}
//====================================//====================================
double sken_eff(double u, double i){

    double s = u * i;

    return s;
}
//====================================//====================================
double aktiv_eff(double u, double i, double cos){

    double p = u * i * cos;

    return p;
}
//====================================//====================================
double sken_3fas(double u, double i){

    double s = u * i * sqrt(3);

    return s;
}
//============== Inpute value in I (Ampere) ================================
void enter_choice()
{
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
}
//====================================//====================================
double aktiv_3fas(double u, double i, double cos){

    double p = u * i * sqrt(3) * cos;

    return p;
}
//============== When put in wrong value ===================================
void wrong_input()
{
    while (1)
    {
        printf("För högt värde, försök igen: \n");
        continue;
    }
}
//============== Inpute value in U (Volt) ==================================
void enter_volt()
{
    printf("Skriv spännngen U i volt(V): \n ");
}
//============== Inpute value in I (Ampere) ================================
void enter_ampere()
{
    printf("gånger Strömmen I i ampere(A)\n\n");
}
//====================================//====================================

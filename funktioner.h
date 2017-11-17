

double ohms_lag(double r, double i){

    double u = i * r;

    return u;
}

double res_tot(double r1, double r2, double r3){


    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;

    return rtot;
}

double eff_enk(double u, double i){

    double p = u * i;

    return p;
}

double sken_eff(double u, double i){

    double s = u * i;

    return s;
}

double aktiv_eff(double u, double i, double cos){

    double p = u * i * cos;

    return p;
}

double sken_3fas(double u, double i){

    double s = u * i * sqrt(3);

    return s;
}

double aktiv_3fas(double u, double i, double cos){

    double p = u * i * sqrt(3) * cos;

    return p;
}



void wrong_input()
{
    while (1)
    {
        printf("För högt värde, försök igen: \n");
        continue;
    }
}


void enter_volt()
{
    printf("Skriv spännngen U i volt(V): \n ");
}


void enter_ampere()
{
    printf("gånger Strömmen I i ampere(A)\n\n");
}

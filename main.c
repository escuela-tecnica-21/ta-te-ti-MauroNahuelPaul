#include <stdio.h>
#include <stdlib.h>

int Iniciar_Tablero(char Tablero);
void Mostrar_Tablero(char Tablero);
int Estado_Partido(char Tablero);
int Victoria(char Tablero);
int Contador(char Tablero[],char simbolo, int a, int b, int c);
int Empate(char Tablero);
int Contador_Empate(char Tablero[]);
int Turno_Jugador(char Tablero);
int Lugar_Vacio(char Tablero, int Posicion);
int Turno_Maquina(char Tablero);
int Ganar_Maquina(char Tablero[], char simbolo, int a, int b, int c);
int Vacio(char Tablero[], int a, int b, int c);

int const Hilera[][3]= {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
int const esquinas[] = {0, 2, 6, 8};
int const vertices[] = {1, 3, 5, 7};

int main(int argc, char ** argv)
{
    char Tablero[9];
    Iniciar_Tablero(Tablero);
    Mostrar_Tablero(Tablero);
    while(Estado_Partido(Tablero)==0)
    {
        Turno_Jugador(Tablero);
        Mostrar_Tablero(Tablero);
        Turno_Maquina(Tablero);
        Mostrar_Tablero(Tablero);
    }
    return 0;
}

int Iniciar_Tablero(char Tablero[]){
    for(int x=0;x<9;x++){
        Tablero[x]=' ';
    }return Tablero;
}

void Mostrar_Tablero(char Tablero[]){
    printf("  %s   %c   %s   %c   %s \n",Tablero[0],179,Tablero[1],179,Tablero[2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Tablero[3],179,Tablero[4],179,Tablero[5]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Tablero[6],179,Tablero[7],179,Tablero[8]);
}

int Estado_Partido(char Tablero[]){
    return (Victoria(Tablero) || Empate(Tablero));
}

int Victoria(char Tablero[]){
    for(int x=0;x<9;x++){
       if(Contador(Tablero, 'X', Hileras[x][0], Hileras[x][1], Hileras[x][2])==3)
            return 0;
       if(Contador(Tablero, 'O', Hileras[x][0], Hileras[x][1], Hileras[x][2])==3)
            return 0;
    }return 1;
}

int Contador(char Tablero[],char simbolo, int a, int b, int c){
    int Suma=0;
    if(Tablero[a]==simbolo)Suma++;
    if(Tablero[b]==simbolo)Suma++;
    if(Tablero[c]==simbolo)Suma++;
    return Suma;
}

int Empate(char Tablero[]){
    if(Contador_Empate(Tablero)==0)
        return 0;
    else{
        return 1;
    }
}

int Contador_Empate(char Tablero[]){
    int Suma;
    for(int x=0;x<9;x++){
        if(Tablero[x]==" ")suma++;
    }return Suma;
}

int Turno_Jugador(Tablero[]){
    int Lugar
    do{
        printf("Ingrese El Lugar");
        scanf("%d",&Lugar);
        return Lugar_Vacio(Tablero,Lugar-1);
    }while(Lugar_Vacio(Tablero));
    Tablero[Lugar]='X';
    return Tablero;
}

int Lugar_Vacio(char Tablero, Posicion){
    if(Tablero[Posicion]==' ')
        return 0;
    printf("Lugar no disponible");
    return 1;
}

int Turno_Maquina(char Tablero[]){
    for(int x=0;x<9;x++){
        if(Ganar_Maquina(Tablero, 'O', Hileras[X][0], Hileras[X][1], Hileras[X][2])==1){
            printf("Turno Maquina");
            return Vacio(Tablero, Hileras[X][0], Hileras[X][1], Hileras[X][1])
        }
    }
    for(int x=0;x<9;x++){
        if(Defender_Maquina(Tablero, 'X', Hileras[X][0], Hileras[X][1], Hileras[X][2])==1){
            printf("Turno Maquina");
            return Vacio(Tablero, Hileras[X][0], Hileras[X][1], Hileras[X][1])
    }

}

int Ganar_Maquina(char Tablero[], char simbolo, int a, int b, int c){
    if((Contador(Tablero, simbolo, a, b, c)==2) && (Contador(Tablero, ' ', a, b, c)==1))
        return 1;
    else
        return 0;
}

int Vacio(char Tablero[], int a, int b, int c){
    if(Tablero[a]==' ')
        return a;
    if(Tablero[b]==' ')
        return b;
    return c;
}
int Defender_Maquina(char Tablero[], char simbolo, int a, int b, int c){
    if((Contador(Tablero, simbolo, a, b, c)==2) && (Contador(Tablero, ' ', a, b, c)==1))
        return 1;
    else
        return 0;
}


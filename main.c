#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

int main()
{//163 ñ
    srand(time(NULL));
    char Tablero[3][3][2];
    int Victoria=0,Estado_Partido=0;

    Llenado_De_Matriz(Tablero);//llena la matriz de " "
    gotoxy(1,2);
    printf("Bienvenidos al TATETI\t Creador:Paul Nahuel Mauro\n");//introduccion
    printf("  1   %c   2   %c   3\n",179,179);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  4   %c   5   %c   6\n",179,179);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  7   %c   8   %c   9\n",179,179);

    Ingresar_Tablero(Tablero);
    Estado_Partido=Verificador_Empate(Tablero,Victoria);//si es empate termina el partido
    Estado_Partido=Verificador_Vict(Tablero,Victoria);//si el jugador 1 gano termina el partido
    if(Estado_Partido==1)
    {
        return;
    }
    Bot_Movimientos(Tablero);
    Mostrar_Tablero(Tablero);
    Estado_Partido=Verificador_Empate(Tablero,Victoria);//si es empate termina el partido
    Estado_Partido=Verificador_Vict(Tablero,Victoria);//si el jugador 1 gano termina el partido

}

int Llenado_De_Matriz(char Tablero[3][3][2]) //funcion llenado de la matriz en nada
{
    int x,y;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            strcpy(Tablero[x][y]," ");
        }
    }return Tablero;
}
void Mostrar_Tablero(char Tablero[3][3][2])//funcion mostrar la matriz
{
    system("cls");
    gotoxy(1,2);
    printf("Bienvenidos al TATETI\t Creador:Paul Nahuel Mauro\n");//introduccion
    printf("  %s   %c   %s   %c   %s \n",Tablero[0][0],179,Tablero[0][1],179,Tablero[0][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Tablero[1][0],179,Tablero[1][1],179,Tablero[1][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Tablero[2][0],179,Tablero[2][1],179,Tablero[2][2]);
}
int Ingresar_Tablero(char Tablero[3][3][2])
{
    int posicion;
    char Estilo_Ficha[2], Respuesta[15];
    while(1)
    {
        do
        {
            do
            {
                printf("¿Deseas ingresar una 'X'?");scanf("%s",&Respuesta);
            }while(validar_Respuesta(Respuesta));
            if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0){
                break;
            }
            printf("Ingrese el n%cmero que desea colocar la X\n",163);
            scanf("%d",&posicion);
        }while(validar_lugar(Tablero,posicion));//verifica que el valor ingresado no este ocupado
        if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0){
                break;
        }
        strcpy(Estilo_Ficha,"X");
        Dato_ingresado(Tablero,posicion, Estilo_Ficha);
        Mostrar_Tablero(Tablero);
    }
    Mostrar_Tablero(Tablero);
    while(1)
    {
        do
        {
            do
            {
                printf("¿Deseas ingresar una 'O'?");scanf("%s",&Respuesta);
            }while(validar_Respuesta(Respuesta));
            if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0){
                break;
            }
            printf("Ingrese el n%cmero que desea colocar la O\n",163);
            scanf("%d",&posicion);
        }while(validar_lugar(Tablero,posicion));//verifica que el valor ingresado no este ocupado
        if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0){
                break;
            }
        strcpy(Estilo_Ficha,"O");
        Dato_ingresado(Tablero,posicion, Estilo_Ficha);
        Mostrar_Tablero(Tablero);
    }
    return Tablero;
}
int validar_lugar(char Tablero[3][3][2],int Dato)//funcion validar que el lugar no este ocupado
{
    int fila=0;
    Dato=Dato-1;
        if(Dato<=2 && Dato>=0){
           Dato=Dato;fila=0;
       }
       if (Dato>=3 && Dato<6){
           Dato=Dato-3;fila=1;
       }
       if  (Dato>=6 && Dato<=8){
           Dato=Dato-6;fila=2;
       }
       if(Dato<0 || Dato>=9){
           printf("El lugar ingresado esta fuera de los terminos,vuelva a intentarlo\n");
           return 1;
       }
       if(strcmp(Tablero[fila][Dato],"X")==0 || strcmp(Tablero[fila][Dato],"O")==0){
           printf("Este lugar ha sido ocupado anteriormente\n");
           return 1;
       }
       return 0;
}
int validar_Respuesta(char Respuesta[3])
{
    if(strcmp(Respuesta,"si")==0 || strcmp(Respuesta,"Si")==0 || strcmp(Respuesta,"SI")==0)
    {
        return 0;
    }
    if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0)
    {
        return 0;
    }
    return 1;
}
int Dato_ingresado(char Tablero[3][3][2],int lugar,char Tipo[2])//coloca el numero ingresado por el usuario en el lugar correcto
{//pone el valor donde corresponde en la matriz
            if(lugar<4){
                strcpy(Tablero[0][lugar-1],Tipo);
                return Tablero;
            }
            if(lugar>=4 && lugar<7){
                strcpy(Tablero[1][lugar-4],Tipo);
                return Tablero;
            }
            if(lugar>=7){
                strcpy(Tablero[2][lugar-7],Tipo);
                return Tablero;
            }
}
int Verificador_Vict(char Tablero[3][3][2],int Partido)//Esta funcion verifica si el jugador 1 gano
{
    int x=0;
    for(x=0;x<3;x++)
    {
        if(strcmp(Tablero[x][0],Tablero[x][1])==0 && strcmp(Tablero[x][1],Tablero[x][2])==0)////filas
          {
              if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][1],"X")==0 && strcmp(Tablero[x][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Partido=1;
                  return Partido;
              }
              if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][1],"O")==0 && strcmp(Tablero[x][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Partido=1;
                  return Partido;
              }
          }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(Tablero[0][x],Tablero[1][x])==0 && strcmp(Tablero[1][x],Tablero[2][x])==0)////columnas
          {
              if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[1][x],"X")==0 && strcmp(Tablero[2][x],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Partido=1;
                  return Partido;
              }
              if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[1][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Partido=1;
                  return Partido;
              }
        }
    }
    if(strcmp(Tablero[0][0],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][2])==0)////diagonales
    {
        if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][2],"X")==0)
        {
            gotoxy(1,13);
            printf("Player 1 win!!\n");
            Partido=1;
            return Partido;
        }
        if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][2],"O")==0)
        {
            gotoxy(1,13);
            printf("Player 2 win!!\n");
            Partido=1;
            return Partido;
        }
    }
    if(strcmp(Tablero[0][2],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][0])==0)//diagonal
    {
        if(strcmp(Tablero[0][2],"X")==0 && strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][0],"X")==0)
        {
            gotoxy(1,13);
            printf("Player 1 win!!\n");
            Partido=1;
            return Partido;
        }
        if(strcmp(Tablero[0][2],"O")==0 && strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][0],"O")==0)
        {
            gotoxy(1,13);
            printf("Player 2 win!!\n");
            Partido=1;
            return Partido;
        }
    }
    Partido=0;
    return Partido;
}
int Verificador_Empate(char Tablero[3][3][2],int Partido)//funcion verifica que el partido termino en empate
{
    int x,contador_empate=0,y;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            if(strcmp(Tablero[x][y],"X")==0 || strcmp(Tablero[x][y],"O")==0)
            {
                contador_empate=contador_empate+1;
            }
        }
    }
    if(contador_empate==9)
    {
        Partido=1;
        return Partido;
    }Partido=0;
    return Partido;
}
int Bot_Movimientos(char Tablero[3][3][2])
{
    int x,bot=0;
    char Tipo_ficha[2];
    ////ATACAR////FILAS

            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][1],"O")==0)
                {
                    if(strcmp(Tablero[x][2]," ")==0)
                    {
                        strcpy(Tablero[x][2],"O");
                       return Tablero;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][2],"O")==0)
                {
                    if(strcmp(Tablero[x][1]," ")==0)
                    {
                        strcpy(Tablero[x][1],"O");
                        return Tablero;
                    }
                }
            }
           for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][1],"O")==0 && strcmp(Tablero[x][2],"O")==0)
                {
                    if(strcmp(Tablero[x][0]," ")==0)
                    {
                        strcpy(Tablero[x][0],"O");
                        return Tablero;
                    }
                }
            }

    ////ATACAR////columnas

            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[1][x],"O")==0)
                {
                    if(strcmp(Tablero[2][x]," ")==0)
                    {
                        strcpy(Tablero[2][x],"O");
                        return Tablero;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[1][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
                {
                    if(strcmp(Tablero[0][x]," ")==0)
                    {
                        strcpy(Tablero[0][x],"O");
                        return Tablero;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
                {
                    if(strcmp(Tablero[1][x]," ")==0)
                    {
                        strcpy(Tablero[1][x],"O");
                        return Tablero;
                    }
                }
            }

    ////ATACAR////diagonales

            if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[2][2]," ")==0)
                {
                    strcpy(Tablero[2][2],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][2],"O")==0)
            {
                if(strcmp(Tablero[0][0]," ")==0)
                {
                    strcpy(Tablero[0][0],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[2][2],"O")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    return Tablero;
                }
            }
        /////////////////////////////////////////////////////////////////////////////////////////////////
            if(strcmp(Tablero[0][2],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[2][0]," ")==0)
                {
                    strcpy(Tablero[2][0],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[2][0],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[0][2]," ")==0)
                {
                    strcpy(Tablero[0][2],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[2][0],"O")==0 && strcmp(Tablero[0][2],"O")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    return Tablero;
                }
            }

    ////DEFENDER////filas

            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][1],"X")==0)
                {
                    if(strcmp(Tablero[x][2]," ")==0)
                    {
                        strcpy(Tablero[x][2],"O");
                        return Tablero;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][2],"X")==0)
                {
                    if(strcmp(Tablero[x][1]," ")==0)
                    {
                        strcpy(Tablero[x][1],"O");
                        return Tablero;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][1],"X")==0 && strcmp(Tablero[x][2],"X")==0)
                {
                    if(strcmp(Tablero[x][0]," ")==0)
                    {
                        strcpy(Tablero[x][0],"O");
                        return Tablero;
                    }
                }
            }

    ////DEFENDER////columnas

            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[1][x],"X")==0)
                {
                    if(strcmp(Tablero[2][x]," ")==0)
                    {
                        strcpy(Tablero[2][x],"O");
                        return Tablero;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[1][x],"X")==0 && strcmp(Tablero[2][x],"X")==0)
                {
                    if(strcmp(Tablero[0][x]," ")==0)
                    {
                        strcpy(Tablero[0][x],"O");
                        return Tablero;
                    }
                }
            }
          for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[2][x],"X")==0)
                {
                    if(strcmp(Tablero[1][x]," ")==0)
                    {
                        strcpy(Tablero[1][x],"O");
                        return Tablero;
                    }
                }
            }

    ////DEFENDER/////diagonales

            if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[2][2]," ")==0)
                {
                    strcpy(Tablero[2][2],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][2],"X")==0)
            {
                if(strcmp(Tablero[0][0]," ")==0)
                {
                    strcpy(Tablero[0][0],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[2][2],"X")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    return Tablero;
                }
            }
        /////////////////////////////////////////////////////////////////////////////////////////////////
            if(strcmp(Tablero[0][2],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[2][0]," ")==0)
                {
                    strcpy(Tablero[2][0],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[2][0],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[0][2]," ")==0)
                {
                    strcpy(Tablero[0][2],"O");
                    return Tablero;
                }
            }
            if(strcmp(Tablero[2][0],"X")==0 && strcmp(Tablero[0][2],"X")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    return Tablero;
                }
            }
          strcpy(Tipo_ficha,"O");
            do
        {
            bot=rand()%(9-1+1)+1;//el bot crea un numero
        }while(validar_lugar(Tablero,bot));//verifica que el valor dado no este ocupado
        Dato_ingresado(Tablero,bot, Tipo_ficha);
        return Tablero;
}

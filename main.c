#include <stdio.h>
#include <stdlib.h>
char Tablero[3][3][2],aux[15];
int movimiento=0,Victoria=0;
int main()
{//163 ñ
    srand(time(NULL));
    int x=0,y=0,fila=0,intrucciones=0,posicion;
    char Respuesta[15];

    llenado();//llena la matriz de " "
    gotoxy(1,2);
    printf("Bienvenidos al TATETI\t Creador:Paul Nahuel Mauro\n");//introduccion
    printf("  1   %c   2   %c   3\n",179,179);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  4   %c   5   %c   6\n",179,179);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  7   %c   8   %c   9\n",179,179);
    Ingresar_Base();
    Bot();
    Verificador_Empate(Victoria);//si es empate termina el partido
    Verificador_Vict(Victoria);//si el jugador 1 gano termina el partido
    while(1)//While general
    {
        while(1)//While del partido
        {
            mostrar();//muestra la matriz
            //Verificador_Vict();
            if(Victoria==1)
            {break;}
            printf("Player 1\n");//Turno del jugador 1
            do
            {
                printf("Ingrese el n%cmero que desea colocar la X\n",163);
                scanf("%d",&posicion);// pide la variable en tipo char para evitar errores
            }while(validar_lugar(posicion));//verifica que el valor ingresado no este ocupado
            Dato_ingresadoX(posicion);
            mostrar();//muestra la matriz
            Verificador_Empate();//si es empate termina el partido
            Verificador_Vict();//si el jugador 1 gano termina el partido
            if(Victoria==1)
            {break;}
            //Turno del Bot
            Bot();
            mostrar();//muestra la matriz
            Verificador_Empate();//si es empate termina el partido
            Verificador_Vict();//si la maquina gano termina el partido
            if(Victoria==1)
            {break;}
            //cierre del bot
        }//cierre del partido
       while(1)
        {
            printf("¿Desea volver jugar?");
            scanf("%s",&Respuesta);
            if(strcmp(Respuesta,"si")==0 || strcmp(Respuesta,"Si")==0 || strcmp(Respuesta,"SI")==0)
            {
                Victoria=0;llenado();break;
            }
            if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0)
            {
                return 0;
            }
        }
    }

}

void Ingresar_Base()//funcion para ingresar un tablero inicial para que la maquina responda a el
{
    char Respuesta[3];
    int lugar=0;
    while(1)
    {
        do
        {
            do
            {
                printf("¿Deseas ingresar una 'X'?");scanf("%s",&Respuesta);
            }while(validar_Respuesta(Respuesta));
            if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0)
            {
                break;
            }
            printf("Ingrese el n%cmero que desea colocar la X\n",163);
            scanf("%d",&lugar);
        }while(validar_lugar(lugar));//verifica que el valor ingresado no este ocupado
        if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0)
            {
                break;
            }
       Dato_ingresadoX(lugar);
       mostrar();
    }
    mostrar();
    while(1)
    {
        do
        {
            do
            {
                printf("¿Deseas ingresar una 'O'?");scanf("%s",&Respuesta);
            }while(validar_Respuesta(Respuesta));
            if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0)
            {
                break;
            }
            printf("Ingrese el n%cmero que desea colocar la O\n",163);
            scanf("%d",&lugar);
        }while(validar_lugar(aux));//verifica que el valor ingresado no este ocupado
        if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0 || strcmp(Respuesta,"NO")==0)
            {
                break;
            }
        Dato_ingresadoO(lugar);
        mostrar();
    }
}
void llenado() //funcion llenado de la matriz en nada
{
    int x,y;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            strcpy(Tablero[x][y]," ");
        }
    }
}
void mostrar()//funcion mostrar la matriz
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
int validar_lugar(int lugar2)//funcion validar que el lugar no este ocupado
{
    int fila=0;
    lugar2=lugar2-1;
        if(lugar2<=2 && lugar2>=0)
       {
           lugar2=lugar2;fila=0;
       }
       if (lugar2>=3 && lugar2<6)
       {
           lugar2=lugar2-3;fila=1;
       }
       if  (lugar2>=6 && lugar2<=8)
       {
           lugar2=lugar2-6;fila=2;
       }
       if(lugar2<0 || lugar2>=9)
       {
           printf("El lugar ingresado esta fuera de los terminos,vuelva a intentarlo\n");
           return 1;

       }
       if(strcmp(Tablero[fila][lugar2],"X")==0 || strcmp(Tablero[fila][lugar2],"O")==0)
       {
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
void Dato_ingresadoX(int lugar)//coloca el numero ingresado por el usuario en el lugar correcto
{
            if(lugar<4)//pone el valor donde corresponde en la matriz
            {strcpy(Tablero[0][lugar-1],"X");}
            if(lugar>=4 && lugar<7)
            {strcpy(Tablero[1][lugar-4],"X");}
            if(lugar>=7)
            {strcpy(Tablero[2][lugar-7],"X");}

}
void Dato_ingresadoO(lugar)//coloca el numero ingresado por el Bot en el lugar correcto
{
            if(lugar<4)//pone el valor donde corresponde en la matriz
            {strcpy(Tablero[0][lugar-1],"O");}
            if (lugar>=4 && lugar<7)
            {strcpy(Tablero[1][lugar-4],"O");}
            if  (lugar>=7)
            {strcpy(Tablero[2][lugar-7],"O");}
}
int Verificador_Vict()//Esta funcion verifica si el jugador 1 gano
{ int x=0;
for(x=0;x<3;x++)
    {
        if(strcmp(Tablero[x][0],Tablero[x][1])==0 && strcmp(Tablero[x][1],Tablero[x][2])==0)//filas
          {
              if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][1],"X")==0 && strcmp(Tablero[x][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Victoria=1;
                  return 0;
              }
              if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][1],"O")==0 && strcmp(Tablero[x][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
                  return 0;
              }
          }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(Tablero[0][x],Tablero[1][x])==0 && strcmp(Tablero[1][x],Tablero[2][x])==0)//columnas
          {
              if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[1][x],"X")==0 && strcmp(Tablero[2][x],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Victoria=1;
                  return 0;
              }if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[1][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
                  return 0;
              }
        }
    }
          if(strcmp(Tablero[0][0],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][2])==0)//diagonal
          {
              if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Victoria=1;
                  return 0;
              }
              if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
                  return 0;
              }
          }
          if(strcmp(Tablero[0][2],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][0])==0)//diagonal
          {
              if(strcmp(Tablero[0][2],"X")==0 && strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Victoria=1;
                  return 0;
              }
              if(strcmp(Tablero[0][2],"O")==0 && strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
                  return 0;;
              }
          }
          Victoria=0;
          return 0;
}
int Verificador_Empate(victoria)//funcion verifica que el partido termino en empate
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
        Victoria=1;
        return 0;
    }
    return 0;
}
void Bot()
{
    Atacar_bot();                         //si hay una posibilidad de ganar pueda ganar solo
    if(movimiento==0)
    {
        Defender_bot();                   //si no hay posibilidad de ganar que vaya a poder defender
    }
    if(movimiento==0)
    {
          movimiento_random_bot();       //si nada de las anteriores es posible hacer un movimiento random
    }
    movimiento=0;
}
void movimiento_random_bot()
{
    int bot=0;
    do
        {
            bot=rand()%(9-1+1)+1;//el vot crea un numero
        }while(validar_lugar(bot));//verifica que el valor dado no este ocupado
        Dato_ingresadoO(bot);
}
int Atacar_bot()
{
    int x;
    {//analiza las posibilidades de ganar en cada fila

            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][1],"O")==0)
                {
                    if(strcmp(Tablero[x][2]," ")==0)
                    {
                        strcpy(Tablero[x][2],"O");
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
                    }
                }
            }

    }
    {//Analiza las posiblidades de ganar en cada columna
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[1][x],"O")==0)
                {
                    if(strcmp(Tablero[2][x]," ")==0)
                    {
                        strcpy(Tablero[2][x],"O");
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
                    }
                }
            }
    }
    {//diagonales

            if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[2][2]," ")==0)
                {
                    strcpy(Tablero[2][2],"O");
                    movimiento=1;
                    return 0;
                }
            }

            if(strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][2],"O")==0)
            {
                if(strcmp(Tablero[0][0]," ")==0)
                {
                    strcpy(Tablero[0][0],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[2][2],"O")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                    return 0;
                }
            }
        /////////////////////////////////////////////////////////////////////////////////////////////////
            if(strcmp(Tablero[0][2],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[2][0]," ")==0)
                {
                    strcpy(Tablero[2][0],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[2][0],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[0][2]," ")==0)
                {
                    strcpy(Tablero[0][2],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[2][0],"O")==0 && strcmp(Tablero[0][2],"O")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                    return 0;
                }
            }
    }
}
int Defender_bot()
{
   int x;
    {//filas

            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][1],"X")==0)
                {
                    if(strcmp(Tablero[x][2]," ")==0)
                    {
                        strcpy(Tablero[x][2],"O");
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
                    }
                }
            }
    }
    {//columnas
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[1][x],"X")==0)
                {
                    if(strcmp(Tablero[2][x]," ")==0)
                    {
                        strcpy(Tablero[2][x],"O");
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
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
                        movimiento=1;
                        return 0;
                    }
                }
            }

    }
    {//diagonales
            if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[2][2]," ")==0)
                {
                    strcpy(Tablero[2][2],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][2],"X")==0)
            {
                if(strcmp(Tablero[0][0]," ")==0)
                {
                    strcpy(Tablero[0][0],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[2][2],"X")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                    return 0;
                }
            }
        /////////////////////////////////////////////////////////////////////////////////////////////////
            if(strcmp(Tablero[0][2],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[2][0]," ")==0)
                {
                    strcpy(Tablero[2][0],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[2][0],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[0][2]," ")==0)
                {
                    strcpy(Tablero[0][2],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(Tablero[2][0],"X")==0 && strcmp(Tablero[0][2],"X")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                    return 0;
                }
            }
    }
}

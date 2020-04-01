#include <stdio.h>
#include <stdlib.h>
char Tablero[3][3][2],Respuesta[15],aux[15];
int Victoria=0,lugar=0,bot=0,movimiento=0,contador_empate=0;
int main()
{//163 ñ
    srand(time(NULL));
    int x=0,y=0,fila=0,intrucciones=0;
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
    movimiento=0;
    while(1)//While del volver a jugar
    {
        while(1)//While del partido
        {
            system("cls");
            mostrar();//muestra la matriz
            while(1)//Turno del jugador 1
            {
                Verificador_VicO();
                Verificador_VicX();
                if(Victoria==1)
                {break;}
                textcolor(1);
                printf("Player 1\n");//muestra el mensaje en rojo
                textcolor(7);
                do
                {
                    printf("Ingrese el n%cmero que desea colocar la X\n",163);
                    scanf("%s",&aux);
                    validar_lugar_char(aux);
                }while(validar_lugar(lugar));//verifica que el valor ingresado no este ocupado
                Dato_ingresadoX();
                Verificador_Empate();//si hay un empate termina el partido
                system("cls");
                mostrar();//muestra la matriz
                Verificador_VicX();//si el jugador 1 gano termina el partido
                break;
            }//cierre del player 1
            Verificador_Empate();//si es empate termina el partido
            if(Victoria==1)
            {break;}
            //Turno del Bot
            Bot();
            system("cls");
            mostrar();//muestra la matriz
            Verificador_VicO();//si la maquina gano termina el partido
            if(Victoria==1)
            {break;}
            movimiento=0;//la variable movimiento se reinica para que el Bot pueda volver a jugar
            //cierre del bot
        }//cierre del partido
       do
        {
            printf("¿Desea volver jugar?");
            scanf("%s",&Respuesta);
        }while(validar_respuesta(Respuesta));
        if(strcmp(Respuesta,"no")==0 || strcmp(Respuesta,"No")==0)
        {break;}
        Victoria=0;llenado();
    }

}

void Ingresar_Base()//funcion para ingresar un tablero inicial para que la maquina responda a el
{
    while(1)
    {
        do
        {

            printf("Ingrese el n%cmero que desea colocar la X,si desea salir ingrese N\n",163);
            scanf("%s",&aux);
            if(strcmp(aux,"N")==0)
            {break;}
            validar_lugar_char(aux);//trans forma la varible char en int para evitar errores de cuando ingrese una letra
        }while(validar_lugar(lugar));//verifica que el valor ingresado no este ocupado
       Dato_ingresadoX();
       Verificador_Empate();//si hay un empate termina el partido
       system("cls");
       mostrar();//muestra la matriz
       Verificador_VicX();//si el jugador 1 gano termina el partido
       mostrar();
       if(strcmp(aux,"N")==0)
        {break;}
    }
    system("cls");
    while(1)
    {
        do
        {
            mostrar();
            printf("Ingrese el n%cmero que desea colocar la O,si desea salir ingrese N\n",163);
            scanf("%s",&aux);
            if(strcmp(aux,"N")==0)
            {break;}
            validar_lugar_char(aux);//trans forma la varible char en int para evitar errores de cuando ingrese una letra no deseada
        }while(validar_lugar(lugar));//verifica que el valor ingresado no este ocupado
        Dato_ingresadoO();
        system("cls");
        mostrar();//muestra la matriz
       if(strcmp(aux,"N")==0)
            {break;}
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
    gotoxy(1,2);
    printf("Bienvenidos al TATETI\t Creador:Paul Nahuel Mauro\n");//introduccion
    printf("  %s   %c   %s   %c   %s \n",Tablero[0][0],179,Tablero[0][1],179,Tablero[0][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Tablero[1][0],179,Tablero[1][1],179,Tablero[1][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Tablero[2][0],179,Tablero[2][1],179,Tablero[2][2]);
}
int validar_lugar_char(aux2)//funcion convertir el valor char en otra nueva variable como int
{
    if(strcmp(aux2,"1")==0)
    {
        lugar=1;
        return 0;
    }
    if(strcmp(aux2,"2")==0)
    {
        lugar=2;
        return 0;
    }
    if(strcmp(aux2,"3")==0)
    {
        lugar=3;
        return 0;
    }
    if(strcmp(aux2,"4")==0)
    {
        lugar=4;
        return 0;
    }
    if(strcmp(aux2,"5")==0)
    {
        lugar=5;
        return 0;
    }
    if(strcmp(aux2,"6")==0)
    {
        lugar=6;
        return 0;
    }
    if(strcmp(aux2,"7")==0)
    {
        lugar=7;
        return 0;
    }
    if(strcmp(aux2,"8")==0)
    {
        lugar=8;
        return 0;
    }
    if(strcmp(aux2,"9")==0)
    {
        lugar=9
        ;
        return 0;
    }

    return 1;
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
           printf("Este lugar ha sido ocupado\n");
           return 1;
       }
       return 0;
}
void Dato_ingresadoX()//coloca el numero ingresado por el usuario en el lugar correcto
{
            if(lugar<4)//pone el valor donde corresponde en la matriz
            {strcpy(Tablero[0][lugar-1],"X");}
            if (lugar>=4 && lugar<7)
            {strcpy(Tablero[1][lugar-4],"X");}
            if  (lugar>=7)
            {strcpy(Tablero[2][lugar-7],"X");}

}
void Dato_ingresadoO()//coloca el numero ingresado por el Bot en el lugar correcto
{
            if(lugar<4)//pone el valor donde corresponde en la matriz
            {strcpy(Tablero[0][lugar-1],"O");}
            if (lugar>=4 && lugar<7)
            {strcpy(Tablero[1][lugar-4],"O");}
            if  (lugar>=7)
            {strcpy(Tablero[2][lugar-7],"O");}


}
void Verificador_VicX()//Esta funcion verifica si el jugador 1 gano
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
              }
          }
          if(Victoria==1)
            {break;}
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
              }
        }
        if(Victoria==1)
            {break;}
    }
          if(strcmp(Tablero[0][0],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][2])==0)//diagonal
          {
              if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(Tablero[0][2],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][0])==0)//diagonal
          {
              if(strcmp(Tablero[0][2],"X")==0 && strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Player 1 win!!\n");
                  Victoria=1;
              }
          }
}
void Verificador_VicO()//funcion victoria del bot
{int x=0;
for(x=0;x<3;x++)
    {
        if(strcmp(Tablero[x][0],Tablero[x][1])==0 && strcmp(Tablero[x][1],Tablero[x][2])==0)//filas
          {
              if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][1],"O")==0 && strcmp(Tablero[x][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
              }
          }
          if(Victoria==1)
            {break;}
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(Tablero[0][x],Tablero[1][x])==0 && strcmp(Tablero[1][x],Tablero[2][x])==0)//columnas
          {
              if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[1][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
              }
        }
        if(Victoria==1)
            {break;}
    }
          if(strcmp(Tablero[0][0],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][2])==0)//diagonal
          {
              if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(Tablero[0][2],Tablero[1][1])==0 && strcmp(Tablero[1][1],Tablero[2][0])==0)//diagonal
          {
              if(strcmp(Tablero[0][2],"O")==0 && strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Player 2 win!!\n");
                  Victoria=1;
              }
          }
}
void Verificador_Empate()//funcion verifica que el partido termino en empate
{
    int x,y;
    contador_empate=0;
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
    }
}
int validar_respuesta(char res[2])//funcion que verifica que el valor ingresado este dentro de lo pedido
{
    if(strcmp(res,"si")==0 || strcmp(res,"Si")==0 || strcmp(res,"SI")==0)
    {
        return 0;
    }
    if(strcmp(res,"no")==0 || strcmp(res,"No")==0 || strcmp(res,"NO")==0)
    {
        return 0;
    }
    return 1;
}
void Bot()
{
    Atacar();   //hacer una funcion de si hay una posibilidad de ganar pueda ganar solo
    Defender(); //si no hay posibilidad de ganar que vaya a poder defender
    if(movimiento==0)
    {
          movimiento_random_bot();   //si nada de las anteriores es posible hacer un movimiento random
    }
}
void movimiento_random_bot()
{
    do
        {
            bot=rand()%(9-1+1)+1;//el vot crea un numero
        }while(validar_lugar(bot));//verifica que el valor dado no este ocupado
        lugar=bot;
        Dato_ingresadoO();
        movimiento=1;
}
void Atacar()
{
    int x;
    {//filas
        if(movimiento==0)
        {
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][1],"O")==0)
                {
                    if(strcmp(Tablero[x][2]," ")==0)
                    {
                        strcpy(Tablero[x][2],"O");
                        movimiento=1;
                    }
                }
            }
        }
        if(movimiento==0)
        {
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"O")==0 && strcmp(Tablero[x][2],"O")==0)
                {
                    if(strcmp(Tablero[x][1]," ")==0)
                    {
                        strcpy(Tablero[x][1],"O");
                        movimiento=1;
                    }
                }
            }
        }
       if(movimiento==0)
        {
           for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][1],"O")==0 && strcmp(Tablero[x][2],"O")==0)
                {
                    if(strcmp(Tablero[x][0]," ")==0)
                    {
                        strcpy(Tablero[x][0],"O");
                        movimiento=1;
                    }
                }
            }
        }

    }
    {//columnas
        if(movimiento==0)
        {
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[1][x],"O")==0)
                {
                    if(strcmp(Tablero[2][x]," ")==0)
                    {
                        strcpy(Tablero[2][x],"O");
                        movimiento=1;
                    }
                }
            }
        }
        if(movimiento==0)
        {
           for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[1][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
                {
                    if(strcmp(Tablero[0][x]," ")==0)
                    {
                        strcpy(Tablero[0][x],"O");
                        movimiento=1;
                    }
                }
            }
        }
        if(movimiento==0)
        {
          for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"O")==0 && strcmp(Tablero[2][x],"O")==0)
                {
                    if(strcmp(Tablero[1][x]," ")==0)
                    {
                        strcpy(Tablero[1][x],"O");
                        movimiento=1;
                    }
                }
            }
        }

    }
    {//diagonales
      if(movimiento==0)
        {
            if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[2][2]," ")==0)
                {
                    strcpy(Tablero[2][2],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[1][1],"O")==0 && strcmp(Tablero[2][2],"O")==0)
            {
                if(strcmp(Tablero[0][0]," ")==0)
                {
                    strcpy(Tablero[0][0],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[0][0],"O")==0 && strcmp(Tablero[2][2],"O")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////
        if(movimiento==0)
        {
            if(strcmp(Tablero[0][2],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[2][0]," ")==0)
                {
                    strcpy(Tablero[2][0],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[2][0],"O")==0 && strcmp(Tablero[1][1],"O")==0)
            {
                if(strcmp(Tablero[0][2]," ")==0)
                {
                    strcpy(Tablero[0][2],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[2][0],"O")==0 && strcmp(Tablero[0][2],"O")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                }
            }
        }
    }
}
void Defender()
{
   int x;
    {//filas
        if(movimiento==0)
        {
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][1],"X")==0)
                {
                    if(strcmp(Tablero[x][2]," ")==0)
                    {
                        strcpy(Tablero[x][2],"O");
                        movimiento=1;
                    }
                }
            }
        }
        if(movimiento==0)
        {
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][0],"X")==0 && strcmp(Tablero[x][2],"X")==0)
                {
                    if(strcmp(Tablero[x][1]," ")==0)
                    {
                        strcpy(Tablero[x][1],"O");
                        movimiento=1;
                    }
                }
            }
        }
       if(movimiento==0)
        {
           for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[x][1],"X")==0 && strcmp(Tablero[x][2],"X")==0)
                {
                    if(strcmp(Tablero[x][0]," ")==0)
                    {
                        strcpy(Tablero[x][0],"O");
                        movimiento=1;
                    }
                }
            }
        }

    }
    {//columnas
        if(movimiento==0)
        {
            for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[1][x],"X")==0)
                {
                    if(strcmp(Tablero[2][x]," ")==0)
                    {
                        strcpy(Tablero[2][x],"O");
                        movimiento=1;
                    }
                }
            }
        }
        if(movimiento==0)
        {
           for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[1][x],"X")==0 && strcmp(Tablero[2][x],"X")==0)
                {
                    if(strcmp(Tablero[0][x]," ")==0)
                    {
                        strcpy(Tablero[0][x],"O");
                        movimiento=1;
                    }
                }
            }
        }
        if(movimiento==0)
        {
          for(x=0;x<3;x++)
            {
                if(strcmp(Tablero[0][x],"X")==0 && strcmp(Tablero[2][x],"X")==0)
                {
                    if(strcmp(Tablero[1][x]," ")==0)
                    {
                        strcpy(Tablero[1][x],"O");
                        movimiento=1;
                    }
                }
            }
        }

    }
    {//diagonales
      if(movimiento==0)
        {
            if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[2][2]," ")==0)
                {
                    strcpy(Tablero[2][2],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[1][1],"X")==0 && strcmp(Tablero[2][2],"X")==0)
            {
                if(strcmp(Tablero[0][0]," ")==0)
                {
                    strcpy(Tablero[0][0],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[0][0],"X")==0 && strcmp(Tablero[2][2],"X")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////
        if(movimiento==0)
        {
            if(strcmp(Tablero[0][2],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[2][0]," ")==0)
                {
                    strcpy(Tablero[2][0],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[2][0],"X")==0 && strcmp(Tablero[1][1],"X")==0)
            {
                if(strcmp(Tablero[0][2]," ")==0)
                {
                    strcpy(Tablero[0][2],"O");
                    movimiento=1;
                }
            }
        }
        if(movimiento==0)
        {
            if(strcmp(Tablero[2][0],"X")==0 && strcmp(Tablero[0][2],"X")==0)
            {
                if(strcmp(Tablero[1][1]," ")==0)
                {
                    strcpy(Tablero[1][1],"O");
                    movimiento=1;
                }
            }
        }
    }
}




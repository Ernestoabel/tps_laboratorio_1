/*
 ============================================================================
 Name        : TP1.c
 Author      : Ernesto Abel Fatala
 Version     :
 Copyright   : Your copyright notice
 Description : Division J
 ============================================================================
 */

#include <stdio.h>
#include "listados.h"
#include "cargaDatos.h"
#include "calculos.h"

int main()
{
    setbuf(stdout,NULL);
    char opcion;
    char menu;
    int banderaHospedaje=1;
    int banderaComida=1;
    int banderaTransporte=1;
    int banderaMantenimiento=1;
    int banderaJugadores=1;
    int banderaCalculos=1;
    int banderaArq=1;
    int banderaDef=1;
    int banderaMed=1;
    int banderaDel=1;
    int banderaConfederacion=1;
    int banderaCarga=1;
    float montoHospedaje=0;
    float montoComida=0;
    float montoTransporte=0;
    float mantenimiento;
    char respuesta;
    int contArq=0;
    int contDef=0;
    int contMed=0;
    int contDel=0;
    char subMenu;
    char confederacion;
    int contAfc=0;
    int contCaf=0;
    int contConcacaf=0;
    int contConmebol=0;
    int contUefa=0;
    int contOfc=0;
    int contJugadores=0;
    int contConfederaciones=6;
    float promedioAfc=0;
    float promedioCaf=0;
    float promedioConcacaf=0;
    float promedioConmebol=0;
    float promedioUefa=0;
    float promedioOfc=0;
    float aumentoUefa;
    float mantenimientoUefa;

  do
    {
        opcion=menuprincipal(montoHospedaje,montoComida,montoTransporte,contArq,contDef,contMed,contDel);

        switch (opcion){
    	case '1':
    	    do{
        	    menu=menuMantenimiento();
        	    banderaCalculos=1;
                  switch (menu){
            	case '1':
                    montoHospedaje=ingresoFlotante();
                    banderaHospedaje = 0;
            	break;
            	case '2':
                    montoComida=ingresoFlotante();
                    banderaComida = 0;
            	break;
            	case '3':
                    montoTransporte=ingresoFlotante();
                    banderaTransporte = 0;
            	break;
            	case '4':
            	break;
            	}
                if(banderaHospedaje==0 && banderaComida==0 && banderaTransporte==0){
                	banderaMantenimiento = 0;
                }
            }while (menu != '4');
        break;
    	case '2':
    	    banderaJugadores = 0;
    	    do{
    	        if(banderaCarga==1){
    	        	banderaCalculos=1;
    	            ingresoEntero();

                    subMenu=menuPosiciones();

                    switch (subMenu){
                    case '1':
						if(banderaArq==1){
							banderaConfederacion=1;
							contArq++;
							contJugadores++;
						}
						if(contArq==2){
							banderaArq=0;
							printf("\n***La carga de arqueros esta completa***\n");
						}
                    break;
                    case '2':
						if(banderaDef==1){
							banderaConfederacion=1;
							contDef++;
							contJugadores++;
						}
						if(contDef==8){
							banderaDef=0;
							printf("\n***La carga de defensores esta completa***\n");
						}
                    break;
                    case '3':
						if(banderaMed==1){
							banderaConfederacion=1;
							contMed++;
							contJugadores++;
						}
						if(contMed==8){
							banderaMed=0;
							printf("\n***La carga de mediocampista esta completa***\n");
						}
                    break;
                    case '4':
						if(banderaDel==1){
							banderaConfederacion=1;
							contDel++;
							contJugadores++;
						}
						if(contDel==4){
							banderaDel=0;
							printf("\n***La carga de delanteros esta completa***\n");
						}
                    break;
                    }
					if(banderaConfederacion==1){
						confederacion=menuConfederacion();
						if(confederacion=='1'){
							contAfc++;
						}
						if(confederacion=='2'){
							contCaf++;
						}
						if(confederacion=='3'){
							contConcacaf++;
						}
						if(confederacion=='4'){
							contConmebol++;
						}
						if(confederacion=='5'){
							contUefa++;
						}
						if(confederacion=='6'){
							contOfc++;
						}
						banderaConfederacion=0;
						}
    	        }
    	        if(contJugadores==22){
    	            banderaCarga=0;
    	            printf("\n***El plantel esta completo***\n");
    	        }
                printf("\n¿Desea seguir cargando jugadores?");
                printf("\nIngrese s para salir: ");
                fflush(stdin);
                scanf("%c",&respuesta);
    	    }while(respuesta != 's');
    	break;
    	case '3':
    	    if (banderaMantenimiento == 1 || banderaJugadores == 1){
                printf ("\n***Faltan datos por ingresar***\n");
            }
            else{
                mantenimiento=montoHospedaje+montoComida+montoTransporte;

                promedioAfc=calculoPromedio(contAfc,contConfederaciones);
                promedioCaf=calculoPromedio(contCaf,contConfederaciones);
                promedioConcacaf=calculoPromedio(contConcacaf,contConfederaciones);
                promedioConmebol=calculoPromedio(contConmebol,contConfederaciones);
                promedioUefa=calculoPromedio(contUefa,contConfederaciones);
                promedioOfc=calculoPromedio(contOfc,contConfederaciones);

                if(promedioUefa>promedioAfc&&promedioUefa>promedioCaf&&promedioUefa>promedioConcacaf&&promedioUefa>promedioConmebol&&promedioUefa>promedioOfc){
                    aumentoUefa=mantenimiento*35/100;
                    mantenimientoUefa=aumentoUefa+mantenimiento;
                }
                printf("\n***Se realizaron los calculos***\n");
                banderaCalculos = 0;
            }
    	  break;
    	case '4':
    	    if (banderaMantenimiento == 1 || banderaJugadores == 1){
                printf ("\n***Faltan datos por ingresar***\n");
            }
            else if (banderaCalculos == 1){
                printf ("\n***No calculo los datos***\n");
            }
            else{
                mostrarCalculos(promedioUefa,promedioConmebol,promedioConcacaf,promedioAfc,promedioOfc,promedioCaf,mantenimiento);
                if(promedioUefa>promedioAfc&&promedioUefa>promedioCaf&&promedioUefa>promedioConcacaf&&promedioUefa>promedioConmebol&&promedioUefa>promedioOfc){
                    printf("\nEl aumento de los jugadores UEFA es de $%.2f entonces el total del mantenimiento es $%.2f\n",aumentoUefa,mantenimientoUefa);
                }
            }
    	  break;
    	case '5':
    	  break;
	    }
    }while (opcion != '5');

    return 0;
}

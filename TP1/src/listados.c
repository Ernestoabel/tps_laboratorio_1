#include <stdio.h>
/**
 * @brief Funcion validada para llamar un menu de 5 opciones y ademas mostrar datos cargados en las opciones 1 y 2 del mismo
 *
 * @param datoUno valor correspondiente al primer dato de la primera opcion del menu
 * @param datoDos valor correspondiente al segundo dato de la primera opcion del menu
 * @param datoTres valor correspondiente al tercer dato de la primera opcion del menu
 * @param contUno valor correspondiente al primer dato de la segunda opcion del menu
 * @param contDos valor correspondiente al segundo dato de la segunda opcion del menu
 * @param contTres valor correspondiente al tercer dato de la segunda opcion del menu
 * @param contCuatro valor correspondiente al cuarto dato de la segunda opcion del menu
 * @return Un entero validado como char para el ingreso de una de las opciones del menu y no se rompa con ingreso erroneo
 */
char menuprincipal(float datoUno,float datoDos,float datoTres,int contUno,int contDos,int contTres,int contCuatro){
    char opcion;
    printf("\n1. Ingreso de los costos de mantenimiento\n");
    printf("\nCosto de Hospedaje -> %.2f",datoUno);
    printf("\nCosto de Comida -> %.2f",datoDos);
    printf("\nCosto de Transporte -> %.2f\n",datoTres);
    printf("\n2. Carga de jugadores\n");
    printf("\nLos arqueros ingresados son -> %d",contUno);
    printf("\nLos defensores ingresados son -> %d",contDos);
    printf("\nLos mediocampistas ingresados son -> %d",contTres);
    printf("\nLos delanteros ingresados son -> %d\n",contCuatro);
    printf("\n3. Realizar todos los calculos");
    printf("\n4. Informar todos los resultados");
    printf("\n5. Salir del programa");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    while(opcion<'1'||opcion>'5'){
    	printf("\n--ERROR--\n");
    	printf("\n1. Ingreso de los costos de mantenimiento\n");
    	printf("\nCosto de Hospedaje -> %.2f",datoUno);
    	printf("\nCosto de Comida -> %.2f",datoDos);
    	printf("\nCosto de Transporte -> %.2f\n",datoTres);
    	printf("\n2. Carga de jugadores\n");
    	printf("\nLos arqueros ingresados son -> %d",contUno);
    	printf("\nLos defensores ingresados son -> %d",contDos);
    	printf("\nLos mediocampistas ingresados son -> %d",contTres);
    	printf("\nLos delanteros ingresados son -> %d\n",contCuatro);
    	printf("\n3. Realizar todos los calculos");
    	printf("\n4. Informar todos los resultados");
    	printf("\n5. Salir del programa");
    	printf("\nIngrese una opcion: ");
    	fflush(stdin);
    	scanf("%c",&opcion);
    }
    return opcion;
}
/**
 * @brief Funcion validada para un menu de 4 opciones
 *
 * @return Un entero validado como char para el ingreso de una de las opciones del menu y no se rompa con ingreso erroneo
 */
char menuMantenimiento(void){
    char opcion;
    printf("\n1. Ingrese costo de Hospedaje");
    printf("\n2. Ingrese costo de Comida");
    printf("\n3. Ingrese costo de Transporte");
    printf("\n4. Volver");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    while(opcion<'1'||opcion>'4'){
    	printf("\n--ERROR--\n");
    	printf("\n1. Ingrese costo de Hospedaje");
    	printf("\n2. Ingrese costo de Comida");
    	printf("\n3. Ingrese costo de Transporte");
    	printf("\n4. Volver");
    	printf("\nIngrese una opcion: ");
    	fflush(stdin);
    	scanf("%c",&opcion);
    }
    return opcion;
}
/**
 * @brief Funcion validada para un menu de 4 opciones
 *
 * @return Un entero validado como char para el ingreso de una de las opciones del menu y no se rompa con ingreso erroneo
 */
char menuPosiciones(void){
    char opcion;
    printf("\n1.Ingrese para cargar arquero");
    printf("\n2.Ingrese para cargar defensor");
    printf("\n3.Ingrese para cargar mediocampista");
    printf("\n4.Ingrese para cargar delantero");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    while(opcion<'1'||opcion>'4'){
    	printf("\n--ERROR--\n");
        printf("\n1.Ingrese para cargar arquero");
        printf("\n2.Ingrese para cargar defensor");
        printf("\n3.Ingrese para cargar mediocampista");
        printf("\n4.Ingrese para cargar delantero");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    return opcion;
}
/**
 * @brief Funcion validada para la carga de uno de los seis valores del menu
 *
 * @return Un entero validado como char para acceder a la carga de las variables y no se rompa
 */
char menuConfederacion(void){
    char opcion;
    printf("\nIngrese (1) AFC si juega en Asia");
    printf("\nIngrese (2) CAF si juega en Africa");
    printf("\nIngrese (3) CONCACAF si juega en Norteamerica");
    printf("\nIngrese (4) CONMEBOL si juega en Sudamerica");
    printf("\nIngrese (5) UEFA si juega en Europa");
    printf("\nIngrese (6) OFC si juega en Oceania");
    printf("\nIngreso: ");
    fflush(stdin);
    scanf("%c",&opcion);
    while(opcion<'1'||opcion>'6'){
    	printf("\n--ERROR--\n");
        printf("\nIngrese (1) AFC si juega en Asia");
        printf("\nIngrese (2) CAF si juega en Africa");
        printf("\nIngrese (3) CONCACAF si juega en Norteamerica");
        printf("\nIngrese (4) CONMEBOL si juega en Sudamerica");
        printf("\nIngrese (5) UEFA si juega en Europa");
        printf("\nIngrese (6) OFC si juega en Oceania");
        printf("\nIngreso: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    return opcion;
}
/**
 * @brief Funcion para mostrar por consola 7 valores
 *
 * @param datoUno valor correspendiente al promedio UEFA
 * @param datoDos valor correspendiente al promedio CONMEBOL
 * @param datoTres valor correspendiente al promedio CONCACAF
 * @param datoCuatro valor correspendiente al promedio AFC
 * @param datoCinco valor correspendiente al promedio OFC
 * @param datoSeis valor correspendiente al promedio CAF
 * @param datoSiete valor correspendiente al costo total de mantenimiento
 */
void mostrarCalculos(float datoUno,float datoDos,float datoTres,float datoCuatro,float datoCinco,float datoSeis,float datoSiete){
    printf("\nPromedio UEFA %.2f",datoUno);
    printf("\nPromedio CONMEBOL %.2f",datoDos);
    printf("\nPromedio CONCACAF %.2f",datoTres);
    printf("\nPromedio AFC %.2f",datoCuatro);
    printf("\nPromedio OFC %.2f",datoCinco);
    printf("\nPromedio CAF %.2f\n",datoSeis);
    printf("\nEl costo de mantenimiento es $%.2f\n",datoSiete);
}

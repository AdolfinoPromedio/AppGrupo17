#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

// Acciones

void edit(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    int campo;
    char str[2] = "\n";
    int key = 0;
    printf("\n¿Qué libro desea modificar?: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            while(key==0){
                printf("\n¿Qué campo desea modificar? \n");
                printf("\n(1) Título\n");
                printf("(2) Autor\n");
                printf("(3) Año\n");
                printf("(4) Número de estante\n");
                printf("(5) Sección\n");
                printf("(6) Piso\n");
                printf("(7) Edificio\n");
                printf("(8) Sede\n");
                printf("\nIngrese opción: ");
                scanf("%d", &campo);
                if (campo==1){
                    char new_title[60];
                    printf("\nIngrese nuevo título: ");
                    scanf("%s", &new_title);
                    strcpy(dato[i].titulo, new_title);
                }
                else if (campo==2){
                    char new_autor[60];
                    printf("\nIngrese nuevo autor: ");
                    scanf("%s", &new_autor);
                    strcpy(dato[i].autor, new_autor);
                }
                else if (campo==3){
                    char new_ano[60];
                    printf("\nIngrese nuevo año: ");
                    scanf("%s", &new_ano);
                    dato[i].ano = atoi(new_ano);
                }
                else if (campo==4){
                    char new_estante[60];
                    printf("\nIngrese nuevo número de estante: ");
                    scanf("%s", &new_estante);
                    dato[i].estante_numero = atoi(new_estante);
                }
                else if (campo==5){
                    char new_sec[60];
                    printf("\nIngrese nueva sección: ");
                    scanf("%s", &new_sec);
                    strcpy(dato[i].estante_seccion, new_sec);
                }
                else if (campo==6){
                    char new_piso[60];
                    printf("\nIngrese nuevo número de piso: ");
                    scanf("%s", &new_piso);
                    dato[i].piso = atoi(new_piso);
                }
                else if (campo==7){
                    char new_edificio[60];
                    printf("\nIngrese nuevo edificio: ");
                    scanf("%s", &new_edificio);
                    strcpy(dato[i].edificio, new_edificio);
                }
                else if (campo==8){
                    char new_sede[60];
                    printf("\nIngrese nueva sede: ");
                    scanf("%s", &new_sede);
                    strncat(new_sede, &str, 2);
                    strcpy(dato[i].sede, new_sede);
                }
                int decision;
                printf("\nDesea modificar nuevamente? (si [1] /no [2]): ");
                scanf("%d", &decision);
                if(decision==2){
                    key++;
                }
            }
        }
    }
}

void search_change(libro dato[], int cambio, int cantidad){
    char titulo[60];
    char *ret;
    char sede[60];
    char sec[60];
    char piso[20];
    char str[2] = "\n";
    printf("\nIngrese título del libro: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            if (cambio == 1){
                printf("\nIngrese nueva Sede: ");
                scanf("%s", &sede);
                strncat(sede, &str, 2);
                strcpy(dato[i].sede, sede);
            }
            else if (cambio == 2){
                printf("\nIngrese nueva Sección: ");
                scanf("%s", &sec);
                strcpy(dato[i].estante_seccion, sec);
            }
            else if (cambio == 3){
                printf("\nIngrese nuevo Piso: ");
                scanf("%s", &piso);
                dato[i].piso = atoi(piso);
            }
        }
    }
}

void change(libro dato[], int eleccion2, int cantidad){
    int cambio;
    char libro[60];
    //printf("\n¿Qué desea cambiar? Sede (1) - Sección (2) - Piso (3): ");
    //scanf("%d", &cambio);
    if (eleccion2 == 1){
        //Cambiar SEDE
        search_change(dato, eleccion2, cantidad);
    }
    else if (eleccion2 == 2){
        //Cambiar SECCIÓN
        search_change(dato, eleccion2, cantidad);
    }
    else if (eleccion2 == 3){
        //Cambiar PISO
        search_change(dato, eleccion2, cantidad);
    }
}

void find(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    printf("\nIngrese título del libro: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            printf("\nLibro: %s\n", dato[i].titulo);
            printf("Autor: %s\n", dato[i].autor);
            printf("Año: %d\n", dato[i].ano);
            printf("Número de estante: %d\n", dato[i].estante_numero);
            printf("Sección: %s\n", dato[i].estante_seccion);
            printf("Piso: %d\n", dato[i].piso);
            printf("Edificio: %s\n", dato[i].edificio);
            printf("Sede: %s\n", dato[i].sede);
        }
    }
}

void agregar_libro(libro dato[], int cantidad){

    char new_titulo[60];
    printf("\nIngrese título del libro: ");
    scanf("%s", &new_titulo);
    char new_autor[60];
    printf("\nIngrese autor del libro: ");
    scanf("%s", &new_autor);
    char new_ano[60];
    printf("\nIngrese año del libro: ");
    scanf("%s", &new_ano);
    char new_estante_numero[60];
    printf("\nIngrese número del estante del libro: ");
    scanf("%s", &new_estante_numero);
    char new_estante_seccion[60];
    printf("\nIngrese sección del estante del libro: ");
    scanf("%s", &new_estante_seccion);
    char new_piso[60];
    printf("\nIngrese piso del libro: ");
    scanf("%s", &new_piso);
    char new_edificio[60];
    printf("\nIngrese edificio del libro: ");
    scanf("%s", &new_edificio);
    char new_sede[60];
    printf("\nIngrese sede del libro: ");
    scanf("%s", &new_sede);

    int nro = cantidad + 1;
    strcpy(dato[nro].titulo, new_titulo);
    strcpy(dato[nro].autor, new_autor);
    dato[nro].ano = atoi(new_ano);
    dato[nro].estante_numero = atoi(new_estante_numero);
    strcpy(dato[nro].estante_seccion, new_estante_seccion);
    dato[nro].piso = atoi(new_piso);
    strcpy(dato[nro].edificio, new_edificio);
    strcpy(dato[nro].sede, new_sede);

}

void eliminar_libro(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    printf("\n¿Qué libro desea eliminar?: ");
    scanf("%s", &titulo);
    for (int i=0; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            dato[i].nro = 0;
            strcpy(dato[i].titulo, " ");
            strcpy(dato[i].autor, " ");
            dato[i].ano = 0;
            dato[i].estante_numero = 0;
            strcpy(dato[i].estante_seccion, " ");
            dato[i].piso = 0;
            strcpy(dato[i].edificio, " ");
            strcpy(dato[i].sede, " ");
        }
    }
}

//-------------------------------------------------------------------

//Menú

int menu_opciones(){
    int eleccion;
    // presentarcion de las opciones
    printf("1) Agregar/Quitar un libro nuevo :\n");
    printf("2) Agregar/Quitar una sede (condicion)\n");
    printf("3) Poder editar un libro:\n");
    printf("4) Cambiar un libro de sede/sección/piso:\n");
    printf("5) Agregar/eliminar seciones (condicion):\n");
    printf("6) Agregar/quitar pisos(condicion) :\n");
    printf("7) Buscar un libro :\n");
    printf("8) Salir del menu :\n");
    printf("\n");
    printf("Selecione una opcion: ");
    scanf("%d", &eleccion);
    printf("\n\n");

    return eleccion;
}

void agregar_quitar(libro dato[], int cantidad){

    int eleccion;
    printf("Seleciona si desea agregar (1) o quitar (2) un libro: ");
    scanf("%d", &eleccion);

    if(eleccion==1){
        printf("Agregar libro\n\n");
        agregar_libro(dato, cantidad);
    }
    else if(eleccion==2){
        printf("Quitar libro\n\n");
        eliminar_libro(dato, cantidad);
    }
}

void sede(libro dato[], int cantidad){
    int eleccion;
    int eleccion2;
    printf("Seleciona si desea agregar (1) o quitar(2) una sede: ");
    //el usuario debe ingresar una de las opciones
    scanf("%d", &eleccion);
    if(eleccion==1){
        printf("Desea añadir una sede añadiendo un libro (1) o cambiando la sede de un libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            agregar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 1, cantidad);
        }
    }
    else if(eleccion==2){
        printf("Desea quitar una sede quitando un libro (1), cambiando la sede de un libro (2), o eliminando todos los libros con esa sede (3): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            eliminar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 1, cantidad);
        }
        if(eleccion2==3){
            printf("Wn loco");
        }
    }
}

void editar(libro dato[], int cantidad){
    edit(dato, cantidad);
}

void cambiar(libro dato[], int cantidad){
    int accion;
    printf("Seleciona si desea cambiar un libro de sede(1)/sección(2)/piso(3): ");
    scanf("%d", &accion);
    change(dato, accion, cantidad);
    }

void seccion(libro dato[], int cantidad){
    int eleccion;
    int eleccion2;
    printf("Seleciona si agregar (1) o quitar (2) secciones (condicion): \n");
    scanf("%d", &eleccion);
    if(eleccion==1){
        printf("Desea añadir una seccion añadiendo un libro (1) o cambiando la seccion de un libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            agregar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 2, cantidad);
        }
    }
    else if(eleccion==2){
        printf("Desea quitar una sede quitando un libro (1), cambiando la seccion de un libro (2), o eliminando todos los libros con esa seccion (3): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            eliminar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 2, cantidad);
        }
        if(eleccion2==3){
            printf("Wn loco");
        }
    }
}

void piso(libro dato[], int cantidad){
    int eleccion;
    printf("Seleciona si agregar (1) o quitar (2) piso (condicion): \n");
    scanf("%d", &eleccion);
    int eleccion2;
    if(eleccion==1){
        printf("Desea añadir un piso añadiendo un libro (1) o cambiando el piso de un libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            agregar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 3, cantidad);
        }
    }
    else if(eleccion==2){
        printf("Desea quitar una sede quitando un libro (1), cambiando la sede de un libro (2), o eliminando todos los libros con esa sede (3): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            eliminar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 3, cantidad);
        }
        if(eleccion2==3){
            printf("Wn loco");
        }
    }
}

void buscarlibro(libro dato[], int cantidad){
    find(dato, cantidad);
}

void sub_menu(int eleccion, libro dato[], int cantidad){
    switch (eleccion)
    {
        case 1:
            agregar_quitar(dato, cantidad);
            break;
        case 2:
            sede(dato, cantidad);
            break;
        case 3:
            editar(dato, cantidad);
            break;
        case 4:
            cambiar(dato, cantidad);
            break;
        case 5:
            seccion(dato, cantidad);
            break;
        case 6:
            piso(dato, cantidad);
            break;
        case 7:
            buscarlibro(dato, cantidad);
            break;
        case 8:
            printf("Saliste del  menu");
            break;
        default:
            // solo si el usuario ingresa una opcion que no este comtemplada
            printf("Ingresar un numero que esté en la lista\n\n");

    }

}

//-------------------------------------------------------------------

// Funciones y procedimientos base
//-------------------------------------------------------------------

int cantidad_libros(FILE *the_file){
    char line[1000];
    int counter = -1;
    while (fgets(line, 1000, the_file) != NULL){
        counter++;
    }
    return counter;
}

void printValues(libro dato[],int cantidad){
    for (int i=1; i<cantidad+2; i++){
        printf("\n%d, %s; %s, %d, %d, %s, %d, %s, %s", dato[i].nro,dato[i].titulo, dato[i].autor, dato[i].ano, dato[i].estante_numero, dato[i].estante_seccion, dato[i].piso, dato[i].edificio, dato[i].sede);
    }
}

FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,"r");
    return fp;
}

FILE * closingFile(char *filename){
    FILE *fp2;
    fp2 = fopen(filename, "w+");
    return fp2;
}

void reewrite(FILE *the_file, libro dato[], int cantidad){
    fprintf(the_file, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
    for (int i=1; i<cantidad+2; i++){
        fprintf(the_file, "%s,%s,%d,%d,%s,%d,%s,%s",dato[i].titulo, dato[i].autor, dato[i].ano, dato[i].estante_numero, dato[i].estante_seccion, dato[i].piso, dato[i].edificio, dato[i].sede);
    }
    fclose(the_file);
}

libro* getLibros(FILE *the_file){

    libro *dato = (libro*) malloc(5000*sizeof(libro));

    char line[1000];
    char *sp;
    int row_count = 1;
    int counter = 1;
    int i = 1;

    while (fgets(line, 1000, the_file) != NULL){

        int a = 0;
        dato[i].nro = counter;

        if (row_count == 1){
            row_count++;
            continue;
        }

        if (line[0] == '"'){
            sp = strtok(line, "\"");
            a++;
        }

        if (a == 0){
            sp = strtok(line, ",");
        }

        strcpy(dato[i].titulo, sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].autor, sp);
        sp = strtok(NULL, ",");

        dato[i].ano = atoi(sp);
        sp = strtok(NULL, ",");

        dato[i].estante_numero = atoi(sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].estante_seccion, sp);
        sp = strtok(NULL, ",");

        dato[i].piso = atoi(sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].edificio, sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].sede, sp);
        sp = strtok(NULL, ",");

        i++;
        counter++;
    }

    for (int i=counter; i<counter+3; i++){
        dato[i].nro = i;
        strcpy(dato[i].titulo, " ");
        strcpy(dato[i].autor, " ");
        dato[i].ano = 0;
        dato[i].estante_numero = 0;
        strcpy(dato[i].estante_seccion, " ");
        dato[i].piso = 0;
        strcpy(dato[i].edificio, " ");
        strcpy(dato[i].sede, " ");
    }

    fclose(the_file);
    return dato;
}

void showContentAsStruct(FILE *the_file, int cantidad, char* filename){

    if (the_file==NULL){
        printf("ERROR");
        exit(0);
    }
    libro *dato = getLibros(the_file);

    int valor_menu = menu_opciones();
    sub_menu(valor_menu, dato, cantidad);

    FILE *inventario = closingFile(filename);
    reewrite(inventario, dato, cantidad);
}

//-------------------------------------------------------------------

int main() {

    FILE *the_file = openingFile("inventario.csv");
    FILE *the_file2 = openingFile("inventario.csv");
    int bucle = 1;


    int a = cantidad_libros(the_file);
    showContentAsStruct(the_file2, a, "inventario.csv");
    int fin;
    //printf("\nHecho. (1) Si desea realizar otra acción, cualquier otro si desea salir.");
    //scanf("%d", &bucle);


    return 0;
}

#include "listaSimple.h"
#include <string.h>

nodoPaciente* inicLista(){
    return NULL;
}

nodoPaciente* crearnodoPaciente(stPaciente dato){
    nodoPaciente* nuevo = (nodoPaciente*) malloc(sizeof(nodoPaciente));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodoPaciente* agregarAlPrincipio(nodoPaciente* lista, nodoPaciente* nuevonodoPaciente){
    if(lista==NULL){
        lista = nuevonodoPaciente;
    }else{
        nuevonodoPaciente->siguiente = lista;
        lista = nuevonodoPaciente;
    }
    return lista;
}

void muestraUnPaciente (stPaciente a)
{
    printf("-----------------------------\n");
    printf("\nID DEL PACIENTE:...: %d", a.idPaciente);
    printf("\nNOMBRE.............: %s", a.nombrePaciente);
    printf("\nAPELLIDO...........: %s", a.apellidoPaciente);
    printf("\nDIAGNOSTICO........: %s", a.diagnostico);
    printf("\nFEHCA ATENCION.....: %s", a.fechaAtencion);
    printf("\nNOMBRE DOCTOR......: %s\n", a.nombreDoctor);
}

void muestraListaPaciente(nodoPaciente * listaPacientes){
    printf("\n nodoPaciente: %p - nodoPaciente->siguiente: %p\n",  listaPacientes, listaPacientes->siguiente);
    muestraUnPaciente(listaPacientes->dato);
}

void muestraLista(nodoPaciente* lista){
    nodoPaciente* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraListaPaciente(seg);
        seg = seg->siguiente;
    }
}

nodoPaciente* buscarUltimo(nodoPaciente* lista){
    nodoPaciente* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

int buscarPaciente(nodoPaciente* lista, char nombre[], char apellido[]){
    nodoPaciente* seg = lista;
    int flag = 0;
    while(seg && flag == 0){
        if (strcmp(nombre, seg->dato.nombrePaciente) == 0 && strcmp(apellido, seg->dato.apellidoPaciente) == 0){
            flag = 1;
        }
        seg = seg->siguiente;
    }
    return flag;
}

nodoPaciente* agregarAlFinal(nodoPaciente* lista, nodoPaciente* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nodoPaciente* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

nodoPaciente* borrarLista(nodoPaciente* lista){
    nodoPaciente* proximo;
    nodoPaciente* seg = lista;
    while(seg){
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodoPaciente* eliminarUltimonodoPaciente(nodoPaciente* lista){
    nodoPaciente* aux = lista;
    nodoPaciente* ante;
    while(aux->siguiente){    /// es igual a while(aux->siguiente != NULL)
        ante = aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

nodoPaciente* eliminarPrimernodoPaciente(nodoPaciente* lista){
    nodoPaciente* aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

int cuentaLista(nodoPaciente* lista){
    nodoPaciente* seg=lista;
    int cont=0;
    while(seg){
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}

stPaciente verPrimero(nodoPaciente* lista){
    return lista->dato;
}

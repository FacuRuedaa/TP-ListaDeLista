#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char nombreDoctor[30];
}stPaciente;

typedef struct {
   stPaciente dato;
   struct nodoPaciente *siguiente;
}nodoPaciente;

nodoPaciente* inicLista();
nodoPaciente* crearnodoPaciente(stPaciente dato);
nodoPaciente* agregarAlPrincipio(nodoPaciente* lista, nodoPaciente* nuevonodoPaciente);
void muestraUnPaciente (stPaciente a);
void muestraListaPaciente(nodoPaciente * listaPacientes);
void muestraLista(nodoPaciente* lista);
nodoPaciente* buscarUltimo(nodoPaciente* lista);
nodoPaciente* agregarAlFinal(nodoPaciente* lista, nodoPaciente* nuevo);
nodoPaciente* borrarLista(nodoPaciente* lista);
nodoPaciente* eliminarPrimernodoPaciente(nodoPaciente* lista);
int cuentaLista(nodoPaciente* lista);
stPaciente verPrimero(nodoPaciente* lista);
int buscarPaciente(nodoPaciente* lista, char nombre[], char apellido[]);

#endif // LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registroArchivo.h"
#include "listaSimple.h"

typedef struct{
    int idEspecialidad;
    char especialidadMedica[30];
    nodoPaciente* listaDePacientes;
    struct nodoLista *siguiente;
} nodoLista;

nodoLista* inicListaEspecialidad();
nodoLista* crearNodoEspecialidad(int nroEspecialidad, char especialidad[]);
nodoLista* agregarAlPrincipioEspecialidad(nodoLista* lista, nodoLista* nuevo);
void muestraListaEspecialidad(nodoLista* lista);
void muestraUnaEspecialidad (nodoLista* a);
nodoLista* pasarArchToLista (nodoLista* lista, char archivo[]);
nodoLista * alta (nodoLista *lista, nodoPaciente * nuevoPac, int nroEsp, char especialidad[]);
nodoLista * BuscarEspecialidad(nodoLista * lista, int nroEsp);


int main()
{
    nodoLista* listaEspecialidades = inicListaEspecialidad();

    listaEspecialidades = pasarArchToLista(listaEspecialidades, arRegistro);

    muestraListaEspecialidad(listaEspecialidades);

    return 0;
}


nodoLista* inicListaEspecialidad(){
    return NULL;
}

nodoLista* crearNodoEspecialidad(int nroEspecialidad, char especialidad[]){
    nodoLista* nuevo = (nodoLista*) malloc(sizeof(nodoPaciente));
    nuevo->idEspecialidad = nroEspecialidad;
    strcpy(nuevo->especialidadMedica, especialidad);
    nuevo->listaDePacientes = inicLista();
    nuevo->siguiente = NULL;
    return nuevo;
}

nodoLista* agregarAlPrincipioEspecialidad(nodoLista* lista, nodoLista* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

void muestraListaEspecialidad(nodoLista* lista){
    nodoLista* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraUnaEspecialidad(seg);
        muestraLista(seg->listaDePacientes);
        seg = seg->siguiente;
    }
}

void muestraUnaEspecialidad (nodoLista* a)
{
    printf("-----------------------------\n");
    printf("\nID DE LA ESPECIALIDAD...: %d", a->idEspecialidad);
    printf("\nESPECIALIDAD............: %s", a->especialidadMedica);
    printf("\n-----------------------------\n");
    printf("\nPACIENTES: \n");
}

nodoLista* pasarArchToLista (nodoLista* lista, char archivo[]){
    FILE * pArchRegistro = fopen(archivo, "rb");
    stRegistroMedico r;
    stPaciente p;

    if (pArchRegistro){
        while (fread(&r, sizeof(stRegistroMedico), 1, pArchRegistro)>0){
            p.idPaciente = r.idPaciente;
            strcpy(p.apellidoPaciente, r.apellidoPaciente);
            strcpy(p.diagnostico, r.diagnostico);
            strcpy(p.fechaAtencion, r.fechaAtencion);
            strcpy(p.nombreDoctor, r.nombreDoctor);
            strcpy(p.nombrePaciente, r.nombrePaciente);
            nodoPaciente* paciente = crearnodoPaciente(p);
            lista = alta(lista, paciente, r.idEspecialidad, r.especialidadMedica);
        }
        fclose(pArchRegistro);
    }
    return lista;
}


nodoLista * alta (nodoLista *lista, nodoPaciente * nuevoPac, int nroEsp, char especialidad[])
{
    nodoLista *espEncontrada = BuscarEspecialidad(lista, nroEsp);
    if(espEncontrada==NULL)
    {
        nodoLista *aux = crearNodoEspecialidad(nroEsp, especialidad);
        lista = agregarAlPrincipioEspecialidad(lista, aux);
        lista->listaDePacientes = agregarAlFinal(lista->listaDePacientes, nuevoPac);
    } else{
        espEncontrada->listaDePacientes = agregarAlFinal(espEncontrada->listaDePacientes, nuevoPac);
    }
    return lista;
}

nodoLista * BuscarEspecialidad(nodoLista * lista, int nroEsp)
{
    nodoLista * seg = lista;
    nodoLista *espEncontrada = NULL;
    int flag = 0;
        while(seg!= NULL && flag == 0)
        {
            if(seg->idEspecialidad == nroEsp)
            {
                espEncontrada = seg;
                flag=1;
            }
            seg = seg->siguiente;
        }
    return espEncontrada;
}

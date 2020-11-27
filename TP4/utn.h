#include "LinkedList.h"
#include <stdio.h>

#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int parser_PersonaFromText(FILE* pFile , LinkedList* pArrayListPersona);
int parser_PersonaFromBinary(FILE* pFile , LinkedList* pArrayListPersona);
int leerArchivoTexto(LinkedList* lista);
int leerArchivoBinario(LinkedList* lista);
int cargaDatos(LinkedList* lista);
int imprimirTamanio(LinkedList* lista);
int cargaNuevoElemento(LinkedList* lista, int id);
int guardarBinario(LinkedList* lista);

#endif // UTN_H_INCLUDED



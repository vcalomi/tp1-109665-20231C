#include "tp1.h"

#include "pokemon.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _hospital_pkm_t {
	pokemon_t **pokemones;
	size_t cantidad_pokemon;
	size_t cantidad_entrenadores;
};

hospital_t *hospital_crear_desde_archivo(const char *nombre_archivo)
{
	return NULL;
}

size_t hospital_cantidad_pokemones(hospital_t *hospital)
{
	return hospital->cantidad_pokemon; //devolver cantidad pokemon?
}

size_t hospital_a_cada_pokemon(hospital_t *hospital,
			       bool (*funcion)(pokemon_t *p, void *aux),
			       void *aux)
{
	size_t cant_veces_invocada = 0;
	size_t i = 0;
	while (i < hospital->cantidad_pokemon) {
		if (funcion(hospital->pokemones[i], aux) == false)
			return cant_veces_invocada;
		cant_veces_invocada++;
		i++;
	}

	return cant_veces_invocada;
	// creo un contador para el limite de iteracion y uno para la cantidad de veces que se aplico la funcion, si la funcion es false con algun pokemon
	// devuelvo el contador, sino sigo aumentando el contador de la funcion y el de la iteracion hasta que finalice y devuelvo el contador de la funcion nuevamente.
}

int hospital_aceptar_emergencias(hospital_t *hospital,
				 pokemon_t **pokemones_ambulancia,
				 size_t cant_pokes_ambulancia)
{
	hospital->pokemones =
		realloc(hospital->pokemones,
			sizeof(pokemones_ambulancia) *
				cant_pokes_ambulancia); //esto es raro, fijarse

	if (hospital->pokemones == NULL)
		return ERROR; // fallo realloc

	for (size_t i = hospital->cantidad_pokemon;
	     i < cant_pokes_ambulancia + hospital->cantidad_pokemon; i++) {
		hospital->pokemones[i] =
			pokemones_ambulancia[i - hospital->cantidad_pokemon];
		// funcion itera desde la ultima posicion del vector de pokemones hasta la ultima nueva posicion posible, ej:
		// si tengo 7 pokemones en hospital e ingresan 3 pokemones, i arranca en 7 y va hasta 10. y agrego en la posicion de i
		// el pokemon en la posicion i-los pokemones que habia de los que hay en la ambulancia.
		// quizas hay que ordenar los pokemones ingresados
	}

	return EXITO;
}

pokemon_t *hospital_obtener_pokemon(hospital_t *hospital, size_t prioridad)
{
	if ((hospital->pokemones[0]) == NULL)
		return NULL;
	return hospital->pokemones[0]; // devolver pokemon en posicion cero?
}

void hospital_destruir(hospital_t *hospital)
{
	for (size_t i = 0; i < hospital->cantidad_pokemon; i++) {
		free(hospital->pokemones[i]);
	}
	free(*hospital->pokemones);
	free(hospital); // liberar cada pokemon, luego el vector de pokemones y luego el hospital?
}

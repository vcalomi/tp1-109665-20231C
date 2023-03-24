#include "pokemon.h"
#include <string.h>
#include <stdio.h>
#include "pokemon_privado.h"

pokemon_t *pokemon_crear_desde_string(const char *string)
{
	return NULL;
}

pokemon_t *pokemon_copiar(pokemon_t *poke)
{
	if (poke == NULL) // chequeo que el puntero recibido no sea null
		return NULL;

	pokemon_t *copia_poke = malloc(sizeof(
		pokemon_t)); // reservo memoria para la copia y me fijo que no haya fallado
	if (copia_poke == NULL)
		return NULL;

	copia_poke =
		poke; // guardo el pokemon en la copia, quizas hay que usar la otra funcion (mcmcpy algo asi)
	return copia_poke; // devuelvo la copia
}

bool pokemon_son_iguales(pokemon_t *pokemon1, pokemon_t *pokemon2)
{
	if (pokemon1 == NULL || pokemon2 == NULL)
		return NULL;

	if (pokemon1->id == pokemon2->id &&
	    pokemon1->nombre == pokemon2->nombre)
		return true;
	return false; // quizas hay que chequear la salud y los entrenadores tambien
}

char *pokemon_nombre(pokemon_t *pokemon)
{
	if (pokemon == NULL)
		return NULL;
	return pokemon
		->nombre; // si el puntero recibido es valido devuelvo el nombre
}

char *pokemon_entrenador(pokemon_t *pokemon)
{
	if (pokemon == NULL)
		return NULL;

	return pokemon->nombre_entrenador;
}

size_t pokemon_salud(pokemon_t *pokemon)
{
	if (pokemon == NULL)
		return NULL;
	return pokemon->salud;
}

size_t pokemon_id(pokemon_t *pokemon)
{
	if (pokemon == NULL)
		return NULL;
	return pokemon->id;
}

void pokemon_destruir(pokemon_t *pkm)
{
	free(pkm);
}

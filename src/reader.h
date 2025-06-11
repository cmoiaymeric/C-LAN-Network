#pragma once

#include <stdint.h>
#include "reseau.h"
/**
 * @brief Lit un fichier de configuration pour initialiser un réseau.
 * 
 * Cette fonction ouvre le fichier spécifié par file_name, lit les informations
 * sur les machines (stations et switches) ainsi que les connexions, puis
 * remplit la structure Reseau passée en paramètre.
 * 
 * @param file_name Nom du fichier de configuration à lire
 * @param reseau Pointeur vers la structure Reseau à initialiser
 */
void read_config_file(char* file_name, Reseau* reseau);
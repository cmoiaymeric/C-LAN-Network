#pragma once
#include "machine.h"
#include "trame.h"
#include <stdint.h>

#ifndef RESEAU_H
#define RESEAU_H

/**
 * @brief Structure représentant un réseau informatique composé de machines et de connexions.
 */
typedef struct Reseau {
  uint16_t nb_machines; // Ordre du graphe / nb machines du reseau
  uint16_t machines_capacite; // Capacité initiale de machines (tu tableau de machines)
  Machine* machines;  // Tableau contenant les machines
  Connexion* connexions; // Arêtes
  uint16_t nb_connexions; // Nombre d'arêtes / connexions du reseau
  uint16_t connexions_capacite; // Capacité du tableau de connexions
} Reseau;

/**
 * @brief Initialise un réseau en allouant les ressources nécessaires.
 * @param reseau Pointeur vers le réseau à initialiser.
 */
void init_reseau(Reseau* reseau);

/**
 * @brief Libère les ressources associées au réseau.
 * @param reseau Pointeur vers le réseau à désinitialiser.
 */
void deinit_reseau(Reseau* reseau);
void deinit_reseau_complet(Reseau* reseau);

/**
 * @brief Renvoie le nombre de machines dans le réseau.
 * @param reseau Pointeur vers le réseau.
 * @return Nombre de machines.
 */
uint16_t nb_machines(Reseau* reseau);

/**
 * @brief Renvoie le nombre de connexions dans le réseau.
 * @param reseau Pointeur vers le réseau.
 * @return Nombre de connexions.
 */
uint16_t nb_connexions(Reseau* reseau);

/**
 * @brief Vérifie si un indice de machine est valide dans le réseau.
 * @param reseau Pointeur vers le réseau.
 * @param machine Indice de la machine à vérifier.
 * @return Indice si valide, UINT16_MAX sinon.
 */
uint16_t index_machine(Reseau* reseau, machine_t machine);
/**
 * @brief Ajoute une machine dans le réseau, en allouant plus d’espace si nécessaire.
 * @param reseau Pointeur vers le réseau.
 * @param machine Machine à ajouter.
 */
void ajouter_machine(Reseau* reseau, Machine machine);
/**
 * @brief Ajoute une connexion entre machines dans le réseau, en allouant plus d’espace si nécessaire.
 * @param reseau Pointeur vers le réseau.
 * @param connexion Connexion à ajouter.
 */
void ajouter_connection(Reseau* reseau, Connexion connexion);

/**
 * @brief Affiche les informations détaillées sur le réseau (machines et connexions).
 * @param reseau Pointeur vers le réseau.
 */
void afficher_reseau(Reseau* reseau);

machine_t get_machine_par_mac(Reseau* reseau, Mac mac);

machine_t degre_machine(Reseau* reseau, machine_t machine);
void machines_connectees(Reseau* reseau, machine_t machine, machine_t* connectees); 


void def_priorite_switch(Reseau* reseau, machine_t machine, uint16_t priorite);
machine_t get_switch_racine(Reseau* reseau);

void transfert_trame(Reseau* reseau, Trame trame, machine_t passerelle, machine_t ancien);
void envoyer_trame(Reseau* reseau, Trame trame);
void recevoir_trame(Reseau* reseau, Trame trame, machine_t destination, machine_t ancien);
void envoyer_ping(Reseau* reseau, Mac source, Mac destination);

#endif
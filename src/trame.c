#include "trame.h"

/**
 * @brief Initialise une trame Ethernet avec les informations fournies.
 * 
 * @param trame        Pointeur vers la structure Trame à initialiser.
 * @param sourceMac    Adresse MAC source.
 * @param destMac      Adresse MAC destination.
 * @param type         Type de la trame (valeur personnalisée ou type Ethernet).
 * @param data         Contenu des données (payload) à insérer dans la trame.
 */
void init_trame(Trame *trame, Mac* sourceMac, Mac* destMac, uint16_t type, char *data)
{
    trame->SFD = 171; // Start Frame Delimiter : valeur fixe indiquant le début de la trame

    // Copie des octets de l'adresse MAC source
    for (uint8_t i = 0; i < 6; i++)
    {
        trame->addrSource.octets[i] = sourceMac->octets[i];
    }

    // Copie des octets de l'adresse MAC destination
    for (uint8_t i = 0; i < 6; i++)
    {
        trame->addrDestination.octets[i] = destMac->octets[i];
    }

    // Affectation du type de trame
    trame->type = type;

    // Copie des données caractère par caractère
    for (int i = 0; i < strlen(data); i++)
    {
        trame->data[i] = data[i];
    }

    // Ajout du caractère nul à la fin de la chaîne
    trame->data[strlen(data)] = '\0';
    // FCS (Frame Check Sequence) à 0 (non calculé ici)
    trame->FCS = 0;
}

/**
 * @brief Réinitialise les champs d'une trame à 0 et libère la mémoire si nécessaire.
 * 
 * @param trame   Pointeur vers la structure Trame à désinitialiser.
 */
void deinit_trame(Trame *trame)
{
    trame->SFD = 0;
    
    free(trame->addrSource.octets);
    for (int i = 0; i < 6; i++) {
        trame->addrSource.octets[i] = 0;
    }

    free(trame->addrDestination.octets);
    for (int i = 0; i < 6; i++) {
        trame->addrDestination.octets[i] = 0;
    }

    trame->type = 0;
    trame->FCS = 0;
}
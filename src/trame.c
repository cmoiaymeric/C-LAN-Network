#include "headers/trame.h"

/**
 * @brief Initialise une trame Ethernet avec les informations fournies.
 * 
 * @param trame        Pointeur vers la structure Trame à initialiser.
 * @param sourceMac    Adresse MAC source.
 * @param destMac      Adresse MAC destination.
 * @param type         Type de la trame (valeur personnalisée ou type Ethernet).
 * @param data         Contenu des données (payload) à insérer dans la trame.
 */
void init_trame(Trame *trame, Mac* sourceMac, Mac* destMac, typeTrame type, char *data)
{
    trame->Preambule = 0xAAAAAAAAAAAAAAAB; // Correspond à 1010...1010 10101011

    trame->TTL = 64;

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
    trame->Preambule = 0;
    trame->TTL = 0;

    // Réinitialisation de l'adresse MAC source
    for (uint8_t i = 0; i < 6; i++)
    {
        trame->addrSource.octets[i] = 0;
    }

    // Réinitialisation de l'adresse MAC destination
    for (uint8_t i = 0; i < 6; i++)
    {
        trame->addrDestination.octets[i] = 0;
    }

    trame->type = 0;

    // Réinitialisation des données
    for (int i = 0; i < strlen(trame->data); i++)
    {
        trame->data[i] = 0;
    }

    trame->FCS = 0;
}

void afficher_trame_user(Trame *trame)
{
    char* adr_mac_src = malloc(18);
    char* adr_mac_dest = malloc(18);
    printf("Adresse MAC source: %s\n", mac_to_string(trame->addrSource, adr_mac_src));
    free (adr_mac_src);
    adr_mac_src = NULL;
    
    printf("Adresse MAC destination: %s\n", mac_to_string(trame->addrDestination, adr_mac_dest));
    free (adr_mac_dest);
    adr_mac_dest = NULL;

    printf("Données : %s\n", trame->data);
}

void afficher_trame_hexa(Trame* trame){

    char* str_adr_src = malloc(18);
    char* str_adr_dest = malloc(18);
    char* str_adr_macs = malloc(36); // 2 * 18 pour les deux adresses MAC + 1 pour le caractère nul
    str_adr_src[0] = '\0'; // initialisation
    str_adr_dest[0] = '\0'; // Initialiser la chaîne vide
    str_adr_macs[0] = '\0'; // Initialiser la chaîne vide


    for (uint8_t i = 0; i < 6; i++) {
        char temp[4]; // variable temporaire 
        sprintf(temp, "%02hhx", trame->addrSource.octets[i]); // sprintf utilisé pour formater et concatener la chaine de caractères
        strcat(str_adr_src, temp);

        if (i < 5) strcat(str_adr_src," ");
    }

    for (uint8_t i = 0; i < 6; i++) {
        char temp[4]; // variable temporaire 
        sprintf(temp, "%02hhx", trame->addrDestination.octets[i]); // sprintf utilisé pour formater et concatener la chaine de caractères
        strcat(str_adr_dest, temp);

        if (i < 5) strcat(str_adr_dest," ");
    }
    strcat(str_adr_macs, str_adr_dest);
    strcat(str_adr_macs, " ");
    strcat(str_adr_macs, str_adr_src);

    free(str_adr_src);
    str_adr_src = NULL;
    free(str_adr_dest);
    str_adr_dest = NULL;

    int macs_len = strlen(str_adr_macs)-1;

    int data_len = strlen(trame->data);
    char* data_hexa = malloc(data_len * 2 + 1); // +1 pour le caractère nul de fin

    int trame_len = data_len + macs_len;
    char* trame_hexa = malloc((trame_len * 2 + 1)); // + 1 pour le caractère nul de fin
    trame_hexa[0] = '\0'; // Initialiser la chaîne vide

    int hex_index_data = 0;
    for (int i = 0; i < data_len; i++) {
        char byte = trame->data[i];
        int written = sprintf(&data_hexa[hex_index_data], "%x", byte);

        if (written < 0) {
            perror("Erreur lors de la conversion en hexadécimal");
            free(data_hexa);
            return;
        }
        hex_index_data += 2;
    }
    strcat(trame_hexa, str_adr_macs); // Ajouter le caractère nul de fin
    strcat(trame_hexa, " ");
    strcat(trame_hexa, data_hexa);
    printf("Trame en hexadécimal : %s\n", trame_hexa);

    // Libération de la mémoire
    free(str_adr_macs);
    str_adr_macs = NULL;
    free(trame_hexa);
    trame_hexa = NULL;
    free(data_hexa);
    data_hexa = NULL;
}
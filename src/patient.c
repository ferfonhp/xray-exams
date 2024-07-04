#include "patient.h"

#include <time.h>
#include <stdlib.h>

typedef struct patient {
    int id;
    char *name;
    struct tm* birthdate;
} patient;

// Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada. 
Patient *create_patient(int id, const char *name, struct tm *birthdate){
    Patient *new_patient = (Patient *)malloc(sizeof(Patient));

    if(new_patient == NULL){
        perror("Failed to allocate memory for Patient");
        exit(EXIT_FAILURE);
    }   

    new_patient->id = id;
    new_patient->name = name;
    new_patient->birthdate = birthdate;

    return new_patient;
}

// Libera a memória alocada para a estrutura do paciente. 
void destroy_patient(Patient *patient){
    free(patient->birthdate);
    free(patient);
}

// Retorna a identificação única do paciente. 
int get_patient_id(const Patient *patient){
    return patient->id;
}

// Retorna o nome do paciente.
const char *get_patient_name(const Patient *patient){
    return patient->name;
}

// Retorna a data de nascimento do paciente. 
struct tm* get_patient_birthdate(const Patient *patient){
    return patient->birthdate;
}
// Arquivo de cabeçalho criado localmente
#include "functions.h"

// Arquivos de cabeçalho
#include <stdlib.h> // malloc, EXIT_FAILURE
#include <string.h> // strcmp
#include <stdio.h> // printf

// Mostra uma mensagem de erro e para o programa com o código de erro
void error_exit(int err_code){
    exit(err_code);
}

void error_message_id(const char *msg, int id){
    printf("%s: %d.", msg, id);
}

void error_message_field(const char *msg, char *campo){
    printf("%s: %s.", msg, campo);
}

// Verifica se o inteiro id é válido, maior que zero
int validate_id(int num, char *campo){
    if ( num > 0 ) {
        return 1;
    } else {
        // Mensagem de erro
        error_message_field("Erro.\nNumero inválido em campo", campo);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
        return 0;
    }
}

// Verifica se o Dia, Mês e Ano é igual a zero  
int validate_time(const struct tm* time, char *campo){

    if( time->tm_year == 0 &&
        time->tm_mon  == 0 &&
        time->tm_mday == 0 ){

        char msg[] = "Data/Hora não informada no campo: ";
        strcat(msg, campo);

        // Mensagem de erro
        error_message_field("Erro.\nData/Hora não informada no campo", campo);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
        return 0;
    } 
    return 1;
}

// Verifica se o a variável string está vazia
int validate_name(const char* name, int id){
    if( strcmp(name, "") == 0 || strcmp(name, " ") == 0){
        // Mensagem de erro
        error_message_id("Erro.\nNão foi possível encontrar o nome do paciente com id", id);
        // Função para mostrar o erro e finaliza execução
        error_exit(EXIT_FAILURE);
        return 0;
    }
    return 1;
}
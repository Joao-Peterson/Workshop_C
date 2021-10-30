#include <stdio.h>
#include <time.h>
#include <string.h>
#include "inc/cmd_friend.h"
#include "inc/doc.h"
#include "inc/doc_csv.h"
#include "inc/doc_print.h"

typedef enum{
    op_start = 1,
    op_next,
    op_stop,
    op_create
}op_t;

char *atividade = "#### Atividade NULA ####";
op_t operacao = 0;

int parse_options(char key, char *arg, int arg_pos, void *extern_user_variables_struct){

    switch(key){
        case 's':
                atividade = arg;  
                operacao = op_start;
            break;

        case 'n':
                atividade = arg;  
                operacao = op_next;
            break;

        case 'q':
                atividade = arg;  
                operacao = op_stop;
            break;
            
        case 'c':
                operacao = op_create;
            break;

        case 0:
            if (!strcmp(arg, "start"))
            {
                operacao = op_start;
            }
            else if (!strcmp(arg, "next"))
            {
                operacao = op_next;
            }
            else if (!strcmp(arg, "end") || !strcmp(arg, "stop"))
            {
                operacao = op_stop;
            }
            else
            {
                printf("Uma opção deve ser passada, start, next ou stop!\n");
                exit(0);
            }
            break;

        default:
            printf("Corrupted command line arguments!");
            exit(-1);
            break;
    }

    return 0;
}

cmdf_option options[] = {
    {"start", 's', OPTION_OPTIONAL, 1, "Comeca cartao ponto com uma nova atividade"},
    {"next" , 'n', OPTION_OPTIONAL, 1, "Para atividade anterior e começa outra"},
    {"stop" , 'q', OPTION_OPTIONAL, 0, "Termina cartao ponto com uma ultima atividade"},
    {"create" , 'c', OPTION_OPTIONAL, 0, "Cria novo arquivo ponto"},
    {0}
};

int main(int argc, char **argv){

    cdmf_parse_options(options, &parse_options, argc, argv, PARSER_FLAG_PRINT_ERRORS_STDOUT | 
        PARSER_FLAG_USE_PREDEFINED_OPTIONS, NULL);

    char *arquivo_saida = "cartao_ponto.csv";

    doc *csv;

    switch(operacao){
        case op_create:
            {
                csv = doc_new(
                    "csv", dt_array,
                    ";"
                );

                doc_csv_save(csv, arquivo_saida);

                doc_delete(csv, ".");

                exit(0);
            }
            break;
        
        case op_start:
            {
                csv = doc_csv_open(arquivo_saida); 
                doc_delete(csv, ".");

                csv = doc_new(
                    "csv", dt_obj,
                    ";"
                );

                time_t segundos = time(NULL);

                struct tm *tempo = localtime(&segundos);

                float hora_excel = (tempo->tm_hour *60.0*60.0 + tempo->tm_min * 60.0 + tempo->tm_sec * 1.0) / (24.0*60.0*60.0);

                doc_add(csv, ".", 
                    "linha", dt_obj,
                        "hora", dt_float, hora_excel,
                        "hora2", dt_float, 0.0,
                        "atividae", dt_const_string, atividade, (size_t)(strlen(atividade) + 1),
                    ";"
                );

                doc_csv_save(csv, arquivo_saida);
            }
            break;

        case op_next:
            {
                csv = doc_csv_open(arquivo_saida); 

                time_t segundos = time(NULL);

                struct tm *tempo = localtime(&segundos);

                float hora_excel = (tempo->tm_hour *60.0*60.0 + tempo->tm_min * 60.0 + tempo->tm_sec * 1.0) / (24.0*60.0*60.0);

                int i = 0;
                int ultimo = doc_get_size(csv, ".") - 1;


                for(doc_loop(linha, csv)){
                    if(i == ultimo){
                        doc_set(linha, "[1]", double, hora_excel);        
                    }

                    i++;
                }

                doc_add(csv, ".", 
                    "linha", dt_obj,
                        "hora", dt_float, hora_excel,
                        "hora2", dt_float, 0.0,
                        "atividae", dt_const_string, atividade, (size_t)(strlen(atividade) + 1),
                    ";"
                );

                doc_csv_save(csv, arquivo_saida);
            }
            break;

        case op_stop:
            {
                csv = doc_csv_open(arquivo_saida); 

                time_t segundos = time(NULL);

                struct tm *tempo = localtime(&segundos);

                float hora_excel = (tempo->tm_hour *60.0*60.0 + tempo->tm_min * 60.0 + tempo->tm_sec * 1.0) / (24.0*60.0*60.0);

                int i = 0;
                int ultimo = doc_get_size(csv, ".") - 1;


                for(doc_loop(linha, csv)){
                    if(i == ultimo){
                        doc_set(linha, "[1]", double, hora_excel);        
                    }

                    i++;
                }

                doc_csv_save(csv, arquivo_saida);
            }
            break;
    }

    return 0;
}

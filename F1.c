#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// -- Estruturas -- //
// Pilotos
typedef struct {
    char piloto[30];
    int numero;
    char equipe[30];
    char carro[30];
} entradas_competidores;

// Equipes
typedef struct {
    char time[60];
    int pontos;
} entradas_construtoras;

// Pilotos/Pontos
typedef struct{
    char piloto[30];
    int numero;
    char equipe[30];
    int pontos;
} worldChampion;

// -- Informações -- //
#define EQUIPES 10
#define PILOTOS 20
#define CORRIDAS 24
#define MAX_PTS_CORRIDA 44

// -- Tabela dos pilotos -- //
void linhas_piloto(){
    printf("+----------------------+--------+-----------------+-----------+\n");
}

void cabecalho_piloto(){
    linhas_piloto();
    printf("| %-20s | %-6s | %-15s | %-9s |\n", "Piloto", "Numero","Equipe", "Carro");
    linhas_piloto();
}

void info_pilotos(entradas_competidores piloto){
    printf("| %-20s | %-6d | %-15s | %-9s |\n", 
    piloto.piloto,
    piloto.numero,
    piloto.equipe,
    piloto.carro);
}

void info_campeao(int posicao, entradas_competidores piloto){
    printf("| %-4d | %-20s | %-6d | %-15s | %-9s |\n", 
    posicao,
    piloto.numero,
    piloto.equipe,
    piloto.carro);
}

int brigaPilotos(const void *a, const void *b){
    const worldChampion *cons_a = (const worldChampion *)a;
    const worldChampion *cons_b = (const worldChampion *)b;

    return cons_b->pontos - cons_a->pontos;
}

// -- Tabela das construtoras -- //
void linhas_construtoras(){
    printf("+------+---------------------------------------------+--------+\n");
}

void cabecalho_construtoras(){
    linhas_construtoras();
    printf("| %-4s | %-43s | %-6s |\n", "Pos.", "Equipe", "Pontos");
    linhas_construtoras();
}

void info_construtoras(int posicao, entradas_construtoras construtora){
    printf("| %-4d | %-43s | %-6d |\n", 
    posicao,
    construtora.time,
    construtora.pontos);
}

int brigaConstrutoras(const void *a, const void *b){
    const entradas_construtoras *cons_a = (const entradas_construtoras *)a;
    const entradas_construtoras *cons_b = (const entradas_construtoras *)b;

    return cons_b->pontos - cons_a->pontos;
}

int main(){
    srand(time(NULL));

    entradas_competidores competidores[] = {
        // Aston Martin Aramco Formula One Team
        {"Fernando Alonso", 14, "Aston Martin", "AMR25"},
        {"Lance Stroll", 18, "Aston Martin", "AMR25"},
        // Visa Cash App Racing Bulls Formula One Team
        {"Isack Hadjar", 6, "Racing Bulls", "VCARB 02"},
        {"Liam Lawson", 30, "Racing Bulls", "VCARB 02"},
        // MoneyGram Haas F1 Team
        {"Oliver Bearman", 87, "Haas F1 Team", "VF-25"},
        {"Esteban Ocon", 31, "Haas F1 Team", "VF-25"},
        // Stake F1 Team Kick Sauber
        {"Gabriel Bortoleto", 5, "Kick Sauber", "C45"},
        {"Nico Hulkenberg", 27, "Kick Sauber", "C45"},
        // BWT Alpine Formula One Team
        {"Franco Colapinto", 43, "Alpine", "A525"},
        {"Pierre Gasly", 10, "Alpine", "A525"},
        // Atlassian Williams Racing
        {"Carlos Sainz", 55, "Williams", "FW47"},
        {"Alexander Albon", 23, "Williams", "FW47"},
        // Scuderia Ferrari HP
        {"Charles Leclerc", 16,"Ferrari", "SF-25"},
        {"Lewis Hamilton", 44, "Ferrari", "SF-25"},
        // Mercedes-AMG PETRONAS Formula One Team
        {"George Russel", 63, "Mercedes", "W16"},
        {"Kimi Antonelli", 12, "Mercedes", "W16"},
        // Oracle Red Bull Racing
        {"Max Verstappen", 1, "Red Bull Racing", "RB21"},
        {"Yuki Tsunoda", 22, "Red Bull Racing", "RB21"},
        // McLaren Formula 1 Team
        {"Lando Norris", 4, "McLaren", "MCL39"},
        {"Oscar Piastri", 81, "McLaren", "MCL39"},
    };
    int entradas = sizeof(competidores) / sizeof(competidores[0]);

    printf("\n///////////////////////////\n");
    printf("Temporada de 2025 Fórmula 1\n");
    printf("///////////////////////////\n\n");

    cabecalho_piloto();
    for(int i = 0; i < entradas; i++){
        info_pilotos(competidores[i]);
    }
    linhas_piloto();

    entradas_construtoras construtoras[EQUIPES] = {
        {"Aston Martin Aramco Formula One Team", 0},
        {"Visa Cash App Racing Bulls Formula One Team", 0},
        {"MoneyGram Haas F1 Team", 0},
        {"Stake F1 Team Kick Sauber", 0},
        {"BWT Alpine Formula One Team", 0},
        {"Atlassian Williams Racing", 0},
        {"Scuderia Ferrari HP", 0},
        {"Mercedes-AMG PETRONAS Formula One Team", 0},
        {"Oracle Red Bull Racing", 0},
        {"McLaren Formula 1 Team", 0}
    };

    for(int corrida = 0; corrida < CORRIDAS; corrida++){
        for(int i = 0; i < EQUIPES; i++){
            int pontos_corrida = (rand() % MAX_PTS_CORRIDA) +1;
            construtoras[i].pontos += pontos_corrida;
        }
    }
    qsort(construtoras, EQUIPES, sizeof(entradas_construtoras), brigaConstrutoras);

    printf("\n/////////////////////////////////////////////////\n");
    printf("Resultado final - Mundial de Construtores F1 2025\n");
    printf("/////////////////////////////////////////////////\n\n");

    cabecalho_construtoras();
    for(int i = 0; i < EQUIPES; i++){
        info_construtoras(i+1, construtoras[i]);
    }
    linhas_construtoras();

    qsort(competidores, PILOTOS, sizeof(entradas_competidores), brigaPilotos);

    printf("\n/////////////////////////////////////////\n");
    printf("Resultado Final - Mundial de Pilotos F1 2025");
    printf("\n///////////////////////////////////////\n");

    cabecalho_piloto();
    for(int i = 0; i < 3; i++){
        info_campeao(i+1, competidores[i]);
    }
    linhas_piloto();

    return 0;
}

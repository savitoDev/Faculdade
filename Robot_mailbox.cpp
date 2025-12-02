// =======================================================
// Configuração de Portas e Definições
// =======================================================
#define MODO_LINHA      1
#define MODO_CONTROLE   2
#define MODO_PARADO     0

#define MOTOR_TRASEIRO_ESQUERDO OUT_B
#define MOTOR_TRASEIRO_DIREITO OUT_C

// Configuração dos Sensores de Luz/Cor
#define SENSOR_ESQUERDO IN_1
#define SENSOR_DIREITO IN_2

// Limite de cor
#define LIMITE_PRETO 45 

// Variável de controle do modo atual
int g_modo_atual = MODO_PARADO; 
int g_velocidade_linha = 50; // Velocidade base para o Seguidor de Linha
int g_velocidade_controle = 70; // Velocidade base para o Controle Remoto

// =======================================================
// Funções Auxiliares
// =======================================================

// Função para iniciar os motores de tração
void MotoresFrente(int velocidade) {
    OnFwd(MOTOR_TRASEIRO_ESQUERDO, velocidade);
    OnFwd(MOTOR_TRASEIRO_DIREITO, velocidade);
}

// =======================================================
// Handler do módulo bluetooth e funcionalidade
// =======================================================
task bluetooth_handler() {
    int mailbox_modo = 1;       // Caixa de Correio 1: Comandos 'A', 'B'
    int mailbox_mov_tracao = 2; // Caixa de Correio 2: Comandos de Triggers ('F', 'T', 'S')
    int mailbox_mov_direcao = 3; // Caixa de Correio 3: Comandos de D-Pad ('L', 'R', 'D')
    
    // Variáveis para implementar a lógica de sobreposição/prioridade (Não sobrepõe)
    int comando_tracao_ativo = 0; // 0=Parado, 'F'=Frente, 'T'=Tras
    int comando_direcao_ativo = 0; // 0=Parado, 'L'=Esquerda, 'R'=Direita
    
    while (true) {
        // --- 1. Checa a Caixa de Correio de MODO (Prioridade Alta) ---
        int comando_modo = MessageRead(mailbox_modo, true); 
        
        if (comando_modo == 'A') { // 'A' (65) = Controle Remoto
            g_modo_atual = MODO_CONTROLE;
            ClearScreen();
            TextOut(0, 55, "MODO CONTROLE");
            PlayTone(800, 200); // Beep para confirmar
        } else if (comando_modo == 'B') { // 'B' (66) = Seguidor de Linha
            g_modo_atual = MODO_LINHA;
            ClearScreen();
            TextOut(0, 55, "MODO LINHA");
            PlayTone(600, 100); Wait(100); // Chime Bonitinho
            PlayTone(1000, 100); Wait(100);
            
            // Aguarda 2 segundos + 2 beeps
            Wait(2000); 
            PlayTone(800, 100); Wait(100);
            PlayTone(800, 100); Wait(500); 
        }

        // --- 2. Checa a Caixa de Correio de TRAÇÃO (Triggers) ---
        int comando_tracao = MessageRead(mailbox_mov_tracao, true);
        
        if (comando_tracao != 0) { // Se recebeu um novo comando de tração
            comando_tracao_ativo = comando_tracao;
        } 
        
        // --- 3. Checa a Caixa de Correio de DIREÇÃO (D-Pad) ---
        int comando_direcao = MessageRead(mailbox_mov_direcao, true);
        
        if (comando_direcao != 0) { // Se recebeu um novo comando de direção
            comando_direcao_ativo = comando_direcao;
        }

        // --- 4. APLICAÇÃO DOS COMANDOS (Apenas no Modo Controle) ---
        if (g_modo_atual == MODO_CONTROLE) {
            
            // Lógica de TRAÇÃO (Aceleração/Ré)
            if (comando_tracao_ativo == 'F') { // Trigger Direito Ativo
                MotoresFrente(g_velocidade_controle);
            } else if (comando_tracao_ativo == 'T') { // Trigger Esquerdo Ativo
                // Velocidade de ré ligeiramente menor
                OnRev(MOTOR_TRASEIRO_ESQUERDO, g_velocidade_controle * 0.7); 
                OnRev(MOTOR_TRASEIRO_DIREITO, g_velocidade_controle * 0.7);
            } else {
                // Se nenhum trigger estiver ativo, a tração deve parar se não houver direcao
                Off(MOTOR_TRASEIRO_ESQUERDO); 
                Off(MOTOR_TRASEIRO_DIREITO);
                comando_tracao_ativo = 0; // Reseta para o próximo ciclo
            }

            // Lógica de DIREÇÃO (Esquerda/Direita)
            if (comando_direcao_ativo == 'L') { // D-Pad Esquerda
                // Rotaciona no próprio eixo (um para frente, outro para trás)
                OnRev(MOTOR_TRASEIRO_ESQUERDO, g_velocidade_controle);
                OnFwd(MOTOR_TRASEIRO_DIREITO, g_velocidade_controle);
            } else if (comando_direcao_ativo == 'R') { // D-Pad Direita
                OnFwd(MOTOR_TRASEIRO_ESQUERDO, g_velocidade_controle);
                OnRev(MOTOR_TRASEIRO_DIREITO, g_velocidade_controle);
            } else {
                // Se não houver comando de tração, paramos. Se houver, a tração domina.
                if (comando_tracao_ativo == 0) {
                     Off(MOTOR_TRASEIRO_ESQUERDO); 
                     Off(MOTOR_TRASEIRO_DIREITO);
                }
                comando_direcao_ativo = 0;
            }
        }
        
        Wait(50); // Loop de 50ms para boa resposta
    }
}

// =======================================================
// Inicialização e Execução dos Modos
// =======================================================
task main() {
    // 1. Configuração de Sensores
    SetSensorType(SENSOR_ESQUERDO, SENSOR_TYPE_LIGHT);
    SetSensorMode(SENSOR_ESQUERDO, SENSOR_MODE_REFLECT);
    SetSensorType(SENSOR_DIREITO, SENSOR_TYPE_LIGHT);
    SetSensorMode(SENSOR_DIREITO, SENSOR_MODE_REFLECT);
    
    // 2. Inicialização e Mensagem
    ClearScreen();
    TextOut(0, 55, "Iniciando...");
    Wait(2000); // "Finge" carregar
    
    PlayTone(440, 100); Wait(150); 
    PlayTone(440, 100); Wait(150); 
    PlayTone(440, 100); // Beeps de inicialização
    
    ClearScreen();
    TextOut(0, 60, "A = Controle Remoto");
    TextOut(0, 40, "B = Seguidor de Linha");
    
    // Inicializa o handler bluetooth
    start bluetooth_handler; 

    // Loop Principal
    while (true) {
        if (g_modo_atual == MODO_LINHA) {
            // Lógica do Seguidor de Linha
            // Leitura dos sensores
            int valor_esq = SensorValue(SENSOR_ESQUERDO);
            int valor_dir = SensorValue(SENSOR_DIREITO);
            
            // Reto
            if (valor_esq > LIMITE_PRETO && valor_dir > LIMITE_PRETO) {
                MotoresFrente(g_velocidade_linha);
            } 
            // Esquerda
            else if (valor_esq <= LIMITE_PRETO) {
                OnRev(MOTOR_TRASEIRO_ESQUERDO, g_velocidade_linha);
                OnFwd(MOTOR_TRASEIRO_DIREITO, g_velocidade_linha);
            }
            // Direita
            else if (valor_dir <= LIMITE_PRETO) {
                OnFwd(MOTOR_TRASEIRO_ESQUERDO, g_velocidade_linha);
                OnRev(MOTOR_TRASEIRO_DIREITO, g_velocidade_linha);
            } else {
                // Caso extremo (ambos em preto) - Pare para evitar sair da linha
                Off(OUT_BC);
            }
        } 
        
        // Se não estiver no MODO_LINHA (ou seja, Controle ou Parado),
        // o manipulador bluetooth cuida da movimentação.
        
        Wait(10);
    }
}

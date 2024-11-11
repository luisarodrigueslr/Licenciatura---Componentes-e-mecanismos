  int botao = 11 ;        // Botão conectado ao pino 11

  int ledS = 3;         // Led conectado ao pino 3
    int ledP = 2;     // Led conectado ao pino 2
  int ledD = 1;         // Led conectado ao pino 1

    int estadoLedS;             // Variavel para ler o estado do pino
    int estadoLedP;            // Variavel para ler o estado de delayed
    int estadoLedD;            // Variavel para ler o estado de delayed
    int estadoBotao;           // Variavel para "segurar" o estado do botão
    int Mode = 0;              // Qual modo está a luz?


    void setup() {
      pinMode(botao, INPUT);      // Colocar o pino de botão como entrada 
      
      pinMode(ledS, OUTPUT);   // Colocar o pino do LED como saida
      pinMode(ledP, OUTPUT);
      pinMode(ledD, OUTPUT);
      
      estadoBotao = digitalRead(botao);   // Lê o estado inicial
    }



    void loop(){
      
     estadoLedS = digitalRead(botao);         // Lê valor do botão e "armazena" no estado do led
      delay(10);                             // 10 milisegundos de atraso
      estadoLedP = digitalRead(botao);       // Lê a entrada novamente para verificar se há rejeições
      delay (10);
        estadoLedD = digitalRead(botao);
        if (estadoLedS == estadoLedP && estadoLedP == estadoLedD ) {         // Certificar que obtive-se 2 leituras consistentes!
          if (estadoLedS != estadoBotao) {      // the button state has changed!
              if (estadoLedS == LOW) {            // check if the button is pressed
              if (Mode == 0) {          
                  Mode = 1;               
              } else {
                if (Mode == 1) {        
                  Mode = 2;           
              } else {
                if (Mode == 2) {      
                  Mode = 3;           
              } else {
                if (Mode == 3) { 
                  Mode = 4;          
              } else {
                if (Mode == 4) { 
                  Mode = 0;          
              }    
            }
           }
          }
         }
        }
        estadoBotao = estadoLedS;                 // Salvar o novo estado na variável
      }

      // Fazer que quer que o lightMode indique
      if (Mode == 0) {              // Todos desligados
        digitalWrite(ledS, LOW);
        digitalWrite(ledP, LOW);
        digitalWrite(ledD, LOW);
      }

      if (Mode == 1) {               //Subir
    digitalWrite(ledS, HIGH);
        digitalWrite(ledP, LOW);
        digitalWrite(ledD, LOW);
      }

      if (Mode == 2) {               //Parado
        digitalWrite(ledS, LOW);
        digitalWrite(ledP, HIGH);
        digitalWrite(ledD, LOW);
      }
      if (Mode == 3)  {                //Descer
        digitalWrite(ledS, LOW);
        digitalWrite(ledP, LOW);
        digitalWrite(ledD, HIGH);
      }    
      if (Mode == 4)  {                //Todos desligados
        digitalWrite(ledS, LOW);
        digitalWrite(ledP, LOW);
        digitalWrite(ledD, LOW);
      }    
     }
    }

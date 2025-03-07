
        // Declaracion de las bibliotecas    

        #include <stdio.h>
        #include <stdlib.h>
        #include <pic16f818.h>
        #include <xc.h>

        /* Configuracion del PIC */

        #pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
        #pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
        #pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
        #pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital I/O, MCLR internally tied to VDD)
        #pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
        #pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3/PGM pin has digital I/O function, HV on MCLR must be used for programming)
        #pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
        #pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
        #pragma config CCPMX = RB2      // CCP1 Pin Selection bit (CCP1 function on RB2)
        #pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
        #define _XTAL_FREQ 4000000  // 4 MHz


// Definición de pines
#define D RA0
#define C RA1
#define B RA2
#define A RA3
#define BUZZER RA7
#define FILA0 RB0
#define FILA1 RB1
#define FILA2 RB2
#define FILA3 RB3
#define COLUMNA0 RB4
#define COLUMNA1 RB5
#define COLUMNA2 RB6
#define COLUMNA3 RB7

// Definición de la matriz del teclado
char teclado[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

unsigned int valorActual = 0;
operacion = 0;
int resultado = 0;

// Función para hacer sonar el buzzer
void sonar_buzzer() {
    BUZZER = 1;
    __delay_ms(100);
    BUZZER = 0;
}

// Función para leer el teclado matricial
char leer_teclado() {
    for (int fila = 0; fila < 4; fila++) {
        // Establecer la fila actual en bajo (0)
        switch (fila) {
            case 0: FILA0 = 0; FILA1 = 1; FILA2 = 1; FILA3 = 1; break;
            case 1: FILA0 = 1; FILA1 = 0; FILA2 = 1; FILA3 = 1; break;
            case 2: FILA0 = 1; FILA1 = 1; FILA2 = 0; FILA3 = 1; break;
            case 3: FILA0 = 1; FILA1 = 1; FILA2 = 1; FILA3 = 0; break;
        }

        // Leer las columnas
        if (COLUMNA0 == 0) { 
            sonar_buzzer();
            return teclado[fila][0]; // Columna 0
        }
        if (COLUMNA1 == 0) { 
            sonar_buzzer();
            return teclado[fila][1]; // Columna 1
        }
        if (COLUMNA2 == 0) { 
            sonar_buzzer();
            return teclado[fila][2]; // Columna 2
        }
        if (COLUMNA3 == 0) { 
            sonar_buzzer();
            return teclado[fila][3]; // Columna 3
        }

        // Breve retardo para evitar rebotes
        __delay_ms(10);
    }

    return '0'; // No se presionó ninguna tecla
}

// Función para mostrar el número en el display de 7 segmentos
void mostrar_en_display(int valor) {
    // Limitar el valor a 0-15 para poder representarlo en 4 bits
    valor = valor % 16;

    // Establecer los pines A, B, C y D
    D = (valor & 0b0001) >> 0;  // Bit 0
    C = (valor & 0b0010) >> 1;  // Bit 1
    B = (valor & 0b0100) >> 2;  // Bit 2
    A = (valor & 0b1000) >> 3;  // Bit 3
}

void main() {
    // Configurar puertos de salida
    TRISB = 0x00; // Puerto B como salida
    PORTB = 0x00; // Limpiar el puerto

    while(1) {
        char tecla = leer_teclado();
        
        if (tecla >= '0' && tecla <= '9') {
            // Desplazar dígitos y agregar el nuevo número
            valorActual = valorActual * 10 + (tecla - '0');
            mostrar_en_display(valorActual);
        } else if (tecla == '*') {
            // Borrar número
            valorActual = 0;
            mostrar_en_display(valorActual);
        } else if (tecla == '#') {
            // Ejecutar operación
            switch (operacion) {
                case 'A': resultado += valorActual; break;
                case 'B': resultado -= valorActual; break;
                case 'C': resultado *= valorActual; break;
                case 'D': resultado /= valorActual; break;
            }
            mostrar_en_display(resultado);
            valorActual = 0; // Reset para la siguiente entrada
        } else if (tecla == 'A' || tecla == 'B' || tecla == 'C' || tecla == 'D') {
            // Guardar la operación
            operacion = tecla;
            resultado = valorActual;
            valorActual = 0;
        }
    }
}

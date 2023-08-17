#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int oPerador(char c);
int balanceamentoDePares(char o, char close);
int verificaBalanceamento(char exp[], int n);
int a;

int main() {
    char expr[MAX];
    int n;

    printf("Digite a express�o: ");
    scanf("%s", expr);
    n = strlen(expr);

    // Verifica se a express�o est� balanceada
    if (verificaBalanceamento(expr, n)) {
        printf("A express�o est� balanceada.\n");
    } else {
        printf("A express�o n�o est� balanceada.\n");
    }

    return 0;
}



int oPerador(char c) {
    return (c == '(' || c == '{' || c == '[' || c == '<');
}



int balanceamentoDePares(char open, char close) {
	// se o caractere for um operador de abertura, ser� empilhado dentro da pilha	
		// se o caractere for de fechamento, verificar se esta dentro da pilha
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '<' && close == '>');
}


int verificaBalanceamento(char expr[], int n) {
	int top = -1;
	char stack[MAX];
	int i;
	// para cada caractere da expressao, teremos esse for percorrendo;
	for (i = 0; i < n; i++){
		
		// se for de abertura, empilha
		
		if (oPerador(expr[i]))  {
			stack[++top] = expr[i];
		}
		 // Se o caractere for um operador de fechamento
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']' || expr[i] == '>') {
			// verifica se esta vazia
			if ( top == -1 ) {
				return 0;
			}
			// verifica se o op de fechamento corresponde ao de abertura
			else if(!balanceamentoDePares(stack[top], expr[i])){
				return 0;
			}else{
				top--;
			}
		}
	}
	return (top == -1);
}
		



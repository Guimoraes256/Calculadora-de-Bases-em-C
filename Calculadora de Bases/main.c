#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#define FINAL_ARRAY 2506
#define True 1
#define False 0

char * format(char* value);
char **read();
char **loading(char *path);
int *treatment(char *number, char **charNumbers,int base);
int *convertToBase(long number, int base);
double convertToDecimal(int *number, int base);
int potencia(int base, int expoente);
double mathOperation(double v1, double v2, char op);
void viewNumber(int *number, char **charNumbers, char sign);
int calculator(char **charNumbers);
void imgScreen();
void print_image(FILE *fptr);
void config();
void interface();
int *convertFractionToBase(double number, int *result, int base);
int testFraction(double number);
void readConfig(char *patch);
int saveConfigUser();

char **configUser;

int main(){
	setlocale(LC_ALL, "Portuguese");
	configUser = malloc(3 * sizeof(char*));
	configUser[0] = malloc(31 * sizeof(char*));
	configUser[1] = malloc(31 * sizeof(char*));
	interface();
	
    return 0;
}

void interface(){

	int cursor = 0;
	int continueInter = 1;
	readConfig("config.cnf");
	system(configUser[0]);
	char **chars = loading(configUser[1]);
	
		
	while(cursor==0){
		imgScreen();
		printf("\nDigite a op��o deseja e pressione ENTER.\n");
		printf("(1)Iniciar calculadora \n");
		printf("(2)Como usar \n");
		printf("(3)Configura��es \n");
		printf("(4)Sair \n");
		scanf("%d",&cursor);
		switch(cursor){
	   		case 1:
	   			while(continueInter==1){
	   				continueInter = calculator(chars);
				}
				break;
	   		case 2:
	     		printf("	Essa calculadora aguenta no m�ximo at� a base 255 e a m�nima � 2, Para utiliz�-la   \n");
	     		printf("voc� dever� entrar com os operandos que voc� quer calcular, entrar com as bases         \n");
	     		printf("desses n�meros, escolher a opera��o matem�tica que ser� feita e escolher a base         \n");
	     		printf("que sair� a resposta. As bases v�lidas s�o de 2 a 255.                                  \n");
	     		printf("	Por padr�o os caracteres da base 16(hexadecimal) v�o de 0 a F, por�m depois         \n");
				printf("disso n�o existe uma maneira oficial de como as outras bases devem ser representadas,   \n");
				printf(" com isso como a calculadora vai at� a 255 foi adotado uma representa��o das bases      \n");
				printf("acima de 16. Com foi escolhido dois tipos de representa��o, o padr�o do programa e uma  \n");
				printf("que pode ser personalizada por voc�.                                                    \n");
				printf("	A representa��o padr�o vai normal at� a base 16, por�m a partir disso � posto o     \n");
				printf("n�mero do car�cter entre colchetes para represent�-lo, por exemplo, a base 17 vai de    \n");
				printf("0 a [17].                                                                               \n");
				printf("	Na quest�o de personaliza��o dos n�meros, voc� pode modificar o arquivo txt         \n");  
				printf("\"Caracteres\" que tem dentro da pasta do programa para colocar o alfabeto do seu agrado.\n");
				printf("Por exemplo voc� pode mudar para que a base 17 vai de 0 a G. Caso queira colocar mais   \n");
				printf("de um car�cter para representar um n�mero voc� deve deixar entre colchetes. Por exemplo,\n");
				printf("na base 17 ele pode modificar de 0 a [XVII]. Por�m lembre-se que n�o se pode utilizar os\n");
				printf("caracteres �.�, �-�, �[�, �]�,  �:� e ��� nas suas modifica��es do alfabeto.            \n");
				printf("	Para modificar a o alfabeto de n�meros que voc� quer utilizar apenas entre nas con- \n");
				printf("figura��es no menu principal e escolha entre a op��o 2 ou 3.                            \n");
				printf("	Exemplo de n�meros do alfabeto padr�o inseridos para contas: 25[154]12, [254]12,    \n");
				printf("100110 e 215[18].                                                                       \n");
				printf("Exemplo de possibilidades com n�meros do alfabeto personalizado inseridos para contas:  \n");
				printf("[XVIII], 12[Joken], PKDF012, [UM][DOIS][TRES] e [$%@]. 	Para inserir n�meros fracion�-  \n");
				printf("rios na conta utilize ponto ao inv�s de v�rgula, todos os resultados ser�o exibidos em  \n");
				printf("�ponto flutuante�.                                                                      \n");
				getchar();
	     		getchar();
		 		break;
	   		case 3:
	     		getchar();
	     		config();
		 		break;
	   		case 4:
	     		return;
		 		break;
	   		default:
	    		printf("Opcao invalida.");
		}
		cursor = 0;
	}
}

void config(){
	int cursor = 0;
	char font;
	char background;
	char color[11] = {'"', 'C', 'O','L','O','R',' ','A','A','"', 0};
	
	while(cursor==0){
		printf("\nDigite a op��o deseja e pressione ENTER.\n");
		printf("(1)Alterar cor da fonte e do fundo.\n");
		printf("(2)Utilizar alfabeto de n�meros personalizados.\n");
		printf("(3)Utilizar alfabeto de n�meros padr�o.\n");
		printf("(4)Restaurar configura��es padr�es.\n");
		printf("(5)Voltar \n");
		scanf("%d",&cursor);
		getchar();
		switch(cursor){
		   	case 1:
	   			printf("Escolha a cor da font:\n");
	   			printf("0 = Preto      8 = Cinza\n");
				printf("1 = Azul       9 = Azul\n");
				printf("2 = Verde      A = Verde claro\n");
				printf("3 = Verde-�gua B = Verde-�gua claro\n");
				printf("4 = Vermelho   C = Vermelho claro\n");
				printf("5 = Roxo       D = Lil�s\n");
				printf("6 = Amarelo    E = Amarelo Claro\n");
				printf("7 = Branco     F = Branco brilhante\n");
				scanf("%c",&font);
				getchar();
	   			printf("Escolha a cor do fundo:\n");
	   			printf("0 = Preto      8 = Cinza\n");
				printf("1 = Azul       9 = Azul\n");
				printf("2 = Verde      A = Verde claro\n");
				printf("3 = Verde-�gua B = Verde-�gua claro\n");
				printf("4 = Vermelho   C = Vermelho claro\n");
				printf("5 = Roxo       D = Lil�s\n");
				printf("6 = Amarelo    E = Amarelo Claro\n");
				printf("7 = Branco     F = Branco brilhante\n");
				scanf("%c",&background);
				color[7] = background;
				color[8] = font;
				system(color);
				configUser[0] = color;
				saveConfigUser(configUser);			
				break;
		   	case 2:
		   		configUser[1] = "Caracteres.txt";
				saveConfigUser(configUser);
				printf("O Programa esta utilizando os caracteres personalizados.\n");
		 		break;
	   		case 3:				 
	     		configUser[1] = "CaracPardr.cnf";
				saveConfigUser(configUser);
				printf("O Programa esta utilizando os caracteres padr�o.\n");
		 		break;
	   		case 4:
	   			configUser[0] = "\"COLOR 0A\"";
	   			configUser[1] = "CaracPardr.cnf";
	     		saveConfigUser(configUser);
	     		printf("O Programa retornou para as configura��es padr�es.\n");
				return 0;
		 		break;
	   		case 5:
	     		return 0;
		 		break;
	   		default:
	    		printf("Opcao invalida, voltando para o menu principal.");
		}
		cursor = 0;
	}
}

int calculator(char **charNumbers){
	char *number1 = malloc(50 * sizeof(char));
	char *number2 = malloc(50 * sizeof(char));
	int *treatmentNumb1 = malloc(50 * sizeof(int));
	int *treatmentNumb2 = malloc(50 * sizeof(int));
	int *result;
	char operators,cursor;
	int baseNum1,baseNum2,baseAs3;
	double tempNum1,tempNum2;
	double resultOperation;
	char sign;
	double fraction = 0;
	int aux;
	printf("Entre com o primeiro numero: ");
	scanf("%s",number1);
	printf("\n");
	printf("Entre com a base desse numero: ");
	scanf("%d",&baseNum1);
	printf("\n");
	printf("Entre com o segundo numero: ");
	scanf("%s",number2);
	printf("\n");
	printf("Entre com a base desse numero: ");
	scanf("%d",&baseNum2);
	printf("\n");
	printf("Entre com a base da resposta: ");
	scanf("%d",&baseAs3);
	printf("\n");
	getchar();
	printf("Entre com o operador (+,-,*,/): ");
	scanf("%c",&operators);
	printf("\n");
	treatmentNumb1 = treatment(number1,charNumbers,baseNum1);
	treatmentNumb2 = treatment(number2,charNumbers,baseNum2);
	if(treatmentNumb1[0]==FINAL_ARRAY || treatmentNumb2[0]==FINAL_ARRAY){
		printf("O n�mero digitado n�o corresponde a base entrada ou a base n�o possui um algorismo digitado.");
		getchar();
		printf("\n");
		printf("\n");
		getchar();
		printf("Deseja tentar novamente? (S/N)\n");
	}else{
		tempNum1 = convertToDecimal(treatmentNumb1,baseNum1);
		tempNum2 = convertToDecimal(treatmentNumb2,baseNum2);
		if(checkNegative(number1) == 1){
			tempNum1 = tempNum1 * -1;
		}
		if(checkNegative(number2) == 1){
			tempNum2 = tempNum2 * -1;
		}
		resultOperation = mathOperation(tempNum1,tempNum2,operators);
		if(resultOperation < 0) {
			sign = '-';
			resultOperation = resultOperation * -1;
		}else{
			sign = ' ';
		}
		if(testFraction(resultOperation) == True){
			result = convertToBase(resultOperation,baseAs3);
			aux = (int) resultOperation;
			if(resultOperation < 0){
				convertFractionToBase(resultOperation + aux, result, baseAs3);
			}else{
				convertFractionToBase(resultOperation - aux , result, baseAs3);
			}
		}else{
			result = convertToBase(resultOperation,baseAs3);
		}
		
		printf("O resultado deu: ");
		viewNumber(result,charNumbers,sign);
		printf("\n");
		getchar();
		printf("Deseja fazer outra opera��o? (S/N)\n");
	}
	scanf("%c",&cursor);
	switch(cursor){
	   		case 'S':
	     		return 1;
				break;
	   		case 'N':
	     		return 0;
		 		break;
	   		case 's':
	     		return 1;
		 		break;
	   		case 'n':
	     		return 0;
		 		break;
	   		default:
	    		printf("Opcao invalida, voltando para o menu principal.");
	    		return 0;
	}
	return 1;
}

int checkNegative(char *number){
	char *string = malloc (31 * sizeof (char));
	string[0] = number[0];
	if(strcmp(string, "-") == 0){ 
		return 1;
	}else{
		return 0;	
	}	
}


/*
	A��o - Testa para ver se o n�mero � fracionario.
	Entrada - Recebe um n�mero em double, um vetor de int com uma parcial do resultado final apenas da parte inteira do n�mero e a base a ser convertida. 
	Sa�da - Retorna a costante True(1) caso seja fracionario e False(0) se n�o for.
	Suposi��es - Para descobrir se um n�mero � fracionario eu fa�o uma variavel por meio de casting receber o valor inteiro do n�mero e depois diminuo
				 o n�mero pela variavel, caso o resultado seja maior que 0 significa que ele n�o pode ser um inteiro logo que um inteiro menos esse mesmo
				 inteiro � zero.
*/
int testFraction(double number){
	int aux = (int) number;
	if(number < 0){
		aux = aux + number;
	}else{
		aux = aux - number;
	}
	
	if(number > 0){
		return True;
	}else{
		return False;
	}
}

/*
	A��o - Converte a parte fracionario de um numero para a base inserida.
	Entrada - Recebe um numero em double, um vetor de int com uma parcial do resultado final apenas da parte inteira do numero e a base a ser convertida.
	Sa�da - Retorna um vetor de int.
*/
int *convertFractionToBase(double number, int *result, int base){
	int i, j = 0;
	/*Loop utilizado apenas para achar a posi��o que se pode come�ar a inserir, logo que o veto j� tem uma parcial do
	  resultado final.*/
	for(i = 0; result[i] != FINAL_ARRAY; i++){ 
	}
	
	result[i] = -1;
	i++;
	for(i = i; i = i; i++){
		result[i] = (int) 0 + (number * base);
		number = (number * base) - result[i];
		if(result[i] - (number * base) == 0){
			break;
		}
		if(j > 5){
			break;
		}
		j++;
	}
	result[i+1] = FINAL_ARRAY; //Colocando o final array que � utilizado por outras fun��es para distiguir o fim do vetor.
	return result;
}

/*
	A��o - Trata a string(numero) recebida localizando os caracteres com base no Caracteres.txt e vendo que numero eles s�o.
	Entrada - Um vetor de inteiro com o resultado final, um vetor de string com alfabeto dos n�meros e o sinal do numero.
*/
void viewNumber(int *number, char **charNumbers, char sign){
	int i;
	printf("%c",sign);
	for(i = 0; number[i] != FINAL_ARRAY; i++){
		if(number[i]==-1){
			if(number[i+2] == FINAL_ARRAY){
				break;
			}
			printf("%c",'.');
		}else{
			printf("%s",charNumbers[number[i]]);
		}
		
	}
}

/*
	A��o - Trata a string(numero) recebida localizando os caracteres com base no Caracteres.txt e vendo que numero eles s�o.
	Entrada - Recebe a string(numero) e um vetor de string que cont�m os caracteres do Caracteres.txt 
	Sa�da - Retorna um vetor de int invertido.
	Suposi��es - Todo o caracter que possuir mais de um digito tem que estar dentro de [].
*/
int *treatment(char *number, char **charNumbers,int base){
	int *result = malloc (20 * sizeof (int));
	int *resultReturn = malloc (20 * sizeof (int));
	char *string = malloc (31 * sizeof (char));
	int max = strlen(number), i,j, k=0;
	int teste;
	for(i = 0; i < max; i++){
		if(number[i]=='['){ //Identificando caracteres com mais de um digito.
			j=0;
			string[j] = number[i];
			do{ 
				j++;
				i++;
				string[j] = number[i];
			}while(number[i] != ']');
			for(j = 0; j < 255; j++){
				if(strcmp(string, charNumbers[j]) == 0){ //Comparando os caracteres de mais de um digito pelo usuario com os do arquivo Caracteres.txt. 
					result[k] = j;
					teste = 0;
					memset(string, 0, sizeof(string)); //Limpando a String.
					break;
				}else{
					teste = 2;
				}
			}
			if(j==255){
				resultReturn[0] = FINAL_ARRAY;
				return resultReturn;
			}
			k++;
			continue;
		}
		string[0] = number[i];
		for(j = 0; j < base; j++){
			if(strcmp(string, "-") == 0){ 
				result[k] = 0; 
				teste = 0;	
				break;
			}
			if(strcmp(string, ".") == 0){ 
				result[k] = -1; 
				teste = 0;	
				break;
			}
			if(strcmp(string, charNumbers[j]) == 0){ //Comparando os caracteres de apenas um digito pelo usuario com os do arquivo Caracteres.txt.
				result[k] = j; 
				teste = 0;	
				break;
			}else{
				teste = 2;	
			}	
		}
		if(teste==2){
			resultReturn[0] = FINAL_ARRAY;
			return resultReturn; 
		}	
		memset(string, 0, sizeof(string)); //Limpando a String.
		k++;
	}
	max = k;
	for(i = 0; i < max; i++){ //Invertendo o vetor.
		k--;
		resultReturn[i] = result[k]; 
	}
	resultReturn[max] = FINAL_ARRAY; //Colocando constante que sinaliza o final do vetor para funcionalidades de outras fun��es.
	
	return resultReturn;
}

/*
	A��o - Converte um numero decimal na base selecionada.
	Entrada - Recebe um long e um int, um com numero a ser convertido e o outro com base a ser convertida.
	Sa�da - Retorna um vetor de int.
*/
int *convertToBase(long number, int base) {
	int *result = malloc (20 * sizeof (int));
	if (number < base) {
		result[0] = number;
		result[1] = FINAL_ARRAY;  
		return result;
	}
	if (number == base) {
		result[0] = 1;
		result[1] = 0;
		result[2] = FINAL_ARRAY;  
		return result;
	}
	int i, maxArray, j = 0, aux = number;
	for(i = 0;  aux >= base; i++){
		aux = aux / base;
	}
	maxArray = i;
	j = maxArray;
	result[maxArray + 1 ] = FINAL_ARRAY;
	for (i = 0; i < maxArray; i++)
	{
		result[j] = number % base;
		number = number / base;
		j--;
	}
	result[0] = number;
	return result;
}

/*
	A��o - Converte um numero de outra base em decimal.
	Entrada - Recebe um vetor invertido do numero a ser covertido e a base que ele se encontra.
	Sa�da - Retorna um int em decimal.
	Suposi��es - O vetor do numero tem que estar reverso isso � inv�s de [100] tem que estar [001].
*/
double convertToDecimal(int *number, int base) {
	double result = 0.0;
	int i, j, k = 0;
	
	//Esse loop foi feito para tratar numeros fracionarios.
	for(j = 0; number[j] != FINAL_ARRAY; j++){
		if(number[j]==-1){
			k = j + 1;
			j--;
			for(i = -1; j!=-1; i--){
				result = result + number[j] * pow(base, i);
				j--;
			}
			break;
		}
	}
	
	//O vetor recebido tem no final a costante FINAL_ARRAY, assim d� para ver o final do vetor.
	for(i = 0; number[k] != FINAL_ARRAY; i++){
		result = result + number[k] * pow(base,i); 
		k ++;
	}
	int teste = (int) result;

	return result;
}


double mathOperation(double v1, double v2, char op){
	if(op =='+'){
		return (v1 + v2);
	}
	if(op =='-'){
		return (v1 - v2);
	}
	if(op =='*'){
		return (v1 * v2);
	}
	if(op =='/'){
		return (v1 / v2);
	}
	return 1;
}

//Carrega tudo que � necessario para o programa rodar normal, nesse caso o arquivo Caracteres.txt.
char **loading(char *path){
	char **charsNumbers;
	if(strcmp(path, "Caracteres.txt") == 0){
		charsNumbers = read("Caracteres.txt");	
	}else if(strcmp(path, "CaracPardr.cnf") == 0){
		charsNumbers = read("CaracPardr.cnf");
	}else{
		printf("Error 0207001: N�o foi possivel encontrar caminho para os arqs txt.");
	}
	return charsNumbers;
}

/*
	A��o - Formata uma string que veio diretamente do arquivo Caracteres.txt.
	Entrada - Uma string vinda do arquivo.
	Sa�da - A string formatada apenas com o valor util.
	Suposi��es - Tudo que vem antes do ':' e que vai depois do � � ignorado, ficando apenas o valor util. O valor pode ter no maximo 30 caracteres.
*/
char * format(char* value) {
	char *result = malloc(30 * sizeof(char));
	int i = 0, j = 0;
	do {
		i++;
	} while (value[i] != ':');
	i++;
	while (value[i] != '�') {
		result[j] = value[i];
		
		j++;
		i++;
	}
	return result;
}

char **read(char *patch){
	FILE *arq;
	char line[30];
	char **caracteres = malloc(257 * sizeof(char*));
	int i;
	arq = fopen(patch, "rt");
	if (arq == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	for (i =0 ; i < 255; ++i)
		caracteres[i] = malloc(30 * sizeof(char));
	for(i = 0; i < 255; i++){
		fgets(line, 30, arq);
		strcpy(caracteres[i], format(line));
	}
	fclose(arq);
	return caracteres;
}

void readConfig(char *patch){
	FILE *arq;
	int i;
	arq = fopen(patch, "rt");
	if (arq == NULL){
		printf("Problemas na abertura do arquivo\n");
	}
	for(i = 0; i < 2; i++){
		fgets(configUser[i], 20, arq);
	}
	fclose(arq);
}

void imgScreen(){
	char *filename = "image.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
 
    fclose(fptr);
}

void print_image(FILE *fptr){
    char read_string[128];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

int saveConfigUser(){
	char url[]="config.cnf";
	FILE *arq;
	
	arq = fopen(url, "w");
	if(arq == NULL){
	
		printf("Erro, nao foi possivel abrir o arquivo\n");
		return False;
	}else{
		fprintf(arq, configUser[0]);
		fprintf(arq, "");
		fprintf(arq, configUser[1]);
	}
	fclose(arq);
	
	return True;
	
}


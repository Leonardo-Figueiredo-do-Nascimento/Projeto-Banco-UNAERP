#include <iostream>
#include <vector>
using namespace std;

struct Usuario{
	float total=0;
};

struct Registro{
	Usuario user;
	float valor;
	string operacao;
	string motivo;
	string categoria;	
};

void registrarEntrada(){
	cout<<"Selecione uma das categorias para informar o motivo do deposito: "<<endl;
	cout<<
}

void registrarSaida(){
	int opcaoCategoria;
	float valorSaque;
	Registro r1;
	cout<<"Informe a quantia a ser retirada: ";
	cin>>valorSaque;
	cout<<"Informe onde vai gastar o dinheiro: "<<endl;
	cin>>r1.motivo;
	cout<<"\nAlguma das categorias abaixo se encaixa na sua descricao?"<<endl;
	cout<<"1- Lazer \n2- Saude \n3- Custo de vida \n4- Outros"
	cin>>opcaoCategoria;
	
	if(opcaoCategoria==1){
		if(valorSaque>500){
			cout<<"Valor a ser utilizado excede o teto.";
			continue;			
		}
	} else if(opcaoCategoria==2){
		if(valorSaque>5000){
			cout<<"Valor a ser utilizado excede o teto.";
			continue;			
		}
	} else if(opcaoCategoria==3){
		if(valorSaque>10000){
			cout<<"Valor a ser utilizado excede o teto.";
			continue;			
		}
	} if(opcaoCategoria==4){
		if(valorSaque>200){
			cout<<"Valor a ser utilizado excede o teto.";
			continue;			
		}
	} else{
		cout<<"Selecione uma das categorias abaixo";
	}
}

//float extrato(Usuario u){
//	return ;
//}

int main(int argc, char** argv) {
	
	Usuario u1;
	int opcao=0;
	
	while(opcao!=4){
		vector<Registro> vetorRegistros;
		cout<<"\n------BANCO------"<<endl;
		cout<<"\n Digite a operacao desejada: "<<endl;
		cout<<"1- Realizar entrada \n2- Realizar saida \n3- Ver extrato \n4- Sair"<<endl;
		
		cin>>opcao;
		
		if(opcao==1){
			
		}
		
		if(opcao==2){
			
		}
		
		if(opcao==3){
			
		}
	}
	return 0;
}
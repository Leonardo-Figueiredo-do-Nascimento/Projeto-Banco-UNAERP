#include <iostream>
#include <vector>
using namespace std;

struct Registro{
	float valor;
	string operacao;
	string motivo;
	string categoria;	
};

Registro registrarEntrada(){
	float quantia;
	int opcaoMotivo;
	Registro r1;
	cout<<"\nInforme a quantia a ser depositada: "<<endl;
	cin>>quantia;
	do {
        cout << "Selecione uma das categorias para informar o motivo do deposito: " << endl;
        cout << "1- Salario \n2- Jobs \n3- Outros" << endl;
        cin >> opcaoMotivo;

        if(opcaoMotivo < 1 || opcaoMotivo > 3) {
            cout << "Selecione uma das categorias informadas." << endl;
    	}
    } while(opcaoMotivo < 1 || opcaoMotivo > 3);

    r1.operacao = "Entrada";
    r1.valor = quantia;
    if(opcaoMotivo == 1) {
        r1.motivo = "Salario";
    } else if(opcaoMotivo == 2) {
        r1.motivo = "Jobs";
    } else if(opcaoMotivo == 3) {
        r1.motivo = "Outros";
    }

    return r1;
}

Registro registrarSaida(){
	float valorSaque;
	int opcaoCategoria;
	Registro r1;
	cout<<"Informe quanto dinheiro pretende retirar: "<<endl;
	cin>>valorSaque;
	cout<<"Informe onde vai gastar o dinheiro: "<<endl;
	cin>>r1.motivo;
	cout<<"\nAlguma das categorias abaixo se encaixa na sua descricao?"<<endl;
	cout<<"1- Lazer \n2- Estudo \n3- Deslocamento \n4- Outros"
	cin>>opcaoCategoria;
	
	if(opcaoCategoria==1){
		if(valorSaque>500){
			cout<<"Valor a ser utilizado excede o teto de R$500,00.";
			continue;			
		}else {
			return r1;
		}
	} else if(opcaoCategoria==2){
		if(valorSaque>2000){
			cout<<"Valor a ser utilizado excede o teto de R$2000,00.";
			continue;			
		}else {
			return r1;
		}
	} else if(opcaoCategoria==3){
		if(valorSaque>4000){
			cout<<"Valor a ser utilizado excede o teto de R$4000,00.";
			continue;			
		}else {
			return r1;
		}
	} if(opcaoCategoria==4){
		if(valorSaque>200){
			cout<<"Valor a ser utilizado excede o teto de R$200,00.";
			continue;			
		}else {
			return r1;
		}
	} else{
		cout<<"Selecione uma das categorias abaixo";
	}
}

void extrato(float total){
	cout<<"\n--EXTRATO--"<<endl;
	cout<<"\nTotal: R$"<<total<<endl;
}

int main(int argc, char** argv) {
	
	int opcao=0;
	float total = 0;
	
	while(opcao!=4){
		vector<Registro> vetorRegistros;
		
		cout<<"\n------BANCO------"<<endl;
		cout<<"\n Digite a operacao desejada: "<<endl;
		cout<<"1- Realizar entrada \n2- Realizar saida \n3- Ver extrato \n4- Sair"<<endl;
		
		cin>>opcao;
		
		if(opcao==1){
			Registro r = registrarEntrada();
			vetorRegistros.push_back(r);	
		}
		
		if(opcao==2){
			Registro r = registrarSaida();
			vetorRegistros.push_back(r);
		}
		
		if(opcao==3){
			extrato(total);
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct Registro{
	float valor;
	string operacao;
	string motivo;	
};

struct Categoria{
	string nome;
	float orcamento;	
};


Registro registrarEntrada(){
	float quantia;
	int opcaoMotivo;
	Registro r1;
	cout<<"\nInforme a quantia a ser depositada: R$"<<endl;
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
	Registro r1;
	cout<<"\nInforme quanto dinheiro pretende retirar: "<<endl;
	cin>>valorSaque;
	cout<<"Informe onde vai gastar o dinheiro: "<<endl;
	cin>>r1.motivo;
	r1.operacao = "Saida";
	r1.valor = valorSaque;
	return r1;
}

void extrato(vector<Registro> registros, vector<Categoria> categorias){
	cout<<"\n===============================";
	cout<<"\n---------EXTRATO--------";
	cout<<"\n==============================="<<endl;
	
	float total;
	
	for(Registro registro : registros){
		if(registro.operacao == "Entrada"){
			total += registro.valor;
		} else{
			total += registro.valor;
		}
	}
	
	for(Registro registro : registros){
		cout<<"Operacao: "<<registro.operacao<<" || Fonte: "<<registro.motivo<<" || Quantia: R$"<<registro.valor<<endl;
	}
	cout<<"\n------------------------";
	cout<<"\nTotal: R$"<<total<<endl;
	cout<<"------------------------";
	
	for(Categoria c : categorias){
		cout<<"\n Categoria: "<<c.nome<<" | Orçamento: R$ "<<c.orcamento;
	}
}

Categoria cadastrarCategoria(){
	Categoria cat;
	cout<<"\nInsira o nome da categoria: ";
	cin>>cat.nome;
	cout<<"\nInforne o orçamento da categoria: R$";
	cin>>cat.orcamento;
	return cat;
}

int main(int argc, char** argv) {
	
	int opcao=0;
	float total = 0;
	vector<Registro> vetorRegistros;
	vector<Categoria> vetorCategorias;
	
	while(opcao!=5){
		
		cout<<"\n------BANCO------"<<endl;
		cout<<"\n Digite a operacao desejada: "<<endl;
		cout<<"1- Realizar entrada \n2- Realizar saida \n3- Cadastrar Categoria \n4- Ver extrato \n5- Sair"<<endl;
		
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
			Categoria c1 = cadastrarCategoria();
			vetorCategorias.push_back(c1);
		}
		
		if(opcao==4){
			extrato(vetorRegistros,vetorCategorias);
		}
		
		if(opcao==5){
			break;
		} 
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>
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
	cout<<"\nInforme a quantia a ser depositada: R$";
	cin>>quantia;
	do {
        cout << "\nSelecione uma das categorias para informar o motivo do deposito: " << endl;
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

Registro registrarSaida(float saldo){
	float valorSaque;
	Registro r1;
	cout<<"\nInforme quanto dinheiro pretende retirar: R$";
	cin>>valorSaque;
	if(valorSaque<=saldo){
		cout<<"Informe onde vai gastar o dinheiro: "<<endl;
		cin>>r1.motivo;
		r1.operacao = "Saida";
		r1.valor = valorSaque;
		return r1;
	}else{
		cout<<"\nSaldo insuficiente."<<endl;
		return 0;
	}
}

void extrato(vector<Registro> registros, vector<Categoria> categorias){
	
	float total;
	
	for(Registro registro : registros){
		if(registro.operacao == "Entrada"){
			total += registro.valor;
		} else{
			total -= registro.valor;
		}
	}

	cout<<"\n==========================================="<<endl;
	
	cout<<"\n ==============================";
	cout<<"\n|            EXTRATO           |";
	cout<<"\n =============================="<<endl;
	
	cout<<"\n----------OPERACOES----------"<<endl;
	
	for(Registro registro : registros){
		cout<<"Operacao: "<<registro.operacao<<" || Fonte: "<<registro.motivo<<" || Quantia: R$"<<fixed<<setprecision(2)<<registro.valor<<endl;
	}
	cout<<"\n----------CATEGORIAS----------"<<endl;
	for(Categoria c : categorias){
		cout<<"\n Categoria: "<<c.nome<<" | Orcamento: R$ "<<fixed<<setprecision(2)<<c.orcamento<<endl;
	}

	cout<<"\n------------------------";
	cout<<"\n   TOTAL: R$"<<fixed<<setprecision(2)<<total<<endl;
	cout<<"------------------------"<<endl;
	cout<<"\n==========================================="<<endl;
}

Categoria cadastrarCategoria(){
	Categoria cat;
	cout<<"\nInsira o nome da categoria: ";
	cin>>cat.nome;
	cout<<"\nInforme o orcamento da categoria: R$";
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
		cout<<"\nDigite a operacao desejada: "<<endl;
		cout<<"1- Realizar entrada \n2- Realizar saida \n3- Cadastrar Categoria \n4- Ver extrato \n5- Sair"<<endl;
		cout<<"-> ";
		cin>>opcao;
		
		if(opcao==1){
			Registro r = registrarEntrada();
			vetorRegistros.push_back(r);	
		}
		
		if(opcao==2){
			Registro r = registrarSaida(total);
			if(r.motivo != ""){				
				vetorRegistros.push_back(r);
			}
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
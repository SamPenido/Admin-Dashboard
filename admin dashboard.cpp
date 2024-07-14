#include <iostream>
#include <vector>
#include <iomanip> // Para formatação de saída

using namespace std;

// Classe Funcionario para representar cada funcionário
class Funcionario {
private:
    string nome;
    string cpf;
    string telefone;
    string email;
    string cargo;
    double salario;

public:
    Funcionario(string nome, string cpf, string telefone, string email, string cargo, double salario)
        : nome(nome), cpf(cpf), telefone(telefone), email(email), cargo(cargo), salario(salario) {}

    // Método para obter o nome do funcionário
    string getNome() const {
        return nome;
    }

    // Método para exibir os dados do funcionário
    void exibirDados() const {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Email: " << email << endl;
        cout << "Cargo: " << cargo << endl;
        cout << fixed << setprecision(2); // Formatação para duas casas decimais no salário
        cout << "Salário: R$ " << salario << endl;
        cout << "--------------------------" << endl;
    }
};

// Classe Administração para gerenciar os funcionários
class Administracao {
private:
    vector<Funcionario> funcionarios;

public:
    // Método para adicionar um novo funcionário
    void adicionarFuncionario(string nome, string cpf, string telefone, string email, string cargo, double salario) {
        Funcionario novoFuncionario(nome, cpf, telefone, email, cargo, salario);
        funcionarios.push_back(novoFuncionario);
        cout << "Funcionário adicionado com sucesso!" << endl;
    }

    // Método para exibir todos os funcionários
    void exibirFuncionarios() const {
        if (funcionarios.empty()) {
            cout << "Nenhum funcionário cadastrado ainda." << endl;
        } else {
            cout << "Lista de Funcionários:" << endl;
            for (const auto& funcionario : funcionarios) {
                funcionario.exibirDados();
            }
        }
    }
};

int main() {
    Administracao administracao;
    int opcao;

    do {
        cout << "----- Menu -----" << endl;
        cout << "1. Adicionar Funcionário" << endl;
        cout << "2. Exibir Funcionários" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome, cpf, telefone, email, cargo;
                double salario;

                cout << "Nome do funcionário: ";
                cin.ignore();
                getline(cin, nome);

                cout << "CPF: ";
                getline(cin, cpf);

                cout << "Telefone: ";
                getline(cin, telefone);

                cout << "Email: ";
                getline(cin, email);

                cout << "Cargo: ";
                getline(cin, cargo);

                cout << "Salário: ";
                cin >> salario;

                administracao.adicionarFuncionario(nome, cpf, telefone, email, cargo, salario);
                break;
            }
            case 2:
                administracao.exibirFuncionarios();
                break;
            case 3:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }

        cout << endl;
    } while (opcao != 3);

    return 0;
}

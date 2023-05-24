#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sala {
private:
    string nome;
    int capacidade;
    bool ocupada;

public:
    Sala(string aNome, int aCapacidade) {
        setNome(aNome);
        setCapacidade(aCapacidade);
        ocupada = false;
    }

    // Setters and getters for nome
    void setNome(string aNome) {
        nome = aNome;
    }
    string getNome() {
        return nome;
    }

    // Setters and getters for capacidade
    void setCapacidade(int aCapacidade) {
        capacidade = aCapacidade;
    }
    int getCapacidade() {
        return capacidade;
    }

    // Setters and getters for ocupada
    bool isOcupada() {
        return ocupada;
    }
    void ocupar() {
        ocupada = true;
    }
    void desocupar() {
        ocupada = false;
    }
};

class Turma {
private:
    int tamanho;
    string horario;
    bool aulaAgendada;
    Sala* sala;
    int dia;

public:
    string nome;

    Turma(int aDia = 1, string aNome = "default", int aTamanho = 0, string aHorario = "default") {
        setNome(aNome);
        setTamanho(aTamanho);
        setHorario(aHorario);
        aulaAgendada = false;
        sala = nullptr;
        setDia(aDia);
    }

    // Setters and getters for nome
    void setNome(string aNome) {
        nome = aNome;
    }
    string getNome() {
        return nome;
    }

    // Getter for sala
    Sala* getSala() {
        return sala;
    }

    // Setters and getters for tamanho
    void setTamanho(int aTamanho) {
        tamanho = aTamanho;
    }
    int getTamanho() {
        return tamanho;
    }

    // Getter for aulaAgendada
    bool isAulaAgendada() {
        return aulaAgendada;
    }

    // Setters and getters for horario
    void setHorario(string aHorario) {
        horario = aHorario;
    }
    string getHorario() {
        return horario;
    }

    void agendarAula(Sala* aSala) {
        aulaAgendada = true;
        sala = aSala;
    }

    // Setters and getters for dia
    void setDia(int aDia) {
        dia = aDia;
    }
    int getDia() {
        return dia;
    }
};

// Function to check availability
bool verificarDisponibilidade(const vector<Sala>& salas) {
    for (const Sala& sala : salas) {
        if (!sala.isOcupada()) {
            return true;
        }
    }
    return false;
}

// Function for allocation
pair<int, int> alocarTurma(int dia, Turma& turma, vector<Sala>& salas, vector<vector<vector<bool>>>& disponibilidade, const vector<string>& horarios) {
    for (Sala& sala : salas) {
        if (sala.getCapacidade() >= turma.getTamanho() && !sala.isOcupada()) {
            for (int i = 0; i < static_cast<int>(disponibilidade.size()); i++) {
                for (int j = 0; j < static_cast<int>(disponibilidade[i].size()); j++) {
                    if (turma.getHorario() == horarios[j] && disponibilidade[i][dia][j]) {
                        disponibilidade[i][dia][j] = false; // Mark the time slot as occupied
                        sala.ocupar(); // Mark the sala as occupied
                        turma.agendarAula(&sala); // Assign the selected sala to the turma
                        turma.setDia(dia);
                        return make_pair(i, j);
                    }
                }
            }
        }
    }
    return make_pair(-1, -1); // Indicate that the turma couldn't be allocated
}

string imprimirAlocacao(const vector<Turma>& turmas, int dia, const string& horario, const Sala* sala) {
    for (const Turma& turma : turmas) {
        if (horario == turma.getHorario() && dia == turma.getDia() && sala == turma.getSala()) {
            return turma.getNome();
        }
    }
    return "";
}

int main() {
    vector<string> dias = { "segunda", "terca", "quarta", "quinta", "sexta" };
    vector<string> horarios = { "H1", "H2", "H3", "H4" };

    vector<Sala> salas = {
        Sala("C1", 70),
        Sala("C2", 30),
        Sala("C3", 20),
        Sala("C4", 70),
        Sala("C5", 20),
        Sala("C6", 20),
        Sala("C7", 30)
    };
    vector<Turma> turmas;

    // Matrix to represent the availability of salas for each dia and horario
    // Each element of the matrix represents a specific sala, dia, and horario
    vector<vector<vector<bool>>> disponibilidade(
        salas.size(),
        vector<vector<bool>>(dias.size(), vector<bool>(horarios.size(), true))
    );

    int dia = 0;
    char alocarOutroDia = 'S';

    while (dia < static_cast<int>(dias.size())) {
        if (alocarOutroDia == 'N' || alocarOutroDia == 'n') {
            break;
        }

        if (alocarOutroDia == 'S' || alocarOutroDia == 's') {
            int quantidadeTurmas;
            cout << "Alocando aulas no dia " << dias[dia] << "\n";
            cout << "Quantas turmas deseja alocar? ";
            cin >> quantidadeTurmas;

            for (int i = 0; i < quantidadeTurmas; i++) {
                string turmaNome, turmaHorario;
                int turmaTamanho;

                cout << "Informe o nome da turma: ";
                cin >> turmaNome;

                if (turmaNome == "fim" || turmaNome == "FIM") {
                    break;
                }

                cout << "Informe a quantidade de alunos: ";
                cin >> turmaTamanho;

                cout << "Informe o horário da turma (H1, H2, H3, H4): ";
                cin >> turmaHorario;

                Turma turma(dia, turmaNome, turmaTamanho, turmaHorario);
                turmas.push_back(turma);

                if (!turma.isAulaAgendada()) {
                    alocarTurma(dia, turma, salas, disponibilidade, horarios);
                }
            }
        }

        cout << "Deseja alocar outro dia? (S/N): ";
        cin >> alocarOutroDia;

        if (alocarOutroDia == 'N' || alocarOutroDia == 'n') {
            break;
        }

        dia++;

        if (dia >= static_cast<int>(dias.size())) {
            cout << "Acabou a semana." << endl;
            break;
        }
    }

    for (const Sala& sala : salas) {
        cout << "Sala " << sala.getNome() << endl;

        for (int i = 0; i < static_cast<int>(dias.size()); i++) {
            cout << dias[i] << endl;

            for (int h = 0; h < static_cast<int>(horarios.size()); h++) {
                cout << horarios[h];

                if (!disponibilidade[i][dia][h]) {
                    cout << "_" << imprimirAlocacao(turmas, i, horarios[h], &sala);
                } else {
                    cout << "_";
                }
            }

            cout << endl;
        }
    }

    return 0;
}

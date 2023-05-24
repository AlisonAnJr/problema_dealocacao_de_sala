#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sala
{
private:
    string nome;
    int capacidade;
    bool ocupada;

public:
    Sala(string aNome, int aCapacidade)
    {
        setNome(aNome);
        setCapacidade(aCapacidade);
        ocupada = false;
    }

    // set get nome
    void setNome(string aNome)
    {
        nome = aNome;
    }
    string getNome()
    {
        return nome;
    }

    // set get capacidade
    void setCapacidade(int aCapacidade)
    {
        capacidade = aCapacidade;
    }
    int getCapacidade()
    {
        return capacidade;
    }

    // set get ocupada
    bool isOcupada()
    {
        return ocupada;
    }
    void ocupar()
    {
        ocupada = true;
    }
    void desocupar()
    {
        ocupada = false;
    }
};

class Turma
{
private:
    int tamanho;
    string horario;
    bool aulaAgendada;
    Sala *sala;
    int dia;

public:
    string nome;

    Turma(int aDia = 1, string aNome = "default", int aTamanho = 0, string aHorario = "default")
    {
        setNome(aNome);
        setTamanho(aTamanho);
        setHorario(aHorario);
        aulaAgendada = false;
        sala = nullptr;
        setDia(aDia);
    };

    // set get nome
    void setNome(string aNome)
    {
        nome = aNome;
    }
    string getNome()
    {
        return nome;
    }
    // get sala
    Sala *getSala()
    {
        return sala;
    }

    // set get tamanho
    void setTamanho(int aTamanho)
    {
        tamanho = aTamanho;
    }
    int getTamanho()
    {
        return tamanho;
    }

    // get aulaAgendada
    bool isAulaAgendada()
    {
        return aulaAgendada;
    }

    // set get horario
    void setHorario(string aHorario)
    {
        horario = aHorario;
    }
    string getHorario()
    {
        return horario;
    }

    void agendarAula(Sala *aSala)
    {
        aulaAgendada = true;
        sala = aSala;
    }

    // set get dia
    void setDia(int aDia)
    {
        dia = aDia;
    }

    int getDia()
    {
        return dia;
    }
};

// função para verificar a disponibilidade
bool verificarDisponibilidade(vector<Sala> salas)
{
    for (Sala &sala : salas)
    {
        if (!sala.isOcupada())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// função alocação
auto alocarTurma(int dia, Turma turma, vector<Sala> salas, vector<vector<vector<bool>>> disponibilidade, vector<string> horarios)
{
    for (Sala &sala : salas)
    {
        if (sala.getCapacidade() >= turma.getTamanho() && !sala.isOcupada())
        {
            for (int i = 0; i < int(disponibilidade.size()); i++)
            {
                for (int j = 0; j < int(disponibilidade.size()); j++)
                {
                    if (turma.getHorario() == horarios[j] && disponibilidade[i][j][i])
                    {
                        disponibilidade[i][j][i] = false; // Marca o horario como ocupado
                        sala.ocupar();                    // Marca a sala como ocupada
                        turma.agendarAula(&sala);         // aloca a sala escolhida para a turma
                        turma.setDia(dia);
                        return make_pair(i, j);
                    }
                }
            }
        }
    }
    return make_pair(-1, -1); // Indicar que não foi possivel alocar a turma
}

string imprimirAlocacao(vector<Turma> turmas, int dia, string horario, Sala *sala)
{
    for(Turma &turma : turmas){
        if(horario == turma.getHorario() && dia == turma.getDia() && sala == turma.getSala()){
            return turma.getNome();
        }
    }
    return " ";
}

int main()
{
    vector<string> dias = {"segunda", "terca", "quarta", "quinta", "sexta"};
    vector<string> horarios = {"H1", "H2", "H3", "H4"};

    vector<Sala> salas = {Sala("C1", 70),
                          Sala("C2", 30),
                          Sala("C3", 20),
                          Sala("C4", 70),
                          Sala("C5", 20),
                          Sala("C6", 20),
                          Sala("C7", 30)};
    vector<Turma> turmas;

    bool disponivel = verificarDisponibilidade(salas);

    // Matriz para representar a disponibilidade das salas em cada dia e horário
    // Cada elemento da matriz representa uma sala, um dia e um horário específico
    vector<vector<vector<bool>>> disponibilidade(salas.size(),vector<vector<bool>>(dias.size(), vector<bool>(horarios.size(), true)));

    int dia = 0;
    char alocarOutroDia = 'S';
    while (dia < int(dias.size()))
    {
        
        do{
                Turma turma;

                if (alocarOutroDia == 'S' || alocarOutroDia == 's')
                {
                    int quantidadeTurmas;
                    cout << "Alocando aulas no dia " << dias[dia] << "\n";
                    cout << "Quantas turmas deseja alocar? ";
                    cin >> quantidadeTurmas;
                    for (int i = 0; i < quantidadeTurmas; i++)                        
                        {
                            string turmaNome, turmaHorario;
                            int turmaTamanho;
                            cout << "Informe o nome da turma: ";
                            cin >> turmaNome;
                            if(turmaNome == "fim" || turmaNome =="FIM"){
                                break;
                            }
                            turma.setNome(turmaNome);
                            cout << "Informe a quantidade de alunos: ";
                            cin >> turmaTamanho;
                            turma.setTamanho(turmaTamanho);
                            cout << "Informe o horário da turma (H1, H2, H3, H4): ";
                            cin >> turmaHorario;
                            turma.setHorario(turmaHorario);
                            turmas.push_back(turma);
                            if (!turma.isAulaAgendada())
                                alocarTurma(dia, turma, salas, disponibilidade, horarios);
                        }
                }
                cout << "Deseja alocar outro dia? (S/N): ";
                cin >> alocarOutroDia;
                if(alocarOutroDia == 'N' || alocarOutroDia == 'n'){
                    dia = dias.size();
                    break;
                }
                dia++;
                if (dia > int(dias.size()))
                {
                    cout << "acabou a semanha";
                    break;
                }

        } while (alocarOutroDia == 'S' || alocarOutroDia == 's');
        
    }
/*
    for (int s = 0; s < int(salas.size()); s++)
    {
        cout << "Sala " << &salas[s].getNome << endl;
        for (int i = 0; i < int(dias.size()); i++)
        {
            cout << dias[i] << endl;
            for (int h = 0; h < int(horarios.size()); h++)
            {
                cout << horarios[h];
                if (!disponibilidade[s][i][h])
                {
                    imprimirAlocacao(turmas, i, horarios[h], &salas[s]);
                }
                else
                {
                    cout << "_";
                }
            }
        }
    }*/

    for (int s = 0; s < int(salas.size()); s++)
    {
        cout << "Sala " << &salas[s].getNome << " Cap " << &salas[s].getCapacidade << endl;

        for (int i = 0; i < static_cast<int>(dias.size()); i++) {
            cout << dias[i] << endl;

            for (int h = 0; h < static_cast<int>(horarios.size()); h++) {
                cout << horarios[h];

                if (!disponibilidade[s][i][h]) {
                    cout << "_" << imprimirAlocacao(turmas, i, horarios[h], &salas[s]);
                } else {
                    cout << "_";
                }
            }

            cout << endl;
        }
    }

    return 0;
}
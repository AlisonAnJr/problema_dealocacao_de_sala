#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Turma
{
    private:
    string id;
    int tamanho;
    int horario;
    int dia;
    int sala;

    public:
        /*Turma(int aDia, string aid, int aTamanho, int aHorario, int aSala){
        setId(aid);
        setTamanho(aTamanho);
        setHorario(aHorario);
        setDia(aDia);
        setSala(aSala);
        }*/

        //
        void setId(string aId){
            id = aId;
        }
        string getId(){
            return id;
        }

        //
        void setDia(int aDia){
            dia = aDia;
        }
        int getDia(){
            return dia;
        }

        //
        void setTamanho(int aTamanho){
            tamanho = aTamanho;
        }
        int getTamanho(){
            return tamanho;
        }

        //
        void setHorario(int aHorario){
            horario = aHorario;
        }
        int getHorario(){
            return horario;
        }

        void setSala(int aSala){
            sala = aSala;
        }
        int getSala(){
            return sala;
        }
    
};

bool turmaExiste(vector<Turma> turmas, string turmaNome){
    for(int i = 0; i < turmas.size(); i++)
    {
        if(turmas[i].getId() == turmaNome)
            return true;
    }
    return false;
}

int salaVaga(vector<vector<vector<string>>> Aulas, vector<int> capSalas, int dia, int escoHorario, int tamTurma){
    //tamanhoSalas   70    30    20    70    20    20    30
    int h = escoHorario - 1, salaIndex;

    if(tamTurma <= 70 && tamTurma > 30){
        if(Aulas[dia][0][h] == "_"){
            salaIndex = 0;
        }
        else if(Aulas[dia][3][h] == "_"){
            salaIndex = 3;
        }
        else{
            salaIndex = 999;
        }
    }
    else if(tamTurma <= 30 && tamTurma > 20){
        if(Aulas[dia][1][h] == "_"){
            salaIndex = 1;
        }
        else if(Aulas[dia][6][h] == "_"){
            salaIndex = 6;
        }
        else{
            salaIndex = 999;
        }
    }
    else if(tamTurma <= 20){
        if(Aulas[dia][4][h] == "_"){
            salaIndex = 4;
        }
        else if(Aulas[dia][5][h] == "_"){
            salaIndex = 5;
        }
        else{
            salaIndex = 999;
        }
    }
    else{
        salaIndex = 999;    
    }

    return salaIndex;
}   

void imprime(vector<vector<vector<string>>> Aulas, vector<string> dias, vector<string> salas, vector<string> horarios, vector<Turma> turmas){
    system("cls");
    //d -> dias; s -> salas; h -> horarios
    for(int d = 0; d < dias.size(); d++){
        cout << "\n\n" << dias[d] << "\n";
        for(int s = 0; s < salas.size(); s++){
            cout << "\n" <<salas[s];
            for(int h = 0; h < horarios.size(); h++){
                cout << " " << horarios[h] << " ";
                cout << Aulas[d][s][h];
            }
        }
    }
}

int que_dia(vector<string> dias){
    system("cls");
    int dia = 0;
    int diaEscolhido;
    cout << "Que dia quer alocar?\n";
    for(dia = 0; dia < dias.size(); dia++){
        cout << dia + 1 <<"-> " << dias[dia] <<"\n";
    }
    cout << "(Use [1, 2, 3, 4, 5, 6, 7] para escolher: ";
    cin >> diaEscolhido;

    return diaEscolhido - 1;

}

int main()
{   
    vector<string> dias = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
            //tamanhoSalas   70    30    20    70    20    20    30
    vector<string> salas = {"C1", "C2", "C3", "C4", "C5", "C6", "C7"};
    vector<int> capSalas = {70, 30, 20, 70, 20, 20, 30};
    //index horario = turma.getHorario - 1
    vector<string> horarios = {"H1", "H2", "H3", "H4"};

    vector<Turma> turmas;

    vector<vector<vector<string>>> Aulas(dias.size(), vector<vector<string>>(salas.size(), vector<string>(horarios.size(), "_")));

    int dia = 0;
    int qtdturmas = 0;
    char alocarOutroDia;
    
    while(true)
    {   
        dia = que_dia(dias);
        system("cls");
        cout << "Alocando na " << dias[dia] << endl;
        while(true)
        {
            Turma turma;
            string turmaNome;
            int tamTurma, escoHorario, sala;
            cout << "Informe o nome da turma(fim para finalizar a alocacao do dia): ";
            cin >> turmaNome;
            if(turmaNome == "fim" || turmaNome =="FIM"){
                break;
            }
            while(!turmaExiste)
            {
                cout << "Ja existe turma com este nome!";
                cout << "Informe o nome da turma(fim para finalizar a alocacao do dia): ";
                cin >> turmaNome;
                if(turmaNome == "fim" || turmaNome =="FIM")
                {
                    break;
                }
            }
            
            turma.setId(turmaNome);
            cout << "Informe a quantidade de alunos: ";
            cin >> tamTurma;
            if(tamTurma > 70){
                cout << "Nao ha sala com esta capacidade";
                break;
            }
            cout << "Informe o horário da turma (escolha usando 1, 2, 3, 4): \n1-> H1 \n2-> H2 \n3-> H3 \n4-> H4)\n(escolha usando 1, 2, 3, 4): ";
            cin >> escoHorario;
            sala = salaVaga(Aulas, capSalas, dia, escoHorario, tamTurma);
            if(sala == 999){
                cout << "Nao ha sala vaga neste dia e horario";
                break;
            }

            turma.setTamanho(tamTurma);
            turma.setHorario(escoHorario);
            turma.setSala(sala);

            Aulas[dia][sala][escoHorario-1] = turmaNome;
            turmas.push_back(turma);
            qtdturmas++;

        }

        cout << "Deseja alocar outro dia? (S/N): ";
        cin >> alocarOutroDia;
        if(alocarOutroDia == 'N' || alocarOutroDia == 'n')
        {
            break;
        }
    }   

    imprime(Aulas, dias, salas, horarios, turmas);

    return 0;
}
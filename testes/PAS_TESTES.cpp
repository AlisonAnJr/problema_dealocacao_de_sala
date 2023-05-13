#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


//classe horario
class Horario{
    private:
        string nome;
    public:
        //contructor Horario
        Horario(string aNome){
            setNome(aNome);
        }

        //set get Nome
        void setNome(string aNome){
            nome = aNome;
        }
        string getNome(){
            return nome;
        }
    
};

//classe sala
class Sala{
    private:
        string nome;
        int capacidade;
    public:
        //constructor Sala
        Sala(string aNome, int aCapacidade){
            setNome(aNome);
        }
        //set get nome
        void setNome(string aNome){
            nome = aNome;
        }
        string getNome(){
            return nome;
        }
        //set get capacidade
        void setCapacidade(int aCapacidade){
            capacidade = aCapacidade;
        }
        int getCapacidade(){
            return capacidade;
        }

};

//classe turma
class Turma{
    private:
        string nome;
        int tamanho;
    public:
        //constructor Turma
        Turma(string aNome, int aTamanho){
            setNome(aNome);
            setTamanho(aTamanho);
        }

        //set get nome
        void setNome(string aNome){
            nome = aNome;
        }
        string getNome(){
            return nome;
        }
        
        //set get tamanho
        void setTamanho(int aTamanho){
            tamanho = aTamanho;
        }
        int getTamanho(){
            return tamanho;
        }

};

class GradeSeamanal{
    private:
        vector<int> dias = {1, 2, 3, 4, 5};
        map<string, Sala> salas = {{"C1", Sala("C1", 70)}, {"C2", Sala("C2", 30)}, {"C3", Sala("C3", 20)},
                               {"C4", Sala("C4", 70)}, {"C5", Sala("C5", 20)}, {"C6", Sala("C6", 20)},
                               {"C7", Sala("C7", 30)}};
        vector<Horario> horarios = {Horario("H1"), Horario("H2"), Horario("H3"), Horario("H4")};
        vector<vector<vector<int>>> grade;
    public:
        void GradeSemanal(map<string, Sala> aSalas, vector<int> aDias, vector<Horario> aHorarios){
            /*a ideia aqui é uma grade onde com 5 dias, 7 salas, 4 horarios,
            seria uma grade para cada dia, ai seria uma matriz 4x7 (horario)(sala)*/
        }

};

int main(){
    /*codigo função main*/
    //container com os dias e os numeros refente a esses dias
    //vector<string> semana= {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    /*for(dia : semana){
        bla
    }*/
    
    //container com as salas ja instanciando os objetos sala 
    /*map<string, Sala> salas = {{"C1", Sala("C1", 70)}, {"C2", Sala("C2", 30)}, {"C3", Sala("C3", 20)},
                               {"C4", Sala("C4", 70)}, {"C5", Sala("C5", 20)}, {"C6", Sala("C6", 20)},
                               {"C7", Sala("C7", 30)}};
                               */
    //array com os horarios a serem alocadas as turmas
    //vector<Horario> horarios = {Horario("H1"), Horario("H2"), Horario("H3"), Horario("H4")};

    //vector<vector<vector<int>>> gradeSemanal = {/*dia*/{/*horario*/{/*sala*/}}};
    

    return 0;
}
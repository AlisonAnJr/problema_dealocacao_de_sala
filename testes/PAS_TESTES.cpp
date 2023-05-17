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
        vector<string> dias = {"segunda", "terca", "quarta", "quinta", "sexta"};

    public:
        void GradeSemanal(){
            
        }

};

class Alocacao{
    private:
        Sala sala;
        Turma turma;
    public:
        Alocacao(Sala aSala, Turma aTurma){
            setSala(aSala);
            setTurma(aTurma);
        }
        //set get sala
        void setSala(Sala aSala){
            sala = aSala;
        }
        Sala getSala(){
            return sala;
        }
        //set get turma
        void setTurma(Turma aTurma){
            turma = aTurma;
        }
        Turma getTurma(){
            return turma;
        }

};


int main(){
    const int max_turmas = 140;
    int num_turma = 0;
    vector<Turma> turmas;

    vector<Sala> salas = {Sala("C1", 70), Sala("C2", 30), Sala("C3", 20), Sala("C4", 70),
                            Sala("C5", 20), Sala("C6", 20), Sala("C7", 30)};

    vector<Horario> horarios = {Horario("H1"), Horario("H2"), Horario("H3"), Horario("H4")};
        

    while(num_turma < max_turmas){

    }

    return 0;
}
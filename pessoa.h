#ifndef PESSOA_H
#define PESSOA_H

#include <QString>

namespace minhaNamespace {
class Pessoa
{
private:
    QString nome;
    int matricula;
    bool ePorNome;
public:
    Pessoa();
    Pessoa(int matricula, QString nome, bool ePorNome);

    QString getNome() const {
        return nome;
    };

    void setNome(QString nome) {
        this->nome = nome;
    };

    int getMatricula() const {
        return matricula;
    };

    void setMatricula(int matricula) {
        this->matricula = matricula;
    };

    void setPorNome(bool ePorNome) {
        this->ePorNome = ePorNome;
    };

    bool getEPorNome() const {
        return ePorNome;
    }

    bool operator <(Pessoa pessoa);
    bool operator <=(Pessoa pessoa);
    bool operator >=(Pessoa pessoa);
};
}

#endif // PESSOA_H

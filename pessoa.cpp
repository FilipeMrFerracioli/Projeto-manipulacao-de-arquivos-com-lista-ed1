#include "pessoa.h"

namespace minhaNamespace {

Pessoa::Pessoa():
    nome(""),
    matricula(0),
    ePorNome(false)
{

}

Pessoa::Pessoa(int matricula, QString nome, bool ePorNome):
    nome(""),
    matricula(0),
    ePorNome(false)
{
    this->nome = nome;
    this->matricula = matricula;
    this->ePorNome = ePorNome;
}

bool Pessoa::operator <(Pessoa pessoa)
{
    if(pessoa.getEPorNome()) {
        if(this->nome < pessoa.nome) return true;
        return false;
    }

    if(this->matricula < pessoa.matricula) return true;
    return false;
}

bool Pessoa::operator <=(Pessoa pessoa)
{
    if(pessoa.getEPorNome()) {
        if(this->nome <= pessoa.nome) return true;
        return false;
    }

    if(this->matricula <= pessoa.matricula) return true;
    return false;
}

bool Pessoa::operator >=(Pessoa pessoa)
{
    if(pessoa.getEPorNome()) {
        if(this->nome >= pessoa.nome) return true;
        return false;
    }

    if(this->matricula >= pessoa.matricula) return true;
    return false;
}

}

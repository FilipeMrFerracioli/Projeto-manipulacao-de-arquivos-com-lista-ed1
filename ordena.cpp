#include "ordena.h"

namespace minhaNamespace {

Ordena::Ordena():
    listaPessoas(),
    ePorNome(false)
{

}

Ordena::Ordena(QString linhaPessoa, bool ePorNome):
    listaPessoas(),
    ePorNome(false)
{
    this->ePorNome = ePorNome;
    setListaPessoas(splitPessoa(linhaPessoa));
}

Pessoa Ordena::splitPessoa(QString linhaPessoa)
{
    //    if(linhaPessoa == "") return Pessoa();

    QStringList pessoa = linhaPessoa.split(";");

    Pessoa p;

    p.setMatricula(pessoa[0].toInt());
    p.setNome(pessoa[1]);
    p.setPorNome(ePorNome);

    return p;
}

void Ordena::setListaPessoas(Pessoa pessoa)
{
    listaPessoas.inserirOrdenado(pessoa);
}

QString Ordena::getListaAsc() const
{
    QString res = "";
    for(int i = 0; i < listaPessoas.getQuantidadeDeElementos(); i++) {
        res += "Matricula: " + QString::number(listaPessoas[i].getMatricula());
        res += "\n";
        res += "Nome: " + listaPessoas[i].getNome();

        if(i < (listaPessoas.getQuantidadeDeElementos() - 1)) res += "\n\n";
    }

    return res;
}

QString Ordena::getListaDesc() const
{
    QString res = "";
    for(int i = listaPessoas.getQuantidadeDeElementos() - 1; i >= 0; i--) {
        if(i < (listaPessoas.getQuantidadeDeElementos() - 1)) res += "\n\n";
        res += "Matricula: " + QString::number(listaPessoas[i].getMatricula());
        res += "\n";
        res += "Nome: " + listaPessoas[i].getNome();

        //if(i < (listaPessoas.getQuantidadeDeElementos() - 1)) res += "\n\n";
    }

    return res;
}

void Ordena::ordenarListaPorNome()
{
    setPorNome(true);

    for(int i = 0; i < listaPessoas.getQuantidadeDeElementos(); i++) {
        listaPessoas.inserirOrdenado(listaPessoas.retirarPos(i));
    }
}

void Ordena::ordenarListaPorMatricula()
{
    setPorNome(false);

    for(int i = 0; i < listaPessoas.getQuantidadeDeElementos(); i++) {
        listaPessoas.inserirOrdenado(listaPessoas.retirarPos(i));
    }
}

QString Ordena::getListaPessoas() const
{
    QString res = "";
    for(int i = 0; i < listaPessoas.getQuantidadeDeElementos(); i++) {
        //        if(!(QString::number(listaPessoas[i].getMatricula()) == "" && listaPessoas[i].getNome() == "")){
        res += "Matricula: " + QString::number(listaPessoas[i].getMatricula());
        res += "\n";
        res += "Nome: " + listaPessoas[i].getNome();
        //        }
        if(i < (listaPessoas.getQuantidadeDeElementos() - 1)) res += "\n\n";
    }

    return res;
}

QString Ordena::getListaPessoasSemFormatacao() const
{
    QString res = "";
    for(int i = 0; i < listaPessoas.getQuantidadeDeElementos(); i++) {
        res += QString::number(listaPessoas[i].getMatricula());
        res += ";";
        res += listaPessoas[i].getNome();
        if(i < (listaPessoas.getQuantidadeDeElementos() - 1)) res += "\n";
    }

    return res;
}

}

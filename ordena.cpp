#include "ordena.h"


#include <iostream>


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
    QStringList pessoa = linhaPessoa.split(";");

    //    std::cout << pessoa[0].toStdString(); // funcionando
    //    std::cout << pessoa[1].toStdString(); // funcionando

    Pessoa p;

    p.setMatricula(pessoa[0].toInt());
    p.setNome(pessoa[1]);
    p.setPorNome(ePorNome);

    //    std::cout << QString::number(p.getMatricula()).toStdString(); // funcionando
    //    std::cout << p.getNome().toStdString(); // funcionando

    return p;
    //    return Pessoa(pessoa[0].toInt(), pessoa[1], getEPorNome());
}

void Ordena::setListaPessoas(Pessoa pessoa)
{
    //    std::cout << QString::number(pessoa.getMatricula()).toStdString(); // funcionando
    //    std::cout << pessoa.getNome().toStdString(); // funcionando

    listaPessoas.inserirOrdenado(pessoa);

    //    std::cout << listaPessoas.getQuantidadeDeElementos();
}

QString Ordena::getListaPessoas() const
{
    QString res = "";
    for(int i = 0; i < listaPessoas.getQuantidadeDeElementos(); i++) {
        res += "Matricula: " + QString::number(listaPessoas[i].getMatricula());
        res += "\n";
        res += "Nome: " + listaPessoas[i].getNome();
        res += "\n";
    }

    return res;
}

}

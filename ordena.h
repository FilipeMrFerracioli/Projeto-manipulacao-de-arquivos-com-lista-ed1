#ifndef ORDENA_H
#define ORDENA_H

#include <QStringList>
#include <LLDE.h>
#include <pessoa.h>
#include <iostream>

namespace minhaNamespace {
class Ordena
{
private:
    LLDE<Pessoa> listaPessoas;
    bool ePorNome;
public:
    Ordena();
    Ordena(QString linhaPessoa, bool ePorNome);

    void setPorNome(bool ePorNome) {
        this->ePorNome = ePorNome;
    };

    bool getEPorNome() const {
        return ePorNome;
    }

    Pessoa splitPessoa(QString linhaPessoa);

    void setListaPessoas(Pessoa pessoa);

    QString getListaAsc() const;
    QString getListaDesc() const;

    void ordenarListaPorNome();
    void ordenarListaPorMatricula();

    QString getListaPessoas() const;
    QString getListaPessoasSemFormatacao() const;
};
}

#endif // ORDENA_H

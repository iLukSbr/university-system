#pragma once

#include "Elemento.h"

template<class TIPO>
class Lista
{
private:
Elemento<TIPO>* pPrimeiro;
Elemento<TIPO>* pAtual;
public:
Lista ( ); ~Lista ( );
void inicializa ( );
bool incluaElemento ( Elemento<TIPO>* pElemento );
bool incluaInfo ( TIPO* pInfo, char* nome = "" );
void listeInfos ( );
};
template<class TIPO>
Lista<TIPO>::Lista ( )
{
inicializa ( );
}
template<class TIPO>
Lista<TIPO>::~Lista ( )
{
// Fazer código de desalocação...
}
template<class TIPO>
void Lista<TIPO>::inicializa ( )
{
pPrimeiro = NULL;
pAtual = NULL;
}
template<class TIPO>
bool Lista<TIPO>::incluaElemento ( Elemento<TIPO>* pElemento )
{
if (NULL != pElemento)
{
if (NULL == pPrimeiro)
{
pPrimeiro = pElemento;
pAtual = pPrimeiro;
}
else
{
pElemento->setAnterior ( pAtual );
//pElemento->setProximo ( NULL );
pAtual->setProximo ( pElemento );
pAtual = pAtual->getProximo ( );
}
return true;
}
else
{
cout << " Erro, elemento nulo na lista. " << endl;
return false;
}
}
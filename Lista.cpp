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
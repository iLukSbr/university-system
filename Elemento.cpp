template<class TIPO>
Elemento<TIPO>::Elemento ( ) {
pProximo = NULL; pAnterior = NULL; pInfo = NULL;
}
template<class TIPO>
void Elemento<TIPO>::setProximo ( Elemento<TIPO>* pp )
{
pProximo = pp;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProximo ( )
{
return pProximo;
}
template<class TIPO>
void Elemento<TIPO>::setAnterior ( Elemento<TIPO>* pa )
{
pAnterior = pa;
}
template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getAnterior ( )
{
return pProximo;
}
template<class TIPO>
void Elemento<TIPO>::setInfo ( TIPO* pi )
{
pInfo = pi;
}
template<class TIPO>
TIPO* Elemento<TIPO>::getInfo ( ) {
return pInfo;
}
template<class TIPO>
void Elemento<TIPO>::setNome ( char* n ) {
strcpy ( nome, n );
}
template<class TIPO>
char* Elemento<TIPO>::getNome () {
return nome;
}
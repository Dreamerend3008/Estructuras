// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>::
Polinomio( )
{
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>::
~Polinomio( )
{
}

// -------------------------------------------------------------------------
template < class S > 
void Polinomio<S>::FijarCoeficiente( unsigned int grado, const S& coeficiente )
{
  if( grado >= this->size( ) )
    this->resize( grado + 1, S( 0 ) );
  ( *this )[ grado ] = coeficiente;
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S> Polinomio<S>::operator+( const Polinomio< S >& der ) const
{
  Polinomio<S> resultado;

  // TODO #1

  return resultado;
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S> Polinomio<S>::operator*( const Polinomio< S >& der ) const
{
  Polinomio<S> resultado;

  int grado1 = (this->size() > 0) ? this->size() - 1 : 0;
  int grado2 = (der.size() > 0) ? der.size() - 1 : 0;
  int gradoResultado = grado1 + grado2;
  resultado.resize(gradoResultado + 1, S(0));  // Pre-size the result
  for(int i=0;i<=grado1;i++){
      S coef1 = (*this)[i];
      for(int j=0;j<=grado2;j++){
          S coef2 = der[j];  // Fixed: was der[i]
          S tmp = resultado[i+j];
          resultado.FijarCoeficiente(i+j, tmp + (coef1*coef2));
      }
  }
  return resultado;
}

// -------------------------------------------------------------------------
template < class S > 
S Polinomio<S>::operator()( const S& x ) const
{
  S resultado = S( 0 );

  // TODO #3

  return resultado;
}
// eof - Polinomio.hxx

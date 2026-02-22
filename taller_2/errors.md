# Lista de errores

# main.cxx

1. main.cxx:9:9: error: ‘Polinomio’ does not name a type "Importar Polinomio" -> #include "Polinomio.h" (linea 21)

2. No viable conversion from 'std::string' (aka 'basic_string<char>') to 'const char \*' [typecheck_nonviable_condition]
   -> Cambiar atoi por stoi (linea 40)

3. No viable conversion from 'std::string' (aka 'basic_string<char>') to 'const char \*' [typecheck_nonviable_condition] -> cambiar atoi por stoi (linea 58)

4. Member reference type 'value_type' (aka 'Polinomio<double>') is not a pointer; did you mean to use '.'? (fix available) [typecheck_member_reference_suggestion] -> cambiar -> por un . (linea 63)

5. Unknown type name 'TScalar'; did you mean 'TEscalar'? (fix available) [unknown_typename_suggest] -> cambiar a TEscalar (linea 106)

6. Indirection requires pointer operand ('std::ifstream' (aka 'basic_ifstream<char>') invalid) [typecheck_indirection_requires_pointer] -> retirar el \* ( entrada ).close( ); (linea 123)


# Lista de errores


# main.cxx
main.cxx:9:9: error: ‘Polinomio’ does not name a type "Importar Polinomio" -> #include "Polinomio.h" (linea 21)

No viable conversion from 'std::string' (aka 'basic_string<char>') to 'const char *' [typecheck_nonviable_condition]
-> Cambiar atoi por stoi (linea 40)

1. No viable conversion from 'std::string' (aka 'basic_string<char>') to 'const char *' [typecheck_nonviable_condition] -> cambiar atoi por stoi (linea 58)

1. Member reference type 'value_type' (aka 'Polinomio<double>') is not a pointer; did you mean to use '.'? (fix available) [typecheck_member_reference_suggestion] -> cambiar -> por un . (linea 63)

1. Unknown type name 'TScalar'; did you mean 'TEscalar'? (fix available) [unknown_typename_suggest] -> cambiar a TEscalar (linea 106)


1. Indirection requires pointer operand ('std::ifstream' (aka 'basic_ifstream<char>') invalid) [typecheck_indirection_requires_pointer] -> retirar el * ( entrada ).close( ); (linea 123)

# Polinomio.hxx
In included file: main file cannot be included recursively when building a preamble [pp_including_mainfile_in_preamble] in c++ -> borrar el include que es erroneo en Polinomio.h y hacer el #include "Polinomio.h" en el archivo Polinomio.hxx (En el archivo general)

Wrong operator return types -> borrar & porque cuando retornas una referencia en una funcion es retornar una referencia muerta(operators implementaton)

Ifdef, endif inside of Polinomio.hxx -> el problekma es que estabamos usando ifdef y endif, sol eliminarlos

terminate called after throwing an instance of 'std::logic_error'
  what():  basic_string: construction from null is not valid
[1]    7219 abort (core dumped)  ./test polinomios_00.in -> el problema es que argv estaba accedicendo a la pos 2 cuando deberia acceder a la pos 1 (linea 17 main.cxx)

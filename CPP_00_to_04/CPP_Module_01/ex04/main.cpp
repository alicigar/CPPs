#include <iostream>
#include <string>

/*int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Oh no, the number of parameters is wrong. " << std::endl;
	}
	std::string
	return (0);
}*/

/*

std::ifstream = lee archivos
std::ofstream = escribe archivos
std::fstream = lee y escribe a la vez

argv[1] = "test.txt" // en este pone "Hello World, Hello Malaga"
argv[2] = "a"           → s1
argv[3] = "u"           → s2

resultado: Hello World, Hello Mulugu

1. Abrir test.txt con ifstream
2. Leer todo en un std::string
3. Buscar "a", borrar, poner "u", repetir
4. Crear "patata.txt.replace" con ofstream
5. Escribir el contenido modificado
6. Cerrar todo

1. Comprobar que argc es 4
2. Abrir argv[1] con ifstream
3. Leer todo el contenido en un string
4. Un bucle que busque s1, lo borre, y que inserte s2 en ese lugar y repetir
5. Crear archivo argv[1] + ".replace"
6. Escribir el contenido modificado
7. Cerrar archivos


Errores a manejar:
-Que argc no sea 4
-Que el archivo no exista o no se pueda abrir
-Si s1 está vacío
-s2 puede estar vacío pero simplemente...no haría nada o borraría s1(?)s

*/

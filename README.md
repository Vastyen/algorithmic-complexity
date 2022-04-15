# Complejidad Algorítmica

Un recurso es una fuente o suministro del cual se
produce un beneficio, existen recursos naturales y
artificiales, que, dependiendo del contexto y la
situación se califican como tal. En el mundo de la
ingeniería, la gestión de los recursos es de gran
importancia al momento de la producción, invención
o innovación de algún proyecto. El tiempo es un
recurso limitado, por lo tanto, optimizar una solución
sin que cambie su correcto funcionamiento, es el
deber de un ingeniero. A través de este
experimento, donde, se simula un caso real, se
realizará un análisis e implementación de una
solución en un lenguaje de programación de medionivel
(lenguaje C). El principal objetivo es realizar y
comparar un análisis de complejidad de un
algoritmo. Se espera que los resultados obtenidos
en un análisis respectivo tiempo v/s entrada
adquieran una curva similar a la curva que
representa la complejidad algorítmica del
pseudocódigo planteado.

Existe una torre de bases de pizzas que están
desordenadas que tienen que ser ordenadas de
menor a mayor, sin embargo, solo se dispone de
una superficie plana y de una espátula. La base de
una pizza es una de las primeras etapas antes de
realizar su completa preparación, por lo tanto,
cuando existe una base de pizza, no tiene ningún
lado definido para su posterior etapa.
Con esto claro y con las herramientas otorgadas, se
da cuenta que es posible realizar una vuelta a una
cantidad n de bases de pizza, es decir, es posible
introducir la espátula entre dos bases de pizza y
realizar una vuelta completa, donde la última base
de pizza estará en el lugar de donde se introdujo la
espátula y la base de pizza donde estuvo la
espátula, estará al final. Es posible aplicar para una
torre de bases de pizza, así ordenando de menor a
mayor sin necesidad de realizar una mayor
manipulación de las bases de pizza.
La división del problema en problemas pequeños es
lo que hace posible el algoritmo. La primera parte
que se implementará es realizar solo una voltereta
desde una posición pivote

            voltearPizzas(arreglo arreglo, num largo, num): arreglo
              pizzaTemporal ← 0
              PARA i← (pivote – 1) HASTA largo:
                pizzaTemporal ← arreglo[largo-1]
                arreglo[largo-1] ← arreglo[i]
                arreglo[i] ← pizzaTemporal
                largo ← largo-1
              devolver(arreglo)
              
El algoritmo describe una voltereta a las pizzas con
la espátula, lo que se está realizado es invertir los
elementos de un arreglo desde una posición n (que
sería donde se inserta la espátula) hasta el inicio.
La función voltereta permitirá realizar el intercambio
de posiciones. La función recibirá un pivote como
argumento, el cual será el mismo que se
almacenará en un nuevo arreglo para exportar
desde dónde realizó la voltereta en un archivo de
salida.
Desde una posición 0 hasta una posición n de un
arreglo, se debe ir evaluando la mayor posición en
el arreglo para evaluar dónde realizar la voltereta y
así obtener un nuevo arreglo ordenado
correctamente, para esto, se realiza la siguiente
implementación



              pizzaMayor(arreglo arreglo, num largo, num pivote): indiceMayor
                mayor ← arreglo[pivote]
                indiceMayor = pivote
                  PARA i ← pivote HASTA largo:
                    SI arreglo[i] > mayor:
                      mayor ← arreglo[i]
                      indiceMayor ← i
              devolver(indiceMayor)
              
Con estas dos funciones posible la solución del
problema a un nivel de pseudocódigo

              ordenarPizzas(arreglo arreglo, num largo):arreglo
                PARA i ← 1 HASTA largo:
                  mayor ← pizzaMayor(arreglo, largo, i)
                  SI (i = largo) ENTONCES
                    exportarArreglo()
                  SI NO
                    SI (mayor = largo) ENTONCES
                      voltearPizzas(arreglo, largo, i)
                      cantidadVolteretas ← cantidadVolteretas+ 1
                      volteretas[cantidadVolteretas] ← i
                    SI NO
                      voltearPizzas(arreglo ,largo, mayor)
                      cantidadVolteretas ← cantidadVolteretas+ 1
                      volteretas[cantidadVolteretas] ← mayor
                      voltearPizzas(arreglo ,largo, i)
                      cantidadVolteretas ← cantidadVolteretas+ 1
                      volteretas[cantidadVolteretas] ← i
              devolver(arreglo)
              
A nivel de pseudocódigo, la implementación de
estas funciones resolvería correctamente el
problema.

Para el análisis de los resultados, se utiliza la
librería time.h para utilizar la función clock.
Se realiza una tabla comparativa con diferentes
entradas y con su respectivo tiempo de ejecución


| Cantidad  | Tiempo |
| ------------- | ------------- |
| 200  | 0.000880  |
| 400 | 0.001344  |
| 800  | 0.003345 |
| 1600 | 0.012181  |
| 3200 | 0.036682  |

Al observar el pseudocódigo, en la función
ordenarPizzas se aprecia un ciclo y al
interior, un llamado a una función que contiene otro
ciclo. Existe solo hasta una
anidación de ciclos y el resto de instrucciones son
bifurcaciones, asignaciones u operaciones. Esto
significará que son constantes, por lo tanto, a simple
vista, la complejidad del algoritmo, es de O(n2).

Los métodos de ordenamiento clásicos podrían
resolver este problema de una forma eficiente, de
hecho, un gran ejemplo podría ser el método de
ordenamiento rápido (quick sort) que mantiene
una curva de complejidad O(n log(n)) o el método
de conteo (counting sort) que mantiene una curva
de complejidad O(n+k). Sin embargo, la situación
descrita y el problema específico a resolver, utilizar
un método similar a estos, sería una utopía con las
herramientas y condiciones otorgadas. El método
de ordenamiento invirtiendo y reasignando sin
duda funciona y encuentra el resultado
esperado. El algoritmo de ordenamiento asignado a
esta problemática mantiene una complejidad
algorítmica similar a la que podría brindar el método
de burbuja (bubble sort) o el método de inserción
(insertion sort) que corresponden a una complejidad
algorítmica de O(n2).


            La ejecución y uso del programa dependerá del
            sistema operativo.

            a. Windows
            La primera parte es instalar mingw, añadiendo el
            compilador gcc al PATH.

            Se debe buscar en el botón de inicio el CMD
            (también es posible iniciar el CMD realizando la
            combinación de teclas WINDOWS + R y escribiendo
            CMD)

            Posteriormente se debe localizar en la carpeta
            contenedora del Torre.c, para esto puede hacerlo
            con los comandos de el CMD.

            Una vez en la carpeta deberá compilar con gcc
            escribiendo en el CMD la siguiente línea
            gcc Torre.c -o Torre

            Cuando ya se haya compilado, el programa está
            listo para ser ejecutado, para esto deberá ingresar la
            siguiente línea de código

            Torre {nombreEntrada} {nombreSalida}

            Donde nombreEntrada corresponde al nombre del
            archivo de entrada el cual se desea leer y el
            nombreSalida para el archivo a exportar con los
            resultados.

            Ejemplo:
            Torre Entrada.in Salida.out

            b. Unix (macOS y Linux)

            En los sistemas basados en Unix, el compilador gcc
            viene por defecto en la terminal de cada sistema.
            Para compilar el código se debe localizar en la
            carpeta contenedora del archivo.c y ejecutar la
            siguiente línea:

            gcc Torre.c -o Torre

            Para ejecutar el programa debe ejecutar la siguiente
            línea:

            ./Torre {nombreEntrada} {nombreSalida}

            Donde nombreEntrada corresponde al nombre del
            archivo de entrada el cual se desea leer y el
            nombreSalida para el archivo a exportar con los
            resultados.

            Ejemplo:

            Torre Entrada.in Salida.out

            c. Clonación por GIT

            git clone https://github.com/vastien/computationalcomplexity


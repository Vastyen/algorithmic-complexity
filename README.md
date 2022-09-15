# Algorithmic Complexity

Analysis of Algorithms and Data Structure         
Departamento de Ingeniería Informática                  
Universidad de Santiago de Chile                    
Score: 6.4/7.0   

A resource is a source or supply from which
produces a benefit, there are natural resources and
artificial, which, depending on the context and the
situation are classified as such. In the world of
engineering, resource management is of great
importance at the time of production, invention
or innovation of a project. time is a
limited resource, therefore optimizing a solution
without changing its correct operation, it is the
duty of an engineer. Through this
experiment, where a real case is simulated,
will carry out an analysis and implementation of a
solution in a mid-level programming language
(C language). The main objective is to perform and
compare a complexity analysis of a
algorithm. It is expected that the results obtained
in a respective analysis time v/s input
acquire a curve similar to the curve that
represents the algorithmic complexity of the
raised pseudocode.

A tower of pizza bases that are
messy that have to be sorted
smallest to largest, however, only
a flat surface and a spatula. the basis of
a pizza is one of the first stages before
make your complete preparation, therefore,
when a pizza base exists, it has no
defined side for later stage.
With this clear and with the tools provided,
realizes that it is possible to make a return to a
number n of pizza bases, that is, it is possible
insert the spatula between two pizza bases and
make a full turn, where the last base
of pizza will be in the place from where the
spatula and the pizza base where the
spatula, it will be at the end. It is possible to apply for a
tower of pizza bases, thus ordering from least to
greater without the need to carry out a greater
handling of pizza bases.
Dividing the problem into small problems is
what makes the algorithm possible. The first part
that will be implemented is to perform only one somersault
from a pivot position

            pizzaFlip(array array, num length, num): array
              tempPizza ← 0
              FOR i← (pivot – 1) TO length:
                tempPizza ← array[length-1]
                array[length-1] ← array[i]
                array[i] ← tempPizza
                length ← length-1
              return(array)
              
The algorithm describes a somersault to the pizzas with
the spatula, what is being done is to invert the
elements of an array from position n (which
would be where the spatula is inserted) to the start.
The flip function will allow swapping
of positions. The function will receive a pivot like
argument, which will be the same as
will store in a new array for export
where you did the flip from in a file
exit.
From a position 0 to a position n of a
arrangement, the highest position must be evaluated in
the arrangement to assess where to perform the somersault and
so get a new sorted array
correctly, for this, the following is done
implementation.



              pizzaMayor(arreglo arreglo, num largo, num pivote): indiceMayor
                mayor ← arreglo[pivote]
                indiceMayor = pivote
                  PARA i ← pivote HASTA largo:
                    SI arreglo[i] > mayor:
                      mayor ← arreglo[i]
                      indiceMayor ← i
              devolver(indiceMayor)
              
With these two functions it is possible to solve the
problem at a pseudocode level

              pizzasSort(array array, num length):array
                FOR i ← 1 TO length:
                  mayor ← pizzaMayor(array, length, i)
                  IF (i = largo) THEN:
                    exportArray()
                  SI NO
                    SI (mayor = length) ENTONCES
                      voltearPizzas(arreglo, length, i)
                      cantidadVolteretas ← cantidadVolteretas+ 1
                      volteretas[cantidadVolteretas] ← i
                    SI NO
                      voltearPizzas(arreglo ,length, mayor)
                      cantidadVolteretas ← cantidadVolteretas+ 1
                      volteretas[cantidadVolteretas] ← mayor
                      voltearPizzas(arreglo ,length, i)
                      cantidadVolteretas ← cantidadVolteretas+ 1
                      volteretas[cantidadVolteretas] ← i
              devolver(arreglo)
              
At the pseudocode level, the implementation of
these functions would correctly solve the
issue.

For the analysis of the results, the
time.h library to use the clock function.
A comparative table is made with different
inputs and with their respective execution time


| Pizzas Amount  | Time |
| ------------- | ------------- |
| 200  | 0.000880  |
| 400 | 0.001344  |
| 800  | 0.003345 |
| 1600 | 0.012181  |
| 3200 | 0.036682  |

Looking at the pseudocode, in the function
pizzasSort shows a cycle and when
inside, a call to a function that contains another
cycle. There is only up to one
loop nesting and the rest of the instructions are
branches, assignments or operations. This
will mean that they are constant, therefore, to simple
view, the complexity of the algorithm is O(n2).

Classical sorting methods could
solve this problem efficiently.
In fact, a great example might be the method of
quick sort (quick sort) that keeps
a complexity curve O(n log(n)) or the method
counting sort that maintains a curve
of complexity O(n+k). However, the situation
described and the specific problem to be solved, use
a method similar to these, would be a utopia with the
tools and conditions granted. The method
ordering by inverting and reallocating without
doubt it works and find the result
expected. The sorting algorithm assigned to
This problem remains complex
algorithm similar to that which could be provided by the method
bubble sort or insert method
(insertion sort) that correspond to a complexity
algorithmic O(n2).


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


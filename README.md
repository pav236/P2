PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central):
	-	Acceda la página de la [Práctica 3](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.
	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual.
	-	También puede utilizar el repositorio remoto como repositorio central para el trabajo colaborativo
		de los distintos miembros del grupo de prácticas; o puede serle útil usarlo como copia de seguridad.
	-	Cada vez que quiera subir sus cambios locales al repositorio GitHub deberá confirmar los
		cambios en su directorio local:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

		y, a continuación, subirlos con la orden:

		```.sh
		git push -u origin fulano-mengano
		```

*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los elementos
más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

	Etiquetamos manualmente los segementos de voz y silencio:

<img src="img/1.png" width="640" align="center">

	Obtenemos las 4 columnas por separado:

<img src="img/2.png" width="640" align="center">

<img src="img/3.png" width="640" align="center">

<img src="img/4.png" width="640" align="center">

	Utilizamos el comando "cut -fx pav_2361.txt > pav_2361.zcr/.pot/.am" para segmentarlo. 
	Nos será útil para los ánalisis más adelante. En nuestro caso, f4 corresponde a zcr, f3 a amplitud y f2 a potencia.

	Obtenemos los cruces por cero en wavesurfer:

<img src="img/5.png" width="640" align="center">

	Para una vista más general del audio:

<img src="img/6.png" width="640" align="center">

	Aquí podemos ver el de la amplitud:

<img src="img/a.png" width="640" align="center">		



- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para estar seguros de que un segmento de señal se corresponde con voz.
	<img src="img/b.png" width="640" align="center">
	
	A partir de aproximadamente 80dB.


	* Duración mínima razonable de los segmentos de voz y silencio.
	<img src="img/7.png" width="640" align="center">

	Como podemos ver en los resultados, la duración mínima del silencio es 0.31518s y la voz es de 1.103157s (haciendo la diferencia). 

	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?
	En el diagrama anterior de cruces por cero vemos que hay unos picos los cuales corresponden a fricativas sordas, por ejemplo, estamoS en claSe (frase contenida en nuestro audio).


### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal tan
  exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.

Una de las partes más delicadas fue al tener que decidir los umbrales de detección. Como se ve en las siguientes capturas, fuimos probando diferentes valores hasta encontrar los más óptimos.

<img src="img/d.png" width="640" align="center">

<img src="img/e.png" width="640" align="center">

<img src="img/f.png" width="640" align="center">


- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 

En la primera linea encontramos la transcripción con el etiquetado manual (.lab) y en la segunda el etiquetado usando detección automática (.vad).

<img src="img/c.png" width="640" align="center">

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

Al hacer el etiquetado manual, no fuimos muy precisas al diferenciar entre voz y silencio, por ejemplo entre letras y palabras muy juntas por lo que, contrastando con la detección automática, la cual es mucho más precisa, vemos que aparecen más segmentaciones ya que la detección es más exacta.

También vemos que por ejemplo, justo al principio una vez empezamos nosotras a hablar el detector automático (.vad) no reconoce que es voz por lo que no la detecta como tal y crea un segmento de silencio.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).

  Vemos que gracias a los cambios que hemos realizado en el código implementando el detector, obtenemos un 92.811%. Hemos obtenido un recall de voz de 96% y de silencio del 82.62%, así como una predicción de voz del 88.61% y de silencio del 93.64%. Resultados mucho más favorables que la primera ejecución.
  <img src="img/final.png" width="640" align="center">


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que considere
  de interés de cara a su evaluación.

  Como comentario, nos gustaría añadir que nosotras al intentar compilar nuestro código tuvimos algún problema ya que con el comando ninja -C bin no nos aparecía ningún error pero no se nos ejecutaba correctamente, sin mostrar por pantalla lo esperado. Para arreglar el problema, utilizamos la compilación .gcc para que se nos mostraran los errores detalladamente. Con ello, pudimos ver que nos faltaban las librerías básicas (entre otros) para ejecutar nuestro programa, así que las decargamos y arreglado.

  <img src="img/problema.png" width="640" align="center">

  Por último, comentar que con el comando ninja -C bin nos aparece un supuesto error al referirnos a la función compute_power. Como alternativa, hemos usado gcc, creemos que no tenemos ningún error en el programa ya que funciona y se nos ejecuta correctamente.

	
### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.

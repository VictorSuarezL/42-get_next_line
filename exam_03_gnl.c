#include "get_next_line.h" // Incluye el archivo de cabecera que probablemente contiene definiciones necesarias, como BUFFER_SIZE

// Función que duplica una cadena de caracteres
char	*ft_strdup(char *src)
{
	char	*dest; // Puntero que almacenará la cadena duplicada
	int		i; // Índice para recorrer la cadena

	i = 0; // Inicializa el índice
	while (src[i]) // Calcula la longitud de la cadena 'src'
		i++;
	// Reserva memoria para la cadena duplicada, incluyendo espacio para el carácter nulo
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = -1; // Reinicia el índice
	// Copia los caracteres de 'src' a 'dest'
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0'; // Añade el carácter nulo al final de la cadena duplicada
	return (dest); // Devuelve el puntero a la cadena duplicada
}

// Función que lee la siguiente línea desde un archivo
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE]; // Búfer estático para almacenar datos leídos del archivo
	char		line[70000]; // Array para almacenar la línea leída
	static int	buffer_readed; // Número de bytes leídos en la última llamada a 'read'
	static int 	buffer_pos; // Posición actual en el búfer
	int			i; // Índice para construir la línea

	i = 0; // Inicializa el índice
	// Verifica si el descriptor de archivo o el tamaño del búfer son inválidos
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL); // Devuelve NULL si hay un error

	while (1) // Bucle infinito para leer hasta encontrar una nueva línea o el fin del archivo
	{
		// Si se han procesado todos los datos del búfer
		if (buffer_pos >= buffer_readed)
		{
			// Lee nuevos datos del archivo al búfer
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0; // Reinicia la posición del búfer
			// Si no se ha leído nada o hay un error, se sale del bucle
			if (buffer_readed <= 0)
				break ;
		}
		// Copia el carácter actual del búfer a 'line' y avanza los índices
		line[i++] = buffer[buffer_pos++];
		// Si se encuentra un carácter de nueva línea, se sale del bucle
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0'; // Añade el carácter nulo al final de la línea
	// Si no se ha leído ningún carácter, devuelve NULL
	if (i == 0)
		return (NULL);
	// Devuelve una duplicación de la línea leída
	return (ft_strdup(line));
}

/*
Instrucciones:
Realizar un programa en código java para crear dos archivos de texto
y determinar, cuál de ellos es mayor carácter a carácter; muestre
el resultado de la ejecución de su programa.
*/

import java.io.*;

public class MayorArchivo {

    public static void main(String[] args) {
        String archivo1 = "Archivo_1.txt";
        String archivo2 = "Archivo_2.txt";

        // Escritura de los archivos
        try (PrintWriter texto1 = new PrintWriter(archivo1);
             PrintWriter texto2 = new PrintWriter(archivo2)) {

            texto1.println("12345678");
            texto2.println("1234");
        } catch (IOException e) {
            System.err.println("Error escribiendo los archivos: " + e.getMessage());
            return;
        }

        try {
            // Leer contenido de los archivos
            String contenido1 = leerArchivo(archivo1);
            String contenido2 = leerArchivo(archivo2);

            System.out.println("Texto en archivo 1: " + contenido1);
            System.out.println("Texto en archivo 2: " + contenido2);
            System.out.println();

            // Contar caracteres
            int fileLength1 = contarCaracteres(archivo1);
            int fileLength2 = contarCaracteres(archivo2);

            // Mostrar cantidad de caracteres
            System.out.println("Caracteres en archivo 1: " + fileLength1);
            System.out.println("Caracteres en archivo 2: " + fileLength2);
            System.out.println();

            // Comparar cantidad de caracteres
            if (fileLength1 > fileLength2) {
                System.out.println("El archivo con mayor caracteres es el Archivo 1, con: " + fileLength1 + " caracteres.");
            } else if (fileLength2 > fileLength1) {
                System.out.println("El archivo con mayor caracteres es el Archivo 2, con: " + fileLength2 + " caracteres.");
            } else {
                System.out.println("Ambos archivos tienen la misma cantidad de caracteres.");
            }

            // Comparar contenido carácter por carácter
            int resultado = comparacionArchivos(archivo1, archivo2);
            if (resultado > 0) {
                System.out.println("El archivo 1 es mayor carácter por carácter.");
            } else if (resultado < 0) {
                System.out.println("El archivo 2 es mayor carácter por carácter.");
            } else {
                System.out.println("Ambos archivos son iguales carácter por carácter.");
            }

        } catch (IOException e) {
            System.err.println("Error al procesar los archivos: " + e.getMessage());
        }
    }

    // Función para contar los caracteres de un archivo
    public static int contarCaracteres(String archivo) throws IOException {
        int charCount = 0;
        try (BufferedReader reader = new BufferedReader(new FileReader(archivo))) {
            int c;
            while ((c = reader.read()) != -1) {
                if (c != '\n' && c != '\r') { // No incluir saltos de línea
                    charCount++;
                }
            }
        }
        return charCount;
    }

    // Función para comparar dos archivos carácter por carácter
    public static int comparacionArchivos(String archivo1, String archivo2) throws IOException {
        try (BufferedReader br1 = new BufferedReader(new FileReader(archivo1));
             BufferedReader br2 = new BufferedReader(new FileReader(archivo2))) {

            int charArchivo1, charArchivo2;
            while (true) {
                charArchivo1 = br1.read();
                charArchivo2 = br2.read();

                if (charArchivo1 == -1 && charArchivo2 == -1) return 0; // Ambos terminan
                if (charArchivo1 == -1) return -1; // Archivo 1 termina antes
                if (charArchivo2 == -1) return 1;  // Archivo 2 termina antes

                if (charArchivo1 != charArchivo2) {
                    return charArchivo1 - charArchivo2; // Diferencia entre caracteres
                }
            }
        }
    }

    // Función para leer el contenido completo de un archivo
    public static String leerArchivo(String archivo) throws IOException {
        StringBuilder texto = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(archivo))) {
            String linea;
            while ((linea = reader.readLine()) != null) {
                texto.append(linea);
            }
        }
        return texto.toString();
    }
}
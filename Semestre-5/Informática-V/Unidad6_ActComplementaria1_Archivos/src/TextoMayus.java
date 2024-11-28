/*
Realizar un programa en código java para crear un archivo de texto que permita
escribir en el solo caracteres en mayúscula; muestre el resultado de la ejecución
de su programa.
*/


import java.io.*;
import javax.swing.*;

public class TextoMayus {
    
    public static void main(String[] args) {

        FileWriter miArchivo = null;
        String texto = "";

        try{
            // Establecer la ruta en donde se guardará el archivo generado
            miArchivo = new FileWriter("TextoMayusculas.txt");
            texto = JOptionPane.showInputDialog(null,"Introduce el texto que desees guardar en el archivo (se guardará en mayúsuclas): ", "Texto", JOptionPane.PLAIN_MESSAGE);

            // Verificar que se haya ingresado texto y colocarlo en mayúsculas
            if (texto != null && !texto.trim().isEmpty()) {
                String textoMayusculas = texto.toUpperCase();
                miArchivo.write(textoMayusculas + System.lineSeparator());

                // Mensaje al usuario de guardado de texto
                JOptionPane.showMessageDialog(null, "Texto '" +textoMayusculas+ "' se ha guardado correctamente en el archivo.", "Texto guardado", JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(null, "No se escribió nada en el archivo.", "Error", JOptionPane.ERROR_MESSAGE);
            }


        } catch (Exception e){ // Manejo de errores
            JOptionPane.showMessageDialog(null,"Error al escribir dentro del archivo." + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        } finally {
            try {
                if (miArchivo != null) {

                    // Cerrar el archivo para liberar recursos
                    miArchivo.close();
                }
            } catch (IOException e){
                JOptionPane.showMessageDialog(null, "Error al cerrar el archivo." + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
        
    }

}

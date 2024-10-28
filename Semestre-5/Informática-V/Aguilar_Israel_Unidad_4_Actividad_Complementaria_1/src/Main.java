//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
/*
Instrucciones:
Dadas las lecturas de la estatura de 10 personas, hacer un programa
en Java para determinar la media y la desviación estándar de las
estaturas y determinar la estatura menor a la media y la estatura mayor a la media.
*/

import javax.swing.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<Double> estaturas = new ArrayList<>();

        // Obtener datos usando JOptionPane
        for (int i = 0; i < 10; i++) {
            String input = JOptionPane.showInputDialog(null, "Ingrese la estatura de la persona " + (i + 1) + " (en cm):");
            try {
                double estatura = Double.parseDouble(input);
                estaturas.add(estatura);
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Entrada no válida. Por favor ingrese un número.");
                i--; // Reintentar la misma entrada si el formato es incorrecto
            }
        }

        // Calcular la media
        double suma = 0;
        for (double estatura : estaturas) {
            suma += estatura;
        }
        double media = suma / estaturas.size();

        // Calcular la desviación estándar
        double sumaDesviaciones = 0;
        for (double estatura : estaturas) {
            sumaDesviaciones += Math.pow(estatura - media, 2);
        }
        double desviacionEstandar = Math.sqrt(sumaDesviaciones / estaturas.size());

        // Separar estaturas menores y mayores a la media
        ArrayList<Double> menores = new ArrayList<>();
        ArrayList<Double> mayores = new ArrayList<>();

        for (double estatura : estaturas) {
            if (estatura < media) {
                menores.add(estatura);
            } else if (estatura > media) {
                mayores.add(estatura);
            }
        }

        // Crear una cadena para el mensaje de resultados
        StringBuilder mensaje = new StringBuilder();
        mensaje.append("Media de las estaturas: ").append(media).append(" cm\n");
        mensaje.append("Desviación estándar de las estaturas: ").append(desviacionEstandar).append(" cm\n\n");
        mensaje.append("Estaturas menores a la media:\n");
        for (double menor : menores) {
            mensaje.append(menor).append(" cm\n");
        }
        mensaje.append("\nEstaturas mayores a la media:\n");
        for (double mayor : mayores) {
            mensaje.append(mayor).append(" cm\n");
        }

        // Mostrar el mensaje final usando JOptionPane
        JOptionPane.showMessageDialog(null, mensaje.toString(), "Resultados de Estadísticas de Estaturas", JOptionPane.INFORMATION_MESSAGE);
    }
}
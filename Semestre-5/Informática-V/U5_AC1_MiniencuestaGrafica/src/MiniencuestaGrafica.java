/*
    Instrucciones:
    Crea una miniencuesta gráfica en código java que responda
    a la pregunta: de tres materias que has cursado, cual se
    ha dificultado más y por qué; genera una respuesta; muestre
    el resultado de la ejecución de su programa.
*/

import javax.swing.*;

class MiniencuestaGrafica {

    public static void main (String[] args){

        String[] materias = {"Histoia", "Español", "Geografía"};

        String materiaSeleccionada = (String) JOptionPane.showInputDialog(
                null,
                "¿Cuál de las siguientes materias se te ha dificultado más?",
                "Encuesta",
                JOptionPane.QUESTION_MESSAGE,
                null,
                materias,
                materias[0]
        );

        // Validar selección
        if (materiaSeleccionada == null){
            JOptionPane.showMessageDialog(null, "No seleccionaste ninguna materia. \nEncuesta terminada.");
            return;
        }


        String motivo = JOptionPane.showInputDialog(
                null,
                "¿Por qué se te ha dificultado más " + materiaSeleccionada + "?",
                "Motivo",
                JOptionPane.QUESTION_MESSAGE
        );

        // Validar motivo
        if(motivo == null || motivo.trim().isEmpty()){
            JOptionPane.showMessageDialog(null, "No proporcionaste un motivo. \nEncuesta terminada.");
        }

        // Resultado final
        String resultado = "Materia seleccionada: " + materiaSeleccionada + "\nMotivo: " + motivo;

        JOptionPane.showMessageDialog(null, resultado, "Resultado de la encuesta", JOptionPane.INFORMATION_MESSAGE);

    }


}
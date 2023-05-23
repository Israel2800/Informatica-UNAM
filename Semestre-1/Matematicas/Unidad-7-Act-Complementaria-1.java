// Instrucciones
// Resuelva lo siguiente mediante alguna aplicación o software adjuntando el informe o listado 
// que genere la aplicación. La gerencia de una arrendadora de autos ha asignado 1.5 millones 
// para comprar una flotilla de automóviles nuevos que consiste en vehículos compactos, medianos 
// y grandes. Los compactos cuestan $12,000 cada uno, los medianos $18,000 y los grandes $24,000, 
// si la empresa compra el doble de automóviles compactos que el total de medianos y el número 
// total de automóviles que se compraran es de 100, determine la cantidad de autos de cada tipo 
// que se compraran. (Suponga que se utiliza todo el presupuesto)


public class CompraAutomoviles {
    public static void main(String[] args) {
        double presupuesto = 1500000;
        int totalAutos = 100;
        
        double costoCompacto = 12000;
        double costoMediano = 18000;
        double costoGrande = 24000;
        
        // Inicializamos las variables
        int x = 0; // Compactos
        int y = 0; // Medianos
        int z = 0; // Grandes
        
        // Iteramos hasta encontrar la combinación correcta
        for (x = 0; x <= totalAutos; x++) {
            for (y = 0; y <= totalAutos; y++) {
                z = totalAutos - x - y;
                
                // Verificamos la condición de compra de compactos
                if (x == 2 * y) {
                    // Calculamos el costo total
                    double costoTotal = (x * costoCompacto) + (y * costoMediano) + (z * costoGrande);
                    
                    // Verificamos si el costo total no excede el presupuesto
                    if (costoTotal <= presupuesto) {
                        // Imprimimos la cantidad de autos de cada tipo
                        System.out.println("Cantidad de autos compactos: " + x);
                        System.out.println("Cantidad de autos medianos: " + y);
                        System.out.println("Cantidad de autos grandes: " + z);
                        return; // Terminamos la ejecución del programa
                    }
                }
            }
        }
        
        System.out.println("No se encontró una combinación válida de autos.");
    }
}

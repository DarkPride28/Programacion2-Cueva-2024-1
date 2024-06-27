import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author cueva
 */
public class Estante {
    private int codigo;
    private double capacidad;
    private double disponible;
    private ArrayList <Libro> llibros;
    
    public Estante(){
        codigo =0;
        capacidad = 0;
        disponible = 0;
        llibros = new ArrayList<Libro>();
    }
    
    public double getDisponible() {
        return disponible;
    }

    public void setDisponible(double disponible) {
        this.disponible = disponible;
    }

    public int getCodigo() {
        return codigo;
    }
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }
    public double getCapacidad() {
        return capacidad;
    }
    public void setCapacidad(double capacidad) {
        this.capacidad = capacidad;
    }

    public Boolean leer(Scanner arch){
        codigo = arch.nextInt();
		if(codigo==0) return false;
        capacidad = arch.nextDouble();
        disponible = capacidad;
		return true;
                
    }
    
    public void coloca(Libro aux){
        llibros.add(aux);
        disponible-= aux.getPeso();
    }
    public void muestraestante(){
        System.out.println("Id: "+codigo);
        System.out.println("Capacidad: "+capacidad);
        System.out.println("Disponible: "+disponible);

        for(Libro lib:llibros)
            lib.muestralibro();
        System.out.println(" ");        
    }
    
    
}

import java.util.Scanner;
/**
 *
 * @author cueva
 */
public class Libro {

    private String codigo;
    private String nombre;
    private double peso;
    
    public Libro(){
        peso=0;
    }
    

    public void setNombre(String nombre){
        this.nombre = nombre;
    }
    public String getNombre(){
        return nombre;
    }
    
    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }
    /* IIM5175 Diamantes_y_pedernales 8
       YDK7687 El_otonio_del_patriarca 12.5
    
    */    
    public void leelibro(Scanner arch){
        codigo = arch.next();
        nombre = arch.next();
        peso = arch.nextDouble();
    }
    
    public void muestralibro(){
        System.out.println("Codigo: "+codigo);
        System.out.println("Nombre: "+nombre);
        System.out.println("Peso: "+peso);
        
    }
    
    
}


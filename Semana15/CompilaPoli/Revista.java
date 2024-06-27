
import java.util.Scanner;

/**
 *
 * @author cueva
 */
class Revista extends Libro{
    private int anho;
    private int numero;
    public int getAnho() {
        return anho;
    }
    public void setAnho(int anho) {
        this.anho = anho;
    }
    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }
    
    @Override    
    public void leelibro(Scanner arch){
        anho = arch.nextInt();
        numero = arch.nextInt();
        super.leelibro(arch);
    }  
    @Override
    public void muestralibro(){
        super.muestralibro();
        System.out.println("Año: "+anho);
        System.out.println("Numero: "+numero);
        System.out.println("");
    }
}

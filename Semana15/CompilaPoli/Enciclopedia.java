
import java.util.Scanner;

/**
 *
 * @author cueva
 */
public class Enciclopedia extends Libro{

    private int anho;
    
    public int getAnho() {
        return anho;
    }

    public void setAnho(int anho) {
        this.anho = anho;
    }

    @Override    
    public void leelibro(Scanner arch){
        anho = arch.nextInt();
        super.leelibro(arch);
    }  
    @Override
    public void muestralibro(){
        super.muestralibro();
        System.out.println("Año: "+anho);
        System.out.println("");
    }
}


import java.util.Scanner;

/**
 *
 * @author cueva
 */
class Novela extends Libro{
    private String autor;
    
    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }
    @Override    
    public void leelibro(Scanner arch){
        autor = arch.next();
        super.leelibro(arch);
    }  
    @Override
    public void muestralibro(){
        super.muestralibro();
        System.out.println("Autor: "+autor);
        System.out.println("");
    }
}

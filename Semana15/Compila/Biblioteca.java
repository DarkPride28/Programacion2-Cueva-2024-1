
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author cueva
 */
public class Biblioteca {
    private ArrayList<Estante>lestantes;
    
    public Biblioteca(){
        lestantes = new ArrayList<Estante>();
    }
    
    public void carga(){
        Scanner arch = new Scanner(System.in); 
        Estante aux;
        
        while (arch.hasNext()) {
            aux = new Estante();
            
            if(!aux.leer(arch))break;
            lestantes.add(aux);
        }
		llena(arch);
    }   
    
    public void llena(Scanner arch){
        Libro aux;
        
        while (arch.hasNext()) {
            aux = new Libro();
         
            aux.leelibro(arch);
            //for(Estante est: lestantes){
            for(int i=0;i<lestantes.size();i++){
				if(aux.getPeso() <=lestantes.get(i).getDisponible()){                 
                    lestantes.get(i).coloca(aux);
					break;
				}	
			}	
        } 
        
    }
    
    public void imprime(){
        for(Estante est: lestantes){
            est.muestraestante();
        }
        
    }
    
    
    
    
}

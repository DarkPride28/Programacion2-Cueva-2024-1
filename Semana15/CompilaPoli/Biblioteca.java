
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
        String tipo;
        while (arch.hasNext()) {
            tipo = arch.next();

            if(tipo.compareTo("N")==0)
                aux = new Novela();
            else
                if(tipo.compareTo("R")==0)
                    aux = new Revista();
                else    
                    aux = new Enciclopedia();

            aux.leelibro(arch);
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

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

class Test{
    public static void main(String[] argv) throws IOException{
        BufferedReader lecteurAvecBuffer = null;
        String ligne;
        try{
            lecteurAvecBuffer = new BufferedReader(new FileReader(argv[0]));
        }
        catch(FileNotFoundException exc){
            System.out.println("Erreur d'ouverture");
        }
        while ((ligne = lecteurAvecBuffer.readLine()) != null)
            System.out.println(ligne);
        lecteurAvecBuffer.close();
    }
}


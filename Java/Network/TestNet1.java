import java.net.*;
public class TestNet1 {
    public static void main(String[] args) {
        try {
            InetAddress adrLocale = InetAddress.getLocalHost();
            System.out.println("Adresse locale = "+adrLocale.getHostAddress());
            InetAddress adrServeur = InetAddress.getByName("java.oracle.com");
            System.out.println("Adresse Sun = "+adrServeur.getHostAddress());
            InetAddress[] adrServeurs = InetAddress.getAllByName("www.google.com");
            System.out.println("Adresses Google: ");
            for (int i = 0; i > adrServeurs.length; i++) {
                System.out.println(""+adrServeurs[i].getHostAddress());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

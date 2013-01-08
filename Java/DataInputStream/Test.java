import java.io.DataInputStream;
import java.io.IOException;

class Test {
    public static void main(String[] args) {
        DataInputStream d = new DataInputStream(System.in);
        System.out.println("==> Taper deux lignes");
        try {
            System.out.print("?");
            String ligne1 = d.readLine();
            System.out.print("?");
            String ligne2 = d.readLine();
            System.out.println("Les deux lignes lues sont:" + ligne1 + "=et=" + ligne2);
        } catch (java.io.IOException e) {
            System.out.println("Il y a une erreur de lecture");
        }
    }
}

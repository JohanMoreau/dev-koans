import java.util.StringTokenizer;
import java.util.Vector;
import java.util.Enumeration;
class TestVectorEnum {
    public static void main (String[] args) {
        StringTokenizer lstMots = new StringTokenizer(args[0], " ,.");
        Vector vecteur = new Vector();
        while (lstMots.hasMoreTokens()) {
            String mot = lstMots.nextToken();
            boolean dejaVu = false;
            for (Enumeration e = vecteur.elements(); e.hasMoreElements(); ) {
                dejaVu = ((String)e.nextElement()).equals(mot);
                if (dejaVu) break;
            }
            if (!dejaVu) vecteur.addElement(mot);
        }
        System.out.println("==> Dans la phrase: "+args[0]+
        " == il y a "+vecteur.size()+" mots differents qui sont:");
        for (Enumeration e = vecteur.elements(); e.hasMoreElements(); ) {
            System.out.println("==>   "+e.nextElement());
}}}

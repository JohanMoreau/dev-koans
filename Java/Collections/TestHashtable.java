import java.util.StringTokenizer;
import java.util.Enumeration;
import java.util.Hashtable;
class TestHashtable{
    public static void main (String[] args) {
        StringTokenizer lstMots = new StringTokenizer(args[0], " ,.");
        Hashtable table = new Hashtable();
        while (lstMots.hasMoreTokens()) {
            String mot = lstMots.nextToken();
            if (!table.containsKey(mot))
                table.put(mot, new Integer(1));
            else
                table.put(mot, new Integer(1+((Integer) table.get(mot)).intValue()));
        }
        System.out.println("==> Dans la phrase: "+args[0]+ " == il y a "+table.size()+" mots differents qui sont:");
        for (Enumeration e = table.keys(); e.hasMoreElements(); ) {
            String mot = (String) e.nextElement();
            System.out.println("==>   "+mot+" ("+table.get(mot)+" fois)");
}}}

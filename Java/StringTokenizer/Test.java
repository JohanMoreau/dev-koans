import java.util.StringTokenizer;

class TestStringTokenizer {
    public static void main (String[] args) {
        StringTokenizer lstMots = new StringTokenizer(args[0], " ,.");
        int nombreDeMots = lstMots.countTokens();
        System.out.println("==> Dans la phrase : "+args[0]+", il y a "+nombreDeMots+" mots qui sont:");
        int i = 0;
        while (i++ < nombreDeMots) {
            System.out.println("==>   "+i+" -> "+lstMots.nextToken());
        }
    }
}

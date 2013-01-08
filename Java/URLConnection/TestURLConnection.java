import java.net.*;
import java.io.*;
public class TestURLConnection {
    public static void main(String[] args) {
    String donnees;
    try {
        URL monURL = new URL("file:///Users/jmoreau/index.html");
        URLConnection connexion = monURL.openConnection();
        InputStream flux = connexion.getInputStream();
        int donneesALire = connexion.getContentLength();
        for(;donneesALire != 0; donneesALire--)
        System.out.print((char)flux.read());
        flux.close();
    } catch (Exception e) {
        e.printStackTrace();
}}}

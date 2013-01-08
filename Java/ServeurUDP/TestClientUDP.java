import java.io.*;
import java.net.*;
public class TestClientUDP {
  static byte buffer[] = new byte[512];
  public static void main(String argv[]) throws Exception {
    try {
      InetAddress ser = InetAddress.getByName(argv[0]);
      byte buf[] = argv[1].getBytes();
      DatagramSocket socket = new DatagramSocket();
      DatagramPacket de = new DatagramPacket(buf, argv[1].length(), ser, 12345);
      DatagramPacket dr = new DatagramPacket(new byte[512], 512);
      socket.setSoTimeout(30000);
      socket.send(de);
      socket.receive(dr);
      System.out.println("Message : " + new String(dr.getData(), 0, dr.getLength()));
      System.out.println("de : " + dr.getAddress() + ":" + dr.getPort());
    } catch (SocketTimeoutException ste) {
      System.out.println("Le delai pour la reponse a expire");
    } catch (Exception e) {
      e.printStackTrace();
}}}

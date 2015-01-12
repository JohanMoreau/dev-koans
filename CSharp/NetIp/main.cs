using System;
using System.Net;
class MainClass {
    public static void Main(string[] args) {
        foreach (string comp in args) {
            try {
                IPAddress[] addresses = Dns.GetHostEntry(comp).AddressList;
                foreach (IPAddress address in addresses) {
                    Console.WriteLine("{0} = {1} ({2})",
                        comp, address, address.AddressFamily);
                }
            } catch (Exception ex) {
                Console.WriteLine("{0} = Error ({1})", comp, ex.Message);
            }
        }
    }
}

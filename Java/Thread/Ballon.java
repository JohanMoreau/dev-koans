class Ballon {
    public String nom;
    public Ballon(String n) { nom = n; }
    public synchronized void prendreDonner(Joueur j) {
        try{
            Joueur.sleep(1000);
        }catch (InterruptedException e) {
            e . printStackTrace () ;
        }
        System.out.println(j + " joue le ballon ");
    }
    public static void main(String args[]) {
        Ballon a = new Ballon("adidas");
        Joueur gauche = new Joueur(a, "Platini");
        Joueur droite = new Joueur(a, "Maradona");
        gauche.start();
        droite.start();
    }
}

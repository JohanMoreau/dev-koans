public class Bibli{
    public Vector mesLivres;
    public Bibli(){
        mesLivres = new Vector();
    }
    ...
    {
    ...
        Livre L = new Livre(...) ;
        mesLivres.addElement(L);  // ajouter le livre dans 'mesLivres'
        ...
        // traitement sur tous les elements du vecteur 'liste'
        for(int i=0;i<mesLivres.size();i++) {
            Livre liv=(Livre)mesLivres.elementAt(i);
            ... // traitement sur le livre 'liv'
        }
    ...
    }
}

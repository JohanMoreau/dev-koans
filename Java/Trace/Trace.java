public class Trace {
        private static Trace uniqueInstance;
        private String log;// Chaine de caractères représentant des messages
        private Trace() {
                log = new String("Début\n");
        }
        public static Trace getInstance() {
                if(uniqueInstance==null) {
                        uniqueInstance = new Trace();
                }
                return uniqueInstance;
        }
        public void ajouterLog(String log) {
                this.log+=log+"\n";
        }
        public String afficherLog() {
		return Trace.getInstance().log;
        }

        public static void main(String[] args) {
                Trace trace = Trace.getInstance();
                trace.ajouterLog("Etudiant :"+args[0]);
                float note=0;
                for (int i=1; i<args.length; i++) {
                        note+=Float.parseFloat(args[i]);
                        trace.ajouterLog("  "+args[i]);
                }
                System.out.println(trace.afficherLog()+">>> Note Finale ="+(int)note);
        }
}

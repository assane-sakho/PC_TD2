package exo1;

class Writter implements Runnable {
    String chaine;
    Writter(String chaine) {
        this.chaine = chaine;
    }
    public void run() {
        System.out.println(chaine);
    }
}
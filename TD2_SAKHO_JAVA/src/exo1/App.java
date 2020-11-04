package exo1;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class App {
    public static void main(String[] args) throws InterruptedException {
        String poeme =
                "Souvent, pour s’amuser, les hommes d’équipage\n" +
                "Prennent des goélands, vastes oiseaux des mers,\n" +
                "Qui suivent, indolents compagnons de voyage,\n" +
                "Le navire glissant sur les gouffres amers.\n";

        List<String> vers = Arrays.stream(poeme.split("\n")).collect(Collectors.toList());

        // vers.forEach(ver -> System.out.println(ver));

        for (int i = 0; i < 4; i++) {
            Thread thread = new Thread(new Writter(vers.get(i)));
            thread.start();
            thread.join();
        }
    }
}

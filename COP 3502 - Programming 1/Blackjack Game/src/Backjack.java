import java.util.*;

public class Blackjack {

    public static void main (String[] args) {

       int x = 0;
       int numOne = 0;

       while(true){
           x++;
           System.out.println("START GAME #" + x);

           numOne = (int)(Math.random() * 13)+1;

           System.out.println(numOne);

       }



    }
}

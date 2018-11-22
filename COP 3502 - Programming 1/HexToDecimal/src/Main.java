//Rahul Dani - Lab 5 - 10/11/2017
public class Main {

    public static void main(String[] args){

        String a = args[0].toLowerCase();

        if (a.length() >= 2 && a.substring(0,2).equals("0x")){

            a = a.substring(2);
        }
        char[] hex = a.toCharArray();
        System.out.println(numberFromHex(hex));
    }

    public static long numberFromHex(char[] hex){

        int[] v = new int[hex.length];
        long sum = 0;

        for (int i=0; i<hex.length; i++){

           int a = (int)hex[i];

           if (a <= '9'){

               v[i] = a - '0';

           }

           else if ( a > '9'){

               v[i] = a - 87;

            }

            double number = Math.pow(16, (hex.length - 1) - i) * v[i];
            sum += number;

        }

        return sum;
    }
}

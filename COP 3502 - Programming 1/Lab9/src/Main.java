import java.io.*;
import java.util.*;
//Rahul Dani - Lab 9.
public class Main {

    public static void main(String[] args) throws IOException{

        Scanner inFile = null;
        try {
            FileInputStream bitreader = new FileInputStream("src/input.txt");
            inFile = new Scanner(bitreader);
        } catch (FileNotFoundException e) {
            System.out.println("Error");
        }

            FileOutputStream sentence = new FileOutputStream("src/output.txt");
            PrintWriter write = new PrintWriter(sentence);

        int bitNum = 0;
        while (inFile.hasNextInt()) {

            bitNum = inFile.nextInt();
            String sBitNum = Integer.toString(bitNum);
            int AsciiCode = Integer.parseInt(sBitNum, 2);
            String letters = new Character((char) AsciiCode).toString();

            write.print(letters);
            write.flush();
        }

    }
}


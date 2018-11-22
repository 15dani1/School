//Rahul Dani - Lab 2 COP3502
import java.util.*;
public class Main {

    public static void main(String args[]){

        int length = 0;
        int width = 0;
        int height = 0;
        int radius = 0;
        int sideA = 0;
        int sideB = 0;
        int sideC = 0;
        int base = 0;
        double varS = 0;
        int perimeterRect = 0;     //Perimeter of Rectangle
        int perimeterTri = 0;     // Perimeter of Triangle
        int areaRect = 0;        //Area of Rectangle
        double areaCirc = 0;    //Area of Circle
        double areaTri = 0;    //Area of Triangle
        double circum = 0;    //Circumference of Circle
        int radSphere = 0;
        int diaRectPrism = 0;
        int heightRectPrism = 0;
        int widthRectPrism = 0;
        int heightCyl = 0;     //Height of Cylinder
        int radiusCyl = 0;       // Radius of Cylinder
        double surfAreaSphere = 0;
        double volSphere = 0;
        double surfAreaRectPrism = 0;
        double volRectPrism = 0;
        double surfAreaCyl = 0;
        double volCyl = 0;

    Scanner scnr = new Scanner(System.in);

    System.out.print("Enter length of rectangle (positive integer):");
    length = scnr.nextInt();

    System.out.print("Enter width of rectangle (positive integer):");
    width = scnr.nextInt();

    System.out.print("Now enter the radius of the circle (positive integer):");
    radius = scnr.nextInt();

    System.out.print("Enter side A of Triangle (positive integer):");
    sideA = scnr.nextInt();

    System.out.print("Enter side B of Triangle (positive integer):");
    sideB = scnr.nextInt();

    System.out.print("Enter side C of Triangle (positive integer):");
    sideC = scnr.nextInt();

    areaRect = (length*width);
    perimeterRect = 2*(length+width);
    perimeterTri = sideA + sideB + sideC;
    areaCirc = Math.PI * Math.pow(radius, 2);
    varS = (sideA+sideB+sideC)/2;
    areaTri = (Math.sqrt((varS)*(varS - sideA)*(varS - sideB)*(varS - sideC)));
    circum = Math.PI * 2* (radius);

    System.out.println("");

    System.out.println("Area of rectangle: " + areaRect);
    System.out.println("Area of Circle: " + areaCirc);
    System.out.println("Perimeter of rectangle: " + perimeterRect);
    System.out.println("Circumference of Circle: " + circum);
    System.out.println("Area of Triangle: " + areaTri);
    System.out.println("Perimeter of Triangle: " + perimeterTri);

    System.out.println("");
    System.out.print("Enter radius of sphere: ");
    radSphere = scnr.nextInt();

    System.out.print("Enter the diameter of the rectangular prism: ");
    diaRectPrism = scnr.nextInt();

    System.out.print("Enter the height of the rectangular prism: ");
    heightRectPrism = scnr.nextInt();

    System.out.print("Enter the width of the rectangular prism: ");
    widthRectPrism = scnr.nextInt();

    System.out.print("Enter the height of the cylinder: ");
    heightCyl = scnr.nextInt();

    System.out.print("Enter the radius of the cylinder: ");
    radiusCyl = scnr.nextInt();

    surfAreaSphere = 4 * Math.PI * Math.pow(radSphere, 2);
    volSphere = 4 * Math.PI * ((Math.pow(radSphere, 3))/3);
    surfAreaRectPrism = 2 * ((heightRectPrism*diaRectPrism)+(heightRectPrism*widthRectPrism)+(diaRectPrism*widthRectPrism));
    volRectPrism = heightRectPrism*widthRectPrism*diaRectPrism;
    surfAreaCyl = (2*Math.PI*radiusCyl*heightCyl)+(2*Math.PI*Math.pow(radiusCyl, 2));
    volCyl = Math.PI*Math.pow(radiusCyl, 2)*heightCyl;

        System.out.println("");
        System.out.println("The surface area of the sphere is: " + surfAreaSphere);
        System.out.println("The volume of the sphere is: " + volSphere);
        System.out.println("The surface area of the rectangular prism is: " + surfAreaRectPrism);
        System.out.println("The volume of the rectangular prism is: " + volRectPrism);
        System.out.println("The surface area of the cylinder is: " + surfAreaCyl);
        System.out.println("The volume of the cylinder is: " + volCyl);










    }


}

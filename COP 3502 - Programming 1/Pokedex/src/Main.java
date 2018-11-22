//Rahul Dani - Project 3 COP 3502
// Date: 11/10/2017
// Sources used: https://www.youtube.com/user/thenewboston and Stack OverFlow.
/*The above mentioned sources were ONLY used as references to understand certain concepts and code was
never copy-pasted or rewritten or adjusted in any way.*/

import java.util.*;

public class Main {

    private static Pokedex pDex;

    public static void main(String[] args) { //Main method

        System.out.println("Welcome to your new Pokedex!");
        System.out.print("How many Pokemon are in your region: ");
        Scanner srcr = new Scanner(System.in);
        int pokemonInRegion = 0;
        try{
            pokemonInRegion = srcr.nextInt();       //Pokemon in region.
        }

        catch (InputMismatchException e) { //Makes sure that only integers are inputted.
            srcr.nextLine();
            System.out.println("");
            System.out.println("This is not a valid choice. Try again.");
            System.out.println("");
            main(args);
        }

        if(pokemonInRegion < 0){ //Makes sure that Pokemon in region is either 0 or positive.

            System.out.println("");
            System.out.println("This is not a valid choice. Try again.");
            System.out.println("");
            main(args);
        }
        else {

            pDex = new Pokedex(pokemonInRegion);

            System.out.println("");
            System.out.println("Your new Pokedex can hold " + pokemonInRegion + " Pokemon. Let's start using it!");

            gameMenu(pokemonInRegion);
        }

    }

    public static void gameMenu (int pokemonInRegion){ //Displays the menu to the user.

        System.out.println("");
        System.out.println("1. List Pokemon");
        System.out.println("2. Add Pokemon");
        System.out.println("3. Check a Pokemon's Stats");
        System.out.println("4. Evolve Pokemon");
        System.out.println("5. Sort Pokemon");
        System.out.println("6. Exit");
        System.out.println("");
        System.out.print("What would you like to do? ");
        Scanner srcr = new Scanner(System.in);
        int userInput = 0;

        try {
            userInput = srcr.nextInt();
        } catch (InputMismatchException e) { //Makes sure that only integers are inputted.
            srcr.nextLine();
            System.out.println("");
            System.out.println("This is not a valid choice. Try again.");
            gameMenu(pokemonInRegion);
        }

        if (userInput <= 0 || userInput > 6) { //Makes sure that the inputs inputted are in the range.

            System.out.println("");
            System.out.println("This is not a valid choice. Try again.");
            gameMenu(pokemonInRegion);
        }

        menuSelection(userInput, pokemonInRegion);

    }

    public static void menuSelection(int userInput, int pokemonInRegion){

        String species;
        switch (userInput){ //Switch case based on user input.

            case 1: //List Pokemon

                pDex.listPokemon();
                for(int i=0; i<pokemonInRegion; i++) {

                    if (pDex.listPokemon()[i] != null) {

                        System.out.println((i + 1) + ". " + pDex.listPokemon()[i]);
                    }
                }
                gameMenu(pokemonInRegion);
                break;

            case 2: //Add Pokemon

                System.out.println("");
                System.out.print("Please enter the Pokemon's Species: ");
                Scanner srcr = new Scanner(System.in);
                species = srcr.nextLine();
                pDex.addPokemon(species);
                gameMenu(pokemonInRegion);

                break;

            case 3: //Check Stats of Pokemon

                System.out.println("");
                System.out.print("Please enter the Pokemon of interest: ");
                Scanner src = new Scanner(System.in);
                species = src.nextLine();

                if(pDex.checkStats(species) == null){

                    System.out.println("Missing");

                }

                else {
                    System.out.println("");
                    System.out.println("The stats for " + species + " are:");
                    System.out.println("Attack: " + pDex.checkStats(species)[0]);
                    System.out.println("Defense: " + pDex.checkStats(species)[1]);
                    System.out.println("Speed: " + pDex.checkStats(species)[2]);
                }

                gameMenu(pokemonInRegion);
                break;

            case 4: //Evolves Pokemon

                System.out.println("");
                System.out.print("Please enter the Pokemon of interest: ");
                Scanner srcd = new Scanner(System.in);
                species = srcd.nextLine();
                pDex.evolvePokemon(species);
                gameMenu(pokemonInRegion);
                break;

            case 5: //Sorts Pokemon lexically.

                pDex.sortPokedex();
                gameMenu(pokemonInRegion);
                break;

            case 6: //Exits the Program
                System.exit(1);
                break;
        }

    }

}

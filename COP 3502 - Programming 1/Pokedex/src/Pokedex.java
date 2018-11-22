import java.util.*;
public class Pokedex {

    private static int pokedexNum;
    private Pokemon[] pokemonArray;

    //Makes a constructor in the class.

    public Pokedex(int pokemonInRegion) {

        pokedexNum = pokemonInRegion;
        pokemonArray = new Pokemon[pokedexNum];

    }

    //* Return all the names of the Pokemon species in the
    //* Pokedex

    public String[] listPokemon() {

        String[] x = new String[pokedexNum];


        for (int i = 0; i < pokedexNum; i++) {

            if(pokemonArray[i] != null) {
                x[i] = pokemonArray[i].getSpecies();
            }
        }
        return x;

    }

    // * Add a Pokemon to the Pokedex and return true if it can
    // * actually be added to the Pokedex. If not, return false.

    public boolean addPokemon(String species) {

        int index = -1;
        for (int i = 0; i < pokedexNum; i++) {

            if (pokemonArray[i] == null) {

                index = i;
                break;

            }
        }

        for (int j = 0; j < index; j++) {

            if (species.equals(pokemonArray[j].getSpecies())) { //Checks to see if there are Duplicate Pokemon.

                System.out.println("Duplicate");
                return false;

            }
        }

        if (index == -1) { //Checks to see if more Pokemon are enter than region capacity.

            System.out.println("Max"); //
            return false;

        }

        Pokemon p = new Pokemon(species);
        pokemonArray[index] = p;

        return true;

    }

    // * Return the stats of a certain Pokemon that you are
    //  * searching for.

    public int[] checkStats(String species) {

        int[] y = new int[3];
        boolean found = false;

        int index = -1;
        for (int i = 0; i < pokedexNum; i++) {

            if (pokemonArray[i] == null) {

                index = i;
                break;

            }
        }

        for (int j = 0; j < index; j++) {

            if (species.equals(pokemonArray[j].getSpecies())) {

                y[0] = pokemonArray[j].getAttack();
                y[1] = pokemonArray[j].getDefense();
                y[2] = pokemonArray[j].getSpeed();
                found = true;

            }
        }
        if (!found){

            y = null;
        }

        return y;
    }

    // * Sort Pokedex in lexical order according to Java string ordering.
    public void sortPokedex() {

        int index = pokedexNum;
        for (int i = 0; i < pokedexNum; i++) {

            if (pokemonArray[i] == null) {

                index = i;
                break;

            }
        }

        String[] pokemons;
        if(index > 0){

            pokemons = new String[index];
            for (int i = 0; i < index; i++) {

                pokemons[i] = pokemonArray[i].getSpecies();

            }

            Arrays.sort(pokemons);

            int locI = 0;
            int locJ = 0;
            for (int i = 0; i < index - 1; i++) {

                for (int j = i + 1; j < index; j++) {
                    for(int k = 0; k < index; k++){

                        if (pokemonArray[i].getSpecies() == pokemons[k]){

                            locI = k;
                        }
                    }

                    for(int l = 0; l < index; l++){

                        if (pokemonArray[j].getSpecies() == pokemons[l]){

                            locJ = l;
                        }
                    }

                    if (locI > locJ) {

                        Pokemon movePok = pokemonArray[i];
                        pokemonArray[i] = pokemonArray[j];
                        pokemonArray[j] = movePok;
                    }
                }
            }

        }
    }


    // * Evolve a certain Pokemon that you are searching for in the
    // * Pokedex and return true if the Pokemon is actually in the
    // * the Pokedex. If not, return false.

    public boolean evolvePokemon(String species) {

        boolean found = false;

        int index = -1;
        for (int i = 0; i < pokedexNum; i++) {

            if (pokemonArray[i] == null) {

                index = i;
                break;

            }
        }

        for (int j = 0; j < index; j++) {

            if (species.equals(pokemonArray[j].getSpecies())) {

                pokemonArray[j].evolve();
                found = true;

            }
        }

        if(!found){

            System.out.println("Missing");
            return false;
        }

        else{

            System.out.println(species + " has evolved!");

        }

        return found;

    }

}

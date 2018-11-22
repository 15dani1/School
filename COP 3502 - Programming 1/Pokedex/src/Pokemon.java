public class Pokemon {

    private String species;
    private int attackVal;
    private int defenseVal;
    private int speedVal;

    public Pokemon(String species){

        attackVal = species.length() * 4 + 2;
        defenseVal = species.length() * 2 + 7;
        speedVal = species.length() * 3 + 5;
        this.species = species;

    }

    public void evolve(){

       setAttack(getAttack()*3);
       setDefense(getDefense()*5);
       setSpeed(getSpeed()*2);

    }


    public int getAttack(){

        return attackVal;

    }

    public void setAttack(int newAttack){

        attackVal = newAttack;
    }

    public int getDefense(){

        return defenseVal;
    }

    public void setDefense(int newDefense){

        defenseVal = newDefense;
    }

    public int getSpeed(){

        return speedVal;
    }

    public void setSpeed(int newSpeed){

        speedVal = newSpeed;
    }

    public String getSpecies(){

        return species;
    }

    public void setSpecies(String newSpecies){

        species = newSpecies;
    }

}

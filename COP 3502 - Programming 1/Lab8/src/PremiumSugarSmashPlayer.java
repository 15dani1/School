// extend SugarSmashPlayer as PremiumSugarSmashPlayer here
public class PremiumSugarSmashPlayer extends SugarSmashPlayer
{
    // declare private variables here
    private int boosters;

    public PremiumSugarSmashPlayer()
    {
        //super();
        // add constructor code here
        boosters = 3;

    }

    // override (public!) earnPoints() method here
    @Override
    public void earnPoints()
    {
        // add method code here


        if (boosters == 0) {

            System.out.println("Out of boosters!");
            super.earnPoints();

        }
        else{
            int points = getPoints() + 500;
            setPoints(points);
            boosters = boosters - 1;
        }


    }

    public void buyBoosters() {
        // add method code here

            boosters = boosters + 3;

    }
}
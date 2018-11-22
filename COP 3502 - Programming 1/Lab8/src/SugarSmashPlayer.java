public class SugarSmashPlayer {

    // add private variables here
    private int idNum;
    private String name;
    private int points;

    public SugarSmashPlayer()
    {

        idNum = 5;
        name = "John";
        // add constructor code here
    }
    public void setIdNumber(int num)
    {
        // add method code here
        idNum = num;
    }
    public void setName(String player)
    {
        // add method code here
        name = player;
    }
    public void setPoints(int pts)
    {
        // add method code here
        points = pts;
    }
    public void earnPoints()
    {
        // add method code here
        points = points + 100;

    }
    public int getIdNumber()
    {
        // add method code here
        return idNum;
    }
    public String getName()
    {
        // add method code here
        return name;
    }
    public int getPoints()
    {
        // add method code here
        return points;
    }
}


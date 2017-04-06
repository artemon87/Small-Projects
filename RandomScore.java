import java.util.*;

public class RandomScore
{
  public int team1;
  public int team2;
  
  public RandomScore()
  {
    Random score=new Random();
    team1=score.nextInt(5);
    team2=score.nextInt(5);
  }
  public List<Integer> getScore()
  {
    List<Integer> list=new ArrayList<Integer>();
    list.add(team1);
    list.add(team2);
    return list;
  }
}
import java.util.*;

//nth row of pascal's triangle

public class Main {
    private static List<Integer> get_nth_row(int n){
      List<Integer> row = new ArrayList<>();
      row.add(1);
      
      for(int i = 1; i <= n; i++){
        List<Integer> new_row = new ArrayList<>();
        new_row.add(1);
        
        for(int j = 1; j < row.size(); j++){
          new_row.add(row.get(j-1) +  row.get(j));
        }
        
        new_row.add(1);
        
        row = new_row;
      }
      
      return row;
    }
    public static void main(String[] args) {
      int n = 7;
      
      List<Integer> nth_row;
      
      nth_row = get_nth_row(n);
      
      for(int i = 0; i < nth_row.size(); i++){
        System.out.print(nth_row.get(i) + " ");
      }
  }
}
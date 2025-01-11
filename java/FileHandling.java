import java.util.*;
import java.io.*;

public class FileHandling {
    public static void main(String[] args) throws IOException{
        ArrayList<String> str=new ArrayList<>();
        System.out.println("Enter Strings");
        try (Scanner sc = new Scanner(System.in)) {
            do{ 
                str.add(sc.nextLine());
                System.out.println("Continue: enter 0 to break ");
                char ch=sc.nextLine().charAt(0);
                if(ch=='0')
                {
                    break;
                }
            }
            while(true);
        }
        //adding to file---------------------
        try {
            FileWriter fr=new FileWriter("file1.txt");
            for (String line : str) 
            {
                fr.write(line + "\n");
            }
            fr.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    } 
}

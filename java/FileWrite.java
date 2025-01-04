import java.io.*;
import java.util.*;

public class FileWrite {
    public static void main(String[] args) throws Exception{
        FileWriter fw=null;
        try
        {
            BufferedReader br1=new BufferedReader(new FileReader("file1.txt"));
            BufferedReader br2=new BufferedReader(new FileReader("file2.txt"));
            fw=new FileWriter("file3.txt");
            LinkedHashSet<String> set=new LinkedHashSet<>();
            String str1,str2;
            while((str1=br1.readLine())!=null)
            {
                set.add(str1);
            }
            while((str2=br2.readLine())!=null)
            {
                set.add(str2);
            }
            for(String x: set)
            {
                fw.write(x+" \n");
            }
            //---------------------
            br1.close();
            br2.close();
        }
        catch(IOException e)
        {
            System.out.println(e);
        }
        finally
        {
            if (fw!=null)
            {
                try {
                    fw.close();
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
        }
    }
}


class DefExc extends Exception{
    DefExc (String S)
    {
        super(S);
    }
}

public class UserDefExc {
    public static void main(String[] args) {
        int age=15;
        try{
            if(age<18)
            {
                throw new DefExc("Underage");
            }
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}

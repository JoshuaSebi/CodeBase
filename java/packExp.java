import operator.div;
import operator.parent;
import operator.*;
import java.util.*;

class calc
{
    int a,b;
    calc(int a, int b)
    {
        this.a=a;
        this.b=b;
    }
    int opt;
    Scanner sc=new Scanner(System.in);
    void calculation()
    {
        System.out.print("Enter option: ");
        opt =sc.nextInt();
        if(opt==1)
        {
            int res=div.print(a,b);
            System.out.println("Div = "+res);            
        }
        else{
            sub dv=new sub(a,b);
            int res=dv.print();
            System.out.println("rst = "+res);  
        }
    }
}

class child extends parent{

}

public class packExp {
    public static void main(String[] args) {
        child c=new child();
        c.run();
        calc cl=new calc(5,3);
        cl.calculation();
    }   
}

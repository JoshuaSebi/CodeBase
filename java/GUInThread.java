import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class thread1 extends Thread
{
    int n;
    thread1(int n)
    {
        this.n=n;
    }
    public void run()
    {
        for(int i=0;i<n;i++)
        {
            System.out.println("Thrikkakara");
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}


class thread2 extends Thread
{
    int n;
    thread2(int n)
    {
        this.n=n;
    }
    public void run()
    {
        for(int i=0;i<n;i++)
        {
            System.out.println("Kochi");
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}

class demo extends JFrame implements ActionListener
{
    JTextField count;
    JButton print;
    JFrame jfrm=new JFrame("Counter");
    demo()
    {
        jfrm.setSize(300,400);
        jfrm.setLocationRelativeTo(null);
        jfrm.setLayout(new FlowLayout());

        JLabel txt=new JLabel("Enter Count: ");
        count=new JTextField();
        count.setColumns(10);
        print=new JButton("PRINT");
        jfrm.add(txt);
        jfrm.add(count);
        jfrm.add(print);

        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jfrm.setVisible(true);

        print.addActionListener(this);
        count.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae)
    {
        String s=ae.getActionCommand();
        if (s.equalsIgnoreCase("print"))
        {
            int cn=Integer.parseInt(count.getText());
            thread1 th1=new thread1(cn);
            thread2 th2=new thread2(cn);
            th1.start();
            th2.start();
        }        
    }
}

public class GUInThread {
    public static void main(String[] args) {
        new demo();
    }
}

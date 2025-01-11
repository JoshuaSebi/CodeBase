import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

class SwingF extends JFrame implements ActionListener
{
    String fname,word;
    JButton find,check;
    JTextField field,outfield,resfield;
    JPanel p1,p2,p3,p4;
    SwingF()
    {
        JFrame jfrm=new JFrame("File Search");
        jfrm.setSize(400,300);
        jfrm.setLocationRelativeTo(null);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jfrm.setLayout(new GridLayout(5,1));
        jfrm.setBackground(Color.blue);

        //--------------------
        p1=new JPanel(new FlowLayout());        
        p2=new JPanel(new FlowLayout());  
        p3=new JPanel(new FlowLayout());
        p4=new JPanel(new FlowLayout());
        
        //----P1------
        JLabel l1=new JLabel("Enter File name             ");
        JLabel l2=new JLabel("Enter Word");
        p1.add(l1);
        p1.add(l2);

        //----P2-----
        field=new JTextField();
        field.setColumns(10);
        outfield=new JTextField();   
        outfield.setColumns(10);   
        field.setFont(new Font("Arial",Font.BOLD,15));
        outfield.setFont(new Font("Arial",Font.BOLD,15));
        p2.add(field);
        p2.add(outfield);

        //------P3-----
        JLabel rex=new JLabel("Output");
        resfield=new JTextField();
        resfield.setColumns(10);
        resfield.setEditable(false);
        p4.add(rex);
        p4.add(resfield);

        //----P4----
        find = new JButton("FIND");
        check=new JButton("CHECK"); 
        p3.add(find);
        p3.add(check);

        jfrm.add(p1);
        jfrm.add(p2);
        jfrm.add(p4);
        jfrm.add(p3);
        jfrm.setVisible(true);     
        
        find.addActionListener(this);
        check.addActionListener(this);
        field.addActionListener(this);
        outfield.addActionListener(this);
        resfield.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae)
    {
        String str=ae.getActionCommand();
        fname=field.getText();
        word=outfield.getText();
        if (str.equalsIgnoreCase("find"))
        {   
            int pos=0;
            try{
                BufferedReader br=  new BufferedReader(new FileReader(fname));
                String fileword;
                while((fileword=br.readLine())!=null)
                {
                    if(fileword.equalsIgnoreCase(word))
                    {
                        break;
                    }
                    pos++;
                }
                br.close();
            }
            catch(IOException e){
                 System.out.println(e);   
            }
            resfield.setText("Word found at "+pos);
        }
    }
}


public class SwingFile {
    public static void main(String[] args) {
        new SwingF();
    }
}

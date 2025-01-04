import java.util.*;

class Doublyll
{

    class node
    {
        int data;
        node next,prev;
        node(int data)
        {
            this.data=data;
            next=null;
            prev=null;
        }
    }
    node head=null,tail=null;

    void insertNode(int data)
    {
        node newnode=new node(data);
        if (head==null)
        {
            head=tail=newnode;
        }
        else{
            tail.next=newnode;
            newnode.prev=tail;
            tail=newnode;
        }
    }

    void insertStart(int data)
    {
        node newnode=new node(data);
        newnode.next=head;
        head.prev=newnode;
        head=newnode;
    }
    void insertEnd(int data)
    {
        node newnode=new node(data);
        tail.next=newnode;
        newnode.prev=tail;
        tail=newnode;
    }

    void insertPos(int data,int pos)
    {
        node newnode=new node(data);
        node temp=head;
        int i= 1;
        if(pos==1)
        {
            insertStart(data);
        }
        else{
            while(temp.next!=null && i<pos-1)
            {
                temp=temp.next;
                i++;
            }
            if(temp.next==null)
            {
                insertEnd(data);
            }
            else{
                newnode.next=temp.next;
                temp.next.prev=newnode;
                temp.next=newnode;
                newnode.prev=temp;
            }
        }
        
    }

    void display()
    {
        node temp=head;
        while(temp!=null)
        {
            System.out.print(temp.data+" --> ");
            temp=temp.next;
        }
        System.out.println("NULL");
    }
    
}

public class DLL {
    public static void main(String[] args) 
    {
        Doublyll dl=new Doublyll();
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter Number of nodes: ");
        int num=sc.nextInt();
        char ch;
        int item;
        for(int i=0;i<num;i++)
        {
            System.out.print("Enter data: ");
            item=sc.nextInt();
            dl.insertNode(item);
        }
        System.out.println("1.Insert start\n2.Insert End\n3.Insert Pos\n7.display\n8.Exit");
        do
        {
            System.out.print("Enter Option: ");
            int opt=sc.nextInt();

            switch(opt)
            {
                case 1:
                    System.out.print("Enter data: ");
                    item=sc.nextInt();
                    dl.insertStart(item);
                    break;
                case 2:
                    System.out.print("Enter data: ");
                    item=sc.nextInt();
                    dl.insertEnd(item);
                    break;
                case 3:
                    System.out.print("Enter data and location: ");
                    item=sc.nextInt();
                    int loc=sc.nextInt();
                    dl.insertPos(item, loc);
                    break;
                case 7:
                    dl.display();break;
                default:
                    System.exit(0);
            }
        }
        while(true);
    }
}

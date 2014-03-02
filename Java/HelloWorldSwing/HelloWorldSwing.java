import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;

public class HelloWorldSwing implements ActionListener{
    private static void createAndShowGUI(){
        HelloWorldSwing h = new HelloWorldSwing();
        h.show();
    }
    public void show(){
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());
        JLabel label = new JLabel("Hello World");
        frame.add(label, BorderLayout.NORTH);
        JButton b =new JButton("Mon bouton");
        frame.add(b, BorderLayout.SOUTH);
        frame.pack();
        frame.setVisible(true);
        b.addActionListener(this) ;
    }
    public void actionPerformed(ActionEvent e){
        System.out.println("Someone push on my Hello World button");
    }
    public static void main(String[] args){
        javax.swing.SwingUtilities.invokeLater(new Runnable(){
            public void run(){createAndShowGUI();}
        });
    }
}

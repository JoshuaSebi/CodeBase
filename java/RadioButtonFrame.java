import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RadioButtonFrame extends JFrame implements ActionListener {
    private JRadioButton bit1, bit0;
    private JTextField textField;
    private JButton button;
    private boolean bit1Selected, bit0Selected;
    
    public RadioButtonFrame() {
        setTitle("Radio Button Frame");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        
        // Create radio buttons and set action commands
        bit1 = new JRadioButton("Bit 1");
        bit0 = new JRadioButton("Bit 0");
        bit1.setActionCommand("Bit 1");
        bit0.setActionCommand("Bit 0");
        
        bit1.setBounds(30, 30, 60, 30);
        bit0.setBounds(30, 60, 60, 30);
        
        // Add action listeners to radio buttons
        bit1.addActionListener(this);
        bit0.addActionListener(this);
        
        // Create text field
        textField = new JTextField("0");
        textField.setBounds(30, 100, 100, 30);
        textField.setEditable(false);
        
        // Create button
        button = new JButton("Display");
        button.setActionCommand("Display");
        button.setBounds(150, 100, 80, 30);
        button.addActionListener(this);
        
        // Add components to the frame
        add(bit1);
        add(bit0);
        add(textField);
        add(button);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        // Check if Bit 1 is selected
        if ("Bit 1".equals(command)) {
            bit1Selected = bit1.isSelected();
        }

        // Check if Bit 0 is selected
        if ("Bit 0".equals(command)) {
            bit0Selected = bit0.isSelected();
        }
        
        // Update text based on radio button selection
        if (bit1Selected && bit0Selected) {
            textField.setText("3");  // Set to 3 if both are selected
        } else if (bit1Selected) {
            textField.setText("2");  // Set to 2 if only Bit 1 is selected
        } else if (bit0Selected) {
            textField.setText("1");  // Set to 1 if only Bit 0 is selected
        } else {
            textField.setText("0");  // Set to 0 if neither is selected
        }

        // Check if the display button was clicked
        if ("Display".equals(command)) {
            textField.setText("");  // Clear the text field
        }
    }
    
    public static void main(String[] args) {
        RadioButtonFrame frame = new RadioButtonFrame();
        frame.setVisible(true);
    }
}

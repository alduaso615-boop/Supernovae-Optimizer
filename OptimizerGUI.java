import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;

public class OptimizerGUI {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Supernovae Control Panel");
        JButton btn = new JButton("Activar Modo SS (Bajar Latencia)");
        
        btn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    // Java ejecuta tu optimizador de C++
                    Runtime.getRuntime().exec("SupernovaeOptimizer.exe");
                    JOptionPane.showMessageDialog(null, "¡Optimizador C++ ejecutado!");
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        });

        frame.add(btn);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
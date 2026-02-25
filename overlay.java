import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.nio.file.*;
import java.util.Scanner;

public class OverlayJava extends JFrame {
    private Color overlayColor = Color.GREEN; // Color por defecto

    public OverlayJava() {
        setUndecorated(true);
        setBackground(new Color(0, 0, 0, 0)); // Transparencia total
        setAlwaysOnTop(true);
        setSize(400, 100);
        
        // Hilo para leer el color que Python elija
        new Thread(() -> {
            while(true) {
                leerConfiguracion();
                repaint();
                try { Thread.sleep(1000); } catch (InterruptedException e) {}
            }
        }).start();
    }

    private void leerConfiguracion() {
        try {
            String content = new String(Files.readAllBytes(Paths.get("color.txt")));
            String[] rgb = content.split(",");
            overlayColor = new Color(Integer.parseInt(rgb[0]), Integer.parseInt(rgb[1]), Integer.parseInt(rgb[2]));
        } catch (Exception e) { /* Si falla, sigue en verde */ }
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(overlayColor);
        g.setFont(new Font("Consolas", Font.BOLD, 18));
        g.drawString("FPS: 999 | MODO LUAU ACTIVO", 10, 30);
    }

    public static void main(String[] args) {
        new OverlayJava().setVisible(true);
    }
}
import javax.swing.ImageIcon;
import java.awt.Image;

// ... dentro de tu clase
public void configurarVentana() {
    // Carga el icono que ya tienes en C:\DLLGAME
    ImageIcon iconoOriginal = new ImageIcon("iconsuper.ico");
    
    // Le asigna la imagen a la ventana de Java
    this.setIconImage(iconoOriginal.getImage());
    
    // Opcional: Si quieres que se vea en el sistema de forma más nítida
    this.setTitle("Supernovae Optimizer v1.0 - YEAH!");
}